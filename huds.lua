
local numStars = 0
local areaStarCount = 14

local TEX_SEPERATOR = get_texture_info("custom_hud_slash.rgba16")
local TEX_UNCOLLECTED_STAR = get_texture_info("hud_star_uncollected")
local TEX_UNCOLLECTED_STAR_100 = get_texture_info("hud_star_100_uncollected")
local TEX_SCORE = get_texture_info("hud_score")
local TEX_TIMER = get_texture_info("hud_timer")

function mario_update(m)
    numStars = m.numStars
    numCoins = m.numCoins
end

function lobby_hud()
    hud_hide()
    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_HUD)
    if numStars < 10 and numStars > -1 and numStars ~= nil then
        djui_hud_print_text("0"..tostring(numStars), 8, 4, 1)
    else
        djui_hud_print_text(tostring(numStars), 8, 4, 1)
    end
    djui_hud_render_texture(TEX_SEPERATOR, 28, 4, 1, 1)
    djui_hud_print_text(tostring(areaStarCount), 40, 4, 1)
    djui_hud_print_text("*", 68, 3, 1)
    djui_hud_print_text("*", djui_hud_get_screen_width() - 62, 4, 1)
    djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
    djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - 32, 4, 1)
end

function level_hud()
    hud_hide()
    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_HUD)

    djui_hud_render_texture(TEX_SCORE, 8, 4, 1, 1)
    djui_hud_print_text(tostring(score), 24, 4, 1)
    djui_hud_render_texture(TEX_UNCOLLECTED_STAR, ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
    djui_hud_render_texture(TEX_UNCOLLECTED_STAR, ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
    djui_hud_render_texture(TEX_UNCOLLECTED_STAR, ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
    djui_hud_render_texture(TEX_UNCOLLECTED_STAR_100, ((djui_hud_get_screen_width() / 2) - 24) + 42, 4, 1, 1)
    djui_hud_render_texture(TEX_TIMER, ((djui_hud_get_screen_width() / 2) + 46), 4, 1, 1)
    djui_hud_print_text(tostring(timer), djui_hud_get_screen_width() / 2 + 57, 4, 1)
    djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
    djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
    djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - 32, 4, 1)
end

function toad_house_hud()
    hud_hide()
    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_HUD)
    djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
    djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
    djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - 32, 4, 1)
end

function on_hud_render_behind()
    lobby_hud()
    level_hud()
    toad_house_hud()
end

hook_event(HOOK_ON_HUD_RENDER_BEHIND, on_hud_render_behind)
hook_event(HOOK_MARIO_UPDATE, mario_update)