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
const int N = 10 + 5;
int ans = inf;
int n;
int m[N][N];
int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int vis[N][N];
void dfs(int x, int y, int step)
{
    if(step >= ans) return;
    if (x == n and y == n)
    {
        ans = min(ans, step);
        return;
    }
    vis[x][y] = step;
    for (int i = 1; i <= m[x][y]; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            int nx = x + dir[j][0] * i;
            int ny = y + dir[j][1] * i;
            if (nx >= 1 and nx <= n and ny >= 1 and ny <= n)
            {
                if (vis[nx][ny]>step+1)
                {
                    // printf("%d %d\n", nx, ny);
                    dfs(nx, ny, step + 1);
                }
            }
        }
    }
    return;
}
int main()
{
    memset(vis, 0x3f, sizeof(vis));
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    vis[1][1] = 1;
    dfs(1, 1, 0);
    printf("%d\n", ans == inf ? -1 : ans);
    return 0;
}