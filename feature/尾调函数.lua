--[[
	函数的尾调用
	函数返回结果是调用单个函数，称之为尾调函数
	先从栈空间弹出当前函数，再调用尾调函数，从而降低函数调用过程的栈消耗
--]]
function factorial(n, temp)
	temp = temp or 1
	if n <= 1 then
		return temp
	end
	return factorial(n - 1, temp * n)
end

print(factorial(5))
