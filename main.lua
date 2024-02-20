-- name: Super Mario 64 Land
-- description: Awesome romhack by Kaze, Ported By I'mYourCat and xLuigiGamerx.
-- incompatible: romhack

m = gMarioStates[0]

function inf_lives(m)
    m.numLives = 100
end

if m.numStars > 0 then
    gLevelValues.entryLevel = LEVEL_CASTLE_GROUNDS
else
    gLevelValues.entryLevel = LEVEL_CASTLE
end

gLevelValues.exitCastleLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.fixCollisionBugs = true
gLevelValues.metalCapDurationCotmc = 1

--really needed
gServerSettings.stayInLevelAfterStar = true
gLevelValues.disableActs = true

vec3f_set(gLevelValues.starPositions.KingBobombStarPos, 0, 70, 0)

camera_set_use_course_specific_settings(false)

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

hook_event(HOOK_MARIO_UPDATE, inf_lives)
