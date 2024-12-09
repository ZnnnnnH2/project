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
const int N = 50 + 5;
int a[N][N];
int b[N][N];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    int t;
    scanf("%d", &t);
    t /= 90;
    while (t < 0)
    {
        t += 4;
    }
    t%=4;
    int(*op)[N] = a;
    int(*ans)[N] = b;
    while (t--)
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                ans[j][n - i + 1] = op[i][j];
            }
        }
        swap(n, m);
        swap(op, ans);
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            printf("%d ", op[i][j]);
        }
        printf("\n");
    }
    return 0;
}