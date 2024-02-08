local areaStarCount = 14

local TEX_SEPERATOR = get_texture_info("custom_hud_slash.rgba16")
local TEX_UNCOLLECTED_STAR = get_texture_info("hud_star_uncollected")
local TEX_UNCOLLECTED_STAR_100 = get_texture_info("hud_star_100_uncollected")
local TEX_SCORE = get_texture_info("hud_score")
local TEX_TIMER = get_texture_info("hud_timer")

function operation(course, star, is100star)
    courseReal = course - 1
    starflags = save_file_get_star_flags(get_current_save_file_num() - 1, courseReal)
    if starflags & (1 << star) ~= 0 then
        return gTextures.star
    else
        if is100star then
            return TEX_UNCOLLECTED_STAR_100
        else
            return TEX_UNCOLLECTED_STAR
        end
    end
end

function mario_update(m)
    numStars = hud_get_value(HUD_DISPLAY_STARS)
    numCoins = hud_get_value(HUD_DISPLAY_COINS)
end

function lobby_hud()
    if gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_GROUNDS) or gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) then
        djui_hud_set_resolution(RESOLUTION_N64)
        djui_hud_set_font(FONT_HUD)

        if numStars ~= nil then -- here to stop errors
            djui_hud_print_text(string.format("%.02d", numStars), 8, 4, 1)
        end
        djui_hud_render_texture(TEX_SEPERATOR, 28, 4, 1, 1)
        djui_hud_print_text(tostring(areaStarCount), 40, 4, 1)
        djui_hud_print_text("*", 68, 3, 1)
        djui_hud_print_text("*", djui_hud_get_screen_width() - 62, 4, 1)
        djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - 32, 4, 1)
    end
end

function level_hud()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) then
        djui_hud_set_resolution(RESOLUTION_N64)
        djui_hud_set_font(FONT_HUD)

        djui_hud_render_texture(TEX_SCORE, 8, 4, 1, 1)
        djui_hud_print_text(string.format(("%.05d"), math.floor(score)), 24, 4, 1)
        if gNetworkPlayers[0].currLevelNum == LEVEL_BOB then
            djui_hud_render_texture(operation(COURSE_BOB, 0), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 1), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 2), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 6, true), ((djui_hud_get_screen_width() / 2) - 24) + 42, 4, 1, 1)
        end
        djui_hud_render_texture(TEX_TIMER, ((djui_hud_get_screen_width() / 2) + 46), 4, 1, 1)
        djui_hud_print_text(string.format(("%.03d"), math.floor(timer)), djui_hud_get_screen_width() / 2 + 57, 4, 1)
        djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
        djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - 32, 4, 1)
    end
end

function toad_house_hud()
    if gNetworkPlayers[0].currLevelNum == (LEVEL_COTMC) then
        djui_hud_set_resolution(RESOLUTION_N64)
        djui_hud_set_font(FONT_HUD)
        djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
        djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - 32, 4, 1)
    end
end

function tutorial_hud()
    hud_hide()
end
function on_hud_render_behind()
    hud_hide()
    lobby_hud()
    level_hud()
    toad_house_hud()
    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) | HUD_DISPLAY_FLAG_POWER)
end

hook_event(HOOK_ON_HUD_RENDER_BEHIND, on_hud_render_behind)
hook_event(HOOK_MARIO_UPDATE, mario_update)
