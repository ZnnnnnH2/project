#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
void bitget(int x)
{
    if (x == 0)
    {
        printf("0");
        return;
    }
    int k = x;
    int i = 0;
    int tot = 0;
    int *p = new int[100];
    int all = 0;
    while (k)
    {
        int flag = (k & 1);
        k >>= 1;
        if (flag)
        {
            p[++all] = i;
        }
        i++;
    }
    for (int j = all; j >= 1; j--)
    {
        if (j < all)
        {
            printf("+");
        }
        if (p[j] == 1)
        {
            printf("2");
        }
        else
        {
            printf("2(");
            bitget(p[j]);
            printf(")");
        }
    }
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    bitget(n);
    return 0;
}