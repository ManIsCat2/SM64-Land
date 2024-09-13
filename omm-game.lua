---@diagnostic disable: undefined-field, undefined-global
if _G.OmmEnabled then
    _G.OmmApi.omm_register_game("SM64 Land", function() return true end, function()
        ---------------
        -- Game data --
        ---------------

        _G.OmmApi.omm_register_game_data(-1, 0, LEVEL_NONE, true, true, 0xFFFF00, 0)

        -----------------
        -- Level stars --
        -----------------
        
        --------------------
        -- Star behaviors --
        --------------------
        
       -- _G.OmmApi.omm_register_star_behavior(bhv, "name", "NAME", function(bhvParams) return true end)
       _G.OmmApi.omm_register_star_behavior(id_bhvKingGoomba, "King Goomba", "KING GOOMBA", function(bhvParams) return true end)

        --------------------
        -- Camera presets --
        --------------------

        -------------------------
        -- Camera no-col boxes --
        -------------------------

        ----------------
        -- Warp pipes --
        ----------------

        -------------------
        -- Non-Stop mode --
        -------------------
    end)
end