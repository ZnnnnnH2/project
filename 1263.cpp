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
const int N = 1e3 + 5;
const int base = 1e5;
ll generate_mixed_point(int x, int y)
{
    return (ll)x * base + y;
}
struct node
{
    int x, y;
    node(int x = 0, int y = 0) : x(x), y(y) {}
} p[N];
ll mixed_point[N];

int main()
{
    int n;
    scanf("%d", &n);
    while (n != 0)
    {
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &p[i].x, &p[i].y);
            mixed_point[i] = generate_mixed_point(p[i].x, p[i].y);
        }
        sort(mixed_point + 1, mixed_point + n + 1);
        ll ans = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = i + 1; j <= n; j++)
            {
                int x3 = (p[i].x + p[j].x + p[j].y - p[i].y)/2;
                int y3 = (p[i].y + p[j].y + p[i].x - p[j].x)/2;
                int x4 = (p[i].x + p[j].x + p[i].y - p[j].y)/2;
                int y4 = (p[i].y + p[j].y + p[j].x - p[i].x)/2;
                if((x3-p[i].x)*(x4-p[i].x)+(y3-p[i].y)*(y4-p[i].y)!=0 or (x3-p[j].x)*(x4-p[j].x)+(y3-p[j].y)*(y4-p[j].y)!=0)
                    continue;
                if (binary_search(mixed_point + 1, mixed_point + n + 1, generate_mixed_point(x3, y3)) && binary_search(mixed_point + 1, mixed_point + n + 1, generate_mixed_point(x4, y4)))
                {
                    ans++;
                }
            }
        }
        printf("%lld\n", ans/2);
        scanf("%d", &n);
    }
    return 0;
}