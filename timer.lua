-- Timer and bonus timer score --

timer = 0

function on_update()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) then
        timer = timer + 1 / 30
    else
        timer = 0
    end
end

function timerScore()
    if math.floor(timer) <= 300 then
        bonusScore = (300 - math.floor(timer)) * 64
    end
end

hook_event(HOOK_UPDATE, on_update)
hook_event(HOOK_UPDATE, timerScore)