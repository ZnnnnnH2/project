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
const int N = 1e2 + 5;
int a[N][N][2];
struct node
{
    ll dis;
    int id;
    bool operator<(const node &a) const
    {
        if (dis == a.dis)
        {
            return id < a.id;
        }
        return dis < a.dis;
    }
} dis[N * N];
int head[N];

inline ll distance(ll x1, ll y1, ll x2, ll y2)
{
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}
int main()
{
    int m, k;
    scanf("%d%d", &m, &k);
    for (int i = 1; i <= m; i++)
    {
        int n;
        scanf("%d", &n);
        a[i][0][0] = n;
        for (int j = 1; j <= n; j++)
        {
            scanf("%d %d", &a[i][j][0], &a[i][j][1]);
        }
    }
    int x, y;
    scanf("%d%d", &x, &y);
    int tot = 0;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= a[i][0][0]; j++)
        {
            dis[++tot].dis = distance(x, y, a[i][j][0], a[i][j][1]);
            dis[tot].id = i;
        }
    }
    sort(dis + 1, dis + 1 + tot);
    while(dis[k+1].dis==dis[k].dis){
        k++;
    }
    for (int i = 1; i <= k; i++)
    {
        head[dis[i].id]++;
    }
    int ans = 1;
    for (int i = 2; i <= m; i++)
    {
        if (head[i] > head[ans])
        {
            ans = i;
        }
    }
    printf("%d\n", ans);
    return 0;
}