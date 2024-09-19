SURFACE_BOUNCY_CUSTOM = 0x2
SURFACE_BOUNCY = 0xff
SURFACE_CANNON_CUSTOM = 0x6
SURFACE_ACID = 0xFD

bounceMultiplier = 1

local function limit_angle(a)
    return (a + 0x8000) % 0x10000 - 0x8000
end

function surface_check(m)
    if m.playerIndex ~= 0 then return end
    if m.floor ~= nil then
        if m.floor and m.floor.type == SURFACE_ACID then
            m.floor.type = SURFACE_BURNING
        end
        local slopeAngle = atan2s(m.floor.normal.z, m.floor.normal.x)

        if m.floor and (m.floor.type == SURFACE_BOUNCY_CUSTOM or m.floor.type == SURFACE_BOUNCY) and m.floorHeight == m.pos.y and m.action ~= ACT_STAR_DANCE_NO_EXIT then
            if m.action == ACT_GROUND_POUND_LAND then
                set_anim_to_frame(m, 0)
                set_mario_action(m, ACT_TRIPLE_JUMP, 0)
                m.vel.y = 140 * m.floor.normal.y
                if slopeAngle ~= 0 then
                    m.faceAngle.y = slopeAngle
                    mario_set_forward_vel(m, 80 / m.floor.normal.y)
                end
                bounceMultiplier = 3
            else
                set_anim_to_frame(m, 0)
                bounceMultiplier = bounceMultiplier < 3 and bounceMultiplier + math.abs(m.vel.y / 75) or 3
                set_mario_action(m, ACT_TRIPLE_JUMP, 0)
                m.vel.y = ((140 / 3) * (bounceMultiplier <= 3 and bounceMultiplier or 3)) * m.floor.normal.y
                set_mario_particle_flags(m, (PARTICLE_MIST_CIRCLE | PARTICLE_HORIZONTAL_STAR), 0)
            end
        end

        if m.action & ACT_FLAG_AIR == 0 then
            bounceMultiplier = 1
        else
            bounceMultiplier = bounceMultiplier > 3 and 3 or bounceMultiplier
        end

        if m.floor and m.floor.type == SURFACE_CANNON_CUSTOM and m.floorHeight == m.pos.y then
            stuckHud = true
            stuck = true
        end
    end
end

hook_event(HOOK_MARIO_UPDATE, surface_check)
