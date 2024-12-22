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
const int N = 5e2 + 5;
const ll mod = 202420242024;
ll miltipy(ll a, ll b)
{
    ll ans = 0;
    while (b)
    {
        if (b & 1)
            ans = (ans + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ans;
}

ll jiecheng[N];
ll C[N][N];
ll f[N];

int main()
{
    int n;
    scanf("%d", &n);
    jiecheng[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        jiecheng[i] = jiecheng[i - 1] * i % mod;
    }
    C[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        C[i][0] = 1;
        for (int j = 1; j <= n; j++)
        {
            C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % mod;
        }
    }
    f[1] = 0;
    f[2] = 1;
    for (int i = 3; i <= n; i++)
    {
        f[i] = jiecheng[i] - 1;
        for (int j = i - 1; j>= 2;j--)
        {
            f[i] -= miltipy(C[i][i-j], f[j]);
            f[i] %= mod;
            if (f[i] < 0)
                f[i] += mod;
        }
    }
    printf("%lld\n", f[n]);
    return 0;
}