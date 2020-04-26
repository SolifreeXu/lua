local function stringify(root)
	local explicit = function(value)
		local type = type(value)
		if type == "string" then
			return '"' .. value .. '"'
		elseif type == "boolean" then
			return tostring(value)
		elseif type == "number" then
			return value
		end
		return '"' .. tostring(value) .. '"'
	end

	if type(root) ~= "table" then
		return explicit(root)
	end

	local image = {}
	local counter = 0
	local insert = function(value)
		counter = counter + 1
		image[counter] = value
	end
	local remove = function()
		image[counter] = nil
		counter = counter - 1
	end

	local mapper = {}
	local function traverse(root, indent, prefix)
		if mapper[root] then
			insert("[=[" .. mapper[root] .. "]=]")
			return
		end
		mapper[root] = prefix or "[=[[nil]]=]"

		local empty = true
		insert('{')
		insert('\n')
		for key, value in pairs(root) do
			empty = false
			insert(indent .. "\t[" .. explicit(key) .. "] = ")
			if type(value) ~= "table" then
				insert(explicit(value))
			else
				local prefix = (prefix or "") .. '[' .. explicit(key) .. ']'
				traverse(value, indent .. '\t', prefix)
			end
			insert(",\n")
		end
		remove()
		if not empty then
			insert('\n' .. indent)
		end
		insert('}')
	end

	traverse(root, "")
	return table.concat(image)
end
