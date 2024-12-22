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
const int N = 1e5 + 5;
int n;
long long ans = 0;
void dfs(int x, int t, int head)
{
    if (x > n)
    {
        if (head != t)
            ans++;
        return;
    }
    for (int i = 1; i <= 3; i++)
    {
        if (i != t)
        {
            dfs(x + 1, i,head);
        }
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= 3; i++)
    {
        dfs(2, i, i);
    }
    printf("%lld\n", ans);
    return 0;
}