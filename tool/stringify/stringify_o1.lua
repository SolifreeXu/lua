return function(root)
	local explicit = function(value)
		local type = type(value)
		if type == "string" then
			return '"' .. value .. '"'
		elseif type == "number" then
			return value
		elseif type == "boolean" then
			return tostring(value)
		elseif type == "nil" then
			return '"' .. tostring(value) .. '"'
		end
		return "\"\\\"" .. tostring(value) .. "\\\"\""
	end

	if type(root) ~= "table" then
		return explicit(root)
	end

	local image = {}
	local counter = 0
	local mapper = {}
	local function traverse(root, indent, prefix)
		if mapper[root] then
			counter = counter + 1
			image[counter] = "[=[" .. mapper[root] .. "]=]"
			return
		end
		mapper[root] = prefix or "[=[[nil]]=]"

		local empty = true
		counter = counter + 1
		image[counter] = '{'
		counter = counter + 1
		image[counter] = '\n'
		for key, value in pairs(root) do
			empty = false
			counter = counter + 1
			image[counter] = indent .. '[' .. explicit(key) .. "] = "
			if type(value) ~= "table" then
				counter = counter + 1
				image[counter] = explicit(value)
			else
				local prefix = (prefix or "") .. '[' .. explicit(key) .. ']'
				traverse(value, indent .. '\t', prefix)
			end
			counter = counter + 1
			image[counter] = ",\n"
		end
		image[counter] = nil
		counter = counter - 1
		if not empty then
			counter = counter + 1
			image[counter] = '\n' .. indent
		end
		counter = counter + 1
		image[counter] = '}'
	end

	traverse(root, "")
	return table.concat(image)
end
