-- SM64 Land Moveset --

-- Note that a bunch of the code was taken from extended moveset, the rest is written by xLuigiGamerx

------------------------------
----- Localize functions -----
------------------------------

local allocate_mario_action, atan2s, sins, coss, mario_set_forward_vel, set_mario_action, play_mario_sound, play_sound, set_mario_animation, set_anim_to_frame,
check_fall_damage_or_get_stuck, common_air_action_step, perform_air_step, mario_drop_held_object =
    allocate_mario_action, atan2s, sins, coss, mario_set_forward_vel, set_mario_action, play_mario_sound, play_sound, set_mario_animation, set_anim_to_frame,
    check_fall_damage_or_get_stuck, common_air_action_step, perform_air_step, mario_drop_held_object
local math_floor = math.floor

------------------------
-- initialize actions --
------------------------

ACT_FAKE_FREEFALL = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
ACT_GROUND_POUND_JUMP = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR |
    ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
ACT_SPIN_JUMP = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
ACT_WALL_SLIDE = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_MOVING |
    ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
local ACT_CUSTOM_AIR_HIT_WALL = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR)

-----------------------------
-- initialize extra fields --
-----------------------------

local ANGLE_QUEUE_SIZE = 9
local SPIN_TIMER_SUCCESSFUL_INPUT = 4
local SPIN_RISE_TIMER = 0

local didSpin = false

local climbTimer = 4

local SPINACTIONS = {
    [ACT_JUMP] = true,
    [ACT_DOUBLE_JUMP] = true,
    [ACT_TRIPLE_JUMP] = true,
    [ACT_LONG_JUMP] = true,
    [ACT_SIDE_FLIP] = true,
    [ACT_GROUND_POUND_JUMP] = true,
    [ACT_FORWARD_ROLLOUT] = true,
    [ACT_BACKWARD_ROLLOUT] = true,
    [ACT_WALL_KICK_AIR] = true,
    [ACT_BACKFLIP] = true,
    [ACT_FREEFALL] = true
}

local gMarioStateExtras = {}
for i = 0, (MAX_PLAYERS - 1) do
    gMarioStateExtras[i] = {}
    local m = gMarioStates[i]
    local e = gMarioStateExtras[i]
    e.angleDeltaQueue = {}
    for j = 0, (ANGLE_QUEUE_SIZE - 1) do e.angleDeltaQueue[j] = 0 end
    e.rotAngle = 0
    e.boostTimer = 0

    e.stickLastAngle = 0
    e.spinDirection = 0
    e.spinBufferTimer = 0
    e.spinInput = 0
    e.lastIntendedMag = 0

    e.lastPos = {}
    e.lastPos.x = m.pos.x
    e.lastPos.y = m.pos.y
    e.lastPos.z = m.pos.z

    e.fakeSavedAction = 0
    e.fakeSavedPrevAction = 0
    e.fakeSavedActionTimer = 0
    e.fakeWroteAction = 0
    e.fakeSaved = false

    e.savedWallSlideHeight = 0
    e.savedWallSlide = false

    e.animFrame = 0
end

local function limit_angle(a)
    return (a + 0x8000) % 0x10000 - 0x8000
end

-------------------------
-- fall damage removal --
-------------------------
function no_fall_damage(m)
    m.peakHeight = m.pos.y
end

function responsive_ground_pound_turn(m)
    if m.playerIndex ~= 0 then return end
    if m.prevAction == ACT_GROUND_POUND_LAND and m.action ~= ACT_GROUND_POUND_JUMP and m.action & ACT_FLAG_AIR == 0 then
        m.faceAngle.y = m.intendedYaw
    end
end

hook_event(HOOK_MARIO_UPDATE, responsive_ground_pound_turn)

----------
-- spin --
----------

local function mario_update_spin_input(m)
    if m.action & ACT_FLAG_AIR == 0 then return end
    local e = gMarioStateExtras[m.playerIndex]
    local rawAngle = atan2s(-m.controller.stickY, m.controller.stickX)
    e.spinInput = 0

    -- prevent issues due to the frame going out of the dead zone registering the last angle as 0
    if e.lastIntendedMag > 0.5 and m.intendedMag > 0.5 then
        local angleOverFrames = 0
        local thisFrameDelta = 0
        -- local i = 0

        local newDirection = e.spinDirection
        local signedOverflow = 0

        if rawAngle < e.stickLastAngle then
            if e.stickLastAngle - rawAngle > 0x8000 then
                signedOverflow = 1
            end
            if signedOverflow ~= 0 then
                newDirection = 1
            else
                newDirection = -1
            end
        elseif rawAngle > e.stickLastAngle then
            if rawAngle - e.stickLastAngle > 0x8000 then
                signedOverflow = 1
            end
            if signedOverflow ~= 0 then
                newDirection = -1
            else
                newDirection = 1
            end
        end

        if e.spinDirection ~= newDirection then
            for i = 0, (ANGLE_QUEUE_SIZE - 1) do
                e.angleDeltaQueue[i] = 0
            end
            e.spinDirection = newDirection
        else
            for i = (ANGLE_QUEUE_SIZE - 1), 1, -1 do
                e.angleDeltaQueue[i] = e.angleDeltaQueue[i - 1]
                angleOverFrames = angleOverFrames + e.angleDeltaQueue[i]
            end
        end

        if e.spinDirection < 0 then
            if signedOverflow ~= 0 then
                thisFrameDelta = math_floor((1.0 * e.stickLastAngle + 0x10000) - rawAngle)
            else
                thisFrameDelta = e.stickLastAngle - rawAngle
            end
        elseif e.spinDirection > 0 then
            if signedOverflow ~= 0 then
                thisFrameDelta = math_floor(1.0 * rawAngle + 0x10000 - e.stickLastAngle)
            else
                thisFrameDelta = rawAngle - e.stickLastAngle
            end
        end

        e.angleDeltaQueue[0] = thisFrameDelta
        angleOverFrames = angleOverFrames + thisFrameDelta

        if angleOverFrames >= 0xA000 then
            e.spinBufferTimer = SPIN_TIMER_SUCCESSFUL_INPUT
        end


        -- allow a buffer after a successful input so that you can switch directions
        if e.spinBufferTimer > 0 then
            e.spinInput = 1
            e.spinBufferTimer = e.spinBufferTimer - 1
        end
    else
        e.spinDirection = 0
        e.spinBufferTimer = 0
    end

    e.stickLastAngle = rawAngle
    e.lastIntendedMag = m.intendedMag
end

local function act_fake_freefall(m)
    if m.playerIndex ~= 0 then return end

    common_air_action_step(m, ACT_FREEFALL, MARIO_ANIM_GENERAL_FALL,
    AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG)
end

local function act_spin_jump(m)
    local e = gMarioStateExtras[m.playerIndex]
    if m.actionTimer == 0 then
        -- determine clockwise/counter-clockwise spin
        if e.spinDirection < 0 then
            m.actionState = 1
        end
    end

    local spinDirFactor = 1 -- negative for clockwise, positive for counter-clockwise
    if m.actionState == 1 then
        spinDirFactor = -1
    end

    if SPIN_RISE_TIMER % 10 == 0 and SPIN_RISE_TIMER ~= 30 then
        play_sound(SOUND_ACTION_TWIRL, m.marioObj.header.gfx.cameraToObject)
    end

    common_air_action_step(m, ACT_DOUBLE_JUMP_LAND, MARIO_ANIM_TWIRL,
        AIR_STEP_CHECK_HANG)

    if m.action == ACT_SPIN_JUMP then
        SPIN_RISE_TIMER = SPIN_RISE_TIMER + 1
        if SPIN_RISE_TIMER <= 30 then
            m.vel.y = 10
            if m.forwardVel > 15 then
                m.forwardVel = 15
            end
        else
            set_mario_action(m, ACT_FAKE_FREEFALL, 0)
            SPIN_RISE_TIMER = 0
        end
    else
        SPIN_RISE_TIMER = 0
    end

    e.rotAngle = e.rotAngle + 0x2867
    if (e.rotAngle > 0x1000) then e.rotAngle = e.rotAngle - 0x1000 end

    m.marioBodyState.handState = MARIO_HAND_OPEN

    m.marioObj.header.gfx.angle.y = limit_angle(m.marioObj.header.gfx.angle.y + (e.rotAngle * spinDirFactor))

    m.actionTimer = m.actionTimer + 1

    return false
end

local function act_spin_jump_gravity(m)
    if (m.flags & MARIO_WING_CAP) ~= 0 and m.vel.y < 0.0 and (m.input & INPUT_A_DOWN) ~= 0 then
        m.marioBodyState.wingFlutter = 1
        m.vel.y = m.vel.y - 0.7
        if m.vel.y < -37.5 then
            m.vel.y = m.vel.y + 1.4
            if m.vel.y > -37.5 then
                m.vel.y = -37.5
            end
        end
    else
        if m.vel.y > 0 then
            m.vel.y = m.vel.y - 4
        else
            m.vel.y = m.vel.y - 1.4
        end

        if m.vel.y < -75.0 then
            m.vel.y = -75.0
        end
    end

    return 0
end

----------------
-- wall slide --
----------------

function act_wall_slide(m)
    local e = gMarioStateExtras[m.playerIndex]
    e.savedWallSlideHeight = m.pos.y
    e.savedWallSlide = true

    if m.actionTimer == 0 then
        e.animFrame = 0
    end

    if (m.input & INPUT_A_PRESSED) ~= 0 then
        m.vel.y = 52.0
        -- m.faceAngle.y = limit_angle(m.faceAngle.y + 0x8000)
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0)
    end

    -- attempt to stick to the wall a bit. if it's 0, sometimes you'll get kicked off of slightly sloped walls
    mario_set_forward_vel(m, -1)

    m.particleFlags = m.particleFlags | PARTICLE_DUST

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m.terrainSoundAddend, m.marioObj.header.gfx.cameraToObject)
    set_mario_animation(m, MARIO_ANIM_START_WALLKICK)

    if perform_air_step(m, 0) == AIR_STEP_LANDED then
        mario_set_forward_vel(m, 0.0)
        if check_fall_damage_or_get_stuck(m, ACT_HARD_BACKWARD_GROUND_KB) == 0 then
            return set_mario_action(m, ACT_FREEFALL_LAND, 0)
        end
    end

    m.actionTimer = m.actionTimer + 1
    if not m.wall and m.actionTimer > 2 then
        mario_set_forward_vel(m, 0.0)
        return set_mario_action(m, ACT_FREEFALL, 0)
    end

    return 0
end

local function act_wall_slide_gravity(m)
    m.vel.y = m.vel.y - 2

    if m.vel.y < -15 then
        m.vel.y = -15
    end
end

local function act_air_hit_wall(m)
    if m.heldObj ~= 0 then
        mario_drop_held_object(m)
    end

    m.actionTimer = m.actionTimer + 1
    if m.actionTimer <= 1 and (m.input & INPUT_A_PRESSED) ~= 0 then
        m.vel.y = 52.0
        m.faceAngle.y = limit_angle(m.faceAngle.y + 0x8000)
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0)
    elseif m.forwardVel >= 38.0 then
        if m.vel.y > 0.0 then
            m.vel.y = 0.0
        end
        if activePowerup ~= CAT then
            m.faceAngle.y = limit_angle(m.faceAngle.y + 0x8000)
            m.particleFlags = m.particleFlags | PARTICLE_VERTICAL_STAR
            return set_mario_action(m, ACT_WALL_SLIDE, 0)
        else
            return set_mario_action(m, ACT_CAT_CLIMB, 0)
        end
    else
        m.faceAngle.y = limit_angle(m.faceAngle.y + 0x8000)
        return set_mario_action(m, ACT_WALL_SLIDE, 0)
    end

    --! Missing return statement (in original C code). The returned value is the result of the call
    -- to set_mario_animation. In practice, this value is nonzero.
    -- This results in this action "cancelling" into itself. It is supposed to
    -- execute three times, each on a separate frame, but instead it executes
    -- three times on the same frame.
    -- This results in firsties only being possible for a single frame, instead
    -- of three.
    return set_mario_animation(m, MARIO_ANIM_START_WALLKICK)
end
local convert_actions = {
    [ACT_AIR_HIT_WALL] = ACT_CUSTOM_AIR_HIT_WALL
}

local function before_set_mario_action(m, action)
    return convert_actions[action] ~= nil and convert_actions[action] or action
end

local function act_ground_pound_jump(m)
    play_mario_sound(m, SOUND_ACTION_TERRAIN_JUMP, CHAR_SOUND_YAHOO)
    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        mario_set_forward_vel(m, 10.0)
        m.vel.y = 35.0
        play_mario_sound(m, CHAR_SOUND_HOOHOO, CHAR_SOUND_HOOHOO)
        set_mario_action(m, ACT_DIVE, 0)
    end
    if (m.controller.buttonPressed & Z_TRIG) ~= 0 then
        set_mario_action(m, ACT_GROUND_POUND, 0)
    end
    set_mario_action(m, ACT_TRIPLE_JUMP, 0)
    m.actionTimer = m.actionTimer + 1
    return 0
end

local function mario_on_set_action(m)
    local e = gMarioStateExtras[m.playerIndex]

    if (m.action & ACT_FLAG_MOVING) ~= 0 then
        e.savedWallSlide = false
    end

    if e.spinInput ~= 0 and (m.input & INPUT_ABOVE_SLIDE) == 0 then
        if SPINACTIONS[m.action] or m.controller.buttonPressed == X_BUTTON or m.action == ACT_FAKE_JUMP then
            if stuck then return end
            if (m.action == ACT_FAKE_JUMP or m.action == ACT_WALL_KICK_AIR or m.action == ACT_WALL_SLIDE or m.action == ACT_FREEFALL) and didSpin then return end
            set_mario_action(m, ACT_SPIN_JUMP, 1)
            m.vel.y = 65.0
            m.faceAngle.y = m.intendedYaw
            didSpin = true
        end
    end
    
    if m.action & ACT_FLAG_AIR == 0 then
        didSpin = false
    end

    if m.action == ACT_GROUND_POUND_JUMP then
        m.vel.y = 65.0
    elseif m.action == ACT_WALL_SLIDE then
        m.vel.y = 0.0
    elseif m.action == ACT_GROUND_POUND and m.prevAction == ACT_SIDE_FLIP then
        -- correct animation
        m.marioObj.header.gfx.angle.y = limit_angle(m.marioObj.header.gfx.angle.y - 0x8000)
    elseif m.action == ACT_LEDGE_GRAB then
        e.rotAngle = m.forwardVel
    end
end

local function before_mario_update(m)
    local e = gMarioStateExtras[m.playerIndex]
    -- revert fake saved action
    if e.fakeSaved == true then
        if m.action == e.fakeWroteAction and m.prevAction == e.fakeSavedPrevAction and m.actionTimer == e.fakeSavedActionTimer then
            m.action = e.fakeSavedAction
        end
        e.fakeSaved = false
    end
end

local function mario_update(m)
    local e = gMarioStateExtras[m.playerIndex]

    mario_update_spin_input(m)

    -- dive out of ACT_GROUND_POUND
    if m.action == ACT_GROUND_POUND and (m.input & INPUT_B_PRESSED) ~= 0 then
        mario_set_forward_vel(m, 20.0)
        m.vel.y = 35.0
        set_mario_action(m, ACT_DIVE, 0)
        play_sound(SOUND_GENERAL_SWISH_WATER, m.marioObj.header.gfx.cameraToObject)
    end

    -- spin
    if (SPINACTIONS[m.action] or m.action == ACT_FAKE_JUMP) and e.spinInput ~= 0 or (m.controller.buttonPressed == X_BUTTON and (SPINACTIONS[m.action] or m.action == ACT_FAKE_JUMP)) then
        if stuck then return end
        if (m.action == ACT_FAKE_JUMP or m.action == ACT_WALL_KICK_AIR or m.action == ACT_WALL_SLIDE or m.action == ACT_FREEFALL) and didSpin then return end
        set_mario_action(m, ACT_SPIN_JUMP, 1)
        m.vel.y = 65.0
        m.faceAngle.y = m.intendedYaw
        e.spinInput = 0
        didSpin = true
    end

    -- ground pound jump
    if m.action == ACT_GROUND_POUND_LAND and (m.input & INPUT_A_PRESSED) ~= 0 then
        set_mario_action(m, ACT_GROUND_POUND_JUMP, 0)
        m.vel.y = 70
    end

    -- save last pos
    e.lastPos.x = m.pos.x
    e.lastPos.y = m.pos.y
    e.lastPos.z = m.pos.z
end

-----------
-- hooks --
-----------

hook_event(HOOK_BEFORE_MARIO_UPDATE, before_mario_update)
hook_event(HOOK_MARIO_UPDATE, mario_update)
hook_event(HOOK_MARIO_UPDATE, no_fall_damage)
hook_event(HOOK_ON_SET_MARIO_ACTION, mario_on_set_action)
hook_event(HOOK_BEFORE_SET_MARIO_ACTION, before_set_mario_action)

hook_mario_action(ACT_FAKE_FREEFALL, { every_frame = act_fake_freefall })
hook_mario_action(ACT_SPIN_JUMP, { every_frame = act_spin_jump, gravity = act_spin_jump_gravity })
hook_mario_action(ACT_GROUND_POUND_JUMP, { every_frame = act_ground_pound_jump })
hook_mario_action(ACT_WALL_SLIDE, { every_frame = act_wall_slide, gravity = act_wall_slide_gravity })
hook_mario_action(ACT_CUSTOM_AIR_HIT_WALL, { every_frame = act_air_hit_wall })
