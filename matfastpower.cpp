#include <cstdio>
#include <iostream>
using namespace std;
const int mod = 10000;

void mat_mult(int a[2][2], int b[2][2], int c[2][2])
{
    int c1, c2, c3, c4;
    c1 = a[0][0] * b[0][0] + a[0][1] * b[1][0];
    c2 = a[0][0] * b[0][1] + a[0][1] * b[1][1];
    c3 = a[1][0] * b[0][0] + a[1][1] * b[1][0];
    c4 = a[1][0] * b[0][1] + a[1][1] * b[1][1];
    c[0][0] = c1;
    c[0][1] = c2;
    c[1][0] = c3;
    c[1][1] = c4;
    c[0][0] %= mod;
    c[0][1] %= mod;
    c[1][0] %= mod;
    c[1][1] %= mod;
}

void mat_pow(int m[2][2], int n, int result[2][2])
{
    int temp[2][2] = {{1, 1}, {0, 1}}; // 单位矩阵
    while (n)
    {
        if (n % 2 == 1)
        {
            mat_mult(result, m, result);
        }
        mat_mult(m, m, m);
        n /= 2;
    }
    // mat_mult(result, m, result);
}

int main()
{
    int n;
    cin >> n;
    if (n == 0)
    {
        cout << 0;
        return 0;
    }
    int f[2][2] = {{1, 1}, {1, 0}};
    int result[2][2] = {{1, 0}, {0, 1}};
    mat_pow(f, n, result);
    cout << result[0][1];
}