## 简介
为减少项目维护的时间开销，设计并实现文本文件局部复制工具。

## 功能
复制源文本文件指定行区间的内容至目标文本文件的指定行。

## 结构
文件|说明
-|-
[config.lua](config.lua)|配置文件，在此文件之中，配置源文件、目标文件、源行区间、目的起始行。
[copy.lua](copy.lua)|功能实现脚本，加载配置，于源文件读取行区间的内容，读取目标文件至内存，向其插入源内容，将修改写入目标文件。
lua.exe|自研lua文件执行程序，可以考虑以lua解释器替代之。
[copy.bat](copy.bat)|Windows批处理命令文件，以lua.exe执行指定lua文件；若以lua解释器代替lua.exe，需要修改此文件的批处理命令。

## 作者
name：许聪  
mailbox：2592419242@qq.com  
CSDN：https://blog.csdn.net/xucongyoushan  
gitee：https://gitee.com/solifree  
github：https://github.com/xucongandxuchong
