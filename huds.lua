-- Hud Types --

local powerTimer = 45
local Py = 5 - 100
local prevPy = 5 - 100

curWorld = 1
starPower = 0
worldSelected = 1
warpsforlevels = {
    { level = 16, area = 1, warpid = 11 },
    { level = 26, area = 1, warpid = 11 },
    { level = 16, area = 2, warpid = 11 },
}

--[[
    Level values for optimization
    if a level uses more than 1 area just add another table to it with the index of the area id
    boss areas don't count
]]
levelData = {
    [COURSE_BOB] = { { stars = { 0, 2, 1, 6 }, coinStar = 6, finalStar = 1 }, { stars = { 4, 5 }, finalStar = 5 }, { stars = {}, finalStar = nil } },
    [COURSE_WF] = { { stars = { 2, 1, 0 }, finalStar = 0 }, { stars = { 5, 4 }, finalStar = 4 } },
    [COURSE_CCM] = { { stars = { 2, 1, 0 }, finalStar = 0 }, { stars = { 4, 3, 6 }, finalStar = 3 }, { stars = {}, finalStar = nil } },
    [COURSE_JRB] = { { stars = { 2, 1, 0 }, finalStar = 0 }, { stars = { 3, 5, 4 }, finalStar = 4 } },
    [COURSE_BBH] = { { stars = { 1, 2, 0 }, finalStar = 0 } },
    [COURSE_HMC] = { { stars = { 0, 1, 2 }, finalStar = 2 }, { stars = { 5, 4, 3 }, finalStar = 3 } },
    [COURSE_LLL] = { { stars = {}, finalStar = nil } },
    [COURSE_SSL] = { { stars = { 1, 2, 0 }, finalStar = 0 } },
    [COURSE_TTM] = { { stars = { 1, 2 }, finalStar = 2 }, { stars = { 3, 4 }, finalStar = 4 } },
    [COURSE_TTC] = { { stars = { 0 }, finalStar = 0 }, },
    [COURSE_SL] = { { stars = { 5, 4, 3 }, finalStar = 3 }, { stars = { 1, 0 }, finalStar = 0 } },
    [COURSE_THI] = { { stars = { 1, 0 }, finalStar = 0 }, { stars = { 4, 5 }, finalStar = 5 } },
    [COURSE_DDD] = { { stars = { 1, 0 }, finalStar = 0 }, { stars = { 3, 4, 5, 6 }, coinStar = 6, finalStar = 4 }, },
    [COURSE_BITFS] = { { stars = { 1, 0, 2 }, finalStar = 2 } },
    [COURSE_WDW] = { { stars = { 1, 0, 2, 3 }, finalStar = 3 } },
}

bossLevelData = {
    [COURSE_BOB] = { [3] = true },
    [COURSE_CCM] = { [3] = true },
    [COURSE_SSL] = { [3] = true },
    [COURSE_BITFS] = { [2] = true },
    [COURSE_BITDW] = { [1] = true },
}

championsRoadLevlData = {
    [COURSE_BOB] = { [4] = true },
    [COURSE_JRB] = { [3] = true },
    [COURSE_BBH] = { [2] = true },
    [COURSE_WDW] = { [3] = true },
    [COURSE_HMC] = { [3] = true },
    [COURSE_TTM] = { [3] = true },
    [COURSE_THI] = { [3] = true },
    [COURSE_BITFS] = { [3] = true },
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
        return operation(COURSE_JRB, 0) == gTextures.star
    end

    if world == 3 then
        return operation(COURSE_CCM, 5) == gTextures.star
    end

    -- WIP Worlds --

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
    for i = 1, 8 do
        worldsUnlocked = world_unlocked(i) and worldsUnlocked + 1 or worldsUnlocked
    end
    return worldsUnlocked
end

TEX_SEPERATOR = get_texture_info("custom_hud_slash.rgba16")
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
    { "World 1", stars = 14, nil,                         nil },
    { "World 2", stars = 16, starIcon = TEX_WORLD_2_STAR, starPowerIcon = TEX_P_WORLD_2_STAR },
    { "World 3", stars = 15, starIcon = TEX_WORLD_3_STAR, starPowerIcon = TEX_P_WORLD_3_STAR },
    { "World 4", stars = 15, starIcon = TEX_WORLD_4_STAR, starPowerIcon = TEX_P_WORLD_4_STAR },
    { "World 5", stars = 16, starIcon = TEX_WORLD_5_STAR, starPowerIcon = TEX_P_WORLD_5_STAR },
    { "World 6", stars = 14, starIcon = TEX_WORLD_6_STAR, starPowerIcon = TEX_P_WORLD_6_STAR },
    { "World 7", stars = 14, starIcon = TEX_WORLD_7_STAR, starPowerIcon = TEX_P_WORLD_7_STAR },
    { "World 8", stars = 18, starIcon = TEX_WORLD_8_STAR, starPowerIcon = TEX_P_WORLD_8_STAR },
}

--- Returns the hud texture for the star if it's was collected, otherwise returns an uncollected star texture
---@param course integer
---@param star integer
---@param is100star boolean|nil
---@return TextureInfo
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
    starPower = get_star_count() / curWorld
    if gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_GROUNDS) or gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) then
        -- World Star Counter

        djui_hud_print_text(string.format("%.02d", get_world_star_count(curWorld)), 8, 4, 1)
        djui_hud_render_texture(TEX_SEPERATOR, 28, 4, 1, 1)
        djui_hud_print_text(tostring(curWorld and worldSpecific[curWorld].stars or 0), 40, 4, 1)

        starIcon = worldSpecific[curWorld].starIcon
        djui_hud_render_texture(starIcon and starIcon or gTextures.star, 68, 3, 1, 1)

        -- Star Power Counter

        if curWorld > 1 then
            djui_hud_render_texture(worldSpecific[curWorld].starPowerIcon, (djui_hud_get_screen_width() / 2) - 26, 3, 1,
                1)
            djui_hud_print_text("@", (djui_hud_get_screen_width() / 2) - 10, 4, 1)
            djui_hud_print_text(string.format("%d", math.floor(starPower)), (djui_hud_get_screen_width() / 2) + 2, 4, 1)
        end

        -- Star Counter

        djui_hud_print_text("*", djui_hud_get_screen_width() - 62, 4, 1)
        if numStars < 100 then
            djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        end
        djui_hud_print_text(tostring(numStars), djui_hud_get_screen_width() - (32 + (numStars < 100 and 0 or 14)), 4, 1)
    end
end

function level_hud()
    local curCourseNum = gNetworkPlayers[0].currCourseNum
    local curAreaIndex = gNetworkPlayers[0].currAreaIndex
    local bossLevel = bossLevelData[curCourseNum] and bossLevelData[curCourseNum][curAreaIndex] and
        bossLevelData[curCourseNum][curAreaIndex]
    local championsroadLevel = championsRoadLevlData[curCourseNum] and championsRoadLevlData[curCourseNum][curAreaIndex] and
        championsRoadLevlData[curCourseNum][curAreaIndex]
    local hubLevel = gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_COURTYARD) or
        gNetworkPlayers[0].currLevelNum == (LEVEL_CASTLE_GROUNDS)
    local toadHouse = gNetworkPlayers[0].currLevelNum == (LEVEL_COTMC) or
        gNetworkPlayers[0].currLevelNum == (LEVEL_VCUTM) or gNetworkPlayers[0].currLevelNum == (LEVEL_TOTWC)
    if not hubLevel and not bossLevel and not toadHouse and not championsroadLevel and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) then
        -- Score Counter

        djui_hud_render_texture(TEX_SCORE, 8, 4, 1, 1)
        djui_hud_print_text(string.format(("%.05d"), math.floor(scoreCounter)), 24, 4, 1)

        -- Collected Stars Display

        areaStars = levelData[curCourseNum] and levelData[curCourseNum][curAreaIndex].stars
        coinStar = levelData[curCourseNum] and levelData[curCourseNum][curAreaIndex].coinStar
        if areaStars then
            for i = 0, #areaStars - 1 do
                djui_hud_render_texture(operation(curCourseNum, areaStars[i + 1], coinStar and coinStar == areaStars
                    [i + 1]), ((djui_hud_get_screen_width() / 2) - 24) + 14 * i, 4, 1, 1)
            end
        end

        -- Timer

        djui_hud_render_texture(TEX_TIMER, ((djui_hud_get_screen_width() / 2) + 46), 4, 1, 1)
        djui_hud_print_text(string.format(("%.03d"), math.floor(timer)), djui_hud_get_screen_width() / 2 + 57, 4, 1)

        -- Coin Counter

        djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
        if numCoins < 100 then
            djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        end
        djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - (32 + (numCoins < 100 and 0 or 14)), 4, 1)
    end
end

function toad_house_hud()
    if gNetworkPlayers[0].currLevelNum == (LEVEL_COTMC) or gNetworkPlayers[0].currLevelNum == (LEVEL_VCUTM) or gNetworkPlayers[0].currLevelNum == (LEVEL_TOTWC) then
        -- Coin Counter

        djui_hud_print_text("$", djui_hud_get_screen_width() - 62, 4, 1)
        if numCoins < 100 then
            djui_hud_print_text("@", djui_hud_get_screen_width() - 46, 4, 1)
        end
        djui_hud_print_text(tostring(numCoins), djui_hud_get_screen_width() - (32 + (numCoins < 100 and 0 or 14)), 4, 1)
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
    local m = gMarioStates[0]

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

-- Power Meter display --

function power_meter()
    local powerState = gMarioStates[0].health >> 8 < 8 or gMarioStates[0].action & ACT_GROUP_MASK == ACT_GROUP_SUBMERGED
    prevPy = Py
    x = xMid / 2
    y = -11
    if powerTimer > 0 then
        powerTimer = powerTimer - 1 --counting
    elseif powerState then
        if Py < -11 then
            Py = 23 --appear on screen and start ascending
            prevPy = 23
            if gMarioStates[0].health >> 8 < 8 then
                powerTimer = 45 --if you lose health, start a timer to not move the meter
            end
        elseif Py >= 12 and powerTimer == 0 then
            Py = Py - 5 --start moving upwards
        elseif Py >= -2 then
            Py = Py - 3 --slows down
        elseif Py >= -7 then
            Py = Py - 2 --slows down
        elseif Py > -11 then
            Py = Py - 1 --slows down and stops at 5
        end
    else
        if Py == -11 and RunOnce == 0 then
            powerTimer = 45 --restart the timer if powerState is false
            RunOnce = 1
        elseif Py > -11 - 100 and powerTimer == 0 then
            Py = Py - 20 --go offscreen when it's done counting and don't let it ascend infinitely
            RunOnce = 0
        end
    end
    hud_render_power_meter_interpolated(gMarioStates[0].health, x, prevPy, 64, 64, x, Py, 64, 64)
end

function on_hud_render_behind()
    hud_hide()
    djui_hud_set_color(255, 255, 255, 255)
    djui_hud_set_resolution(RESOLUTION_N64)
    djui_hud_set_font(FONT_HUD)
    cannon_hud()
    if _G.OmmEnabled and _G.OmmApi.omm_get_setting(gMarioStates[0], "hud") == 0 or not _G.OmmEnabled then
        lobby_hud()
        level_hud()
        toad_house_hud()
        power_meter()


        hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_LIVES)
        hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_COIN_COUNT)
        hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_TIMER)
        hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_STAR_COUNT)
        hud_set_value(HUD_DISPLAY_FLAGS, hud_get_value(HUD_DISPLAY_FLAGS) & ~HUD_DISPLAY_FLAG_CAMERA)
    end
end

hook_event(HOOK_ON_HUD_RENDER_BEHIND, on_hud_render_behind)
hook_event(HOOK_MARIO_UPDATE, mario_update)
hook_event(HOOK_UPDATE, worldCheck)
