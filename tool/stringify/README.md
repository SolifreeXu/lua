## 简介
应项目需求，设计并实现一款lua串化工具——[stringify.lua](stringify.lua)。

## 功能
串化工具统一转换lua数据类型为字符串，字符串支持再次解释为原始类型，仅限于nil、boolean、number、string、table共5种类型。

## 设计
Lua存在8种数据类型，分别是nil、boolean、number、string、function、userdata、thread和table。
1. 对于boolean和number类型，易转换为string类型。
2. 单独的nil值可以转换为string类型。
3. 遍历table类型，结合以上处理转换为字符串。
4. 至于function、userdata、thread类型，只有给予提示字符串。  
采用特殊格式组织表引用关系，需要额外处理才可以还原表结构。  
针对表与子表循环引用的情况，采用映射表记录已遍历的表路径，以防止无限遍历。    
当连接大量字符串时，由于lua的字符串不可变，存在多次复制大量字符串的问题，影响串化性能。  
于是先把串化结果依次尾插至表中，再调用table.concat函数一次性连接字符串，以提高字符串连接效率。  
另外，在3种表尾插方法之中，效率由低至高排列为table.insert、table size、counter。

## 优化
优化代码：[stringify_o1.lua](stringify_o1.lua)  
函数调用存在一定开销，尤其是频繁执行的代码，函数调用带来的开销不可忽视。  
避免函数调用的开销，可以内嵌函数代码至调用处，不过这会降低代码的可读性、可维护性和可变更性。

## 测试
复制工具：[clone.lua](clone.lua)  
测试代码：[test.lua](test.lua)  
借助复制工具，复制100000个数据表，插入原表之中。  
再调用串化工具串化原表，记录并输出串化耗时。

## 作者
name：许聪
mailbox：2592419242@qq.com
CSDN：https://blog.csdn.net/xucongyoushan  
gitee：https://gitee.com/solifree  
github：https://github.com/xucongandxuchong
