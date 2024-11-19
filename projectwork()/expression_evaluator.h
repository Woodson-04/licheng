/**
程序需要能判断输入是否合法，并在不合法的情况下输出"ILLEGAL"。

输入： 用户输入一个字符串，代表一个中缀表达式。

输出： 如果输入的中缀表达式合法，输出计算结果；如果非法，输出"ILLEGAL"。

要求：
- 支持多重括号和四则运算。
- 支持有限位小数运算，但可以不考虑负数作为输入。
- 识别非法的表达式，如括号不匹配、运算符连续使用、表达式以运算符开头或结尾以及除数是 0 等。
- 使用C++标准库中的容器和算法实现。
- 提供充分多的测试例子。
- 使用 latex 撰写你的报告，包括你的设计思路和结果分析。中英文均可。
- 提供Makefile进行项目的自动编译和链接。

加分因素：
- 考虑了负数，比如：1+-2.1是合法的，但 1++2.1 是非法的。
- 考虑了科学计数法，比如：-1+2e2是合法的。
上述规则可以自己修改调整，但必须在报告中给予说明。规则必须合理且一致。

建议的文件结构：
- main.cpp：主程序入口，处理输入输出和测试。
- expression_evaluator.h：表达式求值相关的函数和类。
- report.tex：项目报告。
- Makefile：用于自动化编译过程。

最后期限是 12 月 22 日，请不要拖到最后一刻！
*/

/** 
基本思路：（仅仅实现正整数在实数域中含至多优先级到四则运算的加减乘除）（全英文字符输入）
要有东西A存储一开始的输入字符串
要将中置运算变成后置运算（要有stack）
通过一个指针遍历所有数据计算得到结果
A存储：3*2+5*（2-3*9）+5
A'存储：3      while stack存储：运算符
3,2，*，5，2，(,*,+,3,9,),*,-,5,+

3*2+5*2-3*9+5
3,2,*,5,2,*,+,3,9,*,-,5,+
A'读A中元素，
if数字则加入，
else if运算符则将要进入stack，然后stack考察，
『
要是进入元素优先级比现有最上元素大，进入，
否则不断pop元素进入A'直到剩下最上元素优先级严格小于将要打入元素，然后进入；
』
读完A中元素，pop stack 元素清空；
现在A'中存储后置运算形式
#注意上面A到A'应当已将非法元过滤
创建指针，读A'中元素（val代表指针存储内容；type：1代表数字，0代表op；prev 代表上指针；const 代表当前指针；next 代表下指针；）
item 记录已有数字个数
判断
『
if 数字：item+1（if item < 2）
else if 运算符：
if item == 2：指针运算上上元(->pre->pre) op 上元 (应当均为数字)
结果更新为当前指针的val，修改type = 0；
更新prev为上上指针的上指针；
删除上指针和上上指针；
else ：代表出错了
』
最终输出当前指针的val即可；

所需结构：
std::stack
list
所需函数：
delete函数
insert函数
构造函数（赋初值）
析构函数

*/

#include <iostream>

class 