## CPP

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
- 指针的偏移与越界
- c和c++的动态分配内存与释放

### 函数
- 函数基础
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