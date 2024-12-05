#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
int a[100005];
bool Check(int x, int y)
{
    for (int i = 0; i < y; i++)
    {
        if (a[x + i] != a[x + y + i])
        {
            return false;
        }
    }
    return true;
}
int main()
{
    memset(a, 0, sizeof(a));
    // freopen("133.in", "r", stdin);
    // freopen("133.out", "w", stdout);
    int N, D;
    scanf("%d %d", &N, &D);
    printf("%d.", N / D);
    N %= D;
    if (N == 0)
    {
        printf("0");
        return 0;
    }
    int tot = 0;
    int positon = 0;
    for (int i = 0; i < 100005; i++)
    {
        N *= 10;
        a[i] = N / D;
        N %= D;
        if(a[i]==0 and a[i-1]==0){
            tot++;
        }
        else {
            tot = 0;
        }
    }
    if(tot>100){
        for (int i = 100004; i >= 0;i--){
            if(a[i]!=0){
                positon = i;
                break;
            }
        }
        for (int i = 0;i<=positon;i++){
            printf("%d", a[i]);
        }
        return 0;
    }
    // for (int i = 0; i < 100005; i++)
    // {
    //     printf("%d", a[i]);
    // }
    for (int i = 0; i < 100005; i++)
    {
        for (int j = 1; j <= 20; j++)
        {
            if (Check(i, j))
            {
                for (int k = 0; k < i; k++)
                {
                    printf("%d", a[k]);
                }
                // bool Flag = false;
                // for (int k = 0; k < j; k++)
                // {
                //     if (a[i + k] != 0)
                //     {
                //         Flag = true;
                //         break;
                //     }
                // }
                // if (!Flag)
                // {
                //     return 0;
                // }
                printf("(");
                for (int k = 0; k < j; k++)
                {
                    printf("%d", a[i + k]);
                }
                printf(")");
                return 0;
            }
        }
    }
    return 0;
}