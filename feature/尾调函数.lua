--[[
	������β����
	�������ؽ���ǵ��õ�����������֮Ϊβ������
	�ȴ�ջ�ռ䵯����ǰ�������ٵ���β���������Ӷ����ͺ������ù��̵�ջ����
--]]
function factorial(n, temp)
	temp = temp or 1
	if n <= 1 then
		return temp
	end
	return factorial(n - 1, temp * n)
end

print(factorial(5))
