-- Placed here to remove the need of setting models for every powerup
-- Uses the definitive model check

-- Models

E_MODEL_TANOOKI_MARI    = smlua_model_util_get_id("tanooki_mario_geo")
E_MODEL_KITSUNE_LUIG    = smlua_model_util_get_id("kitsune_luigi_geo")
E_MODEL_TANOOKI_TOAD    = smlua_model_util_get_id("tanooki_toad_geo")
E_MODEL_TANOOKI_WARI    = smlua_model_util_get_id("tanooki_wario_geo")
E_MODEL_KITSUNE_WALUIGI = smlua_model_util_get_id("kitsune_waluigi_geo")
E_MODEL_CAT_MARI        = smlua_model_util_get_id("cat_mario_geo")
E_MODEL_BEE_MARI        = smlua_model_util_get_id("bee_mario_geo")
E_MODEL_CLOUD_MARIO     = smlua_model_util_get_id("cloud_mario_geo")

-- Powerups enum

NORMAL  = 0
TANOOKI = 1
CAT     = 2
BEE     = 3
CLOUD   = 4
ROCKET  = 5

-- Powerup Relatives
local cloudcount = 0                       -- for cloud flower

gPlayerSyncTable[0].activePowerup = NORMAL -- Current Powerup, set to NORMAL to disable any powerup

characterPowerupModels = {
    [CT_MARIO]   = { tanooki = E_MODEL_TANOOKI_MARIO, cat = E_MODEL_CAT_MARIO, bee = E_MODEL_BEE_MARIO, cloud = E_MODEL_CLOUD_MARIO },
    [CT_LUIGI]   = { tanooki = E_MODEL_KITSUNE_LUIGI, cat = nil, bee = nil, cloud = nil },
    [CT_TOAD]    = { tanooki = E_MODEL_TANOOKI_TOAD, cat = nil, bee = nil, cloud = nil },
    [CT_WARIO]   = { tanooki = E_MODEL_TANOOKI_WARIO, cat = nil, bee = nil, cloud = nil },
    [CT_WALUIGI] = { tanooki = E_MODEL_KITSUNE_WALUIGI, cat = nil, bee = nil, cloud = nil },
}

local powerupStates = {
    [NORMAL]  = { modelId = nil },
    [TANOOKI] = { modelId = nil },
    [CAT]     = { modelId = nil },
    [BEE]     = { modelId = nil },
    [CLOUD]   = { modelId = nil }
}

-- Powerup States, to add more powerups here, you must first add them to the enum and assign a number
function get_character_model(m)
    if m.playerIndex ~= 0 then return end
    CPM = characterPowerupModels[m.character.type] -- To get the model easily
    CPMM = characterPowerupModels[CT_MARIO]        -- To get Mario's model easily
    powerupStates = {
        [NORMAL]  = { modelId = nil },
        [TANOOKI] = { modelId = CPM.tanooki and CPM.tanooki or CPMM.tanooki },
        [CAT]     = { modelId = CPM.cat and CPM.cat or CPMM.cat },
        [BEE]     = { modelId = CPM.bee and CPM.bee or CPMM.bee },
        [CLOUD]   = { modelId = CPM.cloud and CPM.cloud or CPMM.cloud },
        [ROCKET]  = { modelId = nil }
    }
end

hook_event(HOOK_MARIO_UPDATE, get_character_model)

-- Powerup Model Functions --

function powerups()
    gPlayerSyncTable[0].modelId = powerupStates[gPlayerSyncTable[0].activePowerup].modelId
end

hook_event(HOOK_OBJECT_SET_MODEL, function(o)
    if obj_has_behavior_id(o, id_bhvMario) ~= 0 then
        local i = network_local_index_from_global(o.globalPlayerIndex)
        if stuck then
            gPlayerSyncTable[i].modelId = E_MODEL_NONE
        end
        if gPlayerSyncTable[i].modelId ~= nil and obj_has_model_extended(o, gPlayerSyncTable[i].modelId) == 0 then
            obj_set_model_extended(o, gPlayerSyncTable[i].modelId)
        end
    end
end)

-- Resets the player stats when leaving a level or dying

function on_death_warp()
    timer = 0
    score = 0
    scoreCounter = 0
    cloudcount = 0
    gPlayerSyncTable[0].activePowerup = NORMAL
end

-- Removes the player's powerup on damage

function damage_check(m)
    if m.playerIndex ~= 0 then return end
    if m.hurtCounter > 0 or m.action == ACT_BURNING_GROUND or m.action == ACT_BURNING_JUMP then
        gPlayerSyncTable[0].activePowerup = NORMAL
        cloudcount = 0
    end
    if m.action & ACT_FLAG_SWIMMING ~= 0 and gPlayerSyncTable[0].activePowerup == BEE then
        gPlayerSyncTable[0].activePowerup = NORMAL
    end
end

hook_event(HOOK_UPDATE, powerups)
hook_event(HOOK_MARIO_UPDATE, damage_check)
hook_event(HOOK_ON_DEATH, on_death_warp)
hook_event(HOOK_ON_WARP, on_death_warp)

---@param powerup integer
---@param obj Object
function general_powerup_handler(obj, powerup)
    local nreaetsplayertopwoerup = nearest_player_to_object(obj)
    local nearestmariotopowerup = nearest_mario_state_to_object(obj)
    if obj.oAction == 0 then
        if obj_check_hitbox_overlap(nreaetsplayertopwoerup, obj) then
            obj.oAction = 1
            cur_obj_hide()
            obj.oTimer = 0
            cur_obj_play_sound_2(SOUND_MENU_EXIT_PIPE)
            gPlayerSyncTable[network_local_index_from_global(nreaetsplayertopwoerup.globalPlayerIndex)].activePowerup =
            powerup
        end
    end


    if obj.oAction == 1 then
        obj.hitboxRadius = 0
        obj.hitboxHeight = 0
        if obj.oTimer > 200 then
            obj.oTimer = 0
            obj.oAction = 0
            cur_obj_unhide()
            obj.hitboxRadius = 65
            obj.hitboxHeight = 65
        end
    end
end

---@param powerup integer
---@param obj Object
function general_powerup_handler_DONT_SYNC(obj, powerup)
    local nearestmariotopowerup = gMarioStates[0]
    if obj.oAction == 0 then
        if obj_check_hitbox_overlap(nearestmariotopowerup.marioObj, obj) then
            obj.oAction = 1
            cur_obj_hide()
            obj.oTimer = 0
            cur_obj_play_sound_2(SOUND_MENU_EXIT_PIPE)
            gPlayerSyncTable[0].activePowerup = powerup
            if powerup == CLOUD then
                cloudcount = 3
            end
        end
    end


    if obj.oAction == 1 then
        obj.hitboxRadius = 0
        obj.hitboxHeight = 0
        if obj.oTimer > 200 then
            obj.oTimer = 0
            obj.oAction = 0
            cur_obj_unhide()
            obj.hitboxRadius = 65
            obj.hitboxHeight = 65
        end
    end
end

-- Actual Powerups

-- Tanooki Powerup --

E_MODEL_TANOOKI_LEAF = smlua_model_util_get_id("tanooki_leaf_geo")
smlua_anim_util_register_animation("anim_flutter",
    0,
    0,
    0,
    0,
    9,
    { 0x0000, 0x00AA, 0x0000, 0x0000, 0x3FFF, 0x0000, 0x0000, 0x0000, 0x3FC6,
        0x2683, 0xEFB9, 0xE999, 0xE54A, 0x1304, 0x003C, 0xFFFE, 0x0001, 0xC170,
        0xE643, 0xD713, 0xEC60, 0xFFFF, 0x0000, 0xFFF5, 0x0000, 0xF97B, 0xED8B,
        0xFFFE, 0x0001, 0xC170, 0x3BC7, 0x49B0, 0xC9DC, 0xFFFF, 0xFFFF, 0xE8F2,
        0x0000, 0xFFFF, 0xF548, 0x0000, 0x0000, 0xBF5E, 0x00E1, 0xEB1E, 0x705E,
        0x0000, 0xFFFF, 0x4C57, 0x002B, 0xFFCE, 0xD5EB, 0x0000, 0x0000, 0xBF5E,
        0x0FEA, 0x02C6, 0xC52E, 0xFFFF, 0x0000, 0x0A3A, 0xFE60, 0xFF2B, 0xEE9E,
        0xFFFF, 0xFFFE, 0xFFFF, 0xFFFF, 0x0000, 0x0000, 0x0000, 0x0000, 0xFFFF,
        0xFFFF, 0xFFFE, 0x15F6, 0xFDDC, 0xF2D3, 0xF06C, 0xF23B, 0xF3D1, 0x0FBA,
        0x18F4, 0x1826, 0x15F6, },
    { 0x0001, 0x0000, 0x0001, 0x0001, 0x0001, 0x0002, 0x0001, 0x0003, 0x0001,
        0x0004, 0x0001, 0x0005, 0x0001, 0x0006, 0x0001, 0x0007, 0x0001, 0x0008,
        0x0001, 0x0009, 0x0001, 0x000A, 0x0001, 0x000B, 0x0001, 0x000C, 0x0001,
        0x000D, 0x0001, 0x000E, 0x0001, 0x000F, 0x0001, 0x0010, 0x0001, 0x0011,
        0x0001, 0x0012, 0x0001, 0x0013, 0x0001, 0x0014, 0x0001, 0x0015, 0x0001,
        0x0016, 0x0001, 0x0017, 0x0001, 0x0018, 0x0001, 0x0019, 0x0001, 0x001A,
        0x0001, 0x001B, 0x0001, 0x001C, 0x0001, 0x001D, 0x0001, 0x001E, 0x0001,
        0x001F, 0x0001, 0x0020, 0x0001, 0x0021, 0x0001, 0x0022, 0x0001, 0x0023,
        0x0001, 0x0024, 0x0001, 0x0025, 0x0001, 0x0026, 0x0001, 0x0027, 0x0001,
        0x0028, 0x0001, 0x0029, 0x0001, 0x002A, 0x0001, 0x002B, 0x0001, 0x002C,
        0x0001, 0x002D, 0x0001, 0x002E, 0x0001, 0x002F, 0x0001, 0x0030, 0x0001,
        0x0031, 0x0001, 0x0032, 0x0001, 0x0033, 0x0001, 0x0034, 0x0001, 0x0035,
        0x0001, 0x0036, 0x0001, 0x0037, 0x0001, 0x0038, 0x0001, 0x0039, 0x0001,
        0x003A, 0x0001, 0x003B, 0x0001, 0x003C, 0x0001, 0x003D, 0x0001, 0x003E,
        0x0001, 0x003F, 0x000A, 0x0040, 0x000A, 0x004A, })

local flutterTimer = 40
local wallSlideTimer = 0

ACT_FLUTTER = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
local flutterActions = {
    [ACT_JUMP] = true,
    [ACT_DOUBLE_JUMP] = true,
    [ACT_TRIPLE_JUMP] = true,
    [ACT_LONG_JUMP] = true,
    [ACT_SIDE_FLIP] = true,
    [ACT_GROUND_POUND_JUMP] = true,
    [ACT_FORWARD_ROLLOUT] = true,
    [ACT_BACKWARD_ROLLOUT] = true,
    [ACT_WALL_KICK_AIR] = true,
    [ACT_FLUTTER] = true,
    [ACT_FREEFALL] = true,
    [ACT_FAKE_FREEFALL] = true,
    [ACT_BACKFLIP] = true
}

---@param obj Object
function bhv_leaf_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_TANOOKI_LEAF)
    obj_scale(obj, 0.5)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768 -- watchr is so not awesome
    obj.hitboxRadius = 30
    obj.hitboxHeight = 30
    obj.oIntangibleTimer = 0
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_leaf_loop(obj)
    object_step()
    load_object_collision_model()
    local nreaetsplayertopwoerup = nearest_player_to_object(obj)
    if obj_check_hitbox_overlap(nreaetsplayertopwoerup, obj) then
        obj_mark_for_deletion(obj)
        gPlayerSyncTable[network_local_index_from_global(nreaetsplayertopwoerup.globalPlayerIndex)].activePowerup =
            TANOOKI
    end
end

id_bhvSuperLeaf = hook_behavior(id_bhvWingCap, OBJ_LIST_GENACTOR, true, bhv_leaf_init, bhv_leaf_loop)

function tanooki_update(m)
    if m.playerIndex ~= 0 then return end
    if gPlayerSyncTable[0].activePowerup ~= TANOOKI then return end
    if m.action == ACT_WALL_SLIDE then
        wallSlideTimer = 0
    elseif m.action == ACT_WALL_KICK_AIR then
        wallSlideTimer = wallSlideTimer + 1
    else
        wallSlideTimer = 0
    end
    if flutterActions[m.action] then
        if m.controller.buttonPressed & A_BUTTON ~= 0 and m.action & ACT_FLAG_AIR ~= 0 then
            startTimer = false
            if m.pos.y > (m.floorHeight + 100) then
                if wallSlideTimer < 4 and m.action == ACT_WALL_KICK_AIR then return end
                set_mario_action(m, ACT_FLUTTER, 0)
                wallSlideTimer = 0
                play_sound(SOUND_ACTION_SPIN, m.marioObj.header.gfx.cameraToObject)
                startTimer = true
                flutterTimer = 0
            end
        end
        if startTimer then
            flutterTimer = flutterTimer + 1
            if flutterTimer < 10 then
                if m.vel.y < -7.5 then
                    m.vel.y = -7.5
                    smlua_anim_util_set_animation(m.marioObj, "anim_flutter")
                end
            else
                startTimer = false
                flutterTimer = 0
            end
        else
            flutterTimer = 0
        end
    end
end

function act_flutter(m)
    if m.playerIndex ~= 0 then return end
    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        if m.forwardVel >= 28 then
            set_mario_action(m, ACT_DIVE, 0)
        else
            set_mario_action(m, ACT_JUMP_KICK, 0)
        end
    end

    if (m.controller.buttonPressed & Z_TRIG) ~= 0 then
        set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    common_air_action_step(m, ACT_JUMP_LAND, MARIO_ANIM_SINGLE_JUMP,
        AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG)
end

hook_mario_action(ACT_FLUTTER, { every_frame = act_flutter })

hook_event(HOOK_MARIO_UPDATE, tanooki_update)

-- Bee Powerup --

E_MODEL_BEE_SHROOM = smlua_model_util_get_id("bee_shroom_geo")

ACT_FLY = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)

gPlayerSyncTable[0].energyBar = 72 -- 2.4 Seconds

-- Energy Meter Textures --

local EMPTY_ENERGY = get_texture_info("bee_meter_empty")
local TWO_ENERGY = get_texture_info("bee_meter_2")
local THREE_ENERGY = get_texture_info("bee_meter_3")
local FOUR_ENERGY = get_texture_info("bee_meter_4")
local FIVE_ENERGY = get_texture_info("bee_meter_5")
local SIX_ENERGY = get_texture_info("bee_meter_6")
local SEVEN_ENERGY = get_texture_info("bee_meter_7")
local EIGHT_ENERGY = get_texture_info("bee_meter_8")
local NINE_ENERGY = get_texture_info("bee_meter_9")
local TEN_ENERGY = get_texture_info("bee_meter_10")
local ELEVEN_ENERGY = get_texture_info("bee_meter_11")
local FULL_ENERGY = get_texture_info("bee_meter_full")

local energyMeter = {
    { energy = EMPTY_ENERGY },
    { energy = TWO_ENERGY },
    { energy = THREE_ENERGY },
    { energy = FOUR_ENERGY },
    { energy = FIVE_ENERGY },
    { energy = SIX_ENERGY },
    { energy = SEVEN_ENERGY },
    { energy = EIGHT_ENERGY },
    { energy = NINE_ENERGY },
    { energy = TEN_ENERGY },
    { energy = ELEVEN_ENERGY },
    { energy = FULL_ENERGY }
}

local common_blacklisted_actions = {
    [ACT_BACKWARD_AIR_KB] = true,
    [ACT_FORWARD_AIR_KB] = true,
    [ACT_BACKWARD_GROUND_KB] = true,
    [ACT_SOFT_BONK] = true,
    [ACT_HARD_FORWARD_AIR_KB] = true,
    [ACT_THROWN_BACKWARD] = true,
    [ACT_HARD_FORWARD_GROUND_KB] = true,
    [ACT_SOFT_FORWARD_GROUND_KB] = true,
    [ACT_HARD_BACKWARD_GROUND_KB] = true,
    [ACT_SOFT_BACKWARD_GROUND_KB] = true
}

function energy_meter()
    if math.ceil((gPlayerSyncTable[0].energyBar / 12) * 2) ~= 0 then
        curEnergy = math.ceil((gPlayerSyncTable[0].energyBar / 12) * 2)
    else
        curEnergy = 1
    end
end

hook_event(HOOK_UPDATE, energy_meter)

---@param obj Object
function bhv_beesuit_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_BEE_SHROOM)
    obj_scale(obj, 0.5)
    obj.hitboxRadius = 30
    obj.hitboxHeight = 30
    obj.oIntangibleTimer = 0
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_beesuit_loop(obj)
    spawn_non_sync_object(id_bhvSparkleSpawn, E_MODEL_NONE, obj.oPosX, obj.oPosY, obj.oPosZ, nil);
    object_step()
    load_object_collision_model()
    obj.oFaceAngleYaw = obj.oFaceAngleYaw + ((65536 / 360) * 1.5)
    local nreaetsplayertopwoerup = nearest_player_to_object(obj)
    if obj_check_hitbox_overlap(nreaetsplayertopwoerup, obj) then
        obj_mark_for_deletion(obj)
        gPlayerSyncTable[network_local_index_from_global(nreaetsplayertopwoerup.globalPlayerIndex)].activePowerup = BEE
    end
end

id_bhvBeeShroom = hook_behavior(id_bhvVanishCap, OBJ_LIST_GENACTOR, true, bhv_beesuit_init, bhv_beesuit_loop)

---@param m MarioState
function bee_update(m)
    if m.playerIndex ~= 0 then return end
    if gPlayerSyncTable[0].activePowerup ~= BEE then return end
    if m.vel.y <= 0 and m.action & ACT_FLAG_AIR ~= 0 and gPlayerSyncTable[0].energyBar > 0 and (m.action ~= ACT_FAKE_FREEFALL and m.action ~= ACT_WALL_SLIDE and not common_blacklisted_actions[m.action]) then
        if m.controller.buttonDown & A_BUTTON ~= 0 then
            if m.action == ACT_GROUND_POUND then
                if m.vel.y < -50 then
                    set_mario_action(m, ACT_FLY, 0)
                end
            else
                set_mario_action(m, ACT_FLY, 0)
            end
        end
    end
    if m.action & ACT_FLAG_AIR == 0 then
        gPlayerSyncTable[0].energyBar = 72
    end
end

function bee_hud()
    djui_hud_set_resolution(RESOLUTION_N64)

    if gPlayerSyncTable[0].activePowerup ~= BEE then return end
    djui_hud_render_texture(energyMeter[curEnergy].energy, xMid - 62, 4, 1, 1)
end

function act_fly(m)
    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        m.marioObj.header.gfx.angle.y = m.faceAngle.y
        return set_mario_action(m, ACT_DIVE, 0)
    end

    if (m.controller.buttonPressed & Z_TRIG) ~= 0 then
        m.vel.y = 0
        m.marioObj.header.gfx.angle.y = m.faceAngle.y
        return set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    if m.controller.buttonDown & A_BUTTON ~= 0 and gPlayerSyncTable[0].energyBar > 0 then
        m.vel.y = 10
        gPlayerSyncTable[0].energyBar = gPlayerSyncTable[0].energyBar - 1
    end

    common_air_action_step(m, ACT_JUMP_LAND, MARIO_ANIM_SLIDEFLIP,
        AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG)
    set_anim_to_frame(m, m.marioObj.header.gfx.animInfo.curAnim.loopEnd)
    m.marioObj.header.gfx.angle.y = m.faceAngle.y - 0x8000
end

hook_mario_action(ACT_FLY, { every_frame = act_fly })

hook_event(HOOK_MARIO_UPDATE, bee_update)
hook_event(HOOK_ON_HUD_RENDER_BEHIND, bee_hud)

-- Cat Powerup --

catsuit = false
didDive = false
local animFrame = 0
slowDownTimer = 0

E_MODEL_SUPER_BELL = smlua_model_util_get_id("super_bell_geo")

ACT_CAT_DIVE = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_MOVING |
    ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)
ACT_CAT_CLIMB = allocate_mario_action(ACT_FLAG_AIR | ACT_GROUP_AIRBORNE)
ACT_CAT_SLIDE = allocate_mario_action(ACT_FLAG_AIR | ACT_GROUP_AIRBORNE)

local function limit_angle(a)
    return (a + 0x8000) % 0x10000 - 0x8000
end

---@param obj Object
function bhv_superbell_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_SUPER_BELL)
    obj_scale(obj, 0.5)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768
    obj.oIntangibleTimer = 0
    obj.hitboxRadius = 120
    obj.hitboxHeight = 120
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_superbell_loop(obj)
    object_step()
    load_object_collision_model()
    local nreaetsplayertopwoerup = nearest_player_to_object(obj)
    if obj_check_hitbox_overlap(nreaetsplayertopwoerup, obj) then
        obj_mark_for_deletion(obj)
        gPlayerSyncTable[network_local_index_from_global(nreaetsplayertopwoerup.globalPlayerIndex)].activePowerup =
            CAT
    end
end

id_bhvSuperBell = hook_behavior(id_bhvMetalCap, OBJ_LIST_GENACTOR, true, bhv_superbell_init, bhv_superbell_loop)

---@param m MarioState
function cat_update(m)
    if m.playerIndex ~= 0 then return end
    if gPlayerSyncTable[0].activePowerup ~= CAT then return end
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
    if m.playerIndex ~= 0 then return end
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
        slowDownTimer = slowDownTimer + 1 / 10
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
    if m.playerIndex ~= 0 then return end
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
    if m.playerIndex ~= 0 then return end
    if m.pos.y - m.floorHeight < 150 then
        return set_mario_action(m, ACT_DIVE, 0)
    else
        m.vel.y = -10
    end
end

function act_cat_slide(m)
    if m.playerIndex ~= 0 then return end
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
    if m.playerIndex ~= 0 then return end
    m.vel.y = m.vel.y - 2

    if m.vel.y < -15 then
        m.vel.y = -15
    end
end

hook_event(HOOK_MARIO_UPDATE, cat_update)
hook_mario_action(ACT_CAT_CLIMB, { every_frame = act_cat_climb })
hook_mario_action(ACT_CAT_DIVE, { every_frame = act_cat_dive, gravity = act_cat_dive_gravity }, INT_FAST_ATTACK_OR_SHELL)
hook_mario_action(ACT_CAT_SLIDE, { every_frame = act_cat_slide, gravity = act_cat_slide_gravity })

mark_obj_for_deletion = obj_mark_for_deletion

function cloudbox(o)
    o.oCollisionDistance = 1400
    o.oFaceAnglePitch = 0
    o.oFaceAngleRoll = 0
    --o.globalPlayerIndex = (o.parentObj.globalPlayerIndex)
    --djui_chat_message_create(tostring(o.oTimer))
    if o.oTimer < 15 then
        o.header.gfx.scale.x = o.header.gfx.scale.x + 0.097;
        o.header.gfx.scale.y = o.header.gfx.scale.x;
        o.header.gfx.scale.z = o.header.gfx.scale.x;
        o.oFaceAngleYaw = o.oFaceAngleYaw + 0x0800;
    else
        if cur_obj_wait_then_blink(360, 20) ~= 0 or cur_obj_is_mario_ground_pounding_platform() == 1 then
            spawn_mist_particles_variable(0, -40.0, 46.0)
            mark_obj_for_deletion(o)
        else
            load_object_collision_model()
        end
    end
end

MODEL_CLOUDSPAWN = smlua_model_util_get_id("cloudspawn")

-- Function to check the cloud count
function checkCloudCount()
    local gMarioState = gMarioStates[0]
    local gMarioObject = gMarioState.marioObj
    local o

    if cloudcount > obj_count_objects_with_behavior_id(bhvCloudFollow) then
        oclou = spawn_object(gMarioObject, MODEL_CLOUDSPAWN, bhvCloudFollow)
        oclou.oHiddenBlueCoinSwitch = gMarioObject.oHiddenBlueCoinSwitch
        gMarioObject.oHiddenBlueCoinSwitch = oclou
        obj_scale(oclou, 0.3)
    end
end

-- Function for cloud following
local gapclose = 0.1
function cloudfollowing(o)
    local gMarioState = gMarioStates[0]
    local gMarioObject = gMarioState.marioObj
    --o.globalPlayerIndex = (o.parentObj.globalPlayerIndex)
    --obj_set_billboard(o)
    local x, y, z
    if gMarioObject.oHiddenBlueCoinSwitch == o then
        y = gMarioState.pos.y + 150
        x = gMarioState.pos.x + sins(gMarioState.faceAngle.y) * 50
        z = gMarioState.pos.z + coss(gMarioState.faceAngle.y) * 50
    elseif gMarioObject.oHiddenBlueCoinSwitch and (gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch == o) then
        y = gMarioObject.oHiddenBlueCoinSwitch.oPosY + 10
        x = gMarioObject.oHiddenBlueCoinSwitch.oPosX + sins(gMarioObject.oHiddenBlueCoinSwitch.oMoveAngleYaw) * 50
        z = gMarioObject.oHiddenBlueCoinSwitch.oPosZ + coss(gMarioObject.oHiddenBlueCoinSwitch.oMoveAngleYaw) * 50
    elseif gMarioObject.oHiddenBlueCoinSwitch and (gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch) then
        y = gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch.oPosY + 10
        x = gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch.oPosX +
            sins(gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch.oMoveAngleYaw) * 50
        z = gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch.oPosZ +
            coss(gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch.oMoveAngleYaw) * 50
    end
    o.oPosX = o.oPosX + (x - o.oPosX) * gapclose
    o.oPosY = o.oPosY + (y - o.oPosY) * gapclose
    o.oPosZ = o.oPosZ + (z - o.oPosZ) * gapclose
end

---@param obj Object
function bhv_cloudflower_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj.hitboxRadius = 80
    obj.hitboxHeight = 80
    obj.oIntangibleTimer = 0
    obj.oGravity = 3
    obj.oFaceAnglePitch = obj.oFaceAnglePitch + -16384
    obj.oGraphYOffset = 0
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_cloudflower_loop(obj)
    general_powerup_handler_DONT_SYNC(obj, CLOUD)
end

function cloud_powerup(m)
    checkCloudCount()
    --djui_chat_message_create(tostring(cloudcount))
    if m.playerIndex ~= 0 then return end
    local gMarioObject = m.marioObj
    --djui_chat_message_create(tostring(gMarioObject.oHiddenBlueCoinSwitch))
    if gPlayerSyncTable[0].activePowerup == CLOUD then
        local a
        if (m.action & ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION) ~= 0 then
            if (m.action & ACT_FLAG_INVULNERABLE) == 0 then
                if (m.controller.buttonPressed & A_BUTTON) ~= 0 then
                    if m.pos.y > m.floorHeight + 72 then
                        if (m.action ~= ACT_WALL_KICK_AIR) or (m.actionTimer > 1) then
                            if (m.action ~= ACT_FORWARD_ROLLOUT) and (m.action ~= ACT_FLYING_TRIPLE_JUMP) then
                                if cloudcount > 0 then
                                    spawn_sync_object(bhvCloudSpawn, MODEL_CLOUDSPAWN, m.pos.x,
                                        m.pos.y - 130, m.pos.z, nil)

                                    spawn_mist_particles_variable(0, -40.0, 46.0)
                                    m.vel.y = 30
                                    m.forwardVel = 0
                                    --[[gMarioState.inertia[1] = 0
                                    gMarioState.inertia[2] = 0
                                    gMarioState.inertia[3] = 0]]
                                    set_mario_action(m, ACT_FORWARD_ROLLOUT, 0)
                                    cloudcount = cloudcount - 1
                                    if cloudcount == 0 then
                                        --gPlayerSyncTable[0].powerup = NORMAL not in last impacT!!!!
                                        obj_mark_for_deletion(gMarioObject.oHiddenBlueCoinSwitch)
                                    elseif cloudcount == 1 then
                                        obj_mark_for_deletion(gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch)
                                    elseif cloudcount == 2 then
                                        obj_mark_for_deletion(gMarioObject.oHiddenBlueCoinSwitch.oHiddenBlueCoinSwitch
                                            .oHiddenBlueCoinSwitch)
                                    end
                                end
                            end
                        end
                    end
                end
            end
        end
    end
end

bhvCloudFlower = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_cloudflower_init, bhv_cloudflower_loop)
hook_event(HOOK_MARIO_UPDATE, cloud_powerup)

E_MODEL_ROCKET_POWERUP = smlua_model_util_get_id("rocket_powerup_geo")

---@param obj Object
function bhv_rocket_powerup_init(obj)
    obj.oFlags = OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE
    obj_set_model_extended(obj, E_MODEL_ROCKET_POWERUP)
    obj.oFaceAngleYaw = obj.oFaceAngleYaw - 32768
    obj.oIntangibleTimer = 0
    obj.hitboxRadius = 120
    obj.hitboxHeight = 120
    obj.oGravity = 3
    obj.oFriction = 0.8
    obj.oBuoyancy = 1
    network_init_object(obj, true, nil)
end

---@param obj Object
function bhv_rocket_powerup_loop(obj)
    general_powerup_handler(obj, ROCKET)
end

bhvRocketPowerup = hook_behavior(nil, OBJ_LIST_GENACTOR, true, bhv_rocket_powerup_init, bhv_rocket_powerup_loop)
