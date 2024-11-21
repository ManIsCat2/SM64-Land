gPlayerSyncTable[0].score = 0
gPlayerSyncTable[0].scoreHUD = 0

local gScores = {
    enemybouncescore = 200,
    coinscore = 50,
    coinscoreBlue = 100,
}
local function add_to_score(amount)
    gPlayerSyncTable[0].score = gPlayerSyncTable[0].score + amount
end
local function on_interact(m, o, interactType, interactValue)
    if m.playerIndex ~= 0 then return end

    if interactType == INTERACT_BOUNCE_TOP and o.oInteractStatus & INT_STATUS_WAS_ATTACKED ~= 0 then
        add_to_score(gScores.enemybouncescore)
    end

    if interactType == INTERACT_COIN then
        if obj_has_behavior_id(o, id_bhvYellowCoin) ~= 0 or obj_has_behavior_id(o, id_bhvOneCoin) ~= 0 or obj_has_behavior_id(o, id_bhvTemporaryYellowCoin) ~= 0 or obj_has_behavior_id(o, id_bhvRedCoin) ~= 0 then
            add_to_score(gScores.coinscore)
        end

        if obj_has_behavior_id(o, id_bhvHiddenBlueCoin) ~= 0 or obj_has_behavior_id(o, id_bhvBlueCoinJumping) ~= 0 or obj_has_behavior_id(o, id_bhvBlueCoinSliding) ~= 0 or obj_has_behavior_id(o, id_bhvMovingBlueCoin) ~= 0 then
            add_to_score(gScores.coinscoreBlue)
        end
    end
end

function update_hud_score()
   -- djui_chat_message_create("" .. gPlayerSyncTable[0].score)
    if gPlayerSyncTable[0].scoreHUD ~= gPlayerSyncTable[0].score then
        gPlayerSyncTable[0].scoreHUD = approach_f32_symmetric(gPlayerSyncTable[0].scoreHUD, gPlayerSyncTable[0].score, 5)
        play_sound(SOUND_MENU_YOSHI_GAIN_LIVES, gGlobalSoundSource)
    end
end

hook_event(HOOK_ON_INTERACT, on_interact)
hook_event(HOOK_UPDATE, update_hud_score)
