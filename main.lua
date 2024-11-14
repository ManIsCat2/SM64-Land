-- name: \\#00FF00\\SM\\#FF4500\\64 Land
-- description: A linear hack made by Kaze Emanuar with 8 Worlds filled with\nlevels to explore, and all new powers-ups, inspired by Super Mario 3D Land and Super Mario 3D World.\n\nCreated By:\n\\#105009\\Kaze Emanuar (Hack Creator)\n\\#00ff00\\I'mYourCat\\#FF0000\\2 (Port Creator)\n\\#dcdcdc\\x\\#00FF00\\Luigi\\#434343\\Gamer\\#dcdcdc\\x (Coder, Model Porter)\n\\#FFC0CB\\MaiskX3 (Music Porter)\n\\#0000FF\\Woissil (Model Porter, Animator, MOPS)\n\\#105009\\Emeraldsniper (Tester)\n\\#FFC0CB\\Sunk (MOPS)\n\\#00FF00\\EmeraldLockdown (MOPS)\n\\#5d004d\\Blocky.cmd (MOPS)\n\\#595959\\Agent\\#FFA500\\X (Exclamation Box)\n\\#00FFFF\\Steven (Rideable Yoshi)\n\\#FFC0CB\\OneCalledRPG (Coder)
-- incompatible: romhack

gFloodIsEnabled = false
for currentMod in pairs(gActiveMods) do
    if gActiveMods[currentMod].name:find("Flood") then
        gFloodIsEnabled = true
    end
end

local m = gMarioStates[0]

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
gLevelValues.exitCastleWarpNode = 11
-- fix collisions being bad
gLevelValues.fixCollisionBugs = true
gLevelValues.fixCollisionBugsRoundedCorners = false
gLevelValues.fixCollisionBugsGroundPoundBonks = false
--fix  cap durations
gLevelValues.metalCapDurationCotmc = 1
gLevelValues.wingCapDurationTotwc = 1
gLevelValues.vanishCapDurationVcutm = 1
--really needed
gServerSettings.stayInLevelAfterStar = true
gLevelValues.disableActs = true
gBehaviorValues.ShowStarMilestones = false

camera_set_use_course_specific_settings(false)

save_file_set_flags(SAVE_FLAG_HAVE_METAL_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_VANISH_CAP)
save_file_set_flags(SAVE_FLAG_HAVE_WING_CAP)

hook_event(HOOK_MARIO_UPDATE, mario_update)

--[[ World Map Camera
function world_map_cam(m)
    if m.playerIndex ~= 0 then return end
    l = gLakituState
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) then return camera_unfreeze() end
    if m.action == ACT_READING_NPC_DIALOG or m.action == ACT_READING_SIGN then return camera_unfreeze() end
    vec3f_copy(l.focus, m.pos)
    l.pos.x = m.pos.x
    l.pos.y = m.pos.y + 1500
    l.pos.z = m.pos.z + 4350
    djui_chat_message_create("yaw: "..tostring(l.yaw))
    djui_chat_message_create("nextYaw: "..tostring(l.nextYaw))
    djui_chat_message_create("oldYaw: "..tostring(l.oldYaw))
    djui_chat_message_create("yaw: "..tostring(l.yaw))
    djui_chat_message_create("nextYaw: "..tostring(l.nextYaw))
    djui_chat_message_create("oldYaw: "..tostring(l.oldYaw))
    l.yaw = 0
    l.oldYaw = -32768
    l.nextYaw = 0
    l.oldPitch = 0
    l.roll = 0
    l.oldRoll = 0
    camera_freeze()
end

hook_event(HOOK_MARIO_UPDATE, world_map_cam)
]]

function low_grav(m)
    if m.action & ACT_FLAG_AIR ~= 0 and (gNetworkPlayers[0].currLevelNum == LEVEL_WF and gNetworkPlayers[0].currAreaIndex == 2 or gNetworkPlayers[0].currLevelNum == LEVEL_CASTLE_COURTYARD and gNetworkPlayers[0].currAreaIndex == 4) and m.action ~= ACT_TWIRLING then
        m.vel.y = m.vel.y + 1.2
    end
end

hook_event(HOOK_MARIO_UPDATE, low_grav)

-- Timer and bonus timer score --

timer = 0

function timer_update()
    if gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_COURTYARD) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE_GROUNDS) and gNetworkPlayers[0].currLevelNum ~= (LEVEL_CASTLE) then
        timer = math.floor(get_network_area_timer() / 30)
    else
        timer = 0
    end
end

function timer_score()
    local bonusScore = timer < 300 and (300 - math.floor(timer)) * 64
    return bonusScore
end

hook_event(HOOK_UPDATE, timer_update)

function hook_diag(d)
    if d == 13 then
        return false
    end
end

hook_event(HOOK_ON_DIALOG, hook_diag)

local champRoad = "Ch. Road"

local sm64landlevelnames = {
    --{ level = LEVEL_,            names = { "", } },
    --hubs
    { level = LEVEL_CASTLE_GROUNDS,   names = { "World 1", "World 3", "World 5", "World 7", } },
    { level = LEVEL_CASTLE,           names = { "Tutorial", } },
    { level = LEVEL_CASTLE_COURTYARD, names = { "World 2", "World 4", "World 6", "World 8", } },
    --toads
    { level = LEVEL_COTMC,            names = { "Toad House", "Toad House", "Toad House", "Toad House", "Toad House", } },
    { level = LEVEL_VCUTM,            names = { "Toad House", "Toad House", "Toad House", "Toad House", "Toad House", } },
    { level = LEVEL_TOTWC,            names = { "Toad House", "Toad House", "Toad House", "Toad House", "Toad House", } },
    --levels
    { level = LEVEL_BOB,              names = { "1-1", "1-4", "Boss 1", champRoad } },
    { level = LEVEL_WF,               names = { "1-2", "1-3", } },
    { level = LEVEL_JRB,              names = { "2-1", "2-2" } },
    { level = LEVEL_CCM,              names = { "2-3", "2-4", "Boss 2" } },
    { level = LEVEL_BBH,              names = { "3-1", champRoad } },
    { level = LEVEL_HMC,              names = { "3-3", "5-3", champRoad } },
    { level = LEVEL_SSL,              names = { "3-4", "6-3", "Boss 3" } },
    { level = LEVEL_SL,               names = { "5-4", "4-1" } },
    { level = LEVEL_WDW,              names = { "4-4", "4-2", champRoad } },
    { level = LEVEL_TTC,              names = { "7-4", "4-3" } },
    { level = LEVEL_PSS,              names = { "Boss 4", "what the fuck" } },
    { level = LEVEL_DDD,              names = { "5-1", "5-2" } },
    { level = LEVEL_TTM,              names = { "6-1", "6-2", champRoad } },
    { level = LEVEL_THI,              names = { "6-4", "7-1", champRoad } },
    { level = LEVEL_BITDW,            names = { "Boss 6", "what the fuck" } },
    { level = LEVEL_RR,               names = { "7-2", "7-3" } },
    { level = LEVEL_BITS,             names = { "Boss 7" } },
    { level = LEVEL_SA,               names = { "8-1" } },
    { level = LEVEL_WMOTR,            names = { "8-2", "8-3" } },
    { level = LEVEL_BITFS,            names = { "8-4", "Boss 8", champRoad } },
}

function correct_level_name()
    for indexOfNP = 0, MAX_PLAYERS - 1 do
        for j = 1, #sm64landlevelnames do
            if gNetworkPlayers[indexOfNP].currLevelNum == sm64landlevelnames[j].level then
                network_player_set_description(gNetworkPlayers[indexOfNP],
                    sm64landlevelnames[j].names[gNetworkPlayers[indexOfNP].currAreaIndex], 255, 255, 255, 255)
            end
        end
    end
end

hook_event(HOOK_UPDATE, correct_level_name)
