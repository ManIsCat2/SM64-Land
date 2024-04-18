-- name: \\#FFFF00\\Super Mario 64 \\#00ff00\\Land
-- description: Awesome romhack by Kaze, Ported By I'mYourCat and xLuigiGamerx.\n\nCredits to:\nSteven\nSunk\nBlocky\nWoissil\nRushedAccN64
-- incompatible: romhack

m = gMarioStates[0]

local function mario_update(m)
    if m.playerIndex ~= 0 then return end
    m.numLives = 100
    vec3f_set(gLevelValues.starPositions.KingBobombStarPos, m.pos.x, m.pos.y + 200, m.pos.z) -- Makes the star spawn above the player like the romhack
end

--castle exit stuff

if m.numStars > 0 then
    gLevelValues.entryLevel = LEVEL_CASTLE_GROUNDS
else
    gLevelValues.entryLevel = LEVEL_CASTLE
end

gLevelValues.exitCastleLevel = LEVEL_CASTLE_GROUNDS
-- fix collisions being bad
gLevelValues.fixCollisionBugs = true
--fix  cap durations
gLevelValues.metalCapDurationCotmc = 1
gLevelValues.wingCapDurationTotwc = 1

--really needed
gServerSettings.stayInLevelAfterStar = true
gLevelValues.disableActs = true

camera_set_use_course_specific_settings(false)

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

hook_event(HOOK_MARIO_UPDATE, mario_update)

-- World Map Camera --
function world_map_cam(m)
    if m.playerIndex ~= 0 then return end
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) then return camera_unfreeze() end
    if m.action == ACT_READING_NPC_DIALOG or m.action == ACT_READING_SIGN then return camera_unfreeze() end
    gLakituState.curPos.y = m.pos.y + 4000
    gLakituState.curPos.z = 5000
end

--hook_event(HOOK_MARIO_UPDATE, world_map_cam)
