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
class fushu
{
public:
    fushu(double shibu,double xubu):shibu(shibu),xubu(xubu){}
    fushu(const fushu &f):shibu(f.shibu),xubu(f.xubu){}
    ~fushu(){}
    fushu &operator=(const fushu &f){
        shibu=f.shibu;
        xubu=f.xubu;
        return *this;
    }
    fushu &operator+(const double a){
        shibu = a;
        xubu = 0;
        return *this;
    }
    bool operator==(const fushu &f)const{
        return shibu==f.shibu&&xubu==f.xubu;
    }
    bool operator!=(const fushu &f)const{
        return shibu!=f.shibu||xubu!=f.xubu;
    }
    double getshibu()const{
        return shibu;
    }
    double getxubu()const{
        return xubu;
    }
    fushu gonge(const fushu &f) const {
        return fushu(f.shibu,-f.xubu);
    }
    fushu operator-()const{
        return fushu(-shibu,-xubu);
    }
    fushu operator+(const fushu &f)const{
        return fushu(shibu+f.shibu,xubu+f.xubu);
    }
    fushu operator-(const fushu &f)const{
        return fushu(shibu-f.shibu,xubu-f.xubu);
    }
    fushu operator*(const fushu &f)const{
        return fushu(shibu*f.shibu-xubu*f.xubu,shibu*f.xubu+xubu*f.shibu);
    }
    fushu&operator++(){
        this->shibu++;
        return *this;
    }
    fushu operator++(int){
        fushu temp(*this);
        ++(*this);
        return temp;
    }
    operator double()const{
        return sqrt(shibu*shibu+xubu*xubu);
    }
    friend ostream &operator<<(ostream &os, const fushu &f){
        os << f.shibu << "+" << f.xubu << "i";
        return os;
    }
private:
    double shibu, xubu;
};

int main()
{
    fushu f(1, 2);
    cout << f++;
    cout << f;
    return 0;
}