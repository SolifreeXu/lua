-- table.move(src, f, e, t[, dest])
-- �˺���ֻ����Դ����ָ����Χ��Ԫ����Ŀ�������ָ��λ�ã��������Ƴ�Դ����ָ����Χ��Ԫ��
local src = { 1, 2, 3 }
local dest = {}
_G.table.move(src, 1, #src, 1, dest)
print(next(src))
