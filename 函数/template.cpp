#include <iostream>
#include <typeinfo>
using namespace std;

template<typename T>
T sum(T x, T y)
{
    cout << "The input type is " << typeid(T).name() << endl;
    return x +
     y;
}
// Explicitly instantiate
template double sum<double>(double, double);

int tp1()
{
    auto val = sum(4.1, 5.2);
    cout << val << endl;
    return 0;
}

int tp2()
{
    // Implicitly instantiates product<int>(int, int)
    cout << "sum = " << sum<int>(2.2f, 3.0f) << endl;
    // Implicitly instantiates product<float>(float, float)
    cout << "sum = " << sum(2.2f, 3.0f) << endl;

    return 0;
}

struct Point
{
    int x;
    int y;
};

// Specialization for Point + Point operation
template<>
Point sum<Point>(Point pt1, Point pt2)
{
    cout << "The input type is " << typeid(pt1).name() << endl;
    Point pt;
    pt.x = pt1.x + pt2.x;
    pt.y = pt1.y + pt2.y;
    return pt;
}


int tp3()
{
    //Explicit instantiated functions
    cout << "sum = " << sum(1, 2) << endl;
    cout << "sum = " << sum(1.1, 2.2) << endl;

    Point pt1 {1, 2};
    Point pt2 {2, 3};
    Point pt = sum(pt1, pt2);
    cout << "pt = (" << pt.x << ", " << pt.y << ")" << endl;
    return 0;
}