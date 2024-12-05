#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e2 + 5;
int a[N];
int order[N][N];
int via[N];
bool flag[N];
int main()
{
    int n, m;
    cin >> n >> m;
    for (int j = 1; j <= m; j++)
    {
        scanf("%d", &order[j][0]);
        for (int i = 1; i <= order[j][0]; i++)
        {
            scanf("%d", &order[j][i]);
            flag[order[j][i]] = 1;
        }
        via[order[j][1]] = j;
        flag[order[j][1]] = 0;
    }
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!flag[i])
        {
            a[++len] = i;
        }
    }
    int tot = 0;
    do
    {
        tot++;
        printf("%d. ", tot);
        for (int i = 1; i <= len; i++)
        {
            printf("%d ", a[i]);
            if (!via[a[i]])
            {
                continue;
            }
            else
            {
                int j = via[a[i]];
                for (int k = 2; k <= order[j][0]; k++)
                {
                    printf("%d ", order[j][k]);
                }
            }
        }
        printf("\n");
    } while (next_permutation(a + 1, a + len + 1));
    return 0;
}