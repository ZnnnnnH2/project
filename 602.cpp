#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;
int a[N];
bool vis[N];
int len = 0;
int main()
{
    int n;
    scanf("%d", &n);
    int t = sqrt(N);
    vis[0] = 1;
    vis[1] = 1;
    for (int i = 2; i <= t; i++)
    {
        if (!vis[i])
        {
            for (int j = i * i; j <= N; j += i)
            {
                vis[j] = 1;
            }
        }
    }
    for (int i = 2; i <= N; i++)
    {
        if (!vis[i])
        {
            a[++len] = i;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        int ans = 0;
        for (int j = 1; j <= len;j++){
            if(a[j]>x){
                break;
            }
            for (int k = j+1; k <= len;k++){
                int l=x-a[j]-a[k];
                if(l>1000){
                    continue;   
                }
                if(l<=a[k]){
                    break;
                }
                if(!vis[l]){
                    ans++;
                    continue;
                }
            }
        }
        printf("%d ", ans);
    }
    return 0;
}