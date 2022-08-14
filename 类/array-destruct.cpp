#include <iostream>
#include <cstring>

using namespace std;
// array是对象时：销毁需要用delete []array
class Student
{
  private:
    char * name;
    int born;
    bool male; 
  public:
    Student()
    {
        name = new char[1024]{0};
        born = 0;
        male = false;
        cout << "Constructor: Person()" << endl;
    }
    Student(const char * initName, int initBorn, bool isMale)
    {
        name =  new char[1024];
        setName(initName);
        born = initBorn;
        male = isMale;
        cout << "Constructor: Person(const char, int , bool)" << endl;
    }
    ~Student()
    {
        cout << "To destroy object: " << name << endl;
        delete [] name;
    }

    void setName(const char * s)
    {
        strncpy(name, s, 1024);
    }
    void setBorn(int b)
    {
        born = b;
    }
    // the declarations, the definitions are out of the class
    void setGender(bool isMale);
    void printInfo();
};

void Student::setGender(bool isMale)
{
    male = isMale;
}
void Student::printInfo()
{
    std::cout << "Name: " << name << std::endl;
    std::cout << "Born in " << born << std::endl;
    std::cout << "Gender: " << (male ? "Male" : "Female") << std::endl;
}

int main()
{
    Student * class1 = new Student[3]{
        {"Tom", 2000, true},
        {"Bob", 2001, true},
        {"Amy", 2002, false},
    };

    class1[1].printInfo();
    //delete class1; //只会销毁第一个对象
    delete []class1; // 会销毁整个数组中所有对象


    return 0;
}