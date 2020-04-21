local week_day = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
}

-- 定义迭代器
local function ipairs(table)
	-- 定义迭代函数
	local ipairs = function(table, index)
		index = index + 1
		local value = table[index]
		if not value then
			index = nil
		end
		return index, value -- 返回nil，结束泛型for
	end
	return ipairs, table, 0
end

for k, v in ipairs(week_day) do
	print(k .. ": " .. v)
end

-- 定义迭代器
local function pairs(table)
	-- 定义迭代函数
	local pairs = function(table, key)
		key = next(table, key)
		return key, table[key]
	end
	return pairs, table, nil -- 返回迭代函数、遍历集合、初始键
end

for k, v in pairs(week_day) do
	print(k .. ": " .. v)
end
