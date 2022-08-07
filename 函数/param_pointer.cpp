#include <iostream>
using namespace std;

int foo1(int x)
{
    x += 10; // x is a copy
    return x;
}


int foo2(int * p)
{
    (*p) += 10; // pointer-copy
    return *p;
}

int main()
{
    int num1 = 20;
    int num2 = foo1(num1);
    cout << "num1=" << num1 << endl;
    cout << "num2=" << num2 << endl;

    int * p = &num1; // 虽然传参进去的指针也是拷贝，但是指针指向相同，所以数值会被修改
    int num3 = foo2( p );
    cout << "num1=" << num1 << endl;
    cout << "*p=" << *p << endl;
    cout << "num3=" << num3 << endl;
    
    return 0;

    /*
        num1=20
        num2=30
        num1=30
        *p=30
        num3=30
    */
}
