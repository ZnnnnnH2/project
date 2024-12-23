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
const int inf=0x3f3f3f3f;
const int N=1e5+5;
class point{
public:
    point(int x=0,int y=0):x(x),y(y){
        cnt++;
    }
    point(const point &p):x(p.x),y(p.y){
        cnt++;
    }
    ~point(){
        cnt--;
    }
    static void show(){ //静态成员函数
        cout<<cnt<<endl;
    }
    static int getcnt(){} //静态成员函数
    
private:
    static int cnt; //静态成员变量
    int x,y;
};
int point::getcnt(){ //静态成员函数定义 不能加static
    return cnt;
}
int point::cnt=0; //静态成员变量初始化
int main() {
    // int point::cnt = 0;  error 静态成员变量只能在类外初始化
    return 0;
}