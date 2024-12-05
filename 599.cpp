#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;

int main()
{
    int n;
    scanf("%d", &n);
    char c;
    if (n < 10)
    {
        c = '0' + n;
    }
    else
    {
        c = 'A' + n - 10;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j < i; j++)
        {
            printf(" ");
        }
        for (int j = 1; j <= 2 * (n - i) + 1; j++)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    return 0;
}