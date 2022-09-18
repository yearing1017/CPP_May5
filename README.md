





# C_Primer_Plus

## 关于

📚 本仓库是面向 C/C++ 的基础知识总结，包括语言、数据结构。

🙏 仓库内容如有错误或改进欢迎 issue 或 pr. 由于本人水平有限，仓库中的知识点有来自本人原创、读书笔记、书籍、博文等，非原创均已标明出处，如有遗漏，请 issue 提出。本仓库遵循 [CC BY-NC-SA 4.0（署名 - 非商业性使用 - 相同方式共享）](https://github.com/huihut/interview/blob/main/LICENSE) 协议，转载请注明出处，不得用于商业目的。

## 目录
* [STL](#stl)
* [CPP基础](#cpp)


<a id="stl"></a>

## STL

### STL 索引

[STL 方法含义索引](https://github.com/yearing1017/CPP_May5/tree/main/STL)

### STL 容器

容器 | 底层数据结构 | 时间复杂度 | 有无序 | 可不可重复 | 其他
---|---|---|---|---|---
[array](https://github.com/yearing1017/CPP_May5/tree/main/STL#array)|数组|随机读改 O(1)|无序|可重复|支持随机访问
[vector](https://github.com/yearing1017/CPP_May5/tree/main/STL#vector)|数组|随机读改、尾部插入、尾部删除 O(1)<br/>头部插入、头部删除 O(n)|无序|可重复|支持随机访问
[deque](https://github.com/yearing1017/CPP_May5/tree/main/STL#deque)|双端队列|头尾插入、头尾删除 O(1)|无序|可重复|一个中央控制器 + 多个缓冲区，支持首尾快速增删，支持随机访问
[forward_list](https://github.com/yearing1017/CPP_May5/tree/main/STL#forward_list)|单向链表|插入、删除 O(1)|无序|可重复|不支持随机访问
[list](https://github.com/yearing1017/CPP_May5/tree/main/STL#list)|双向链表|插入、删除 O(1)|无序|可重复|不支持随机访问
[stack](https://github.com/yearing1017/CPP_May5/tree/main/STL#stack)|deque / list|顶部插入、顶部删除 O(1)|无序|可重复|deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时
[queue](https://github.com/yearing1017/CPP_May5/tree/main/STL#queue)|deque / list|尾部插入、头部删除 O(1)|无序|可重复|deque 或 list 封闭头端开口，不用 vector 的原因应该是容量大小有限制，扩容耗时
[priority_queue](https://github.com/yearing1017/CPP_May5/tree/main/STL#priority_queue)|vector + max-heap|插入、删除 O(log<sub>2</sub>n)|有序|可重复|vector容器+heap处理规则
[set](https://github.com/yearing1017/CPP_May5/tree/main/STL#set)|红黑树|插入、删除、查找 O(log<sub>2</sub>n)|有序|不可重复|
[multiset](https://github.com/yearing1017/CPP_May5/tree/main/STL#multiset)|红黑树|插入、删除、查找 O(log<sub>2</sub>n)|有序|可重复|
[map](https://github.com/yearing1017/CPP_May5/tree/main/STL#map)|红黑树|插入、删除、查找 O(log<sub>2</sub>n)|有序|不可重复|
[multimap](https://github.com/yearing1017/CPP_May5/tree/main/STL#multimap)|红黑树|插入、删除、查找 O(log<sub>2</sub>n)|有序|可重复|
[unordered_set](https://github.com/yearing1017/CPP_May5/tree/main/STL#unordered_set)|哈希表|插入、删除、查找 O(1) 最差 O(n)|无序|不可重复|
[unordered_multiset](https://github.com/yearing1017/CPP_May5/tree/main/STL#unordered_multiset)|哈希表|插入、删除、查找 O(1) 最差 O(n)|无序|可重复|
[unordered_map](https://github.com/yearing1017/CPP_May5/tree/main/STL#unordered_map)|哈希表|插入、删除、查找 O(1) 最差 O(n)|无序|不可重复|
[unordered_multimap](https://github.com/yearing1017/CPP_May5/tree/main/STL#unordered_multimap)|哈希表|插入、删除、查找 O(1) 最差 O(n)|无序|可重复|


<a id="cpp"></a>

## CPP基础

### 指针相关
- 指针基础
    - 指针存储的是地址，写法：`int * p1 = NULL`
    - 取变量num的地址：`p2 = &num`
    - 指针指向内容赋值：`*p1 = 20`
- 指针与结构体
    - 对象：`Student stu = {"Yu", 2000, true};`
    - 指针：`Student * pStu = &stu;`
    - 指针使用->来指向member：`pStu->member`
    - 对象变量使用 `.` 来指向member：`(*pStu).member || stu.member` 
    - 指针自身也有地址：`int num = 10; int * p = &num; int ** pp = &p;`
- const 指针
    - `int foo(const char * p){ char * p2 = p; return 0; }` const char * 的指针不能用来初始化char *类型指针
    - `const int * p1 = &num;` 不能通过p1来改变p1指向的值，但可以改变p1指向的地址
    - `int * const p2 = &num;` 不能改变p2指向的地址，但可以通过p2来改变p2指向的值
    - `const int* const p3 = &num;` 都不可以改变
- 指针与数组
    - 数组名的指针 指向 数组首元素的地址
- 指针的偏移与越界
    - p + num || num + p 指向数组p的第num个元素
    - p - num 指向数组p的第-num个元素
    - 越界：`int num = 0; int * p = &num; p[-1] = 2; //out of bound p[0] = 3; //okay *(p+1) = 4; //out of bound`
- 指针和数组的区别
    - 数组是一个constant指针
    - sizeof 可以获得数组所有元素的size`int numbers[4] = {0, 1, 2, 3}; cout << sizeof(numbers) << endl; //4*sizeof(int)`
    - 指针的size `int * p = numbers; cout << sizeof(p) << endl; // 4 or 8`
- c和c++的动态分配内存与释放
    - c语言的malloc & free
    - c++的new和delete
        - new() & new[]
        - delete & delete[]

### 函数
- 函数基础
    - .h头文件用来声明函数；func.cpp实现函数；main.cpp调用函数
- 值参数
    - 传递进来的基本类型参数是一份copy；修改该copy，原始数据不会受影响
- 指针参数
    - 传递进来的指针类型参数是一份copy；修改该copy，由于地址的值一样，所以原始数据也会被修改
- 引用 & 引用参数
    - 引用写法`int & num_ref = num`，取地址写法`&num`
    - `int & num_ref = num` &放在类型后面表示引用，不是取地址；相当于取别名
    - 引用在声明的时候一定要初始化
    - 对象特别大时，传参会导致拷贝，所以可以使用指针或引用，不需拷贝
        - 指针vs引用：指针需要判空，引用不需要；
        - 传进来的引用被修改，会导致原始数据也被修改；所以可在引用参数前+const防止被修改
- inline函数与宏
- 函数默认参数
- 函数重载
- 函数模板

### 类
- 类的定义
- 构造函数 + 析构函数