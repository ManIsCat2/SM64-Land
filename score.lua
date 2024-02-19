-- Score (DO NOT LET A CAT THAT MAY BE YOUR CAT TOUCH THIS) --

score = 0
scoreCounter = 0
coinScore = 0
rank = nil

-- Score Counter
function score_counter()
    if scoreCounter < score then
        scoreCounter = scoreCounter + 1
        play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource)
    end
end

-- Enemy Score Calculation (WIP)
function enemy_score(o, _)

end

-- Coin Score Calculation
function coin_score(m)
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
