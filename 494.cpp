#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
struct node
{
    int mun;
    int id;
    node(int a = 0, int b = 0) : mun(a), id(b) {}
    bool operator<(const node &a) const
    {
        return mun < a.mun;
    }
} a[100];

bool flag[1005];

int main()
{
    int n;
    scanf("%d", &n);
    memset(flag, false, sizeof(flag));
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i].mun);
        flag[a[i].mun] = true;
        a[i].id = i;
    }
    // sort(a + 1, a + n + 1);
    int x;
    scanf("%d", &x);
    for (int i = 1; i <= n; i++)
    {
        if (x - a[i].mun > 0)
        {
            if (flag[x - a[i].mun])
            {
                printf("%d ", a[i].id);
                for (int j = i + 1; j <= n; j++)
                {
                    if (a[j].mun == x - a[i].mun)
                    {
                        printf("%d\n", a[j].id);
                    }
                }
                return 0;
            }
        }
    }
    return 0;
}