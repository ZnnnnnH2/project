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
int w[N];
int mun[N];
ll dp[N];
struct node
{
    int w;
    int mun;
    node()
    {
        w = 0;
        mun = 0;
    }
    bool operator<(const node &a) const
    {
        if (mun == a.mun)
        {
            return w < a.w;
        }
        return mun > a.mun;
    }
} querry[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &w[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &mun[i]);
    }
    int maxx = -inf;
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &querry[i].w);
        if (querry[i].w > maxx)
        {
            maxx = querry[i].w;
        }
    }
    dp[0] = 1;
    for (int i = 1; i <= n;i++){
        for (int j = maxx;j>=w[i];j--){
            for (int k = 1; k <= mun[i];k++){
                if(j-w[i]*k<0){
                    break;
                }
                if(dp[j-w[i]*k]){
                    dp[j]+=dp[j-w[i]*k];
                }
            }
        }
        // for(int j=1;j<=maxx;j++){
        //     printf("%lld ", dp[j]);
        // }
        // printf("\n");
    }
    for (int i = 1; i <= m;i++){
        // printf("%lld\n", dp[querry[i].w]);
        querry[i].mun = dp[querry[i].w];
    }
    sort(querry + 1, querry + m + 1);
    for (int i = 1; i <= m;i++){
        printf("%d:%d\n", querry[i].w, querry[i].mun);
    }
    return 0;
}