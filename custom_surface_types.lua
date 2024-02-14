SURFACE_BOUNCY_CUSTOM = 0x2
SURFACE_CANNON_CUSTOM = 0x6

function surface_check(m)
    if m.playerIndex ~= 0 then return end

    if m.floor and m.floor.type == SURFACE_BOUNCY_CUSTOM and m.floorHeight == m.pos.y then
        set_mario_action(m, ACT_DOUBLE_JUMP, 0)
        m.vel.y = 140
    end

    if m.floor and m.floor.type == SURFACE_CANNON_CUSTOM and m.floorHeight == m.pos.y then
        stuckHud = true
        stuck = true
    end
end

hook_event(HOOK_MARIO_UPDATE, surface_check)
