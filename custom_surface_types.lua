SURFACE_BOUNCY_CUSTOM = 0x2
SURFACE_CANNON_CUSTOM = 0x6

bounceMultiplier = 1

function surface_check(m)
    if m.playerIndex ~= 0 then return end

    if m.floor and m.floor.type == SURFACE_BOUNCY_CUSTOM and m.floorHeight == m.pos.y then
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

    if m.action & ACT_FLAG_AIR == 0 then
        bounceMultiplier = 1
    end

    if m.floor and m.floor.type == SURFACE_CANNON_CUSTOM and m.floorHeight == m.pos.y then
        stuckHud = true
        stuck = true
    end
end

hook_event(HOOK_MARIO_UPDATE, surface_check)
