#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
class A
{
public:
    A(int x = 0, int y = 0) : x(x), y(y), b(0) // 常量成员变量初始化 只能在初始化列表中初始化
    {
        cnt++;
    }
    A(const A &p) : x(p.x), y(p.y), b(p.b) // 常量成员变量初始化 只能在初始化列表中初始化
    {
        cnt++;
    }
    ~A()
    {
        cnt--;
    }
    void change_x(int xx)
    {
        x = xx; // 常量对象不能调用非常量成员函数
    }
    void change_y(int yy)
    {
        y = yy; // 常量对象不能调用非常量成员函数
    }
    int get_x() const // 常量成员函数:不能修改成员变量
    {
        z++; // 可变成员变量可以在常函数中修改
        return x;
    }
    int get_y() const
    {
        return y;
    }
    A get_all() const
    {
        return A(x, y);
    }
    static void show()
    { // 静态成员函数
        cout << cnt << endl;
    }
    static int getcnt() {} // 静态成员函数
    bool operator<(const A &a) const
    {
        return x < a.x;
    }

private:
    static int cnt; // 静态成员变量
    int x, y;
    mutable int z;      // 可变成员变量
    static const int a; // 静态常量成员
    const int b;        // 常量成员
};
const int A::a = 100; // 静态常量成员初始化
int A::cnt = 0;       // 静态成员变量初始化
int main()
{
    const int a = 10, n = 1; // 常量
    // a = 20; //error
    // n = 2; //error
    int const b = 10, m = 1; // 常量
    // b = 20; //error
    // m = 2; //error
    // const int 和 int const 是一样的
    const A a1(1, 2); // 常量对象
    // a1.change_x(3); //error 常量对象不能调用非常量成员函数
    a1.get_all().change_x(3); // 可以调用
    cout << a1.get_x() << endl;
    A a2(1, 3);
    const A &a3 = a2; // 常量引用
    a3.get_x();
    // a3.change_x(3);    //error 常量引用不能调用非常量成员函数
    return 0;
}