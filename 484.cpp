#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int a[1005];

int main()
{
    a[0] = -0x7fffffff;
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
    }
    sort(a + 1, a + n + 1);
    bool flag = false;
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == a[i - 1])
        {
            tot++;
        }
        else
        {
            if (tot != 0)
            {
                printf("%d:%d\n", a[i - 1], tot + 1);
                flag = true;
            }
            tot = 0;
        }
    }
    if (tot != 0)
    {
        printf("%d:%d\n", a[n], tot + 1);
        flag = true;
    }
    if (!flag)
    {
        printf("NO\n");
    }
    return 0;
}