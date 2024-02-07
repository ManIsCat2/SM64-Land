-- Score --

score = 0
scoreAdder = 0

function enemyScore(o, _)

end

function coinScore(m)
    scoreAdder = hud_get_value(HUD_DISPLAY_COINS) * 50
    score = scoreAdder
end

hook_event(HOOK_ALLOW_INTERACT, enemyScore)
hook_event(HOOK_MARIO_UPDATE, coinScore)
