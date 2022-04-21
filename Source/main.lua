local menu = playdate.getSystemMenu()
local time = playdate.getCurrentTimeMilliseconds()

function string:split(s, delimiter)
    result = {};
    for match in (s..delimiter):gmatch("(.-)"..delimiter) do
        table.insert(result, match);
    end
    return result;
end

for i, v in pairs("/rom/bank/":split("/")) do
    print (i .. ": " .. v)
end

--[[
This should be assigned to playdate.update when you would like the emulator to run freely
]]--

function running()
    local now = playdate.getCurrentTimeMilliseconds()
    minimon.step(now - time);
    time = now
end

--[[
    This is our loading state
]]--
function load_file()
    local root = "/roms/"
    local files = playdate.file.listFiles(root)

    function change_dir(folder)
        playdate.graphics.drawRoundRect( 5, 5, 390, 230, 3)
    end

    function load_game(path)
    end

    change_dir(root)

    return function ()
        for key, value in pairs(string) do
            playdate.graphics.drawText(key .. " " .. value, 5, key * 30)
        end
    end
end

menu:addMenuItem("Load Game", function()
    playdate.update=load_file()
end)

playdate.update = running
