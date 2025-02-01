#include <iostream>
#include <string.h>
#include <cmath>
#include <algorithm>

using namespace std;

class Point
{
public:
    Point(int xx = 0, int yy = 0)
    {
        _x = xx;
        _y = yy;
    }
    Point(Point &p);

    int getX();
    int getY();

private:
    int _x;
    int _y;
};

Point::Point(Point &p)
{ // 复制构造函数的实现
    _x = p._x;
    _y = p._y;
}

int Point::getX()
{
    return this->_x;
}
int Point::getY()
{
    return this->_y;
}

class Line
{
public:
    Line(Point &a, Point &b);
    int getLength();

private:
    void calLength(); // 计算线段长度，并保存到属性 _len 中
    Point _pa, _pb;
    int _len;
};

Line::Line(Point &a, Point &b) : _pa(a), _pb(b)
{
    this->calLength();
}

int Line::getLength()
{
    return this->_len;
}

// 只考虑平行状况
void Line::calLength()
{
    if (this->_pa.getX() == this->_pb.getX())
    {
        this->_len = abs(this->_pa.getY() - this->_pb.getY());
    }
    else
    {
        this->_len = abs(this->_pa.getX() - this->_pb.getX());
    }
    return;
}

class Rectangle
{
public:
    Rectangle(Point &lb_pt, Point &rt_pt); // 两个输入参数分别是左下角，右上角

    int getPerimeter();                    // 周长
    int getArea();                         // 面积
    int getOverlappedArea(Rectangle &rec); // 计算与另一个矩形重合面积

private:
    bool isOverlapped(Rectangle &rec);
    Point _LB, _RT, _LT, _RB; // 左下角，右上角，左上角，右下角
    Line _horizontal_line;
    Line _vertical_line;
};

Rectangle::Rectangle(Point &lb_pt, Point &rt_pt) : _LB(lb_pt),
                                                   _RT(rt_pt),
                                                   _LT(_LB.getX(), _RT.getY()),
                                                   _RB(_RT.getX(), _LB.getY()),
                                                   _horizontal_line(_LB, _RB),
                                                   _vertical_line(_LB, _LT)
{
}

int Rectangle::getPerimeter()
{
    return 2 * (this->_horizontal_line.getLength() + this->_vertical_line.getLength());
}

int Rectangle::getArea()
{
    return this->_horizontal_line.getLength() * this->_vertical_line.getLength();
}

int Rectangle::getOverlappedArea(Rectangle &rec)
{
    if (!this->isOverlapped(rec))
    {
        return 0;
    }
    else
    {
        int x1 = max(this->_LB.getX(), rec._LB.getX());
        int y1 = max(this->_LB.getY(), rec._LB.getY());
        int x2 = min(this->_RT.getX(), rec._RT.getX());
        int y2 = min(this->_RT.getY(), rec._RT.getY());
        Point p1(x1, y1), p2(x2, y2);
        Rectangle rec1(p1, p2);
        return rec1.getArea();
    }
}

bool Rectangle::isOverlapped(Rectangle &rec)
{
    bool a1 = rec._LB.getX() <= this->_RT.getX() && rec._LB.getY() <= this->_RT.getY() && rec._LB.getX() >= this->_LB.getX() && rec._LB.getY() >= this->_LB.getY();
    bool a2 = rec._RT.getX() <= this->_RT.getX() && rec._RT.getY() <= this->_RT.getY() && rec._RT.getX() >= this->_LB.getX() && rec._RT.getY() >= this->_LB.getY();
    bool a3 = rec._LT.getX() <= this->_RT.getX() && rec._LT.getY() <= this->_RT.getY() && rec._LT.getX() >= this->_LB.getX() && rec._LT.getY() >= this->_LB.getY();
    bool a4 = rec._RB.getX() <= this->_RT.getX() && rec._RB.getY() <= this->_RT.getY() && rec._RB.getX() >= this->_LB.getX() && rec._RB.getY() >= this->_LB.getY();
    return a1 || a2 || a3 || a4;
}

int main()
{
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    int x3, y3, x4, y4;
    cin >> x3 >> y3 >> x4 >> y4;

    Point p1(x1, y1), p2(x2, y2), p3(x3, y3), p4(x4, y4);

    Rectangle rec1(p1, p2);
    Rectangle rec2(p3, p4);
    cout << rec1.getPerimeter() << " " << rec1.getArea();
    cout << " " << rec2.getPerimeter() << " " << rec2.getArea();
    cout << " " << rec1.getOverlappedArea(rec2);
    return 0;
}
