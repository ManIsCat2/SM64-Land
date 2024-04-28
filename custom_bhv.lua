function get_star_count()
    local courseMax = 25
    local courseMin = 1
    return save_file_get_total_star_count(get_current_save_file_num() - 1, courseMin - 1, courseMax - 1)
end

local function obj_set_hitbox(obj, hitbox)
    if not obj or not hitbox then return end
    -- Sets other hitbox values once
    if (obj.oFlags & OBJ_FLAG_30) == 0 then
        obj.oFlags = obj.oFlags | OBJ_FLAG_30
        if hitbox.interactType ~= nil then
            obj.oInteractType = hitbox.interactType
        end
        obj.oDamageOrCoinValue = hitbox.damageOrCoinValue
        obj.oHealth = hitbox.health
        obj.oNumLootCoins = hitbox.numLootCoins

        cur_obj_become_tangible()
    end

    -- Set actual hitboxes
    obj.hitboxRadius = obj.header.gfx.scale.x * hitbox.radius
    obj.hitboxHeight = obj.header.gfx.scale.y * hitbox.height
    obj.hurtboxRadius = obj.header.gfx.scale.x * hitbox.hurtboxRadius
    obj.hurtboxHeight = obj.header.gfx.scale.y * hitbox.hurtboxHeight
    obj.hitboxDownOffset = obj.header.gfx.scale.y * hitbox.downOffset
end

function get_world_star_count(world)
    local course1
    local course2
    local course3
    local stars_world = 0
    if world == 1 then
        course1 = COURSE_BOB
        course2 = COURSE_WF
    end

    if world == 2 then
        course1 = COURSE_JRB
        course2 = COURSE_CCM
    end

    if world == 3 then
        course1 = COURSE_BBH
        course2 = COURSE_SSL
    end

    if world == 4 then
        course1 = COURSE_SL
        course2 = COURSE_WDW
        course3 = COURSE_TTC
    end

    if world == 5 then
        course1 = COURSE_DDD
        course2 = COURSE_SL
        course3 = COURSE_HMC
    end

    for i = course1, course2 do
        local starFlags = save_file_get_star_flags(get_current_save_file_num() - 1, i - 1)
        for star = 0, 6 do
            if starFlags & (1 << star) ~= 0 then
                stars_world = stars_world + 1
            end
        end
    end

    if course3 ~= nil then
        return stars_world + save_file_get_course_star_count(get_current_save_file_num() - 1, course3 - 1)
    else
        return stars_world
    end
end

local repack = function(value, pack_fmt, unpack_fmt)
    return string.unpack(unpack_fmt, string.pack(pack_fmt, value))
end

local FALSE = 0 -- false for custom object fields
local TRUE = 1  -- true for custom object fields

---@param m MarioState
---@return boolean
local function is_bubbled(m)
    return m.action == ACT_BUBBLED
end
local platformTimer = 0
local soundPlayed = false

E_MODEL_RED_WARP_PIPE = smlua_model_util_get_id("warp_pipe_red_geo")
E_MODEL_BLUE_WARP_PIPE = smlua_model_util_get_id("warp_pipe_blue_geo")
E_MODEL_BLOCKED_WARP_PIPE = smlua_model_util_get_id("warp_pipe_blocked_geo")
E_MODEL_PIPE_COVER = smlua_model_util_get_id("pipe_cover_geo")
COL_PIPE_COVER = smlua_collision_util_get("pipe_cover_collision")

-- Big SeeSaw

function big_seesaw_loop(o)
    if (o.oBehParams >> 0) & 0xFF == 1 then
        cur_obj_scale(1.5)
        o.oCollisionDistance = 15000
    end
end

hook_behavior(id_bhvSeesawPlatform, OBJ_LIST_SURFACE, false, nil, big_seesaw_loop)

-- Long Checkerboard Elevator

function long_checkerboard_loop(o)
    obj_scale_xyz(o, 2, 1, 1)
    o.oCollisionDistance = 2000
end

hook_behavior(id_bhvCheckerboardPlatformSub, OBJ_LIST_SURFACE, false, nil, long_checkerboard_loop)

-- Unpoundable Wooden Post

function unpoundable_wooden_post_loop(o)
    o.oWoodenPostSpeedY = 0
end

hook_behavior(id_bhvWoodenPost, OBJ_LIST_SURFACE, false, nil, unpoundable_wooden_post_loop)

-- Huge Metal Box

function huge_metal_box_loop(o)
    cur_obj_scale(1.75)
    o.oCollisionDistance = 2000
    o.oPosX = o.oHomeX
    o.oPosZ = o.oHomeZ
end

hook_behavior(id_bhvPushableMetalBox, OBJ_LIST_SURFACE, false, nil, huge_metal_box_loop)

-- Boss Star Cages

COL_CAGE = smlua_collision_util_get("eight_star_cage_collision")     -- Used by all cages
E_MODEL_8_STAR_CAGE = smlua_model_util_get_id("eight_star_cage_geo") -- World 1

-- Per World Boss Cage Table
worldCage = {
    { cageModelID = E_MODEL_8_STAR_CAGE, starsNeeded = 8 }
}

COL_WORLD_CANNON = smlua_collision_util_get("world_cannon_collision")
E_MODEL_WORLD_CANNON = smlua_model_util_get_id("world_cannon_geo")

---@param o Object
function star_cage_init(o)
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 3000
    o.collisionData = COL_CAGE
end

function star_cage_loop(o)
    load_object_collision_model()
    if get_world_star_count(o.oBehParams2ndByte) >= 8 and o.oBehParams2ndByte == curWorld then
        obj_mark_for_deletion(o)
    end
end

---@param o Object
function world_cannon_init(o)
    o.oInteractType = 0
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_WORLD_CANNON
    o.hitboxRadius = 200
    o.hitboxHeight = 200
end

stuck = false
stuckTimer = 0
stuckX = false
stuckY = false
stuckHud = false

function world_cannon_loop(o)
    load_object_collision_model()
    m = gMarioStates[0]

    if stuck then
        vec3f_set(m.pos, o.oPosX, o.oPosY + 400, o.oPosZ)
        m.freeze = 1
        if soundPlayed == false then
            play_sound(SOUND_GENERAL_CANNON_UP, m.marioObj.header.gfx.cameraToObject)
            soundPlayed = true
        end
    end

    if m.action == ACT_SHOT_FROM_CANNON and m.vel.y >= 0 then
        stuckTimer = stuckTimer + 1
    end

    if stuckTimer > 50 then
        warp_to_warpnode(warpsforlevels[worldSelected].level, warpsforlevels[worldSelected].area, 1,
            warpsforlevels[worldSelected].warpid)
        stuckTimer = 0
    end

    if m.controller.buttonPressed & A_BUTTON ~= 0 and world_unlocked(worldSelected) and m.pos.y == (o.oPosY + 400) then
        stuckHud = false
        stuck = false
        soundPlayed = false
        vec3f_set(m.pos, o.oPosX, o.oPosY + 800, o.oPosZ)
        m.action = ACT_SHOT_FROM_CANNON
        m.faceAngle.y = 23039.6484375
        m.vel.y = 60
        m.forwardVel = 90
    end
end

function world_cannon_warp()
    if gMarioStates[0].area.warpNodes.node.id == 11 and gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) then
        set_mario_action(gMarioStates[0], ACT_SHOT_FROM_CANNON, 0)
    end
    -- djui_chat_message_create(tostring(gMarioStates[0].area.warpNodes.node.id))
end

hook_event(HOOK_ON_WARP, world_cannon_warp)


function pipe_cover_init(o)
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_PIPE_COVER
end

function pipe_cover_loop(o)
    load_object_collision_model()
    if operation(COURSE_BOB, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_mark_for_deletion(o)
    end
    if operation(COURSE_WF, 0) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_mark_for_deletion(o)
    end
    if operation(COURSE_WF, 4) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 3 then
        obj_mark_for_deletion(o)
    end
    if operation(COURSE_BOB, 3) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 4 then
        obj_mark_for_deletion(o)
    end


    if operation(COURSE_CCM, 5) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 8 then
        obj_mark_for_deletion(o)
    end


    if operation(COURSE_SSL, 3) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 12 then
        obj_mark_for_deletion(o)
    end
end

bhvPipeCover = hook_behavior(nil, OBJ_LIST_SURFACE, true, pipe_cover_init, pipe_cover_loop)
bhv8StarCage = hook_behavior(nil, OBJ_LIST_SURFACE, true, star_cage_init, star_cage_loop)
bhvWorldCannon = hook_behavior(nil, OBJ_LIST_SURFACE, true, world_cannon_init, world_cannon_loop)

-- big mushrooms

-- "Fuck MOPS's Bouncers" -xLuigiGamerx

E_MODEL_STRAIGHT_MUSHROOM = smlua_model_util_get_id("custom_DL_19001000")
COL_STRAIGHT_MUSHROOM = smlua_collision_util_get("straight_mushroom_collision")

local squishTime = 0

define_custom_obj_fields({
    oInverted = "f32"
})

---@param o Object
function bhv_mushroom_straight_init(o)
    o.oInverted = false
    if o.oInverted == TRUE then
        squishTimer = MIN
    else
        squishTimer = MAX
    end
    top = true
    o.collisionData = COL_STRAIGHT_MUSHROOM
    o.oCollisionDistance = 2500
    o.header.gfx.skipInViewCheck = true
    network_init_object(o, true, { "oInverted" })
end

function sineInOut(b, e, c, t)
    return b + (0.5 * (1 - math.cos(math.pi * t)) * (e - b))
end

---@param o Object
function bhv_mushroom_straight_loop(o)
    if o.oBehParams2ndByte > (o.oBehParams >> 24) & 0xFF then
        MIN = math.abs(o.oBehParams2ndByte - (o.oBehParams >> 24))
        MAX = o.oBehParams2ndByte * 2 + MIN
        o.oInverted = true
    elseif o.oBehParams2ndByte < (o.oBehParams >> 24) & 0xFF then
        MIN = math.abs(o.oBehParams2ndByte - (o.oBehParams >> 24))
        MAX = (o.oBehParams >> 24) + o.oBehParams2ndByte
        o.oInverted = false
    else
        MIN = 20
        MAX = 135
        o.oInverted = false
    end

    if top then
        if o.oInverted == TRUE then
            squishTimer = sineInOut(MIN, MAX, 1, squishTime)
        else
            squishTimer = sineInOut(MAX, MIN, 1, squishTime)
        end
    else
        if o.oInverted == TRUE then
            squishTimer = sineInOut(MAX, MIN, 1, squishTime)
        else
            squishTimer = sineInOut(MIN, MAX, 1, squishTime)
        end
    end

    if squishTime < 1 then
        squishTime = squishTime + 1 / 900
    else
        top = not top
        squishTime = 0
    end

    load_object_collision_model()
    obj_scale_xyz(o, 1, squishTimer / 100, 1)
end

id_bhvStraightMushroom = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_mushroom_straight_init,
    bhv_mushroom_straight_loop, "id_bhvStraightMushroom")

-- another one :D

E_MODEL_CURVED_MUSHROOM = smlua_model_util_get_id("custom_DL_19001040")
COL_CURVED_MUSHROOM = smlua_collision_util_get("curved_mushroom_collision")

---@param obj Object
function bhv_mushroom_curved_init(obj)
    obj.collisionData = COL_CURVED_MUSHROOM
    obj.oCollisionDistance = 2500
    obj.header.gfx.skipInViewCheck = true
end

function bhv_mushroom_curved_loop(obj)
    load_object_collision_model()
end

id_bhvCurvedMushroom = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_mushroom_curved_init, bhv_mushroom_curved_loop,
    'id_bhvCurvedMushroom')

-- seesaw platform but badass

E_MODEL_GREEN_SEESAW = smlua_model_util_get_id("green_seesaw_geo")
COL_GREEN_SEESAW = smlua_collision_util_get("green_seesaw_collision")


define_custom_obj_fields({
    oEndPointX = "f32",
    oEndPointZ = "f32",
    oDoneEndPoint = "s32"
})

---@param obj Object
function seesaw_green_init(obj)
    obj.oDoneEndPoint = 0
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL
    obj.collisionData = COL_GREEN_SEESAW
    obj.oCollisionDistance = 2500
    obj.header.gfx.skipInViewCheck = true
    obj.oHomeX = obj.oPosX
    obj.oHomeY = obj.oPosY
    obj.oHomeZ = obj.oPosZ
    network_init_object(obj, true, { "oEndPointX", "oEndPointZ", "oDoneEndPoint" })

    -- more things
    o = obj
    if o.oHomeY == 1620 then
        o.oFaceAnglePitch = 2000
        obj.oFaceAngleYaw = obj.oFaceAngleYaw + 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw + 16384
        o.oEndPointX = 1494
    end

    if o.oHomeX == 3341 then
        o.oFaceAnglePitch = 0
        o.oEndPointZ = -12855
    end

    if o.oHomeX == 4401 then
        o.oFaceAnglePitch = 0
        o.oEndPointZ = -11426
    end

    if o.oHomeX == 6675 then
        o.oFaceAnglePitch = 0
        o.oEndPointZ = -9309
    end

    if o.oHomeX == 3497 then
        obj.oFaceAngleYaw = obj.oFaceAngleYaw + 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw + 16384
        o.oEndPointX = 5437
    end

    if o.oHomeX == 5874 then
        obj.oFaceAngleYaw = obj.oFaceAngleYaw - 16384
        obj.oMoveAngleYaw = obj.oMoveAngleYaw - 16384
        o.oEndPointX = -1546
        o.oFaceAnglePitch = -2000
    end
end

---@param o Object
function seesaw_green_loop(o)
    load_object_collision_model()
    ---@type MarioState
    local m = gMarioStates[0]
    --djui_chat_message_create(tostring(m.floor.object.oPosX))

    if m.controller.buttonDown & U_JPAD == 0 then
        o.oForwardVel = 0
    end

    if cur_obj_is_mario_on_platform() == 0 and m.controller.buttonDown & U_JPAD ~= 0 then
        o.oForwardVel = 0
    end

    if cur_obj_is_mario_on_platform() ~= 0 and o.oHomeY == 1620 and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
            o.oPosY = o.oPosY - 3.9
        else
            o.oForwardVel = 0
        end
    end

    if cur_obj_is_mario_on_platform() ~= 0 and (o.oHomeX == 3341 or o.oHomeX == 4401 or o.oHomeX == 6675 or o.oHomeX == 3497) and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
        else
            o.oForwardVel = 0
        end
    end

    if cur_obj_is_mario_on_platform() ~= 0 and o.oHomeX == 5874 and not is_bubbled(m) and o.oDoneEndPoint == 0 then
        if m.controller.buttonDown & U_JPAD ~= 0 then
            o.oForwardVel = 20
            o.oPosY = o.oPosY + 1.7
        else
            o.oForwardVel = 0
        end
    end

    if o.oPosX == o.oEndPointX then
        o.oForwardVel = 0
        o.oDoneEndPoint = 1
    end

    if o.oPosZ == o.oEndPointZ then
        o.oForwardVel = 0
        o.oDoneEndPoint = 1
    end

    if o.oDoneEndPoint == 1 then
        o.oSubAction = o.oSubAction + 1
    end

    -- return

    if o.oSubAction > 400 then
        o.oPosX = o.oHomeX
        o.oPosY = o.oHomeY
        o.oPosZ = o.oHomeZ
        o.oDoneEndPoint = 0
        o.oSubAction = 0
    end
end

id_bhvGreenSeesaw = hook_behavior(nil, OBJ_LIST_SURFACE, true, seesaw_green_init, seesaw_green_loop, "id_bhvGreenSeesaw")


id_bhvPeachCustom = hook_behavior(nil, OBJ_LIST_GENACTOR, true, function(o)
    o.oFlags = OBJ_FLAG_COMPUTE_ANGLE_TO_MARIO | OBJ_FLAG_HOLDABLE | OBJ_FLAG_COMPUTE_DIST_TO_MARIO |
        OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oAnimations = gObjectAnimations.peach_seg5_anims_0501C41C
    o.oInteractType = INTERACT_TEXT
    o.hitboxRadius = 90
    o.hitboxHeight = 150
    cur_obj_init_animation(5)
    bhv_toad_message_init()
end, function(o)
    o.oIntangibleTimer = 0
    --djui_chat_message_create(tostring(o.oOpacity))
    bhv_toad_message_loop()
end)

--dancing hill :D

E_MODEL_DANCING_HILL = smlua_model_util_get_id("dancing_hill_geo")

---@param o Object
function bhv_dancing_hill_init(o)
    o.header.gfx.skipInViewCheck = true
    obj_set_model_extended(o, E_MODEL_DANCING_HILL)
end

function bhv_dancing_hill_loop(o)
    o.oAnimState = o.oAnimState + 1
end

id_bhvDancingHill = hook_behavior(nil, OBJ_LIST_DEFAULT, true, bhv_dancing_hill_init, bhv_dancing_hill_loop)

local antsKilled = 0

function bhv_fake_pipe_init(o)
    o.header.gfx.skipInViewCheck = true
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = gGlobalObjectCollisionData.warp_pipe_seg3_collision_03009AC8
    antsKilled = 0
end

---@param o Object
function fake_pipe_loop(o)
    load_object_collision_model()
    if o.oBehParams2ndByte == 0 then
        o.oSubAction = o.oSubAction + 1
    end

    if o.oSubAction > 120 then
        spawn_sync_object(id_bhvAnt, E_MODEL_ANT, o.oPosX, o.oPosY, o.oPosZ, function(obj)
            obj.parentObj = o
        end)
        o.oSubAction = 0
    end

    if operation(COURSE_BOB, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation(COURSE_WF, 0) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation(COURSE_WF, 4) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 3 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
end

id_bhvFakeWarpPipe = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fake_pipe_init, fake_pipe_loop)


--- gombba :D
E_MODEL_GOOMBOSS = smlua_model_util_get_id("king_goomba_geo")

---@param o Object
function bhv_goomboss_init(o)
    o.oInteractType = INTERACT_DAMAGE
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    o.hitboxRadius = 320
    o.hitboxHeight = 300
    cur_obj_init_animation(0)
end

ACT_GOOMBA_BOSS_RUNNING_TO_WALL = 0
ACT_GOOMBA_BOSS_ON_GROUND = 1

---@param o Object
function bhv_goomboss_loop(o)
    o.oInteractStatus = 0
    local m = gMarioStates[0]
    object_step()
    if o.oAction == ACT_GOOMBA_BOSS_RUNNING_TO_WALL then
        o.oForwardVel = 30
        o.oSubAction = o.oSubAction + 1
    end

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND then
        o.header.gfx.angle.x = 16384
        o.oForwardVel = 0
    end

    if o.oSubAction > 50 then
        o.oAction = ACT_GOOMBA_BOSS_ON_GROUND
        o.oSubAction = 0
    end

    -- other

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND and m.action == ACT_GROUND_POUND and dist_between_objects(o, m.marioObj) < 100 then
        o.oAction = 3
    end
end

id_bhvGoomboss = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_goomboss_init, bhv_goomboss_loop)

--bouncer

COL_BOUNCY_PLATFROM = smlua_collision_util_get("bouncy_platform_collision")
E_MODEL_BOUNCY_PLATFORM = smlua_model_util_get_id("bouncy_platform_geo")

function bhv_bouncy_platform_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_BOUNCY_PLATFROM
    obj_set_model_extended(o, E_MODEL_BOUNCY_PLATFORM)
end

function bhv_bouncy_platform_loop(obj)
    load_object_collision_model()
    local m = gMarioStates[0]

    obj.oPosX = obj.oPosX
    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
        if m.action == ACT_GROUND_POUND_LAND then
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = 140
            bounceMultiplier = 3
        else
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = (140 / 3) * bounceMultiplier
            if bounceMultiplier < 3 then
                bounceMultiplier = bounceMultiplier + 1
            end
        end
        set_mario_particle_flags(gMarioStates[0], (PARTICLE_MIST_CIRCLE | PARTICLE_HORIZONTAL_STAR), 0)
    end
end

id_bhvBouncyPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_bouncy_platform_init, bhv_bouncy_platform_loop)

local sAntHitbox = {
    interactType = INTERACT_BOUNCE_TOP,
    downOffset = 0,
    damageOrCoinValue = 2,
    health = 1,
    numLootCoins = 1,
    radius = 100,
    height = 100,
    hurtboxHeight = 75,
    hurtboxRadius = 75,
    numLootScore = 200
}

local sAntNoCoinOrScoreHitbox = {
    interactType = INTERACT_BOUNCE_TOP,
    downOffset = 0,
    damageOrCoinValue = 2,
    health = 1,
    numLootCoins = 0,
    radius = 100,
    height = 100,
    hurtboxHeight = 75,
    hurtboxRadius = 75,
    numLootScore = 0
}

---@param o Object
function bhv_ant_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    o.oGravity = 3
    o.oFriction = 1
    o.oForwardVel = 3.545
    o.oTimer = antsKilled
    if o.oTimer < 3 then
        obj_set_hitbox(o, sAntHitbox)
    else
        obj_set_hitbox(o, sAntNoCoinOrScoreHitbox)
    end
    --djui_chat_message_create(tostring(o.oTimer))
    obj_scale(o, 2.5)
    cur_obj_init_animation(0)
    --djui_chat_message_create(tostring(antsKilled))
end

E_MODEL_ANT = smlua_model_util_get_id("ant_geo")

---@param o Object
function bhv_ant_loop(o)
    object_step()
    o.oMoveAngleYaw = o.parentObj.oFaceAngleYaw

    if o.oPosZ - o.parentObj.oPosZ >= 3280 then
        obj_mark_for_deletion(o)
    end

    if o.oInteractStatus & INT_STATUS_WAS_ATTACKED ~= 0 then
        o.oHealth = o.oHealth - 1
        antsKilled = antsKilled + 1
    else
        o.oInteractStatus = 0
    end

    obj_die_if_health_non_positive()

    if o.oPosY < -1000 then
        obj_mark_for_deletion(o)
    end
end

id_bhvAnt = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_ant_init, bhv_ant_loop, nil)

E_MODEL_SPONGE = smlua_model_util_get_id("sponge_geo")

function bhv_spong_init(o)
    o.collisionData = smlua_collision_util_get("sponge_collision")
    o.oCollisionDistance = 5000
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
end

function bhv_spong_loop(o)
    load_object_collision_model()
end

id_bhvSponge = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_spong_init, bhv_spong_loop)

-- jelly :D

COL_JELLY = smlua_collision_util_get("jelly_collision")
E_MODEL_JELLY = smlua_model_util_get_id("jelly_geo")

function bhv_jelly_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_JELLY
    obj_set_model_extended(o, E_MODEL_JELLY)
end

-- WIP Jelly bhv

function bhv_jelly_loop(obj)
    load_object_collision_model()
    local m = gMarioStates[0]

    obj.oPosX = obj.oPosX

    if cur_obj_is_mario_on_platform() == 1 and not is_bubbled(m) then
        if m.action == ACT_GROUND_POUND_LAND then
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = 140
            bounceMultiplier = 3
        else
            set_anim_to_frame(m, 0)
            set_mario_action(m, ACT_TRIPLE_JUMP, 0)
            m.vel.y = (140 / 3) * bounceMultiplier
            if bounceMultiplier < 3 then
                bounceMultiplier = bounceMultiplier + 1
            end
        end
    end
end

id_bhvJelly = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_jelly_init, bhv_bouncy_platform_loop)

-- spinning food
COL_SPIN_FOOD = smlua_collision_util_get("spin_food_collision")
E_MODEL_SPIN_FOOD = smlua_model_util_get_id("spin_food_geo")


function bhv_spinning_food_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_SPIN_FOOD
    o.oCollisionDistance = 5000
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(o, E_MODEL_SPIN_FOOD)
end

function bhv_spinning_food_loop(o)
    load_object_collision_model()
    o.oAngleVelYaw = 0x40
    o.oFaceAngleYaw = o.oFaceAngleYaw + 0x40
end

id_bhvSpinningFood = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_spinning_food_init, bhv_spinning_food_loop)


E_MODEL_FLOWER = smlua_model_util_get_id("dancing_flower_geo")

---@param o Object
function bhv_animstate_object_init(o)
    o.header.gfx.skipInViewCheck = true
    obj_scale(o, 2.5)
    obj_set_billboard(o)
end

function bhv_animstate_object_loop(o)
    o.oAnimState = o.oAnimState + 1
end

id_bhvFlower = hook_behavior(nil, OBJ_LIST_DEFAULT, true, bhv_animstate_object_init, bhv_animstate_object_loop)

E_MODEL_FLIP_BLOCK = smlua_model_util_get_id("smw_block_geo")
COL_FLIP_BLOCK = smlua_collision_util_get("smw_block_collision")

local sFlipBlockHitbox = {
    interactType = nil,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 0,
    height = 0,
    hurtboxHeight = 0,
    hurtboxRadius = 0
}

define_custom_obj_fields({
    oFlipping = "f32"
})

function bhv_flip_block_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_FLIP_BLOCK
    o.oCollisionDistance = 1000
    o.oFlipping = false
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_hitbox(o, sFlipBlockHitbox)
    obj_set_model_extended(o, E_MODEL_FLIP_BLOCK)
    network_init_object(o, true, { "oFlipping" })
end

function bhv_flip_block_loop(o)
    if o.oFlipping == FALSE then
        o.oTimer = 0
        o.oFaceAnglePitch = 0
        load_object_collision_model()
        obj_scale_xyz(o, 1, 1, 1)
    else
        if o.oTimer <= 180 then
            o.oFaceAnglePitch = o.oFaceAnglePitch + (210 - o.oTimer) * 16
        else
            o.oFlipping = false
        end
        obj_scale_xyz(o, 1, 1, 0.01)
    end

    ---@type MarioState
    local m = gMarioStates[0]
    if not is_bubbled(m) and (cur_obj_was_attacked_or_ground_pounded() ~= 0 or (m.vel.y <= 0 and m.ceil and m.ceil.object == o and m.pos.y + m.marioObj.hitboxHeight + 156 >= m.ceil.lowerY)) and o.oFlipping == FALSE then
        o.oFlipping = true
    end

    if cur_obj_is_mario_on_platform() ~= 0 then
        --djui_chat_message_create("1: " .. tostring((o.oBehParams >> 24) & 0xFF))
        --djui_chat_message_create("2: " .. tostring((o.oBehParams >> 16) & 0xFF))
        --djui_chat_message_create("3: " .. tostring((o.oBehParams >> 8) & 0xFF))
        --djui_chat_message_create("4: " .. tostring((o.oBehParams >> 0) & 0xFF))
    end
end

id_bhvFlipBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_flip_block_init, bhv_flip_block_loop)

--pushable n64 button
E_MODEL_PUSHABLE_N64_BUTTON = smlua_model_util_get_id("pushable_n64_button_geo")
COL_PUSHABLE_N64_BUTTON = smlua_collision_util_get("pushable_n64_button_collision")

---@param o Object
function bhv_pushable_n64_button_init(o)
    o.collisionData = COL_PUSHABLE_N64_BUTTON
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2000
end

id_bhvPushableN64Button = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_pushable_n64_button_init,
    function(o)
        load_object_collision_model()
        bhv_pushable_loop()
    end)