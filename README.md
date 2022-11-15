# 利用宽度优先搜索方式解决迷宫问题

本程序可以通过迷宫边的格子数的设定大小，编译文件后先输入迷宫边长，然后输入你想去的目标节点（起点只能为1），再确定各个节点的连接情况。

例子：

| 1    | 2    |
| ---- | ---- |
| 3    | 4    |



```
以下是2*2迷宫的样例：（以“4”为终点）
start to create your labyrinth.
input your size of the labyrinth' side: 2
is number1 vex and number2 vex connected?
if so, press 1. if not, press 0: 1
is number1 vex and number3 vex connected?
if so, press 1. if not, press 0: 1
is number2 vex and number4 vex connected?
if so, press 1. if not, press 0: 1
is number3 vex and number4 vex connected?
if so, press 1. if not, press 0: 0
input your target: 4

success!
the way is: 4<-2<-1
```

