#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
int direction[9][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}, {0, 0}};
ll dp[21][21];
int n, m, a, b;
bool Check(int x, int y, int len)
{
    for (int i = 0; i < len; i++)
    {
        int nx = a + direction[i][0];
        int ny = b + direction[i][1];
        if (x == nx && y == ny)
            return true;
    }
    return false;
}
ll Find(int sx, int sy, int ex, int ey, int len)
{
    memset(dp, 0, sizeof(dp));
    for (int i = sx; i <= ex; i++)
    {
        for (int j = sy; j <= ey; j++)
        {
            if (i == sx && j == sy)
            {
                if (Check(i, j, len))
                {
                    dp[i][j] = 0;
                }
                else
                {
                    dp[i][j] = 1;
                }
            }
            else if (!Check(i, j, len))
            {
                dp[i][j] = dp[max(i - 1, 0)][j] + dp[i][max(j - 1, 0)];
            }
            else
            {
                dp[i][j] = 0;
            }
        }
    }
    return dp[ex][ey];
}
int main()
{
    scanf("%d %d %d %d", &n, &m, &a, &b);
    ll ans = 0;
    ans += Find(0, 0, n, m, 9);
    ans += Find(0, 0, a, b, 8) * Find(a, b, n, m, 0);
    printf("%lld\n", ans);
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}