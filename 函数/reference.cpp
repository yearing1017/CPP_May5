#include <iostream>
using namespace std;

int main()
{
    int num = 0;
    int & num_ref = num; // 别名 指向同一个num
    cout << "num = " << num << endl;

    num_ref = 10;
    cout << "num = " << num << endl;

    return 0;
}
