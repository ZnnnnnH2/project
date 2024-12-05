#include <iostream>
#include <stdio.h>
#include <math.h>

using namespace std;
// long long jc[1001]; //阶乘数组
// long long jiecheng(int n){
//     if(jc[n]!=0){
//         return jc[n];
//     }
//     else{
//         return jc[n]=jiecheng(n-1)*n;
//     }
// }
// double m[1001];
// double mi(int n){
//     if(m[n]!=0){
//         return m[n];
//     }
//     else{
//         return m[n]=mi(n-1)*m[1];
//     }
// }
inline int sgn(int x)
{
    if (x % 4 == 0 or x % 4 == 1)
    {
        return 1;
    }
    else
    {
        return -1;
    }
}
double m[10000005];
int main()
{
    // freopen("180.txt", "w", stdout);
    double SIN = 0, COS = 0;
    double s, c;
    double x, t;
    for (int i = 0; i <= 10000000; i++)
    {
        m[i] = 0;
    }
    cin >> x >> t;
    s = sin(x);
    c = cos(x);
    m[0] = 1;
    m[1] = x;
    int i = 1;
    for (int j = 2; j <= 10000000; j++)
    {
        m[j] = m[j - 1] * x / j;
    }
    while (abs(SIN - s) - t > 1e-7)
    {
        SIN += sgn(i) * m[i];
        i += 2;
        cout << i << " " << SIN << " " << m[i] << endl;
    }
    // for(int j=1;j<=i;j++){
    //     cout<<m[j]<<" "<<endl;
    // }

    cout << SIN << endl;
    i = 0;
    while (abs(COS - c) > t)
    {
        COS += sgn(i) * m[i];
        i += 2;
    }
    cout << COS << endl;
    return 0;
}