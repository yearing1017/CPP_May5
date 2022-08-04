#include <iostream>
using namespace std;


int demo1()
{
    int num = 10;
    int * p1 = NULL, * p2 = NULL; // declaration, initialize to 0
    p1 = &num; // take the address of num, assign to p1
    p2 = &num; // take the address of num, assign to p2

    cout << "num = " << num << endl;

    *p1 = 20; // assign to num
    cout << "num = " << num << endl;

    *p2 = 30; // assign to num
    cout << "num = " << num << endl;

    return 0;
}



int main()
{   
    int num = 10;
    int * p = &num; // p为指针 &num表示取num的首地址
    
    int ** pp = &p; // 指针的指针
    *(*pp) = 20;
    cout << "num = " << num << endl;

    *p = 30;
    cout << "num = " << num << endl;

    return 0;

    // result:
    // num = 20
    // num = 30
}

