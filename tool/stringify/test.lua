local function single(names)
	return require(names)
end

local function batch(names)
	local sources = {}
	for index = 1, #names do
		sources = require(names[index])
	end
	return sources
end

local IMPORT_MAPPING = {
	["string"] = single,
	["table"] = batch,
}

path = {}
function path.import(names, path)
	if not names then
		return
	end
	
	local type = type(names)
	if type == "table" and not next(names) then
		return
	end
	
	local import = assert(IMPORT_MAPPING[type], type)
	-- 备份并改变默认搜索路径
	if path then
		path, package.path = package.path, path .. "?.lua"
	end

	local state, sources = xpcall(import, debug.traceback, names)
	if not state then
		print(sources)
	end

	-- 恢复默认搜索路径
	if path then
		package.path = path
	end
	return sources
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

local sources = path.import({"stringify", "copy"}, path.current())
local stringify, copy = table.unpack(sources)

local player = {
	base = {
		id = "RO-0000000001",
		sex = 1,
		name = "solifree",
		nature = "freedom",
		dress = 101,
	},
	organization = "eterfree",
	founder = true,
	action = function() end,
	observer = {},
}

local insert = table.insert
local prototype = copy(player)
---[[
for i = 1, 100000 do
	insert(player.observer, copy(prototype))
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
