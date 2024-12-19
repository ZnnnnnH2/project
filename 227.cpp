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
const int N = 75 + 5;
int w, h;
bool a[N][N];
bool via[N][N];
int dir[4][2] = {
    {0, 1},
    {0, -1},
    {1, 0},
    {-1, 0}};
char getc()
{
    char c;
    do
    {
        c = getchar();
    } while (c != 'X' and c != ' ');
    return c;
}
int ans = inf;
void dfs(int x1, int y1, int x2, int y2, int tot, int k)
{
    if (tot > ans)
    {
        return;
    }
    if (tot > 10)
    {
        return;
    }
    if (x1 == x2 and y1 == y2)
    {
        ans = ans > tot ? tot : ans;
        return;
    }
    if (x1 < 0 or y1 < 0)
    {
        return;
    }
    if (a[x1][y1])
    {
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int xn = x1 + dir[i][0];
        int yn = y1 + dir[i][1];
        if (!via[xn][yn])
        {
            via[xn][yn] = true;
            if (k == inf)
            {
                dfs(xn, yn, x2, y2, tot + 1, i);
            }
            else if ((k <= 1 and i <= 1) or (k > 1 and i > 1))
            {
                dfs(xn, yn, x2, y2, tot, i);
            }
            else
            {
                dfs(xn, yn, x2, y2, tot + 1, i);
            }
            via[xn][yn] = false;
        }
    }
    return;
}
int main()
{
    int w, h;
    scanf("%d %d", &w, &h);
    for (int i = 1; i <= h; i++)
    {
        for (int j = 1; j <= w; j++)
        {
            char c = getc();
            if (c == 'X')
            {
                a[i][j] = true;
            }
            else
            {
                a[i][j] = false;
            }
        }
    }
    for (int i = 0; i <= w + 2; i++)
    {
        a[h + 2][i] = true;
    }
    for (int i = 0; i <= h + 2; i++)
    {
        a[i][w + 2] = true;
    }
    // for(int i=1;i<=h;i++){
    //     for(int j=1;j<=w;j++){
    //         cout<<a[i][j];
    //     }
    //     cout<<endl;
    // }
    int T;
    cin >> T;
    while (T--)
    {
        memset(via, 0, sizeof(via));
        ans = inf;
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &y1, &x1, &y2, &x2);
        a[x1][y1] = 0;
        via[x1][y1] = true;
        dfs(x1, y1, x2, y2, 0, inf);
        a[x1][y1] = 1;
        if (ans != inf)
        {
            printf("%d\n", ans);
        }
        else
        {
            printf("impossible");
        }
    }
    return 0;
}