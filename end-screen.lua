-- Level End Screen Code (WIP)

---@param m MarioState
---@param o Object
---@param interactType InteractionType
---@param interactValue boolean
--this function is for mario interacting with objects. thanks wereyoshi
local function on_interact(m,o,interactType,interactValue)
    if m.playerIndex ~= 0 then return end
    
    if interactType == INTERACT_STAR_OR_KEY then
        starID = o.oBehParams >> 24 -- Returns the star's id
    end
    
end

hook_event(HOOK_ON_INTERACT, on_interact)
hook_event(HOOK_ON_HUD_RENDER_BEHIND, level_end)