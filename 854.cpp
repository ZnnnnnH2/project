#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <unordered_map>

using namespace std;
unordered_map<int, int> mp;
int a[10000005];

int main()
{
    long long ans = 0;
    int n;
    int tot = 0;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int s;
        scanf("%d", &s);
        for (int j = 1; j <= s; j++)
        {
            int x;
            scanf("%d", &x);
            if (mp.find(x) == mp.end())
            {
                mp.insert(make_pair(x, 1));
                a[++tot] = x;
            }
            else
            {
                mp[x]++;
            }
        }
    }
    for (int i = 1; i <= tot; i++)
    {
        if (mp[a[i]] == 1)
        {
            ans += a[i];
        }
    }
    printf("%lld\n", ans);
    return 0;
}