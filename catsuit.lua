--// Catsuit behavior and abilities. //--

catsuit = false
didDive = false
local animFrame = 0
slowDownTimer = 0

E_MODEL_SUPER_BELL = smlua_model_util_get_id("super_bell_geo")

ACT_CAT_DIVE = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_MOVING | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
ACT_CAT_CLIMB = allocate_mario_action(ACT_FLAG_AIR | ACT_GROUP_AIRBORNE)
ACT_CAT_SLIDE = allocate_mario_action(ACT_FLAG_AIR | ACT_GROUP_AIRBORNE)

local function limit_angle(a)
    return (a + 0x8000) % 0x10000 - 0x8000
end

---@param obj Object
function bhv_catsuit_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_SUPER_BELL)
    obj_scale(obj, 0.5)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768 -- watchr is so not awesome
    obj.hitboxRadius = 50
    obj.hitboxHeight = 50
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_catsuit_loop(obj)
    object_step()
    load_object_collision_model()
    local m = gMarioStates[0]
    if obj_check_hitbox_overlap(m.marioObj,obj) then
        obj_mark_for_deletion(obj)
        activePowerup = CAT
    end
end

id_bhvSuperBell = hook_behavior(id_bhvMetalCap, OBJ_LIST_GENACTOR, true, bhv_catsuit_init, bhv_catsuit_loop)

---@param m MarioState
function cat_update(m)
    if m.playerIndex ~= 0 then return end
    if activePowerup ~= CAT then return end
    if m.pos.y > (m.floorHeight + 150) and not didDive then
        if m.controller.buttonPressed & B_BUTTON ~= 0 and m.action & ACT_FLAG_AIR ~= 0 then
            set_mario_action(m, ACT_CAT_DIVE, 0)
            didDive = true
        end
    end
    if m.action & ACT_FLAG_AIR == 0 then
        if didDive then
            didDive = false
        elseif slowDownTimer > 0 then
            slowDownTimer = 0
        end
    end
end

function act_cat_climb(m)
    if (m.input & INPUT_A_PRESSED) ~= 0 then
        m.vel.y = 52.0
        m.faceAngle.y = limit_angle(m.faceAngle.y + 0x8000)
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0)
    end

    if animFrame < m.marioObj.header.gfx.animInfo.curAnim.loopEnd then
        animFrame = animFrame + 15
    else
        animFrame = 0
    end

    if slowDownTimer < 15 then
        slowDownTimer = slowDownTimer + 1/10
    end

    local wallangle = atan2s(m.wallNormal.z, m.wallNormal.x) + 0x8000

    if slowDownTimer > 5 then
        m.vel.y = 15 - slowDownTimer
    else
        m.vel.y = 15
    end

    m.particleFlags = m.particleFlags | PARTICLE_DUST
    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m.terrainSoundAddend, m.marioObj.header.gfx.cameraToObject)

    --Face directly towards wall to make sure we're latched on
    m.faceAngle.y = wallangle
    mario_set_forward_vel(m, 1)

    --Perform air step
    local air_step = perform_air_step(m, AIR_STEP_CHECK_LEDGE_GRAB)
    if air_step == AIR_STEP_LANDED then
        m.faceAngle.y = m.faceAngle.y
        slowDownTimer = 0
        return set_mario_action(m, ACT_FREEFALL_LAND, 0)
    elseif not m.wall then
        m.faceAngle.y = m.faceAngle.y
        slowDownTimer = 0
        mario_set_forward_vel(m, 10)
        m.vel.y = 35
        return set_mario_action(m, ACT_FREEFALL, 0)
    end

    if slowDownTimer >= 15 then
        slowDownTimer = 0
        m.faceAngle.y = m.faceAngle.y - 0x8000
        return set_mario_action(m, ACT_CAT_SLIDE, 0)
    end

    --m.faceAngle.y = wallangle - 0x4000
    --mario_set_forward_vel(m, m.controller.stickX / 10)

    --Climbing animation
    set_mario_animation(m, MARIO_ANIM_CRAWLING)
    set_anim_to_frame(m, animFrame)

    m.marioObj.header.gfx.angle.x = 0xC000
    m.marioObj.header.gfx.angle.y = m.faceAngle.y

    m.marioObj.header.gfx.animInfo.animYTrans = -256
end

function act_cat_dive(m)
    m.actionTimer = m.actionTimer + 1

    if m.prevAction ~= ACT_DIVE then
        if m.actionTimer == 2 then
            common_air_action_step(m, ACT_GROUND_POUND, MARIO_ANIM_GROUND_POUND,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 0
        elseif m.actionTimer >= 6 then
            play_mario_sound(m, CHAR_SOUND_HOOHOO, CHAR_SOUND_HOOHOO)
            common_air_action_step(m, ACT_DIVE, MARIO_ANIM_DIVE,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 40
        end
    else
        if m.actionTimer == 2 then
            common_air_action_step(m, ACT_GROUND_POUND, MARIO_ANIM_START_GROUND_POUND,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 0
        elseif m.actionTimer >= 6 then
            common_air_action_step(m, ACT_DIVE, MARIO_ANIM_DIVE,
            AIR_STEP_CHECK_HANG)
            m.forwardVel = 40
        end
    end

    if m.controller.buttonPressed == Z_TRIG then
        set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    if perform_air_step(m, 0) == AIR_STEP_LANDED then
        set_mario_action(m, ACT_FREEFALL_LAND, 0)
    end
end

function act_cat_dive_gravity(m)
    if m.pos.y - m.floorHeight < 150 then
        return set_mario_action(m, ACT_DIVE, 0)
    else
        m.vel.y = -10
    end
end

function act_cat_slide(m)
    if m.actionTimer == 0 then
        animFrame = 0
    end

    if (m.input & INPUT_A_PRESSED) ~= 0 then
        m.vel.y = 52.0
        return set_mario_action(m, ACT_WALL_KICK_AIR, 0)
    end

    -- attempt to stick to the wall a bit. if it's 0, sometimes you'll get kicked off of slightly sloped walls
    mario_set_forward_vel(m, -1)

    m.particleFlags = m.particleFlags | PARTICLE_DUST

    play_sound(SOUND_MOVING_TERRAIN_SLIDE + m.terrainSoundAddend, m.marioObj.header.gfx.cameraToObject)
    set_mario_animation(m, MARIO_ANIM_CRAWLING)
    set_anim_to_frame(m, 0)

    if perform_air_step(m, 0) == AIR_STEP_LANDED then
        mario_set_forward_vel(m, 0.0)
        if check_fall_damage_or_get_stuck(m, ACT_HARD_BACKWARD_GROUND_KB) == 0 then
            return set_mario_action(m, ACT_FREEFALL_LAND, 0)
        end
    end

    m.marioObj.header.gfx.angle.x = 0xC000
    m.marioObj.header.gfx.angle.y = m.faceAngle.y + 0x8000

    m.actionTimer = m.actionTimer + 1
    if not m.wall and m.actionTimer > 2 then
        mario_set_forward_vel(m, 0.0)
        return set_mario_action(m, ACT_FREEFALL, 0)
    end
end

function act_cat_slide_gravity(m)
    m.vel.y = m.vel.y - 2

    if m.vel.y < -15 then
        m.vel.y = -15
    end
end

hook_event(HOOK_MARIO_UPDATE, cat_update)
hook_mario_action(ACT_CAT_CLIMB, { every_frame = act_cat_climb })
hook_mario_action(ACT_CAT_DIVE, { every_frame = act_cat_dive, gravity = act_cat_dive_gravity }, INT_FAST_ATTACK_OR_SHELL)
hook_mario_action(ACT_CAT_SLIDE, { every_frame = act_cat_slide, gravity = act_cat_slide_gravity })
