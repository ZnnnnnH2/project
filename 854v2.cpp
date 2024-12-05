#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
const int K = 1e6 + 5;
char flag[2 * K];

int main()
{
    int maxx = -0x7fffffff;
    int n;
    long long ans = 0;
    memset(flag, 0, sizeof(flag));
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        int s;
        scanf("%d", &s);
        for (int j = 0; j < s; j++)
        {
            int x;
            scanf("%d", &x);
            x += K;
            if (x > maxx)
                maxx = x;
            if (flag[x] <= 2)
            {
                flag[x]++;
            }
        }
    }
    for(int i = 0; i <= maxx; i++)
    {
        if (flag[i] == 1) ans+=i-K;
    }
    printf("%lld\n", ans);
    return 0;
}