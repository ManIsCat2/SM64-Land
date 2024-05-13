-- Timer and bonus timer score --

timer = 0

function timer_update()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) then
        timer = math.floor(get_network_area_timer() / 30)
    else
        timer = 0
    end
end

function timer_score()
    local bonusScore = timer < 300 and (300 - math.floor(timer)) * 64
    return bonusScore
end

hook_event(HOOK_UPDATE, timer_update)