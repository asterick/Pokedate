local exists = tostring(minimon.step)
local time = playdate.getCurrentTimeMilliseconds()

function playdate:update()
    local now = playdate.getCurrentTimeMilliseconds()
    minimon.step(now - time);
    time = now
end
