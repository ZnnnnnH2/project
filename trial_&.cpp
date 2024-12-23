#include <iostream>
#include <string.h>

class String
{
private:
    char *str;

public:
    String() : str(NULL) {} // 构造函数, 初始化str为NULL
    const char *c_str() { return str; }
    char *operator=(const char *s);

    ~String()
    {
        if (str)
            delete[] str;
    }
};

// 重载 =，使得obj = "hello" 能够成立
char *String::operator=(const char *s)
{

    if (str)
        delete[] str;

    if (s)
    { // s非NULL才执行拷贝
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
    else
        str = NULL;

    return str; // Q: 不要返回值可以不？ 局限是？
}

// 深拷贝
String &String::operator=(const String &s)
{

    if (str == s.str)
        return *this;
    if (str)
        delete[] str;

    if (s.str)
    { // s.str非NULL才执行拷贝
        str = new char[strlen(s.str) + 1];
        strcpy(str, s.str);
    }
    else
        str = NULL;

    return *this;
}

int main()
{
    String s;
    s = "Good Luck,";
    std::cout << s.c_str() << std::endl;

    // String s2 = "hello!"; //<<< 错误！ Q: why?

    s = "Shenzhou8!";
    std::cout << s.c_str() << std::endl;
    return 0;
}
