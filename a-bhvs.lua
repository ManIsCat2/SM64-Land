E_MODEL_NEW_THWOMP = smlua_model_util_get_id("new_thwomp_geo")
E_MODEL_ROTATING_PLATFORM_JRB = smlua_model_util_get_id("rotating_platform_jrb_geo")

local math_sin = math.sin

---from SM64 Last Impact
---@param obj Object
---@param animTable table
---@param animIndex integer
function obj_init_animation_from_custom_table(obj, animTable, animIndex, vanillaAnim, speed)
    ---@type string|Animation
    local setAnim = animTable[animIndex]
    if animTable then
        obj.header.gfx.animInfo.animAccel = speed and speed * 65536 or 65536
        if not vanillaAnim then
            smlua_anim_util_set_animation(obj, setAnim)
        else
            obj.header.gfx.animInfo.curAnim = setAnim
        end
    end
end

---function from SM64: Through the ages
---@param clampFloor boolean
---@param o Object
local function move_obj_with_physics(clampFloor, o)
    local bounciness = o.oBounciness
    o.oVelY = o.oVelY + o.oGravity
    if o.oVelY < -70.0 then
        o.oVelY = -70.0
    end
    o.oPosY = o.oPosY + o.oVelY
    o.oMoveFlags = o.oMoveFlags & ~OBJ_MOVE_ON_GROUND

    if o.oPosY < find_floor_height(o.oPosX, o.oPosY + 70.0, o.oPosZ) and clampFloor then
        o.oPosY = find_floor_height(o.oPosX, o.oPosY + 70.0, o.oPosZ)
        o.oVelY = o.oVelY * bounciness / 100.0
        o.oMoveFlags = o.oMoveFlags | (OBJ_MOVE_ON_GROUND)
    end

    o.oPosX = o.oPosX + o.oForwardVel * sins(o.oMoveAngleYaw)
    o.oPosZ = o.oPosZ + o.oForwardVel * coss(o.oMoveAngleYaw)

    -- wall collision
    cur_obj_resolve_wall_collisions()
end

function get_star_count()
    local courseMax = 25
    local courseMin = 1
    return save_file_get_total_star_count(get_current_save_file_num() - 1, courseMin - 1, courseMax - 1)
end

function for_each_object_with_behavior(behavior, func) --* function by Isaac
    local o = obj_get_first_with_behavior_id(behavior)
    while o do
        func(o)
        o = obj_get_next_with_same_behavior_id(o)
    end
end

---@param parent Object
---@param model ModelExtendedId
---@param behaviorId BehaviorId
function spawn_object2(parent, model, behaviorId)
    local obj = spawn_sync_object(behaviorId, model, 0, 0, 0, nil)
    if not obj then return nil end

    obj_copy_pos_and_angle(obj, parent)
    return obj
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

local function obj_rotate_pitch_toward(o, target, increment)
    local startPitch = o.oMoveAnglePitch
    o.oMoveAnglePitch = approach_s16_symmetric(o.oMoveAnglePitch, target, increment)
    o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, target, increment)

    o.oAngleVelPitch = o.oMoveAnglePitch - startPitch

    return o.oAngleVelPitch == 0
end

local function obj_pitch_angle_to_object(obj1, obj2)
    if obj1 == nil or obj2 == nil then
        return 0
    end

    local z1, x1, y1, z2, x2, y2, h, v
    local angle

    z1 = obj1.oPosZ
    z2 = obj2.oPosZ
    x1 = obj1.oPosX
    x2 = obj2.oPosX
    y1 = obj1.oPosY
    y2 = obj2.oPosY

    h = math.sqrt((z2 - z1) ^ 2 + (x2 - x1) ^ 2)
    v = y2 - y1

    angle = -atan2s(h, v)
    return angle
end

function get_world_star_count(world)
    local course1
    local course2
    local course3
    local course4
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
        course3 = COURSE_HMC
    end

    if world == 4 then
        course1 = COURSE_SL
        course2 = COURSE_WDW
        course3 = COURSE_TTC
        course4 = COURSE_PSS
    end

    if world == 5 then
        course1 = COURSE_DDD
        course2 = COURSE_SL
        course3 = COURSE_HMC
    end

    if world == 6 then
        course1 = COURSE_TTM
        course2 = COURSE_THI
        course3 = COURSE_SSL
    end

    if world == 7 then
        course1 = COURSE_THI
        course2 = COURSE_RR
        course3 = COURSE_BITS
    end

    if world == 8 then
        course1 = COURSE_WMOTR
        course2 = COURSE_SA
        course3 = COURSE_BITFS
    end

    for i = course1, course2 do
        local starFlags = save_file_get_star_flags(get_current_save_file_num() - 1, i - 1)
        for star = 0, 6 do
            if starFlags & (1 << star) ~= 0 then
                stars_world = stars_world + 1
            end
        end
    end

    local totalcourseHub = save_file_get_course_star_count(get_current_save_file_num() - 1, COURSE_NONE - 1)

    if course3 ~= nil then
        return stars_world + save_file_get_course_star_count(get_current_save_file_num() - 1, course3 - 1) +
            totalcourseHub +
            (course4 and (save_file_get_course_star_count(get_current_save_file_num() - 1, course4 - 1)) or 0)
    else
        return stars_world + totalcourseHub
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

smlua_anim_util_register_animation("anim_dance_hill",
    0,
    0,
    0,
    1,
    80,
    { 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0xFFAE, 0xFED2, 0xFD8D, 0xFC03, 0xFA55, 0xF8A7, 0xF71C, 0xF5D7, 0xF4FB,
        0xF4AA, 0xF4C1, 0xF501, 0xF565, 0xF5E4, 0xF67A, 0xF720, 0xF7CF, 0xF881,
        0xF930, 0xF9D5, 0xFA6B, 0xFAF6, 0xFB7B, 0xFBFE, 0xFC84, 0xFD12, 0xFDAE,
        0xFE5B, 0xFF1F, 0x0000, 0x00FF, 0x0218, 0x0346, 0x0484, 0x05CC, 0x0717,
        0x0860, 0x09A1, 0x0AD4, 0x0BF4, 0x0CFC, 0x0DE9, 0x0EBD, 0x0F76, 0x1013,
        0x1096, 0x10FC, 0x1146, 0x1173, 0x1182, 0x1105, 0x0FB2, 0x0DBD, 0x0B5A,
        0x08C1, 0x0627, 0x03C5, 0x01D0, 0x007D, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
        0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0x0000,
        0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000,
        0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
        0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
        0xFFFF, 0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000,
        0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
        0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF,
        0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
        0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000,
        0x0000, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF,
        0x0000, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
        0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0x0000, 0x0000,
        0xFFFF, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0x0000, 0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0xFFFF, 0x0000, 0x0000, 0xFFFF,
        0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0xFFFF, 0x0000, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF, 0xFFFF,
        0xFFFF, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF,
        0x0000, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF, 0xFFFF, 0x0000, },
    { 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001,
        0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0046, 0x0008,
        0x0050, 0x004E, 0x0045, 0x009E, 0x004F, 0x00E3, })

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

function huge_metal_box_init(o)
    o.collisionData = gGlobalObjectCollisionData.metal_box_seg8_collision_08024C28
end

function huge_metal_box_loop(o)
    load_object_collision_model()
    cur_obj_scale(1.75)
    o.oCollisionDistance = 2000
end

hook_behavior(id_bhvPushableMetalBox, OBJ_LIST_SURFACE, true, huge_metal_box_init, huge_metal_box_loop)

-- New Thwomp

function new_thwomp_init(o)
    if o.oBehParams == 2 then
        o.collisionData = smlua_collision_util_get("new_thwomp_collision")
    end
end

hook_behavior(id_bhvThwomp, OBJ_LIST_SURFACE, false, new_thwomp_init, nil)

-- Tall Doors

function tall_doors_init(o)
    if o.oBehParams2ndByte == 1 then
        obj_scale_xyz(o, 1, 1.2, 1)
        o.oCollisionDistance = 2000
    end
end

hook_behavior(id_bhvDoorWarp, OBJ_LIST_SURFACE, false, tall_doors_init, nil)

-- Multidirectional Bullet Bills

function multidirectional_bullet_bill_loop(o)
    local player = nearest_player_to_object(o)
    local distanceToPlayer = player and dist_between_objects(o, player) or 10000
    local angleToPlayer = player and obj_pitch_angle_to_object(o, player) or 0
    if o.oTimer > 50 and o.oAction == 2 then
        if distanceToPlayer > 300.0 then
            obj_rotate_pitch_toward(o, angleToPlayer, 0x100)
        end
        o.oVelY = -o.oForwardVel
        o.oPosY = o.oPosY + o.oVelY * sins(o.oFaceAnglePitch)
        if o.oPosY == o.oFloorHeight then
            o.oAction = 3
            spawn_mist_particles()
        end
    end
end

hook_behavior(id_bhvBulletBill, OBJ_LIST_GENACTOR, false, nil, multidirectional_bullet_bill_loop)

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
    obj_set_model_extended(o, E_MODEL_WORLD_CANNON)
    load_object_collision_model()
    local m = gMarioStates[0]

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
    if operation2(COURSE_BOB, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_mark_for_deletion(o)
    end
    if operation2(COURSE_WF, 0) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_mark_for_deletion(o)
    end
    if operation2(COURSE_WF, 4) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 3 then
        obj_mark_for_deletion(o)
    end
    if operation2(COURSE_BOB, 3) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 4 then
        obj_mark_for_deletion(o)
    end

    if operation2(COURSE_CCM, 5) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 8 then
        obj_mark_for_deletion(o)
    end

    if operation2(COURSE_SSL, 3) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 12 then
        obj_mark_for_deletion(o)
    end

    if operation2(COURSE_PSS, 2) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 20 then
        obj_mark_for_deletion(o)
    end

    if operation2(COURSE_BITDW, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 24 then
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

function cubicOut(b, e, c, t)
    return b + (1 - (1 - t) ^ 3) * (e - b)
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
    local o = obj
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

-- Dialogue Peach

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

-- Rolling Chomps

function bhv_rolling_chomp_init(o)

end

function bhv_rolling_chomp_loop(o)

end

--dancing hill :D

E_MODEL_DANCING_HILL = smlua_model_util_get_id("dancing_hill_geo")

---@param o Object
function bhv_dancing_hill_init(o)
    o.header.gfx.skipInViewCheck = true
    obj_set_model_extended(o, E_MODEL_DANCING_HILL)
    smlua_anim_util_set_animation(o, "anim_dance_hill")
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

    if o.oBehParams2ndByte == 0 then
        network_init_object(o, true, nil)
    end
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

    if operation2(COURSE_BOB, 1) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 1 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation2(COURSE_WF, 0) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 2 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
    if operation2(COURSE_WF, 4) ~= TEX_UNCOLLECTED_STAR and o.oBehParams2ndByte == 3 then
        obj_set_model_extended(o, E_MODEL_BITS_WARP_PIPE)
    end
end

id_bhvFakeWarpPipe = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fake_pipe_init, fake_pipe_loop)


--- gombba :D
E_MODEL_KING_GOOMBA = smlua_model_util_get_id("king_goomba_geo")

local sKingGoombaHitbox = {
    interactType = INTERACT_DAMAGE,
    downOffset = 0,
    damageOrCoinValue = 3,
    health = 3,
    numLootCoins = 0,
    radius = 300,
    height = 300,
    hurtboxHeight = 150,
    hurtboxRadius = 150,
    numLootScore = 0
}

ACT_GOOMBA_BOSS_RUNNING = 0
ACT_GOOMBA_BOSS_HIT_WALL = 1
ACT_GOOMBA_BOSS_ON_GROUND = 2
ACT_GOOMBA_BOSS_DIALOGUE = 3
ACT_GOOMBA_BOSS_CHARGING = 4

---@param o Object
function bhv_king_goomba_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL
    o.oFriction = 1
    o.oMoveAngleYaw = -32768
    o.oFaceAngleYaw = -32768
    o.oPosZ = o.oPosZ + 500
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    o.oAction = ACT_GOOMBA_BOSS_DIALOGUE
    set_background_music(0, SEQ_EVENT_BOSS, 0)
    obj_set_hitbox(o, sKingGoombaHitbox)
    o.oHealth = 3
    cur_obj_scale(5)
    cur_obj_init_animation(0)
    network_init_object(o, true, { "oAction", "oHealth", "oSubAction", "oPosX", "oPosY", "oPosZ", "oAnimState" })
end

---@param o Object
function bhv_king_goomba_loop(o)
    o.oInteractStatus = 0
    --djui_chat_message_create(tostring(o.oFaceAnglePitch))
    ---@type MarioState
    local m = nearest_mario_state_to_object(o)

    if o.oAction == ACT_GOOMBA_BOSS_DIALOGUE and should_start_or_continue_dialog(m, o) ~= 0 and cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_008) ~= 0 then
        o.oAction = ACT_GOOMBA_BOSS_CHARGING
    end

    if o.oHealth <= 0 then
        spawn_mist_particles_variable(0, 0, 100.0);
        spawn_triangle_break_particles(20, 138, 3.0, 4);
        spawn_default_star(m.pos.x, m.pos.y + 200, m.pos.z)
        obj_mark_for_deletion(o)
    end
    --object_step()
    --- action code

    --- charge up
    if o.oAction == ACT_GOOMBA_BOSS_CHARGING then
        cur_obj_init_animation_with_accel_and_sound(0, 3)
        cur_obj_play_sound_at_anim_range(2, 17, SOUND_OBJ_GOOMBA_WALK)
        spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, nil);
        o.oSubAction = o.oSubAction + 1
    end

    if o.oAction == ACT_GOOMBA_BOSS_CHARGING and o.oSubAction > 70 then
        o.oAction    = ACT_GOOMBA_BOSS_RUNNING
        o.oSubAction = 0
    end

    -- run


    if o.oAction == ACT_GOOMBA_BOSS_RUNNING then
        o.oForwardVel = 70
    end

    if obj_find_wall(o.oPosX + o.oVelX, o.oPosY, o.oPosZ + o.oVelZ, o.oVelX, o.oVelZ) == 0 then
        o.oAction = ACT_GOOMBA_BOSS_ON_GROUND
        o.oPosX = o.oPosX - (200 * sins(o.oFaceAngleYaw))
        o.oPosZ = o.oPosZ - (200 * coss(o.oFaceAngleYaw))
    end

    -- on ground
    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND and o.oAnimState ~= 1 then
        o.oFaceAnglePitch = approach_s32(o.oFaceAnglePitch, -16384, 0, 1000)
        o.oInteractType = 0
        o.oForwardVel = 0
    else
        o.oInteractType = INTERACT_DAMAGE
    end

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND and o.oSubAction > 70 then
        o.oSubAction = 0
        o.oFaceAngleYaw = obj_angle_to_object(o, m.marioObj)
        o.oMoveAngleYaw = obj_angle_to_object(o, m.marioObj)
        o.oAnimState = 0
        o.oAction = ACT_GOOMBA_BOSS_CHARGING
    end

    if o.oAnimState == 1 then
        o.oSubAction = o.oSubAction + 1
        o.oFaceAnglePitch = approach_s32(o.oFaceAnglePitch, 0, 1000, 0)
    end

    if o.oAction == ACT_GOOMBA_BOSS_ON_GROUND and m.action == ACT_GROUND_POUND_LAND and obj_check_hitbox_overlap(m.marioObj, o) and o.oAnimState ~= 1 then
        m.action = ACT_TRIPLE_JUMP
        m.vel.y = 78
        m.invincTimer = 60
        play_sound(SOUND_OBJ_KING_WHOMP_DEATH, gGlobalSoundSource)
        o.oHealth = o.oHealth - 1
        spawn_sync_object(id_bhvGoomba, E_MODEL_GOOMBA, o.oPosX, o.oPosY, o.oPosZ,
            function(obj) obj.oBehParams2ndByte = 1 end)
        o.oAnimState = 1
    end
end

id_bhvKingGoomba = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_king_goomba_init, bhv_king_goomba_loop)

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
    network_init_object(o, true, nil)
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

E_MODEL_FLIP_BLOCK = smlua_model_util_get_id("flip_block_geo")
COL_FLIP_BLOCK = smlua_collision_util_get("flip_block_collision")

ACT_FLIP_BLOCK_IDLE = 0
ACT_FLIP_BLOCK_FLIPPING = 1

define_custom_obj_fields({
    oBlockExtX = "f32",
    oBlockExtZ = "f32",
    oBlockExtDiagonal = "f32",
    oBlockExtDelay = "f32"
})

function bhv_flip_block_init(o)
    o.header.gfx.skipInViewCheck = true
    o.collisionData = COL_FLIP_BLOCK
    o.oInteractType = INTERACT_BREAKABLE
    o.oCollisionDistance = 1000
    o.oAction = ACT_FLIP_BLOCK_IDLE
    o.hitboxHeight = 260
    o.hitboxDownOffset = 130
    o.hitboxRadius = 230
    o.oIntangibleTimer = 0
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oBlockExtX = ((o.oBehParams >> 16) & 0xFF)
    o.oBlockExtZ = ((o.oBehParams >> 24) & 0xFF)
    o.oBlockExtDiagonal = (o.oBlockExtX + o.oBlockExtZ) ^ 2 * (o.oBlockExtX * o.oBlockExtZ)
    o.oBlockExtDelay = ((o.oBehParams >> 0) & 0xFF)
    obj_set_model_extended(o, E_MODEL_FLIP_BLOCK)
    network_init_object(o, true, { "oBlockExtX", "oBlockExtZ", "oBlockExtDiagonal", "oBlockExtDelay" })
end

function bhv_flip_block_loop(o)
    --if ((o.oBehParams >> 24) & 0xFF) == 0 and ((o.oBehParams >> 16) & 0xFF) == 0 and ((o.oBehParams >> 0) & 0xFF) == 0 then
    if o.oAction == ACT_FLIP_BLOCK_IDLE then
        o.oTimer = 0
        load_object_collision_model()

        local nearM = nearest_mario_state_to_object(o)

        if (cur_obj_was_attacked_or_ground_pounded() ~= 0) or nearM.ceil ~= nil and nearM.ceil.object == o and obj_check_hitbox_overlap(o, nearM.marioObj) then
            o.oAction = ACT_FLIP_BLOCK_FLIPPING
        end
    elseif o.oAction == ACT_FLIP_BLOCK_FLIPPING then
        o.oFaceAnglePitch = cubicOut(0, 344064, 1, o.oTimer / 150)
        o.oInteractStatus = 0
        if o.oTimer > 150 then
            o.oAction = ACT_FLIP_BLOCK_IDLE
        end
        --obj_scale_xyz(o, 1, 1, 0.02)
    end
end

id_bhvFlipBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_flip_block_init, bhv_flip_block_loop)

--hook_event(HOOK_MARIO_UPDATE, function (m) if m.controller.buttonPressed & X_BUTTON ~= 0 then; spawn_sync_object(id_bhvExtensionBlock, E_MODEL_FLIP_BLOCK, m.pos.x, m.pos.y + 100, m.pos.z, nil) end end)

function bhv_extension_block_init(o)
    o.collisionData = COL_FLIP_BLOCK
    obj_set_model_extended(o, E_MODEL_FLIP_BLOCK)
end

function bhv_extension_block_loop(o)
    load_object_collision_model()
    djui_chat_message_create("i exist")
    djui_chat_message_create(string.format("x %s y %s z %s", o.oPosX, o.oPosY, o.oPosZ))
end

id_bhvExtensionBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_extension_block_init, bhv_extension_block_loop)

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

COL_JRB_PLATFORM = smlua_collision_util_get("rotating_platform_jrb_collision")
---@param o Object
function bhv_custom_rotating_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = COL_JRB_PLATFORM
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 6000
    o.oAngleVelYaw = 100
    network_init_object(o, true, nil)
end

function bhv_custom_rotating_platform_loop(o)
    load_object_collision_model()
    o.oFaceAngleYaw = o.oFaceAngleYaw + 100
end

id_bhvRotPlatformJRB = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_custom_rotating_platform,
    bhv_custom_rotating_platform_loop)

-- Unclimbable Trees

E_MODEL_UNCLIMBABLE_TREE = smlua_model_util_get_id("normal_tree_geo")

local sUnclimbableTreeHitbox = {
    interactType = nil,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 125,
    height = 700,
    hurtboxHeight = 0,
    hurtboxRadius = 0
}

function bhv_unclimbable_tree_init(o)
    obj_set_model_extended(o, E_MODEL_UNCLIMBABLE_TREE)
    obj_set_hitbox(o, sUnclimbableTreeHitbox)
end

function bhv_unclimbable_tree_loop(o)
    cur_obj_push_mario_away_from_cylinder(o.hitboxRadius, o.hitboxHeight)
end

id_bhvUnclimbableTree = hook_behavior(nil, OBJ_LIST_DEFAULT, true, bhv_unclimbable_tree_init, bhv_unclimbable_tree_loop)

-- Kickable Rocks

E_MODEL_KICKABLE_ROCK = smlua_model_util_get_id("kickable_rock_geo")

local sKickableRockHitbox = {
    interactType = nil,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 1,
    radius = 60,
    height = 60,
    hurtboxHeight = 0,
    hurtboxRadius = 0,
    numLootScore = 100
}

function bhv_kickable_rock_init(o)
    obj_set_model_extended(o, E_MODEL_KICKABLE_ROCK)
    o.header.gfx.pos.y = o.oPosY + 50
    obj_set_hitbox(o, sKickableRockHitbox)
    network_init_object(o, true, nil)
end

function bhv_kickable_rock_loop(o)
    if obj_check_hitbox_overlap(gMarioStates[0].marioObj, o) then
        -- need code moment
    end
    if o.oVelX ~= 0 or o.oVelZ ~= 0 then
        local moveAngle = atan2s(o.oVelZ * 100, o.oVelX * 100)
        local forwardRot = math.sqrt(o.oVelX ^ 2 + o.oVelZ ^ 2)
        o.oFaceAngleYaw = moveAngle
        o.oFaceAnglePitch = o.oFaceAnglePitch + forwardRot * 100
    end
end

id_bhvKickableRock = hook_behavior(nil, OBJ_LIST_DEFAULT, true, bhv_kickable_rock_init, bhv_kickable_rock_loop)

-- Checkpoint Flag (I'm so peak)

E_MODEL_CHECKPOINT = smlua_model_util_get_id("checkpoint_geo")

local sCheckpointHitbox = {
    interactType = INTERACT_POLE,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 0,
    numLootCoins = 0,
    radius = 30,
    height = 150,
    hurtboxHeight = 0,
    hurtboxRadius = 0
}

define_custom_obj_fields({
    oCollected = "f32"
})

function bhv_checkpoint_init(o)
    obj_set_model_extended(o, E_MODEL_CHECKPOINT)
    o.oAnimations = gObjectAnimations.castle_grounds_seg7_anims_flags
    o.oAnimState = 1
    cur_obj_init_animation(0)
    o.oCollected = FALSE
    o.header.gfx.pos.y = o.oPosY - 180
    network_init_object(o, true, { "oCollected" })
    obj_set_hitbox(o, sCheckpointHitbox)
end

function bhv_checkpoint_loop(o)
    local m = gMarioStates[0]
    if obj_check_hitbox_overlap(m.marioObj, o) then
        o.oCollected = TRUE
    end
    o.oAnimState = o.oCollected
end

id_bhvCheckpoint = hook_behavior(nil, OBJ_LIST_POLELIKE, true, bhv_checkpoint_init, bhv_checkpoint_loop)

-- Angry Sun

local sAngrySunHitbox = {
    interactType = INTERACT_FLAME,
    downOffset = 0,
    damageOrCoinValue = 3,
    health = 3,
    numLootCoins = 0,
    radius = 180,
    height = 180 * 3,
    hurtboxHeight = 180,
    hurtboxRadius = 180,
    numLootScore = 0
}

E_MODEL_ANGRYSUN = smlua_model_util_get_id("angry_sun_geo")

ACT_ANGRYSUN_CHARGING = 0
ACT_ANGRYSUN_MOVING = 1
ACT_ANGRYSUN_IDLE = 2
ACT_ANGRYSUN_HURT = 3
ACT_ANGRYSUN_DIE = 4

---@param o Object
function bhv_angry_sun_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL|OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW
    o.oFriction = 1
    o.header.gfx.skipInViewCheck = true
    obj_set_billboard(o)
    obj_scale(o, 0.8)
    o.oHealth = 3
    obj_set_hitbox(o, sAngrySunHitbox)
    network_init_object(o, true, { "oAction", "oSubAction", "oInteractStatus", "oPosZ", "oPosY", "oPosX", "oHealth" })
end

---@param o Object
function bhv_angry_sun_loop(o)
    local m = nearest_mario_state_to_object(o)
    if o.oAction == ACT_ANGRYSUN_CHARGING then
        o.oForwardVel = 0
        o.oPosY = o.oPosY + (math.sin(o.oTimer * 0.07) * 8)
        o.oPosX = o.oPosX + (math.sin(o.oTimer * 0.07) * 8)
        o.oSubAction = o.oSubAction + 1
        if o.oSubAction >= 60 then
            o.oAction = ACT_ANGRYSUN_MOVING
        end
    end

    if o.oInteractStatus ~= 0 then
        o.oAction = ACT_ANGRYSUN_CHARGING
        o.oInteractStatus = 0
    end

    if o.oAction == ACT_ANGRYSUN_MOVING then
        o.oMoveAngleYaw = approach_s16_symmetric(o.oMoveAngleYaw, obj_angle_to_object(o, m.marioObj), 0x230)
        o.oForwardVel = approach_f32(o.oForwardVel, 25, 5, 0)
        o.oPosY = approach_s32(o.oPosY, m.pos.y, 10, 10)

        o.oSubAction = o.oSubAction + 1
        if o.oSubAction >= 120 then
            local flameeee = spawn_object2(o, E_MODEL_RED_FLAME, id_bhvFlameBouncing)
            obj_scale(flameeee, 3.5)
            flameeee.hitboxRadius = 90
            flameeee.hitboxHeight = 90
            o.oAction = ACT_ANGRYSUN_CHARGING
        end
    end

    if o.oAction == ACT_ANGRYSUN_HURT then
        spawn_mist_particles_with_sound(5)
        o.oForwardVel = 0
        -- cur_obj_play_sound_1(SOUND_OBJ_ENEMY_DEATH_HIGH)

        o.oSubAction = o.oSubAction + 1
        if o.oSubAction >= 75 then
            o.oAction = ACT_ANGRYSUN_MOVING
        end
    end

    local nearWaterbuc = obj_get_nearest_object_with_behavior_id(o, id_bhvBetaHoldableObject)

    if nearWaterbuc then
        if obj_check_hitbox_overlap(o, nearWaterbuc) and o.oAction ~= ACT_ANGRYSUN_HURT and nearWaterbuc.oCoinUnk110 == 92 then
            o.oAction = ACT_ANGRYSUN_HURT
            o.oHealth = o.oHealth - 1
            nearWaterbuc.oCoinUnk110 = 0
        end
    end

    if o.oAction == ACT_ANGRYSUN_DIE then
        spawn_triangle_break_particles(20, 138, 3.0, 4);
        obj_mark_for_deletion(o)
        spawn_default_star(m.pos.x, m.pos.y + 230, m.pos.z)
        play_sound(SOUND_OBJ_KING_WHOMP_DEATH, gGlobalSoundSource)
    end

    if o.oHealth <= 0 and o.oAction ~= ACT_ANGRYSUN_DIE then
        o.oAction = ACT_ANGRYSUN_DIE
    end
end

id_bhvAngrySun = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_angry_sun_init, bhv_angry_sun_loop)

-- Water Bucket

local sWaterBucketHitbox = {
    interactType = INTERACT_GRABBABLE,
    downOffset = 0,
    damageOrCoinValue = 0,
    health = 1,
    numLootCoins = 0,
    radius = 60,
    height = 60,
    hurtboxHeight = 60,
    hurtboxRadius = 60,
    numLootScore = 0
}

E_MODEL_WATER_BUCKET_FULL = smlua_model_util_get_id("bucket_water_geo")
E_MODEL_WATER_BUCKET_EMPTY = smlua_model_util_get_id("bucket_no_water_geo")

function update_for_eachs()
    for_each_object_with_behavior(id_bhvBetaHoldableObject,
        ---@param o Object
        function(o)
            if o.header.gfx.pos.y < 1555 then
                o.oCoinUnk110 = 92
            end

            if o.oCoinUnk110 == 92 then
                obj_set_model_extended(o, E_MODEL_WATER_BUCKET_FULL)
            else
                obj_set_model_extended(o, E_MODEL_WATER_BUCKET_EMPTY)
            end
        end
    )

    for_each_object_with_behavior(id_bhvHiddenStarTrigger,
        ---@param o Object
        function(o)
            o.oFaceAngleYaw = o.oFaceAngleYaw + 0x700
        end
    )
end

hook_event(HOOK_UPDATE, update_for_eachs)

---@param o Object
function bhv_ttm_blue_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.header.gfx.skipInViewCheck = true
    o.collisionData = smlua_collision_util_get("ttm_blue_platform_collision")

    o.oCollisionDistance = 1000
end

---@param o Object
function bhv_ttm_blue_platform_loop(o)
    load_object_collision_model()
end

bhvTTMBluePlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ttm_blue_platform, bhv_ttm_blue_platform_loop)

---@param o Object
function bhv_swinging_thing_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2000
    o.collisionData = smlua_collision_util_get("ttm_swingy_thing_collision")
end

---@param o Object
function bhv_swinging_thing(o)
    load_object_collision_model()
    o.oFaceAngleRoll = math_sin(o.oTimer * 0.02) * 4300
end

bhvTTMSSwingingThing = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_swinging_thing_init,
    bhv_swinging_thing)


---@param o Object
function bhv_rr_purple_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.header.gfx.skipInViewCheck = true
    o.collisionData = smlua_collision_util_get("rr_purple_block_collision")

    o.oCollisionDistance = 1000
end

---@param o Object
function bhv_rr_purple_platform_loop(o)
    load_object_collision_model()
end

bhvRRPurpleBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_rr_purple_platform, bhv_rr_purple_platform_loop)

---@param o Object
function bhv_rr_rotating_plus_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("rr_rotating_plus_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 3200
    o.oAngleVelYaw = 100
    network_init_object(o, true, nil)
end

function bhv_rr_rotating_plus_loop(o)
    load_object_collision_model()
    o.oFaceAngleYaw = o.oFaceAngleYaw + 100
end

bhvRRRotPlus = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_rr_rotating_plus_init,
    bhv_rr_rotating_plus_loop)

--[[
    const BehaviorScript bhvFliptile[] = {
    BEGIN(OBJ_LIST_SURFACE),
    ID(id_bhvNewId),
    SET_FLOAT(oDrawingDistance, 20000),
    LOAD_COLLISION_DATA(fliptiles_collision0),
    OR_INT(oFlags, OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE),
    BEGIN_LOOP(),
        CALL_NATIVE(fliptilecode),
    END_LOOP(),
};
    ]]

function flipinit(o)
    o.oDrawingDistance = 20000
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("lava_and_snow_platform_collision")
    network_init_object(o, true, { "oAction", "oSubAction", "oTimer", "oFaceAngleRoll" })
end

---@param o Object
function fliptilecode(o)
    local gMarioState = nearest_mario_state_to_object(o)

    o.oAnimState = o.oBehParams2ndByte
    if o.oAction == 0 then
        if o.oSubAction ~= 0 then
            if (gMarioState.action & 0x03000000) == 0x03000000 or (gMarioState.action & 0x03000000) == 0x01000000 then
                if gMarioState.action ~= ACT_LAVA_BOOST and gMarioState.action ~= ACT_FORWARD_ROLLOUT then
                    if gMarioState.vel.y > 10.0 then
                        o.oAction = 1
                    end
                end
            end
        else
            if gMarioState.pos.y == gMarioState.floorHeight then
                o.oSubAction = 1
            end
        end
        load_object_collision_model()
    else
        o.oFaceAngleRoll = o.oFaceAngleRoll + 0x800
        if o.oTimer > 14 then
            o.oAction = 0
        end
    end
end

bhvLavaAndSnowFlipBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, flipinit,
    fliptilecode)

-- From SM64 Last Impact

function really_big_pole(o)
    o.oInteractType = INTERACT_POLE
    o.hitboxHeight = o.oBehParams2ndByte * 64.0
    o.hitboxRadius = 60
    o.oIntangibleTimer = 0
end

bhvReallyBigPole = hook_behavior(nil, OBJ_LIST_POLELIKE, true, really_big_pole, function()
    bhv_pole_base_loop()
end)

---@param o Object
function bhv_paperplane_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("paper_plane_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2000
    o.oMoveAngleYaw = o.oFaceAngleYaw + 32768
    cur_obj_set_home_once()
    ---network_init_object(o, true, nil)
end

PAPERPLANE_ACT_IDLE = 0
PAPERPLANE_ACT_FLYING = 1

---@param o Object
function bhv_paperplane_loop(o)
    load_object_collision_model()

    if o.oAction == PAPERPLANE_ACT_IDLE then
        if cur_obj_is_mario_on_platform() ~= 0 then
            o.oAction = PAPERPLANE_ACT_FLYING
        end
    elseif o.oAction == PAPERPLANE_ACT_FLYING then
        cur_obj_move_xz_using_fvel_and_yaw()
        o.oForwardVel = approach_s16_symmetric(o.oForwardVel, 40, 0x800)
        o.oPosY = o.oPosY + math_sin(o.oTimer * 0.2) * 10

        o.oAnimState = o.oAnimState + 1

        if o.oAnimState > (14 * 30) then -- 14 seconds
            cur_obj_set_pos_to_home()
            o.oAction = 0
            o.oAnimState = 0
        end
    end
end

bhvPaperPlane = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_paperplane_init, bhv_paperplane_loop)

---@param o Object
function bhv_bowser_can_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("bowser_can_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 3000
end

bhvKoopaCola = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_bowser_can_init,
    function() load_object_collision_model() end)

---@param o Object
function bhv_sa_flower_leaves(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("sa_flower_leaves_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
end

bhvSAFlowerLeaves = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_sa_flower_leaves,
    function() load_object_collision_model() end)


---@param o Object
function bhv_thi2_spinning_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("thi2_spinning_platform_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
    o.oAngleVelYaw = 100
end

bhvTHI2SpinningPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_thi2_spinning_platform,
    function(o)
        load_object_collision_model()
        o.oFaceAngleYaw = o.oFaceAngleYaw + 100
    end)


---@param o Object
function bhv_thi2_electric_platform_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("thi2_electric_platform_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 900
    cur_obj_set_home_once()
end

---@param o Object
function bhv_thi2_electric_platform_loop(o)
    load_object_collision_model()
    o.oPosY = o.oPosY + approach_f32_asymptotic(o.oVelY, (o.oHomeY - o.oPosY) / 8, 0.4)
    if cur_obj_is_mario_on_platform() ~= 0 then
        o.oPosY = o.oPosY - 8
    end
end

bhvTHI2ElectricPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_thi2_electric_platform_init,
    bhv_thi2_electric_platform_loop)

---@param o Object
function bhv_synth_train(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("custom_19000220_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 5000
end

bhvSynthTrain = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_synth_train,
    function() load_object_collision_model() end)

---@param o Object
function bhv_sa_flower_top(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("sa_flower_top_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
end

bhvSAFlowerTop = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_sa_flower_top,
    function() load_object_collision_model() end)

---@param o Object
function bhv_custom_donut_platform(o)
    o.collisionData = smlua_collision_util_get("custom_donut_platform_collision")
end

hook_behavior(id_bhvDonutPlatform, OBJ_LIST_SURFACE, false, bhv_custom_donut_platform,
    function() load_object_collision_model() end)


---@param o Object
function bhv_ddd_appearing_path_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("ddd_purple_appearing_path_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 9000
    network_init_object(o, true, { "oAction" })
end

local dddappearpathSpeed = 0.35

---@param o Object
function bhv_ddd_appearing_path_loop(o)
    if o.oAction == 0 then
        cur_obj_hide()
    elseif o.oAction == 1 then
        load_object_collision_model()
        cur_obj_unhide()
    end

    if obj_has_behavior_id(o, bhvDDDAppearingPath) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 30, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath2) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 30, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath3) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 8, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath4) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 20, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath5) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 7, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath6) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 55, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath7) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 55, dddappearpathSpeed)
        end
    elseif obj_has_behavior_id(o, bhvDDDAppearingPath8) ~= 0 then
        if o.oAction == 1 then
            o.header.gfx.scale.z = approach_f32_symmetric(o.header.gfx.scale.z, 50, dddappearpathSpeed)
        end
    end
end

function ddd_white_crystal_init(o)
    o.oFlags           = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.hitboxRadius     = 140
    o.hitboxHeight     = 400
    o.hitboxDownOffset = 200
    o.oIntangibleTimer = 0
    network_init_object(o, true, { "oAction", "oAnimState", "oFaceAngleYaw" })
end

function ddd_white_crystal_loop(o)
    local thePlayer = nearest_player_to_object(o)
    if o.oAction == 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            o.oAction = 1
            cur_obj_play_sound_1(SOUND_GENERAL_WATER_LEVEL_TRIG)
        end
    end

    if o.oAction == 1 then
        o.oAnimState = o.oAnimState + 1

        if o.oAnimState < 90 then
            o.oFaceAngleYaw = o.oFaceAngleYaw + 0x930
        else
            o.oAction = 2
        end
    end
    if obj_has_behavior_id(o, bhvDDDWhiteCrystal) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath).oAction = 1
        end
    elseif obj_has_behavior_id(o, bhvDDDWhiteCrystal2) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath2).oAction = 1
        end
    elseif obj_has_behavior_id(o, bhvDDDWhiteCrystal3and4and5) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath3).oAction = 1
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath4).oAction = 1
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath5).oAction = 1
        end
    elseif obj_has_behavior_id(o, bhvDDDWhiteCrystal6) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath6).oAction = 1
        end
    elseif obj_has_behavior_id(o, bhvDDDWhiteCrystal7) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath7).oAction = 1
        end
    elseif obj_has_behavior_id(o, bhvDDDWhiteCrystal8) ~= 0 then
        if obj_check_hitbox_overlap(o, thePlayer) then
            obj_get_nearest_object_with_behavior_id(o, bhvDDDAppearingPath8).oAction = 1
        end
    end
end

bhvDDDAppearingPath         = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath2        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath3        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath4        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath5        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath6        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath7        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)
bhvDDDAppearingPath8        = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_ddd_appearing_path_init,
    bhv_ddd_appearing_path_loop)

bhvDDDWhiteCrystal          = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
bhvDDDWhiteCrystal2         = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
bhvDDDWhiteCrystal3and4and5 = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
bhvDDDWhiteCrystal6         = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
bhvDDDWhiteCrystal7         = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
bhvDDDWhiteCrystal8         = hook_behavior(nil, OBJ_LIST_LEVEL, true, ddd_white_crystal_init,
    ddd_white_crystal_loop)
---@param o Object
function polygon_stone(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("polygon_stone_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
    -- obj_scale(o, 0.6)
end

bhvPolygonStone = hook_behavior(nil, OBJ_LIST_SURFACE, true, polygon_stone,
    function(o)
        load_object_collision_model()
        o.oFaceAngleRoll = o.oFaceAngleRoll + 0x160 / 4
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x240 / 4
    end)


---@param o Object
function bhv_music_disc(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("music_disc_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2100
    o.oAngleVelYaw = 160 * 5
    -- obj_scale(o, 0.6)
end

bhvMusicDisc = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_music_disc,
    function(o)
        load_object_collision_model()
        o.oFaceAngleYaw = o.oFaceAngleYaw + 160 * 5
    end)


---@param o Object
function bhv_growing_block(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("ddd_growing_block_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1200
end

bhvDDDGrowingBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_growing_block,
    function(o)
        load_object_collision_model()
    end)


---@param o Object
function bhv_nuclear_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("nuclear_platform_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 900
    cur_obj_set_home_once()
end

---@param o Object
function bhv_nuclear_platform_loop(o)
    load_object_collision_model()
    o.oPosY = o.oPosY + approach_f32_asymptotic(o.oVelY, (o.oHomeY - o.oPosY) / 8, 0.4)
    if cur_obj_is_mario_on_platform() ~= 0 then
        o.oPosY = o.oPosY - 4
    end
end

bhvNuclearPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_nuclear_platform,
    bhv_nuclear_platform_loop)

---@param o Object
function bhv_bitfs_moving_pyramd(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("bitfs_moving_pyramid_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 900
    obj_set_model_extended(o, smlua_model_util_get_id("bitfs_moving_pyramid_geo"))
end

bhvBITFSMovingPyramid = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_bitfs_moving_pyramd,
    function(o)
        load_object_collision_model()
    end)


function bhv_bitfs_yellow_pole(o)
    o.oInteractType = INTERACT_POLE
    o.hitboxHeight = 40 * 35.0
    o.hitboxRadius = 100
    o.oIntangibleTimer = 0
end

bhvBITFSYellowPole = hook_behavior(nil, OBJ_LIST_POLELIKE, true, bhv_bitfs_yellow_pole, function()
    bhv_pole_base_loop()
end)

---@param o Object
function bhv_bitfs_light_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("bitfs_light_platform_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2000
end

---@param o Object
function bhv_bitfs_light_platform_loop(o)
    load_object_collision_model()

    if o.oAction == 0 then
        if cur_obj_is_mario_on_platform() ~= 0 then
            o.oAction = 1
        end
    elseif o.oAction == 1 then
        o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, 7300, 0x280)
        o.oSubAction = o.oSubAction + 1
        if o.oSubAction > (9 * 30) then -- 9 seconds
            o.oAction = 0
            o.oFaceAnglePitch = 0
        end
    end
end

bhvBIRFSLightPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_bitfs_light_platform,
    bhv_bitfs_light_platform_loop)


---@param o Object
function bhv_fast_moving_wall(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("fast_moving_wall_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
    cur_obj_set_home_once()
end

local movingwallspeed = 0x140 / 3
---@param o Object
function bhv_fast_moving_wall_loop(o)
    load_object_collision_model()

    local wall4 = obj_get_nearest_object_with_behavior_id(o, bhvFastMovingWall4)
    local wall3 = obj_get_nearest_object_with_behavior_id(o, bhvFastMovingWall3)
    local wall2 = obj_get_nearest_object_with_behavior_id(o, bhvFastMovingWall2)
    local wall1 = obj_get_nearest_object_with_behavior_id(o, bhvFastMovingWall)

    local mWall = gMarioStates[0]

    if mWall.wall and mWall.wall.object == o then
        if mWall.wall ~= nil then
            if mWall.action == ACT_WALL_SLIDE or _G.OmmEnabled and _G.OmmApi["ACT_OMM_WALL_SLIDE"] then
                mWall.vel.y = -1.2
                if obj_has_behavior_id(o, bhvFastMovingWall) ~= 0 or obj_has_behavior_id(o, bhvFastMovingWall2) ~= 0 then
                    mWall.pos.z = o.oPosZ
                else
                    mWall.pos.x = o.oPosX
                end
            end
        end
    end
    if o.oAction == 0 or o.oAction == 2 then
        o.oSubAction = o.oSubAction + 1
    end
    if o.oSubAction > 90 and o.oAction == 0 then
        o.oAction = 1
    end

    if o.oSubAction > 90 and o.oAction == 2 then
        o.oAction = 3
    end
    if o.oAction == 1 then
        if obj_has_behavior_id(o, bhvFastMovingWall) ~= 0 then
            o.oPosZ = approach_f32_symmetric(o.oPosZ,
                wall2.oHomeZ, movingwallspeed)

            if o.oPosZ == wall2.oHomeZ then
                o.oAction = 2
                o.oSubAction = 0
            end
        end

        if obj_has_behavior_id(o, bhvFastMovingWall2) ~= 0 then
            o.oPosZ = approach_f32_symmetric(o.oPosZ,
                wall1.oHomeZ, movingwallspeed)

            if o.oPosZ == wall1.oHomeZ then
                o.oAction = 2
                o.oSubAction = 0
            end
        end

        if obj_has_behavior_id(o, bhvFastMovingWall3) ~= 0 then
            o.oPosX = approach_f32_symmetric(o.oPosX,
                wall4.oHomeX, movingwallspeed)

            if o.oPosX == wall4.oHomeX then
                o.oAction = 2
                o.oSubAction = 0
            end
        end

        if obj_has_behavior_id(o, bhvFastMovingWall4) ~= 0 then
            o.oPosX = approach_f32_symmetric(o.oPosX,
                wall3.oHomeX, movingwallspeed)

            if o.oPosX == wall3.oHomeX then
                o.oAction = 2
                o.oSubAction = 0
            end
        end
    elseif o.oAction == 3 then
        if obj_has_behavior_id(o, bhvFastMovingWall) ~= 0 or obj_has_behavior_id(o, bhvFastMovingWall2) ~= 0 then
            o.oPosZ = approach_f32_symmetric(o.oPosZ,
                o.oHomeZ, movingwallspeed)

            if o.oPosZ == o.oHomeZ then
                o.oAction = 0
                o.oSubAction = 0
            end
        else
            o.oPosX = approach_f32_symmetric(o.oPosX,
                o.oHomeX, movingwallspeed)

            if o.oPosX == o.oHomeX then
                o.oAction = 0
                o.oSubAction = 0
            end
        end
    end
end

bhvFastMovingWall = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fast_moving_wall,
    bhv_fast_moving_wall_loop)
bhvFastMovingWall2 = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fast_moving_wall,
    bhv_fast_moving_wall_loop)
bhvFastMovingWall3 = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fast_moving_wall,
    bhv_fast_moving_wall_loop)
bhvFastMovingWall4 = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_fast_moving_wall,
    bhv_fast_moving_wall_loop)


---@param o Object
function bhv_broken_stairs(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("broken_stairs_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 2100
    cur_obj_set_home_once()
end

bhvBrokenStairs = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_broken_stairs,
    bhv_nuclear_platform_loop)


---@param o Object
function bhv_casino_card(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("casino_card_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 800
end

bhvCasinoCard = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_casino_card,
    function() load_object_collision_model() end)

---@param o Object
function bhv_casino_dice(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("casino_dice_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
end

bhvCasinoDice = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_casino_dice,
    function() load_object_collision_model() end)

---@param o Object
function bhv_wmotr_static_platform(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("wmotr_static_platform_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1000
end

bhvWMOTRStaticPlatform = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_wmotr_static_platform,
    function() load_object_collision_model() end)

---@param o Object
function bhv_mario_world_block(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("mario_world_block_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 800
end

bhvMarioWorldBlock = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_mario_world_block,
    function() load_object_collision_model() end)

---@param o Object
function bhv_soap_bar_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.collisionData = smlua_collision_util_get("soap_bar_collision")
    o.header.gfx.skipInViewCheck = true
    o.oCollisionDistance = 1600
end

---@param o Object
function bhv_soap_bar_loop(o)
    load_object_collision_model()

    o.oPosY = gMarioStates[0].waterLevel
end

bhvSoapBar = hook_behavior(nil, OBJ_LIST_SURFACE, true, bhv_soap_bar_init,
    bhv_soap_bar_loop)

---@param o Object
function bhv_master_hand_bomb(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.oAnimations = gObjectAnimations.bobomb_seg8_anims_0802396C
    cur_obj_init_animation(0)

    o.hitboxHeight = 100
    o.hitboxRadius = 100
    o.oFriction = 1
    o.oForwardVel = 45

    o.oMoveAngleYaw = o.parentObj.oFaceAngleYaw

    o.oPosY = o.oPosY - 100

    network_init_object(o, true, nil)
end

---@param o Object
function bhv_master_hand_bomb_loop(o)
    local m = nearest_mario_state_to_object(o)

    local ResultStep = object_step()

    if obj_check_hitbox_overlap(m.marioObj, o) or ResultStep & OBJ_COL_FLAG_GROUNDED == 1 or ResultStep & OBJ_COL_FLAG_HIT_WALL ~= 0 then
        spawn_sync_object(id_bhvExplosion, E_MODEL_EXPLOSION, o.oPosX, o.oPosY, o.oPosZ, nil)
        obj_mark_for_deletion(o)
    end
end

bhvMasterHandBomb = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_master_hand_bomb,
    bhv_master_hand_bomb_loop)

---@param o Object
function bhv_paper_pin_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.hitboxHeight = 300
    o.hitboxRadius = 200

    o.oIntangibleTimer = 0

    obj_scale(o, 3)
    network_init_object(o, true, nil)
end

---@param o Object
function bhv_paper_pin_loop(o)

end

bhvPaperPin = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_paper_pin_init,
    bhv_paper_pin_loop)

local MASTER_HAND_IDLE = 0
local MASTER_HAND_FOLLOW = 1
local MASTER_HAND_SHOOT = 2
local MASTER_HAND_SMASH = 3
local MASTER_HAND_DAMAGED = 4

local MODEL_MASTER_HAND = smlua_model_util_get_id("master_hand_open_geo")
local MODEL_MASTER_HAND_SHOOT = smlua_model_util_get_id("master_hand_shoot_geo")

---@param o Object
function bhv_master_hand_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.oInteractType = INTERACT_DAMAGE
    o.oDamageOrCoinValue = 2
    o.oIntangibleTimer = 0
    o.hitboxHeight = 300
    o.hitboxRadius = 430
    o.hitboxDownOffset = 100

    o.oHealth = 3

    network_init_object(o, true,
        { "oPosX", "oPosY", "oPosZ", "oFaceAngleYaw", "oAction", "oSubAction", "oAnimState", "oBobombBuddyPosXCopy",
            "oCapUnkF4" })
end

local function do_master_handstep(m, o)
    o.oPosY = approach_f32_symmetric(o.oPosY, m.pos.y + 200, 20 * 5)

    o.oPosX = m.pos.x + 1200
    o.oPosZ = m.pos.z

    o.oFaceAngleYaw = obj_angle_to_object(o, m.marioObj)
end

---@param o Object
function bhv_master_hand_loop(o)
    local nearestpin = obj_get_nearest_object_with_behavior_id(o, bhvPaperPin)
    o.oInteractStatus = 0
    local m = nearest_mario_state_to_object(o)
    if o.oAction == MASTER_HAND_IDLE then
        if should_start_or_continue_dialog(m, o) ~= 0 and cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_019) ~= 0 then
            o.oAction = MASTER_HAND_FOLLOW
        end
    elseif o.oAction == MASTER_HAND_FOLLOW then
        do_master_handstep(m, o)

        o.oSubAction = o.oSubAction + 1

        if o.oSubAction > 180 then
            if m.pos.y < 1700 then
                o.oAction = MASTER_HAND_SHOOT
            else
                o.oAction = MASTER_HAND_SMASH
            end
            o.oSubAction = 0
        end
    elseif o.oAction == MASTER_HAND_SHOOT then
        do_master_handstep(m, o)
        o.oAnimState = o.oAnimState + 1
        if o.oAnimState > 30 then
            spawn_object2(o, E_MODEL_BLACK_BOBOMB, bhvMasterHandBomb)
            o.oAnimState = 0
            o.oBobombBuddyPosXCopy = o.oBobombBuddyPosXCopy + 1
        end

        if o.oBobombBuddyPosXCopy >= 3 then
            o.oAction = MASTER_HAND_FOLLOW
            o.oBobombBuddyPosXCopy = 0
        end
    elseif o.oAction == MASTER_HAND_SMASH then
        o.oCapUnkF4 = o.oCapUnkF4 + 1
        o.oPosX = approach_f32_symmetric(o.oPosX, m.pos.x, 20 * 5)
        o.oPosZ = approach_f32_symmetric(o.oPosZ, m.pos.z, 20 * 5)

        if o.oCapUnkF4 > 40 then
            o.oPosY = o.oPosY - 20

            --check hitbox overlap with nearest spike

            if obj_check_hitbox_overlap(o, nearestpin) then
                obj_mark_for_deletion(nearestpin)

                spawn_triangle_break_particles(20, 138, 3.0, 4);

                o.oAction = MASTER_HAND_DAMAGED

                play_sound(SOUND_OBJ_KING_WHOMP_DEATH, gGlobalSoundSource)

                o.oSubAction = 0

                o.oHealth = o.oHealth - 1
                o.oCapUnkF4 = 0
            end

            if o.oCapUnkF4 > 90 then
                o.oCapUnkF4 = 0
                o.oAction = MASTER_HAND_FOLLOW
            end
        else
            o.oPosY = approach_f32_symmetric(o.oPosY, m.pos.y + 800, 20 * 5)
        end
    elseif o.oAction == MASTER_HAND_DAMAGED then
        o.oFaceAnglePitch = o.oFaceAnglePitch + 0x400 * 2
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x100 * 2
        o.oSubAction = o.oSubAction + 1

        if o.oSubAction > 60 then
            o.oAction = MASTER_HAND_FOLLOW
            o.oFaceAnglePitch = 0
            o.oFaceAngleYaw = 0
            o.oSubAction = 0
        end
    end

    if o.oAction == MASTER_HAND_SHOOT then
        obj_set_model_extended(o, MODEL_MASTER_HAND_SHOOT)
    else
        obj_set_model_extended(o, MODEL_MASTER_HAND)
    end

    if o.oHealth <= 0 then
        obj_mark_for_deletion(o)

        spawn_red_coin_cutscene_star(o.oPosX, o.oPosY - 70, o.oPosZ)
    end
end

bhvMasterHand = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_master_hand_init,
    bhv_master_hand_loop)


---@param o Object
function bhv_mario_world_hill(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.header.gfx.skipInViewCheck = true
end

bhvMarioWorldHill = hook_behavior(nil, OBJ_LIST_LEVEL, true, bhv_mario_world_hill,
    nil)

---@param o Object
function bhv_bush(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
    obj_set_billboard(o)
end

bhvBush = hook_behavior(nil, OBJ_LIST_LEVEL, true, bhv_bush,
    nil)

---@param o Object
function bhv_octopus_boss_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.hitboxHeight = 320 * 4.7
    o.hitboxRadius = 600
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.oHealth = 3

    network_init_object(o, true, { "oAction", "oSubAction", "oHealth" })
end

OCTOPUS_IDLE      = 0
OCTOPUS_ACTIVATED = 2
OCTOPUS_DAMAGED   = 3

---@param o Object
function bhv_octopus_boss_loop(o)
    local nearestMario = nearest_mario_state_to_object(o)

    if o.oAction == OCTOPUS_IDLE then
        if should_start_or_continue_dialog(nearestMario, o) ~= 0 and cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_032) ~= 0 then
            o.oAction = OCTOPUS_ACTIVATED
        end
    elseif o.oAction == OCTOPUS_ACTIVATED then
        o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, 0, 1000)
        o.oFaceAngleYaw = obj_angle_to_object(o, nearestMario.marioObj)
        if nearestMario.action == ACT_SHOT_FROM_CANNON and obj_check_hitbox_overlap(o, nearestMario.marioObj) then
            play_sound(SOUND_OBJ_KING_WHOMP_DEATH, gGlobalSoundSource)
            o.oAction = OCTOPUS_DAMAGED
            o.oHealth = o.oHealth - 1
            o.oSubAction = 0
        end

        if o.oHealth <= 0 then
            spawn_mist_particles_variable(0, 0, 100.0);
            spawn_triangle_break_particles(20, 138, 3.0, 4);
            spawn_default_star(nearestMario.pos.x, nearestMario.pos.y, nearestMario.pos.z)
            obj_mark_for_deletion(o)
        end
    elseif o.oAction == OCTOPUS_DAMAGED then
        o.oSubAction = o.oSubAction + 1
        o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, -16384, 1000)
        if o.oSubAction > 60 then
            o.oAction = OCTOPUS_ACTIVATED
        end
    end
end

bhvOctopusBoss = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_octopus_boss_init,
    bhv_octopus_boss_loop)

---@param o Object
function bhv_octopus_boss_cannon_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.header.gfx.skipInViewCheck = true

    cur_obj_scale(2.1)

    o.hitboxRadius = 160
    o.hitboxHeight = 440

    o.oIntangibleTimer = 0
end

local ACT_IN_CANNON_CUSTOM = allocate_mario_action(ACT_FLAG_STATIONARY)

function act_in_cannon_custom(m)
    m.actionTimer = m.actionTimer + 1

    if m.actionTimer > 30 then
        m.action = ACT_SHOT_FROM_CANNON
        m.vel.y = 40
        m.forwardVel = 80 * 1.22
    end
end

hook_mario_action(ACT_IN_CANNON_CUSTOM, act_in_cannon_custom)
local cannonSpeed = 1300
---@param o Object
function bhv_octopus_boss_cannon_loop(o)
    local localM = gMarioStates[0]

    if o.oAction == 0 then
        o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, 0, cannonSpeed)
        if obj_check_hitbox_overlap(o, localM.marioObj) then
            localM.marioObj.header.gfx.pos.x = o.oPosX
            localM.marioObj.header.gfx.pos.y = o.oPosY
            localM.marioObj.header.gfx.pos.z = o.oPosZ
            localM.pos.x = o.oPosX
            localM.pos.y = o.oPosY
            localM.pos.z = o.oPosZ
            localM.faceAngle.y = o.oFaceAngleYaw
            localM.action = ACT_IN_CANNON_CUSTOM

            o.oAction = 1
        end
    elseif o.oAction == 1 then
        o.oFaceAnglePitch = approach_s16_symmetric(o.oFaceAnglePitch, 11000, cannonSpeed)
        if not obj_check_hitbox_overlap(o, localM.marioObj) then
            o.oAction = 0
        end
    end
end

bhvOctopusBossCannon = hook_behavior(nil, OBJ_LIST_LEVEL, true, bhv_octopus_boss_cannon_init,
    bhv_octopus_boss_cannon_loop)

local bossWarioAnims = {
    [0] = get_mario_vanilla_animation(MARIO_ANIM_FIRST_PERSON),
    get_mario_vanilla_animation(MARIO_ANIM_WALKING),
    get_mario_vanilla_animation(MARIO_ANIM_FIRST_PUNCH),
    get_mario_vanilla_animation(MARIO_ANIM_FIRE_LAVA_BURN),
}


---@param o Object
function bhv_wario_boss_init(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE|OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW
    o.oInteractType = INTERACT_DAMAGE
    o.hitboxHeight = 120
    o.hitboxRadius = 90
    o.oIntangibleTimer = 0
    o.header.gfx.skipInViewCheck = true
    o.oFriction = 1
    o.oGravity = 2.1
    obj_init_animation_from_custom_table(o, bossWarioAnims, 0, true)
    o.oDamageOrCoinValue = 2
    o.oGraphYOffset = 40
    o.oHealth = 3

    ---phase

    o.oBobombBuddyPosXCopy = 1
end

WARIO_IDLE = 0
WARIO_WALK = 1
WARIO_SHOULDER_BASH = 2
WARIO_THROW_BOMB = 3
WARIO_BURNING = 4

---@param o Object
function bhv_wario_boss_loop(o)
    o.oInteractStatus = 0
    local neastMario = nearest_mario_state_to_object(o)

    if o.oAction == WARIO_IDLE then
        o.oForwardVel = 0
        obj_init_animation_from_custom_table(o, bossWarioAnims, 0, true)
        if should_start_or_continue_dialog(neastMario, o) ~= 0 and cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_046) ~= 0 then
            o.oAction = WARIO_WALK
        end
    elseif o.oAction == WARIO_WALK then
        obj_init_animation_from_custom_table(o, bossWarioAnims, 1, true, 3.3)
        o.oForwardVel = 12

        o.oMoveAngleYaw = obj_angle_to_object(o, neastMario.marioObj)
        o.oSubAction = o.oSubAction + 1

        if o.oSubAction > 80 then
            o.oAction = WARIO_SHOULDER_BASH
            play_sound(gCharacters[CT_WARIO].soundWah2, gGlobalSoundSource)
            o.oSubAction = 0
        end
    elseif o.oAction == WARIO_SHOULDER_BASH then
        obj_init_animation_from_custom_table(o, bossWarioAnims, 2, true)
        o.oForwardVel = 18 * 1.7
        o.oSubAction = o.oSubAction + 1

        if o.oSubAction > 40 then
            o.oAction = WARIO_WALK
            o.oSubAction = 0
        end
    elseif o.oAction == WARIO_BURNING then
        obj_init_animation_from_custom_table(o, bossWarioAnims, 3, true)
        o.oForwardVel = 18
    end

    if o.oAction ~= WARIO_BURNING then
        if o.oFloor then
            if o.oFloor.type == SURFACE_BURNING then
                if o.oPosY < find_floor_height(o.oPosX, o.oPosY, o.oPosZ) + 300 then
                    play_sound(gCharacters[CT_WARIO].soundOnFire, gGlobalSoundSource)
                    o.oBobombBuddyPosXCopy = o.oBobombBuddyPosXCopy + 1
                    o.oAction = WARIO_BURNING
                end
            end
        end
    end
    if o.oAction ~= WARIO_IDLE then
        object_step()
    end
end

bhvWarioBoss = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_wario_boss_init,
    bhv_wario_boss_loop)

---@param o Object
function bhv_goomba_watchers(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE | OBJ_FLAG_MOVE_XZ_USING_FVEL | OBJ_FLAG_SET_FACE_ANGLE_TO_MOVE_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.oAnimations = gObjectAnimations.goomba_seg8_anims_0801DA4C
    cur_obj_init_animation(0)
end

bhvGoombaWatchers = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_goomba_watchers,
    nil)

ACT_YEET_STAT = allocate_mario_action(ACT_FLAG_STATIONARY)

function act_yeet_stationary(m)
    set_mario_animation(m, MARIO_ANIM_AIRBORNE_ON_STOMACH)
    m.marioObj.header.gfx.angle.y = m.faceAngle.y
end

hook_mario_action(ACT_YEET_STAT, act_yeet_stationary)

CHUCKYEET_ACT_DIALOG = 0
CHUCKYEET_ACT_FOLLOW = 1
CHUCKYEET_ACT_HOLD = 2
CHUCKYEET_ACT_WAIT = 3

---@param o Object
function bhv_chuckya_lift(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE|OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW

    o.oAnimations = gObjectAnimations.chuckya_seg8_anims_0800C070
    cur_obj_init_animation(4)
    o.hitboxRadius = 200
    o.hitboxHeight = 120 * 2
    obj_scale(o, 2.1)
    o.oBounciness = 0
    o.oGravity = 3 * 4
    o.oFriction = 1
    o.oIntangibleTimer = 0
end

local chuckSpeed = 4
---@param o Object
function bhv_chuckya_lift_loop(o)
    ---@type MarioState
    local lM = gMarioStates[0]
    object_step()
    o.oBounciness = 0
    if o.oAction == CHUCKYEET_ACT_DIALOG then
        cur_obj_init_animation(5)
        --o.oMoveAngleYaw = obj_angle_to_object(o, lM.marioObj) he doesn't actually face mario in the hack
        o.oForwardVel = 0
        if obj_check_hitbox_overlap(o, lM.marioObj) and lM.floorHeight == lM.pos.y then
            set_mario_action(lM, ACT_READING_NPC_DIALOG, 0)
            cur_obj_push_mario_away(o.hitboxRadius)
            if cutscene_object_with_dialog(CUTSCENE_DIALOG, o, DIALOG_015) ~= 0 then
                o.oAction = CHUCKYEET_ACT_FOLLOW
                o.hitboxRadius = 160
            end
        end
    elseif o.oAction == CHUCKYEET_ACT_FOLLOW then
        o.oSubAction = o.oSubAction + 1
        if o.oSubAction > 80 then
            o.hitboxRadius = 160
            o.hitboxHeight = 120 * 2
            o.oSubAction = 0
        end
        cur_obj_init_animation(4)
        ---folllowr
        if dist_between_objects(o, lM.marioObj) > 480 then
            o.oForwardVel = approach_f32_symmetric(o.oForwardVel,
                dist_between_objects(o, lM.marioObj) / 10 - 48 <= 48 and dist_between_objects(o, lM.marioObj) / 10 - 48 or
                48, chuckSpeed)
        else
            o.oForwardVel = approach_f32_symmetric(o.oForwardVel, 0, chuckSpeed)
        end
        if o.oPosY ~= lM.pos.y then
            o.oVelY = approach_f32_symmetric(o.oVelY, lM.vel.y, chuckSpeed)
        else
            o.oVelY = approach_f32_symmetric(o.oVelY, 0, chuckSpeed)
        end

        if lM.pos.y > o.oPosY then
            o.oPosY = lM.pos.y
        end

        if o.oPosY > find_floor_height(o.oPosX, o.oPosY, o.oPosZ) + 300 then
            spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, nil);
        end
        ----------angle
        o.oMoveAngleYaw = obj_angle_to_object(o, lM.marioObj)

        if obj_check_hitbox_overlap(o, lM.marioObj) and o.hitboxRadius ~= 0 then
            o.oAction = CHUCKYEET_ACT_HOLD
            o.oSubAction = 0
        end
    elseif o.oAction == CHUCKYEET_ACT_HOLD then
        cur_obj_init_animation(1)
        o.oForwardVel = 0
        o.oMoveAngleYaw = o.oMoveAngleYaw + 0x200
        lM.action = ACT_YEET_STAT
        lM.forwardVel = 0
        lM.faceAngle.y = o.oMoveAngleYaw

        if lM.controller.buttonPressed & A_BUTTON ~= 0 then
            cur_obj_init_animation(3)
            lM.vel.y = 37
            lM.forwardVel = 50
            o.oAction = CHUCKYEET_ACT_WAIT
            o.hitboxRadius = 0
            o.hitboxHeight = 0
            lM.action = ACT_SHOT_FROM_CANNON
        end

        lM.marioObj.header.gfx.pos.x = o.oPosX + (sins(o.oMoveAngleYaw) * 70)
        lM.marioObj.header.gfx.pos.z = o.oPosZ + (coss(o.oMoveAngleYaw) * 70)
        lM.marioObj.header.gfx.pos.y = o.oPosY + 300

        lM.pos.x = lM.marioObj.header.gfx.pos.x
        lM.pos.z = lM.marioObj.header.gfx.pos.z
        lM.pos.y = lM.marioObj.header.gfx.pos.y
    elseif o.oAction == CHUCKYEET_ACT_WAIT then
        cur_obj_init_animation(3)
        o.header.gfx.animInfo.animFrame = o.header.gfx.animInfo.curAnim.loopEnd
        o.oVelY = 0
        o.oForwardVel = 0
        if lM.action == ACT_IDLE then
            o.oAction = CHUCKYEET_ACT_FOLLOW
        end
    end
end

bhvChuckyaLift = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_chuckya_lift,
    bhv_chuckya_lift_loop)


---@param o Object
function bhv_casino_random_dice(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    o.header.gfx.skipInViewCheck = true
    o.hitboxHeight = 150
    o.hitboxRadius = 110
    o.oIntangibleTimer = 0
    cur_obj_scale(0.5)
    o.oGravity = -6
    o.oGraphYOffset = 76 + 35
    o.oBounciness = 4

    network_init_object(o, true,
        { "oAction", "oVelY", "oForwardVel", "oFaceAngleRoll", "oFaceAnglePitch", "oFaceAngleYaw", "oSubAction" })
end

---@param o Object
function bhv_casino_random_dice_loop(o)
    local oMS = nearest_mario_state_to_object(o)
    if o.oAction == 0 then
        o.oFaceAngleRoll = o.oFaceAngleRoll + 0x160 / 4.7
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x240 / 4.7

        if obj_check_hitbox_overlap(oMS.marioObj, o) then
            o.oMoveAngleYaw = oMS.faceAngle.y
            o.oVelY = 30 * 2.4
            o.oForwardVel = 6 * 2
            o.oFaceAngleRoll = 40000 / 1.1
            o.oFaceAnglePitch = 40000 / 1.1
            o.oAction = 1
            o.oFaceAngleYaw = 0
        end
    elseif o.oAction == 1 then
        if o.oPosY < find_floor_height(o.oPosX, o.oPosY, o.oPosZ) + 100 then
            o.oForwardVel = 0
        end
        o.oFaceAngleRoll = approach_f32_symmetric(o.oFaceAngleRoll, 0, 0x160 / 4.7 * 15)
        o.oFaceAngleYaw = approach_f32_symmetric(o.oFaceAngleYaw, 0, 0x160 / 4.7 * 15)
        o.oFaceAnglePitch = approach_f32_symmetric(o.oFaceAnglePitch, 0, 0x160 / 4.7 * 15)

        if o.oFaceAngleRoll == 0 and o.oFaceAngleYaw == 0 and o.oFaceAnglePitch == 0 then
            o.oSubAction = o.oSubAction + 1
            if o.oSubAction > 25 then
                obj_mark_for_deletion(o)
                spawn_mist_particles()
                spawn_non_sync_object(id_bhvTenCoinsSpawn, E_MODEL_NONE, o.oPosX, o.oPosY, o.oPosZ, nil)
            end
        end
    end
    move_obj_with_physics(true, o)
end

bhvCasinoRandomDice = hook_behavior(nil, OBJ_LIST_LEVEL, true, bhv_casino_random_dice,
    bhv_casino_random_dice_loop)

---@param o Object
function bhv_smash_bros_metal(o)
    o.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE

    o.hitboxHeight = 70
    o.hitboxRadius = 160

    o.oIntangibleTimer = 0
end

---@param o Object
function bhv_smash_bros_metal_loo(o)
    local oSM = gMarioStates[0]
    cur_obj_push_mario_away(150)
    if obj_check_hitbox_overlap(o, oSM.marioObj) then
        play_sound(SOUND_ACTION_METAL_STEP, gGlobalSoundSource)
        oSM.forwardVel = -oSM.forwardVel - 13
    end
end

bhvSmashBrosMetal = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_smash_bros_metal,
    bhv_smash_bros_metal_loo)
