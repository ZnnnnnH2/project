#include <iostream>
#include <stdio.h>

#define ll long long

using namespace std;

const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
const int mod = 10000;

int main()
{
    int n;
    scanf("%d", &n);
    n %= 15000;
    if (n == 0)
    {
        printf("0\n");
        return 0;
    }
    if (n == 1)
    {
        printf("1\n");
        return 0;
    }
    n -= 2;
    int fn_2 = 1, fn_1 = 1, t;
    while (n--)
    {
        t = fn_2 + fn_1;
        t %= mod;
        fn_2 = fn_1;
        fn_1 = t;
    }
    printf("%d\n", fn_1);
    return 0;
}