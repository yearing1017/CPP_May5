// 结构体
#include <iostream>
#include <cstring>
using namespace std;

struct Student
{
    char name[4]; // 
    int born;
    bool male; 
};

int main()
{
    Student stu = {"Yu", 2000, true};
    Student * pStu = &stu; //指向 该对象的首地址 即 name成员的首地址

    cout << stu.name << " was born in " << stu.born 
         << ". Gender: " << (stu.male ? "male" : "female") << endl;

    // 两种方法
    strncpy(pStu->name, "Li", 4);
    pStu->born = 2001;
    (*pStu).born = 2002;
    pStu->male = false;

    cout << stu.name << " was born in " << stu.born 
         << ". Gender: " << (stu.male ? "male" : "female") << endl;


    printf("Address of stu: %p\n", pStu); //C style
    cout << "Address of stu: " << pStu << endl; //C++ style
    cout << "Address of stu: " << &stu << endl;
    cout << "Address of member name: " << &(pStu->name) << endl;
    cout << "Address of member born: " << &(pStu->born) << endl;
    cout << "Address of member male: " << &(pStu->male) << endl;

    cout << "sizeof(pStu) = " << sizeof(pStu) << endl;
    
    return 0;

    /**
        Yu was born in 2000. Gender: male
        Li was born in 2002. Gender: female
        Address of stu: 0x7ffeea986450
        Address of stu: 0x7ffeea986450
        Address of stu: 0x7ffeea986450
        Address of member name: 0x7ffeea986450
        Address of member born: 0x7ffeea986454
        Address of member male: 0x7ffeea986458
        sizeof(pStu) = 8
     **/
}