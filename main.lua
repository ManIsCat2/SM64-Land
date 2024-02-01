-- name: Super Mario 64 Land
-- description: Awesome romhack by Kaze, Ported By I'mYourCat.
-- incompatible: romhack

gLevelValues.entryLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.exitCastleLevel = LEVEL_CASTLE_GROUNDS
--gLevelValues.disableActs = true

vec3f_set(gLevelValues.starPositions.KingBobombStarPos, 0, 70, 0)

camera_set_use_course_specific_settings(false)

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

