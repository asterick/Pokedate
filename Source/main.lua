local menu = playdate.getSystemMenu()
local cartMenuItem = nil

--[[
    Helper functions
]]

function string:split(delimiter)
    result = {}
    for match in (self .. delimiter):gmatch("(.-)" .. delimiter) do
        table.insert(result, match);
    end
    return result
end

function string:join(table)
    if #table == 0 then
        return ""
    end

    local output = table[1]
    for i = 2, #table do
        output = output .. self .. tostring(table[i])
    end
    return output
end

--[[
    This is our running state
]]

function run()
    local time = playdate.getCurrentTimeMilliseconds()

    return function()
        local now = playdate.getCurrentTimeMilliseconds()
        local ms = now - time

        minimon.step(ms);
        time = now
    end
end

--[[
    This toggles power for 100ms
]]

function pressPower()
    local update = playdate.update
    local time = playdate.getCurrentTimeMilliseconds() + 1000

    print("True")
    minimon.powerButton(true)
    return function()
        if playdate.getCurrentTimeMilliseconds() >= time then
            print("Done")
            minimon.powerButton(false)
            playdate.update = update
        end
        --update()
    end
end

--[[
    This is our loading state
]]
function loadMenu()
    local root = "/roms/"
    local files = playdate.file.listFiles(root)

    local function changeDir(folder)
        playdate.graphics.drawRoundRect( 5, 5, 390, 230, 3)
    end

    local function loadGame(path)
        minimon.load(path)
        playdate.update = run()
    end

    return function ()
        loadGame("/roms/Pokemon Race Mini (J).min")
    end
end

--[[
    Setup Context Menu
]]

menu:addMenuItem("Press Power", function()
    playdate.update = pressPower()
end)

function addEjectMenu()
    menu:removeMenuItem(cartMenuItem)

    cartMenuItem = menu:addMenuItem("Eject", 1, function (...)
        minimon.eject()
        addLoadMenu()
    end)
end

function addLoadMenu()
    if (cartMenuItem ~= nil) then
        menu:removeMenuItem(cartMenuItem)
    end

    cartMenuItem = menu:addMenuItem("Load", 1, function (...)
        playdate.update = loadMenu()
        addEjectMenu()
    end)
end

addLoadMenu()
menu:addMenuItem("Reset", minimon.reset)

playdate.update = run()
