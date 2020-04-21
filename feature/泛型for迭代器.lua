local week_day = {
	"Sunday",
	"Monday",
	"Tuesday",
	"Wednesday",
	"Thursday",
	"Friday",
	"Saturday"
}

-- ���������
local function ipairs(table)
	-- �����������
	local ipairs = function(table, index)
		index = index + 1
		local value = table[index]
		if not value then
			index = nil
		end
		return index, value -- ����nil����������for
	end
	return ipairs, table, 0
end

for k, v in ipairs(week_day) do
	print(k .. ": " .. v)
end

-- ���������
local function pairs(table)
	-- �����������
	local pairs = function(table, key)
		key = next(table, key)
		return key, table[key]
	end
	return pairs, table, nil -- ���ص����������������ϡ���ʼ��
end

for k, v in pairs(week_day) do
	print(k .. ": " .. v)
end
