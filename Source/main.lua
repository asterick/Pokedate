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

    -- TODO: EVENTUALLY DRAW A BITMAP SKIN HERE
    playdate.graphics.setDrawOffset(0,0)
    playdate.graphics.setClipRect(0,0,400,240)
    playdate.graphics.clear(playdate.graphics.kColorWhite)

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
            minimon.powerButton(false)
            playdate.update = update
        end
        update()
    end
end

--[[
    This is our loading state
]]
function loadMenu()
    local root = "."
    local files, title, selected

    local function join(path, ...)
        local args = { ... }

        for i = 1, #args do
            path = path .. "/" .. args[i]
        end

        return path
    end

    local function absPath(path)
        local pieces = path:split("/")

        for i = #pieces,1,-1 do
            if pieces[i] == "." or pieces[i] == "" then
                table.remove(pieces, i)
            elseif pieces[i] == ".." then
                table.remove(pieces, i)
                table.remove(pieces, i - 1)
                i = i - 1
            end
        end

        return ("/"):join(pieces)
    end

    local function repaintBorder()
        local gfx <const> = playdate.graphics

        -- Window border
        gfx.setDrawOffset(0, 0)
        gfx.setColor(gfx.kColorBlack)
        gfx.fillRoundRect(25, 5, 350,  30, 5)
        gfx.drawRoundRect(25, 5, 350, 230, 5)

        gfx.setImageDrawMode(gfx.kDrawModeFillWhite)
        gfx.drawText("*" .. title .. "*", 35, 11)
    end

    local function select(target)
        local path = absPath(join(root, target))

        if not playdate.file.exists(path) then
            print("UNKNOWN:" .. path)
        elseif playdate.file.isdir(path) then
            title = target
            root = path
            files = playdate.file.listFiles(root)
            selected = 0

            repaintBorder()
        else
            addEjectMenu()
            minimon.load(path)
            playdate.update = run()
        end

        --= playdate.file.listFiles(root)
    end

    select("roms") -- set our default folder

    local ROW_HEIGHT = 24
    local LIST_HEIGHT = 196
    local offset = 0
    local prev_crank = playdate.getCrankPosition()

    return function ()
        -- Select item with buttons
        if playdate.buttonJustPressed(playdate.kButtonUp) then
            selected = (selected + #files - 1) % #files
        elseif playdate.buttonJustPressed(playdate.kButtonDown) then
            selected = (selected + 1) % #files
        elseif playdate.buttonJustPressed(playdate.kButtonA) then
            select(files[selected+1])
        elseif playdate.buttonJustPressed(playdate.kButtonB) then
            playdate.update = run()
        end

        -- Select item with crank
        local crank = playdate.getCrankPosition()
        local crank_delta = (crank - prev_crank) // 6
        prev_crank = crank

        selected = (selected + crank_delta + #files) % #files

        -- Redraw menu
        local gfx <const> = playdate.graphics

        local targetOffset = (selected * ROW_HEIGHT) - (LIST_HEIGHT - ROW_HEIGHT) / 2
        local maxOffset = #files * ROW_HEIGHT - LIST_HEIGHT

        -- Fit to screen
        if targetOffset > maxOffset then
            targetOffset = maxOffset
        end

        if targetOffset < 0 then
            targetOffset = 0
        end

        local delta = targetOffset - offset
        if delta > 0 then
            offset = (offset + math.log(delta) / math.log(2)) // 1
        elseif delta < 0 then
            offset = (offset - math.log(-delta) / math.log(2)) // 1
        end

        -- File menu contents
        gfx.setColor(gfx.kColorWhite)
        gfx.setDrawOffset(0, 0)
        gfx.setScreenClipRect(30, 37, 340, LIST_HEIGHT)
        gfx.fillRect(30, 37, 340, LIST_HEIGHT)

        gfx.setDrawOffset(30, 37 - offset) -- We are using 1 indexing

        gfx.setColor(gfx.kColorBlack)
        gfx.fillRect(0, selected * ROW_HEIGHT, 400, ROW_HEIGHT)

        for i, fn in pairs(files) do
            if selected+1 == i then
                gfx.setImageDrawMode(gfx.kDrawModeFillWhite)
            else
                gfx.setImageDrawMode(gfx.kDrawModeFillBlack)
            end
            gfx.drawText(fn, 5, (i - 1) * ROW_HEIGHT + 2)
        end
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
    end)
end

addLoadMenu()
menu:addMenuItem("Reset", minimon.reset)

playdate.update = run()
