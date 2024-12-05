#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;

int main()
{
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int ans = 0;
    int pg = 0, kp = 0;
    ans = d / a;
    pg = d / a;
    kp = d / a;
    bool flag = false;
    do{
        flag = false;
        if(pg>=b){
            int k=pg/b;
            ans += k;
            pg-=k*b;
            kp+=k;
            pg+=k;
            flag = true;
        }
        if(kp>=c){
            int k=kp/c;
            ans += k;
            kp-=k*c;
            pg+=k;
            kp+=k;
            flag = true;
        }
    }while(flag);
    cout << ans << endl;
    return 0;
}