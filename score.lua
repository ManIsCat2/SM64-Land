-- Score --

score = 0
function enemyScore(m)

end

function coinScore(m)
    coinsBonus = m.numCoins * 50
end

hook_event(HOOK_MARIO_UPDATE, enemyScore)
hook_event(HOOK_MARIO_UPDATE, coinScore)
