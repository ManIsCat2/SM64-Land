-- name: Super Mario 64 Land
-- description:
-- incompatible: romhack

gLevelValues.entryLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.exitCastleLevel = LEVEL_CASTLE_GROUNDS
gLevelValues.disableActs = true

camera_set_use_course_specific_settings(false)

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

---@param m MarioState
function surfaces(m)
    if m.floor.type == 0x2 and m.floorHeight == m.pos.y then
        m.health = 0
    end
end

hook_event(HOOK_MARIO_UPDATE, surfaces)

