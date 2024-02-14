-- Hud Types --

local curWorld = 1
worldSelected = 1
warpsforlevels = {
    { level = 16, area = 1, warpid = 11 },
    { level = 26, area = 1, warpid = 11 },
}

local xCursorIndex = 1
local yCursorIndex = 1
local stickMoved = false

curWorldStars = 0
worldsUnlocked = 1

function worldCheck()
    if gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_GROUNDS) then
        if gNetworkPlayers[0].currAreaIndex == 1 then
            curWorld = 1
        elseif gNetworkPlayers[0].currAreaIndex == 2 then
            curWorld = 3
        elseif gNetworkPlayers[0].currAreaIndex == 3 then
            curWorld = 5
        elseif gNetworkPlayers[0].currAreaIndex == 4 then
            curWorld = 7
        end
    elseif gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) then
        if gNetworkPlayers[0].currAreaIndex == 1 then
            curWorld = 2
        elseif gNetworkPlayers[0].currAreaIndex == 2 then
            curWorld = 4
        elseif gNetworkPlayers[0].currAreaIndex == 3 then
            curWorld = 6
        elseif gNetworkPlayers[0].currAreaIndex == 4 then
            curWorld = 8
        end
    end
end

function world_unlocked(world)
    if world == 1 then
        return true
    end

    if world == 2 then
        if operation(COURSE_BOB, 3) == gTextures.star then
            return true
        else
            return false
        end
    end
end

function worlds_unlocked()
    if world_unlocked(2)  then
        worldsUnlocked = worldsUnlocked + 1
    end
    return worldsUnlocked
end

local TEX_SEPERATOR = get_texture_info("custom_hud_slash.rgba16")
TEX_UNCOLLECTED_STAR = get_texture_info("hud_star_uncollected") -- DO NOT LOCALIZE
TEX_UNCOLLECTED_STAR_100 = get_texture_info("hud_star_100_uncollected")
local TEX_SCORE = get_texture_info("hud_score")
local TEX_TIMER = get_texture_info("hud_timer")

-- World Specific Hud Stars
local TEX_WORLD_2_STAR = get_texture_info("hud_star_world_2")

local worldSpecific = {
    { "World 1", 14, nil },
    { "World 2", 16, TEX_WORLD_2_STAR },
    { "World 3", 15 },
    { "World 4", 15 },
    { "World 5", 16 },
    { "World 6", 14 },
    { "World 7", 14 },
    { "World 8", 18 },
}

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
        djui_hud_print_text(string.format("%.02d", curWorldStars), 8, 4, 1)
        djui_hud_render_texture(TEX_SEPERATOR, 28, 4, 1, 1)
        if curWorld ~= nil then
            djui_hud_print_text(tostring(worldSpecific[curWorld][2]), 40, 4, 1)
        else
            djui_hud_print_text("NIL", 40, 4, 1)
        end
        if worldSpecific[curWorld][3] == nil then
            djui_hud_print_text("*", 68, 3, 1)
        else
            djui_hud_render_texture(worldSpecific[curWorld][3], 68, 3, 1, 1)
        end
        djui_hud_print_text("*", djui_hud_get_screen_width() - 62, 4, 1)
        djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - 32, 4, 1)
    end
end

function level_hud()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_COTMC) and (gNetworkPlayers[0].currLevelNum == LEVEL_BOB and gNetworkPlayers[0].currAreaIndex ~= 3) then

        djui_hud_render_texture(TEX_SCORE, 8, 4, 1, 1)
        djui_hud_print_text(string.format(("%.05d"), math.floor(scoreCounter)), 24, 4, 1)
        if gNetworkPlayers[0].currLevelNum == LEVEL_BOB and gNetworkPlayers[0].currAreaIndex == 1 then
            djui_hud_render_texture(operation(COURSE_BOB, 0), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 2), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 1), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_BOB, 6, true), ((djui_hud_get_screen_width() / 2) - 24) + 42, 4, 1, 1)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_WF and gNetworkPlayers[0].currAreaIndex == 1 then
            djui_hud_render_texture(operation(COURSE_WF, 2), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_WF, 1), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_WF, 0), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_WF and gNetworkPlayers[0].currAreaIndex == 2 then
            djui_hud_render_texture(operation(COURSE_WF, 5), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_WF, 4), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_CCM and gNetworkPlayers[0].currAreaIndex == 1 then
            djui_hud_render_texture(operation(COURSE_CCM, 0), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_CCM, 1), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_CCM, 2), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
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
        djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
        djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - 32, 4, 1)
    end
end

-- Still WIP
function cannon_hud()
   -- djui_chat_message_create(tostring(xCursorIndex))
    if stuck == false then
        xCursorIndex = 1
        yCursorIndex = 1
    end
    if not stuckHud then return end
    m = gMarioStates[0]
    if m.playerIndex ~= 0 then return end

    if m.controller.stickX > 0 and not stickMoved and world_unlocked(xCursorIndex + 1) then
        xCursorIndex = xCursorIndex + 1
        stickMoved = true
    end

    if m.controller.stickX == 0 and stickMoved then
        stickMoved = false
    end

    if m.controller.stickX < 0 and not stickMoved and world_unlocked(xCursorIndex - 1) then
        xCursorIndex = xCursorIndex - 1
        stickMoved = true
    end

    if xCursorIndex == 0 then
        xCursorIndex = worlds_unlocked()
    end

    if xCursorIndex == (worlds_unlocked() + 1) then
        xCursorIndex = 1
    end

    worldSelected = xCursorIndex * yCursorIndex

    djui_hud_print_text("Warp", (djui_hud_get_screen_width() / 2) - 42, 48, 1)
    djui_hud_print_text("To", (djui_hud_get_screen_width() / 2) + 20, 48, 1)
    if xCursorIndex == 1 then
        djui_hud_print_text("@", (djui_hud_get_screen_width() / 2) - 122, 71, 1)
    elseif xCursorIndex == 2 then
        djui_hud_print_text("@", (djui_hud_get_screen_width() / 2) + 8, 71, 1)
    end
    djui_hud_print_text("World 1", (djui_hud_get_screen_width() / 2) - 106, 71, 1)
    if world_unlocked(2) then
        djui_hud_print_text("World 2", (djui_hud_get_screen_width() / 2) + 24, 71, 1)
    end
end

-- Power Meter display (EXTREMELY WIP)
--function power_meter()
    --if gMarioStates[0].health <= 2047 then
        --hud_render_power_meter(gMarioStates[0].health, (djui_hud_get_screen_width() / 2) - 74, 13, 64, 64)
        --(djui_hud_get_screen_width() / 2) - 74, 21,
    --end
--end

function on_hud_render_behind()
    hud_hide()
    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_HUD)
    lobby_hud()
    level_hud()
    toad_house_hud()
    cannon_hud()
    --power_meter()

    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_LIVES)
    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_COIN_COUNT)
    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_TIMER)
    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_STAR_COUNT)
    hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_CAMERA)
end

--hook_event(HOOK_UPDATE, power_meter)
hook_event(HOOK_ON_HUD_RENDER_BEHIND, on_hud_render_behind)
hook_event(HOOK_MARIO_UPDATE, mario_update)
hook_event(HOOK_UPDATE, worldCheck)
