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
	if path then
		path, package.path = package.path, path .. "?.lua"
	end

	local state, sources = xpcall(import, debug.traceback, names)
	if not state then
		print(sources)
	end

	if path then
		package.path = path
	end
	return sources
end

function path.current()
	local info = debug.getinfo(2, "S")
	local path = string.sub(info.source, 2)
	return string.match(path, "^.*[/\\]")
end

local config = path.import("config", path.current())
local state, file = xpcall(io.open, debug.traceback, config.src)
if not state then
	print(file)
end

local range = config.range
local from, to = range[1], range[2]

local src = {}
for index = 1, from - 1 do
	file:read()
end
for index = from, to do
	table.insert(src, file:read())
end
file:close()

local begin = config.to - 1
for _, name in ipairs(config.dest) do
	local state, file = xpcall(io.open, debug.traceback, name)
	if not state then
		print(file)
		break
	end

	local dest = {}
	for line in file:lines() do
		table.insert(dest, line)
	end
	file:close()

	for index = 1, #src do
		dest[begin + index] = src[index]
	end

	state, file = xpcall(io.open, debug.traceback, name, "w")
	if not state then
		print(file)
		break
	end

	for index = 1, #dest do
		file:write(dest[index], '\n')
	end
	file:close()
end
