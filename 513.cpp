#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
#define ll long long

using namespace std;
int m;
int a[20],len;
ll ans=-0x3f3f3f3f;
void dfs(int position,ll tot,ll front,int mun){
    if(mun==m){
        ll x = 0;
        for(int i=position;i<=len;i++){
            x *= 10;
            x+=a[i];
        }
        tot += x;
        ans = max(ans, tot);
        return;
    }
    if(position==len){
        return;
    }
    dfs(position + 1, tot + front, a[position + 1], mun + 1);
    dfs(position + 1, tot, front * 10 + a[position + 1], mun);
    return;
}
int main() {
    scanf("%d", &m);
    string str;
    cin >> str;
    len = str.length();
    for (int i = 0; i < len;i++){
        a[i+1] = str[i] - '0';
    }
    dfs(1, 0, a[1],0);
    printf("%lld\n", ans);
    return 0;
}