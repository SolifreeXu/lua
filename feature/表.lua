-- table.move(src, f, e, t[, dest])
-- 此函数只复制源数组指定范围的元素至目的数组的指定位置，并不会移除源数组指定范围的元素
local src = { 1, 2, 3 }
local dest = {}
_G.table.move(src, 1, #src, 1, dest)
print(next(src))
