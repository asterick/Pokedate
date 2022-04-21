local time = playdate.getCurrentTimeMilliseconds()

function playdate:update()
    local now = playdate.getCurrentTimeMilliseconds()
    minimon.step(now - time);
    time = now
end

function load_file()
    local root = "."
    local files = playdate.file.listFiles(root)

    return function ()
        for key, value in pairs(files) do
            playdate.graphics.drawText(key .. " " .. value, 5, key * 30)
        end
    end
end

playdate.update = load_file()
