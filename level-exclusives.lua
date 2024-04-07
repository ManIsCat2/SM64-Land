function level_1_3(m)
    if m.action & ACT_FLAG_AIR ~= 0 and gNetworkPlayers[0].currLevelNum == LEVEL_WF and gNetworkPlayers[0].currAreaIndex == 2 and m.action ~= ACT_TWIRLING then
        m.vel.y = m.vel.y + 1.2
    end
end

hook_event(HOOK_MARIO_UPDATE, level_1_3)
