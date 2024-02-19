-- Hud Types --

curWorld = 1
worldSelected = 1
warpsforlevels = {
    { level = 16, area = 1, warpid = 11 },
    { level = 26, area = 1, warpid = 11 },
}

local xCursorIndex = 1
local yCursorIndex = 1
local stickMoved = false

function get_center_offset()
    djui_hud_set_resolution(RESOLUTION_N64)
    xMid = djui_hud_get_screen_width() / 2
    yOff = 16
end

hook_event(HOOK_UPDATE, get_center_offset)

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
        if operation(COURSE_JRB, 0) == gTextures.star then
            return true
        else
            return false
        end
    end

    -- WIP Worlds --

    if world == 3 then
        return false
    end
    if world == 4 then
        return false
    end
    if world == 5 then
        return false
    end
    if world == 6 then
        return false
    end
    if world == 7 then
        return false
    end
    if world == 8 then
        return false
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

    -- Normal Stars

local TEX_WORLD_2_STAR = get_texture_info("hud_star_world_2")
local TEX_WORLD_3_STAR = get_texture_info("hud_star_world_3")
local TEX_WORLD_4_STAR = get_texture_info("hud_star_world_4")
local TEX_WORLD_5_STAR = get_texture_info("hud_star_world_5")
local TEX_WORLD_6_STAR = get_texture_info("hud_star_world_6")
local TEX_WORLD_7_STAR = get_texture_info("hud_star_world_7")
local TEX_WORLD_8_STAR = get_texture_info("hud_star_world_8")

    -- P Stars

local TEX_P_WORLD_2_STAR = get_texture_info("hud_star_p_world_2")
local TEX_P_WORLD_3_STAR = get_texture_info("hud_star_p_world_3")
local TEX_P_WORLD_4_STAR = get_texture_info("hud_star_p_world_4")
local TEX_P_WORLD_5_STAR = get_texture_info("hud_star_p_world_5")
local TEX_P_WORLD_6_STAR = get_texture_info("hud_star_p_world_6")
local TEX_P_WORLD_7_STAR = get_texture_info("hud_star_p_world_7")
local TEX_P_WORLD_8_STAR = get_texture_info("hud_star_p_world_8")

local worldSpecific = {
    { "World 1", 14, nil, nil },
    { "World 2", 16, TEX_WORLD_2_STAR, TEX_P_WORLD_2_STAR },
    { "World 3", 15, TEX_WORLD_3_STAR, TEX_P_WORLD_3_STAR },
    { "World 4", 15, TEX_WORLD_4_STAR, TEX_P_WORLD_4_STAR },
    { "World 5", 16, TEX_WORLD_5_STAR, TEX_P_WORLD_5_STAR },
    { "World 6", 14, TEX_WORLD_6_STAR, TEX_P_WORLD_6_STAR },
    { "World 7", 14, TEX_WORLD_7_STAR, TEX_P_WORLD_7_STAR },
    { "World 8", 18, TEX_WORLD_8_STAR, TEX_P_WORLD_8_STAR },
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
        if numStars < 100 then
            djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
            djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - 32, 4, 1)
        else
            djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - 46, 4, 1)
        end
    end
end

function level_hud()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_COTMC) --[[and (gNetworkPlayers[0].currLevelNum == LEVEL_BOB and gNetworkPlayers[0].currAreaIndex ~= 3)]] then

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
            djui_hud_render_texture(operation(COURSE_CCM, 2), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_CCM, 1), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_CCM, 0), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
        end

        if gNetworkPlayers[0].currLevelNum == LEVEL_JRB and gNetworkPlayers[0].currAreaIndex == 1 then
            djui_hud_render_texture(operation(COURSE_JRB, 2), ((djui_hud_get_screen_width() / 2) - 24), 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_JRB, 1), ((djui_hud_get_screen_width() / 2) - 24) + 14, 4, 1, 1)
            djui_hud_render_texture(operation(COURSE_JRB, 0), ((djui_hud_get_screen_width() / 2) - 24) + 28, 4, 1, 1)
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
    
    if m.controller.stickX == 0 and m.controller.stickY == 0 and stickMoved then
        stickMoved = false
    end

    if m.controller.stickX > 0 and not stickMoved then
        xCursorIndex = xCursorIndex + 1
        if xCursorIndex > 2 then
            xCursorIndex = 1
        end
        stickMoved = true
    end

    if m.controller.stickX < 0 and not stickMoved then
        xCursorIndex = xCursorIndex - 1
        if xCursorIndex < 1 then
            xCursorIndex = 2
        end
        stickMoved = true
    end

    if m.controller.stickY < 0 and not stickMoved then
        if yCursorIndex > math.ceil(worlds_unlocked() / 2) then return end
        yCursorIndex = yCursorIndex + 1
        if yCursorIndex > 4 then
            yCursorIndex = 1
        end
        stickMoved = true
    end

    if m.controller.stickY > 0 and not stickMoved then
        yCursorIndex = yCursorIndex - 1
        if yCursorIndex < 1 then
            yCursorIndex = 4
        end
        stickMoved = true
    end

    if xCursorIndex == 0 then
        xCursorIndex = worlds_unlocked()
    end

    if xCursorIndex == (worlds_unlocked() + 1) then
        xCursorIndex = 1
    end

    if xCursorIndex == 2 then
        worldSelected = xCursorIndex * yCursorIndex
    else
        worldSelected = ((xCursorIndex + 1) * yCursorIndex) - 1
    end
    yCursorOffset = 72 + ((yOff * yCursorIndex) - 16)

    djui_hud_print_text("Warp", xMid - 42, 48, 1)
    djui_hud_print_text("To", xMid + 20, 48, 1)
    if xCursorIndex == 1 then
        djui_hud_print_text("@", xMid - 122, yCursorOffset, 1)
    elseif xCursorIndex == 2 then
        djui_hud_print_text("@", xMid + 8, yCursorOffset, 1)
    end
    djui_hud_print_text("World 1", xMid - 106, 72, 1)
    if world_unlocked(2) then
        djui_hud_print_text("World 2", xMid + 24, 72, 1)
    end

    -- Doesn't show up since it's not done yet

    if world_unlocked(3) then
        djui_hud_print_text("World 3", xMid - 106, 72 + yOff, 1)
    end
    if world_unlocked(4) then
        djui_hud_print_text("World 4", xMid + 24, 72 + yOff, 1)
    end
    if world_unlocked(5) then
        djui_hud_print_text("World 5", xMid - 106, 72 + (yOff * 2), 1)
    end
    if world_unlocked(6) then    
        djui_hud_print_text("World 6", xMid + 24, 72 + (yOff * 2), 1)
    end
    if world_unlocked(7) then
        djui_hud_print_text("World 7", xMid - 106, 72 + (yOff * 3), 1)
    end
    if world_unlocked(8) then
        djui_hud_print_text("World 8", xMid + 24, 72 + (yOff * 3), 1)
    end
end

-- Power Meter display (EXTREMELY WIP)
--function power_meter()
    --if gMarioStates[0].health <= 2047 then
        --hud_render_power_meter(gMarioStates[0].health, xMid - 74, 13, 64, 64)
        --xMid - 74, 21,
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
