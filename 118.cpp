#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int mod = 10000;
void Mtrix(int m[2][2], int n)
{
    if (n == 0)
    {
        m[0][1] = 0;
        return;
    }
    if (n == 1)
    {
        return;
    }
    if (n == 2)
    {
        int a = m[0][0], b = m[0][1], c = m[1][0], d = m[1][1];
        m[0][0] = (a * a + b * c) % mod;
        m[0][1] = (a * b + b * d) % mod;
        m[1][0] = (a * c + c * d) % mod;
        m[1][1] = (b * c + d * d) % mod;
        return;
    }
    if (n % 2 == 0)
    {
        Mtrix(m, n / 2);
        int a = m[0][0], b = m[0][1], c = m[1][0], d = m[1][1];
        m[0][0] = (a * a + b * c) % mod;
        m[0][1] = (a * b + b * d) % mod;
        m[1][0] = (a * c + c * d) % mod;
        m[1][1] = (b * c + d * d) % mod;
        return;
    }
    if (n % 2 == 1)
    {
        int a1 = m[0][0], b1 = m[0][1], c1 = m[1][0], d1 = m[1][1];
        Mtrix(m, (n - 1) / 2);
        int a = m[0][0], b = m[0][1], c = m[1][0], d = m[1][1];
        m[0][0] = (a * a + b * c) % mod;
        m[0][1] = (a * b + b * d) % mod;
        m[1][0] = (a * c + c * d) % mod;
        m[1][1] = (b * c + d * d) % mod;
        int a2 = m[0][0], b2 = m[0][1], c2 = m[1][0], d2 = m[1][1];
        m[0][0] = (a1 * a2 + b1 * c2) % mod;
        m[0][1] = (a1 * b2 + b1 * d2) % mod;
        m[1][0] = (a1 * c2 + c1 * d2) % mod;
        m[1][1] = (b1 * c2 + d1 * d2) % mod;
        return;
    }
}
int main()
{
    int n;
    scanf("%d", &n);
    n %= 15000;
    int m[2][2] = {{1, 1}, {1, 0}};
    Mtrix(m, n);
    printf("%d\n", m[0][1]);
    return 0;
}