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
const int N = 225;
long long ans[N];
void dfs(int id, int fangqi, int lianxu, int fenshu)
{
    if (id > 18)
    {
        ans[fenshu]++;
        return;
    }
    if (fangqi > 3)
    {
        ans[fenshu]++;
        return;
    }
    if (lianxu >= 3)
    {
        ans[fenshu]++;
        return;
    }
    if (fenshu >= 120)
    {
        ans[fenshu]++;
        return;
    }
    dfs(id + 1, fangqi, 0, fenshu + 10);
    if(fangqi<=2)dfs(id + 1, fangqi + 1, lianxu, fenshu);
    dfs(id + 1, fangqi, lianxu + 1, fenshu <= 30 ? 0 : fenshu - (fenshu * (18 - id)) / 36);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    dfs(1, 0, 0, 0);
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        printf("%lld ", ans[x]);
    }
    return 0;
}