path = {}
function path.import(functor, path)
	if not functor then
		return
	end

	-- 备份并改变默认搜索路径
	local temp = path
	if temp then
		path = package.path
		package.path = temp .. "?.lua"
	end

	functor()

	-- 恢复默认搜索路径
	if path then
		package.path = path
	end
end

function path.current()
	--[[
		功能：
			获取指定函数信息，筛选调用此函数的函数所属文件的路径
		参数：
			2：堆栈第2层函数信息，即调用函数path.current的函数信息
			'S'：填充source、short_src、linedefined、lastlinedefined，以及what域
		拓展：
			对于第一参数，0层表示getinfo自身信息，1层表示调用getinfo的函数信息，即path.current的函数信息
			对于第二参数，另外还有'n'、'l'、't'、'u'、'f'、'L'等筛选条件或者操作选项
	--]]
	local info = debug.getinfo(2, "S")
	-- 忽略第一字符'@'
	local path = string.sub(info.source, 2)
	-- 捕获最后一'/'及其之前的内容，即当前文件所在目录
	return string.match(path, "^.*[/\\]")
end

local stringify
local clone
path.import(function()
	stringify = require "stringify"
	clone = require "clone"
end, path.current())

local player = {
	base = {
		id = "RO-0000000001",
		sex = 2,
		name = "solifree",
		nature = "freedom",
		dress = 201,
	},
	organization = "eterfree",
	founder = true,
	action = function() end,
	observer = {},
}

local insert = table.insert
local prototype = clone(player)
---[[
for i = 1, 100000 do
	insert(player.observer, clone(prototype))
end
--]]
--[[
for i = 1, 10 do
	insert(player.observer, prototype)
end
--]]
local time = os.clock()
stringify(player)
--print(stringify(player))
print(os.clock() - time)
