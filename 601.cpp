#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;
int a[N];
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &a[i]);
    }
    a[0] = 1;
    a[m + 1] = 1;
    int front = 0;
    int ans = 0;
    for (int i = 1; i <= m + 1; i++)
    {
        if (a[i] == 1)
        {
            if (front % 2 == 1)
            {
                ans += ((front + 1) / 2) * ((n + 1) / 2);
                ans += ((front / 2) * (n / 2));
            }
            else
            {
                ans += (front / 2) * n;
            }
            front = 0;
            // printf("%d\n", ans);
        }
        else
        {
            front++;
        }
    }
    printf("%d\n", ans);
    return 0;
}