#include<iostream>
#include<stdio.h>
using namespace std;
struct point{
    int x,y;
    point(){   //构造函数
        x=0;
        y=2;
    }
    point(int a,int b){   //构造函数
        x=a;
        y=b;
    }
    void printff(){    //成员函数
        printf("%d %d\n",x,y);
    }
    bool operator<(point &p){  //运算符重载
        return x<p.x&&y<p.y;
    }
    bool operator==(point &p){  //运算符重载
        return x==p.x&&y==p.y;
    }
    point operator+(point &p){  //运算符重载
        x=x+p.x;
        y=y+p.y;
        return *this;
    }
    void operator=(point &p){  //运算符重载
        x=p.x;
        y=p.y;
    }
    friend ostream& operator<<(ostream &out, point &p){  //运算符重载
        out<<p.x<<" "<<p.y<<endl;
        return out;
    }
};

int main(){
    point p1;
    point *p;
    p=&p1;
    p->x=10;
    p->printff();
    point *p2;
    p2 = new point(4,9);
    p2->printff();
    delete p2;
    cout<<p1<<endl;
}