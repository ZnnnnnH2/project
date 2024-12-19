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
int Number[10];
long long betw[10][10];
long long ans1 = 0, ans2 = 0;
int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        Number[i] = i;
    }
    do
    {
        for (int i = 1; i <= m; i++)
        {
            for (int j = i; j <= m; j++)
            {
                betw[i][j] = betw[i][j - 1] * 10 + Number[j];
            }
        }
        for (int i = 1; i <= m; i++)
        {
            for (int j = i+1; j < m; j++)
            {
                int a = betw[1][i];
                int b = betw[i + 1][j];
                int c = betw[j + 1][m];
                if (b % c == 0 and n == a + b / c)
                {
                    // printf("%d+%d/%d\n", a, b, c);
                    ans1++;
                }
                if (n == a + b % c)
                {
                    ans2++;
                }
            }
        }
    } while (next_permutation(Number + 1, Number + m + 1));
    printf("%lld %lld\n", ans1, ans2);
    return 0;
}