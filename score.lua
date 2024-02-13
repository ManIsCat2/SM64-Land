-- Score (DO NOT LET A CAT THAT MAY BE YOUR CAT TOUCH THIS) --

score = 0
scoreCounter = 0
coinScore = 0

-- Score Counter
function score_counter()
    if scoreCounter < score then
        scoreCounter = scoreCounter + 1
    end
end

-- Enemy Score Calculation (WIP)
function enemy_score(o, _)

end

-- Coin Score Calculation
function coin_score(m)
    if m.controller.buttonPressed == X_BUTTON then
        play_sound(SOUND_GENERAL_SWISH_WATER, m.marioObj.header.gfx.cameraToObject)
    end
    if m.playerIndex ~= 0 then return end
    coinScore = m.numCoins * 50
end

-- Final Score Calculation (Final Star Collection Screen)
function final_score()

end

hook_event(HOOK_UPDATE, score_counter)
hook_event(HOOK_ALLOW_INTERACT, enemy_score)
hook_event(HOOK_MARIO_UPDATE, coin_score)
hook_event(HOOK_UPDATE, final_score)
