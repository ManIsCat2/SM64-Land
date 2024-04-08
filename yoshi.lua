-- Rideable Yoshi behavior.

local SOUND_YOSHI_FLUTTER_SHORT = audio_sample_load("flutter-short.mp3")
local SOUND_YOSHI_HIT = audio_sample_load("yoshi_hit.mp3")

define_custom_obj_fields(
    {
        oYoshiIdleTimer = "f32"
    }
)

function bhv_yoshi_rideable_init(obj)
    cur_obj_init_animation(0)
    obj.oFlags = (OBJ_FLAG_SET_FACE_YAW_TO_MOVE_YAW | OBJ_FLAG_UPDATE_GFX_POS_AND_ANGLE)
    obj.oGravity = -3
    obj.oFriction = 1

    obj.activeFlags = obj.activeFlags | ACTIVE_FLAG_UNK9
    cur_obj_scale(1)

    -- animations
    obj.oAnimations = gObjectAnimations.yoshi_seg5_anims_05024100
    obj.oFaceAnglePitch = 0x00
    obj.oFaceAngleRoll = 0x00
    obj.oAction = 0

    -- hitbox
    obj.oHealth = 1
    obj.oIntangibleTimer = 0

    obj.hitboxRadius = obj.header.gfx.scale.x * 50
    obj.hitboxHeight = obj.header.gfx.scale.y * 40

    -- start synchronizing object
    network_init_object(
        obj,
        true,
        {
            "oYoshiIdleTimer"
        }
    )
end

function bhv_yoshi_rideable_loop(o)
    o.oAnimState = 3
    local player = nearest_mario_state_to_object(o)
    local distanceToPlayer = dist_between_objects(o, player.marioObj)
    local rider = nil

    if o.oAction == 0 then -- Unridden.
        cur_obj_init_animation(0)
        o.oForwardVel = 0
        return bhv_yoshi_unridden(o)
    elseif o.oAction == 2 then
        cur_obj_init_animation_with_accel_and_sound(1, 3)
        cur_obj_play_sound_at_anim_range(0, 15, SOUND_GENERAL_YOSHI_WALK)
        o.oForwardVel = 30
        return bhv_yoshi_unridden(o)
    elseif o.oAction == 1 then -- Ridden.
        local animFrame = o.header.gfx.animInfo.animFrame
        rider = gMarioStates[o.heldByPlayerIndex]
        o.oYoshiIdleTimer = 0

        obj_copy_pos(o, rider.marioObj)
        rider.marioObj.header.gfx.animInfo.animFrame = o.header.gfx.animInfo.animFrame
        o.oMoveAngleYaw = rider.faceAngle.y
        o.oFaceAnglePitch = 0x00
        o.oFaceAngleRoll = 0x00

        if rider.action == ACT_RIDE_YOSHI_IDLE then
            cur_obj_init_animation(0)
        elseif rider.action == ACT_RIDE_YOSHI_WALK then
            cur_obj_init_animation_with_accel_and_sound(1, math.abs(rider.forwardVel) / 14)
            cur_obj_play_sound_at_anim_range(0, 15, SOUND_GENERAL_YOSHI_WALK)
        elseif rider.action == ACT_RIDE_YOSHI_JUMP then
            if rider.vel.y >= -21 then
                cur_obj_init_animation(2)
                if o.header.gfx.animInfo.animFrame >= 4 then
                    o.header.gfx.animInfo.animFrame = 4
                end
            else
                smlua_anim_util_set_animation(o, "YOSHI_FALL")
            end
        elseif rider.action == ACT_RIDE_YOSHI_FALL then
            smlua_anim_util_set_animation(o, "YOSHI_FALL_STATIC")
        elseif rider.action == ACT_RIDE_YOSHI_FLUTTER then
            smlua_anim_util_set_animation(o, "YOSHI_FLUTTER")
            if animFrame == 0 or animFrame == 3 then
                audio_sample_play(SOUND_YOSHI_FLUTTER_SHORT, rider.marioObj.header.gfx.cameraToObject, 1)
            end
        else
            mario_stop_riding_object(rider)
        end

        if (o.oInteractStatus & INT_STATUS_STOP_RIDING) ~= 0 then
            o.heldByPlayerIndex = 0
            if rider.hurtCounter ~= 0 then
                audio_sample_play(SOUND_YOSHI_HIT, rider.marioObj.header.gfx.cameraToObject, 1)
                o.oAction = 2
            else
                o.oAction = 0
            end
            o.oInteractStatus = 0
        end
    end
end

function bhv_yoshi_unridden(o)
    local player = nearest_mario_state_to_object(o)
    local distanceToPlayer = dist_between_objects(o, player.marioObj)
    local rider = nil

    o.oYoshiIdleTimer = o.oYoshiIdleTimer + 1
    cur_obj_move_standard(-78)
    cur_obj_update_floor_and_walls()
    cur_obj_if_hit_wall_bounce_away()
    if distanceToPlayer < 100 then
        lua_push_mario_out_of_object(player, o, 2)
    end

    if o.oYoshiIdleTimer >= 600 then
        spawn_mist_particles_with_sound(SOUND_OBJ_DYING_ENEMY1)
        obj_mark_for_deletion(o)
    end

    o.oInteractStatus = 0

    local yoshiRidingActions = {
        [ACT_RIDE_YOSHI_IDLE] = true,
        [ACT_RIDE_YOSHI_WALK] = true,
        [ACT_RIDE_YOSHI_JUMP] = true,
        [ACT_RIDE_YOSHI_FALL] = true,
        [ACT_RIDE_YOSHI_FLUTTER] = true,
        [ACT_FALL_AFTER_STAR_GRAB] = true
    }

    local yoshiGrabbingActions = {
        [ACT_PUNCHING] = true,
        [ACT_MOVE_PUNCHING] = true,
        [ACT_DIVE] = true,
        [ACT_DIVE_SLIDE] = true
    }

    if not yoshiRidingActions[player.action] then
        if
            (((player.action & ACT_FLAG_AIR) ~= 0 and (player.action & ACT_FLAG_SWIMMING_OR_FLYING) == 0 and
                player.vel.y <= 0) and
                distanceToPlayer < 85) or
                (((yoshiGrabbingActions[player.action]) and player.actionArg == 2) and distanceToPlayer < 100)
         then
            player.pos.x = o.oPosX
            player.pos.z = o.oPosZ
            player.faceAngle.y = o.oMoveAngleYaw
            cur_obj_play_sound_2(SOUND_GENERAL_YOSHI_TALK)
            player.interactObj = o
            player.usedObj = o
            player.riddenObj = o
            o.oAction = 1
            o.heldByPlayerIndex = player.playerIndex

            return set_mario_action(player, ACT_RIDE_YOSHI_IDLE, 0)
        end
    end
end

id_bhvYoshiRideable = hook_behavior(nil, OBJ_LIST_PUSHABLE, true, bhv_yoshi_rideable_init, bhv_yoshi_rideable_loop)
