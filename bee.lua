-- Bee Powerup --

E_MODEL_BEE_SHROOM = smlua_model_util_get_id("bee_shroom_geo")

ACT_FLY = allocate_mario_action(ACT_GROUP_AIRBORNE | ACT_FLAG_AIR | ACT_FLAG_ALLOW_VERTICAL_WIND_ACTION)

local energyBar = 72 -- 2.4 Seconds

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
    {energy = EMPTY_ENERGY},
    {energy = TWO_ENERGY},
    {energy = THREE_ENERGY},
    {energy = FOUR_ENERGY},
    {energy = FIVE_ENERGY},
    {energy = SIX_ENERGY},
    {energy = SEVEN_ENERGY},
    {energy = EIGHT_ENERGY},
    {energy = NINE_ENERGY},
    {energy = TEN_ENERGY},
    {energy = ELEVEN_ENERGY},
    {energy = FULL_ENERGY}
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
    if math.ceil((energyBar / 12) * 2) ~= 0 then
        curEnergy = math.ceil((energyBar / 12) * 2)
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
    --spawn_sync_object(id_bhvSparkleParticleSpawner, E_MODEL_SPARKLES, obj.oPosX, obj.oPosY, obj.oPosZ, nil) doesn't work as of currently
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
    object_step()
    load_object_collision_model()
    obj.oFaceAngleYaw = obj.oFaceAngleYaw + ((65536/360) * 1.5)
    local m = gMarioStates[0]
    if obj_check_hitbox_overlap(m.marioObj,obj) then
        obj_mark_for_deletion(obj)
        activePowerup = BEE
    end
end

id_bhvBeeShroom = hook_behavior(id_bhvVanishCap, OBJ_LIST_GENACTOR, true, bhv_beesuit_init, bhv_beesuit_loop)

---@param m MarioState
function bee_update(m)
    if m.playerIndex ~= 0 then return end
    if activePowerup ~= BEE then return end
    if m.vel.y <= 0 and m.action & ACT_FLAG_AIR ~= 0 and energyBar > 0 and (m.action ~= ACT_FAKE_FREEFALL and m.action ~= ACT_WALL_SLIDE and not common_blacklisted_actions[m.action]) then
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
        energyBar = 72
    end
end

function bee_hud()
    djui_hud_set_resolution(RESOLUTION_N64)

    if activePowerup ~= BEE then return end
    djui_hud_render_texture(energyMeter[curEnergy].energy, xMid - 62, 4, 1, 1)
end

function act_fly(m)
    if m.playerIndex ~= 0 then return end
    if m.controller.buttonPressed & B_BUTTON ~= 0 then
        m.marioObj.header.gfx.angle.y = m.faceAngle.y
        return set_mario_action(m, ACT_DIVE, 0)
    end

    if (m.controller.buttonPressed & Z_TRIG) ~= 0 then
        m.vel.y = 0
        m.marioObj.header.gfx.angle.y = m.faceAngle.y
        return set_mario_action(m, ACT_GROUND_POUND, 0)
    end

    if m.controller.buttonDown & A_BUTTON ~= 0 and energyBar > 0 then
        m.vel.y = 10
        energyBar = energyBar - 1
    end

    common_air_action_step(m, ACT_JUMP_LAND, MARIO_ANIM_SLIDEFLIP,
    AIR_STEP_CHECK_LEDGE_GRAB | AIR_STEP_CHECK_HANG)
    set_anim_to_frame(m, m.marioObj.header.gfx.animInfo.curAnim.loopEnd)
    m.marioObj.header.gfx.angle.y = m.faceAngle.y - 0x8000
end

hook_mario_action(ACT_FLY, { every_frame = act_fly })

hook_event(HOOK_MARIO_UPDATE, bee_update)
hook_event(HOOK_ON_HUD_RENDER_BEHIND, bee_hud)
