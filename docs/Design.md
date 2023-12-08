# 总体实现
## 账户类
1. 操作：login, logout, register, change password
2. 变量：ID, nickname, password, priority

## 图书类
1. 操作：buy, add, modify, find
2. 变量：ISBN, name, author, ..., price, stock

## 记录类
1. 操作：list, find, ...
2. 需给出易于人理解的输出实现。
3. 变量：when, who, operation, variable...

## 输入输出
1. 输入处理及异常检测；
2. 实现文件读写类，实现使用块状链表存储上述数据并提取。

## 存储在内存的变量
- 存储当前登录栈、以及对应的权限、操作的图书等缓存信息；

## 希望实现的 Bonus ：汉字处理
- UTF-8 类：实现 Codepoint 与 UTF-8 互转；读取处理；字符串合法性判定；长度计算。

## 数据库实现：
- 三个文件：             
1. book，存储ISBN，书名，作者，价格，存量等；              
2. user，存储账号、密码、权限级别；               
3. log，存储操作记录。根据时间排列。            


- 存储实现设想：用链表对每个搜索关键字排序存储地址，实现O(sqrt(n))插入和查找。
