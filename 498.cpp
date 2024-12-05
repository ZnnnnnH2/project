#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int former[60][60];
int later[60][60];
int n;
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", former[i][j]);
        }
        printf("\n");
    }
    return;
}
bool c1()
{
    int k[60][60];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k[j][n - i - 1] = former[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k[i][j] != later[i][j])
                return false;
        }
    }
    // print();
    return true;
}
bool c2()
{
    int k[60][60];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k[n - j - 1][i] = former[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k[i][j] != later[i][j])
                return false;
        }
    }
    return true;
}
bool c3()
{
    int k[60][60];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            k[n - i - 1][n - j - 1] = former[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (k[i][j] != later[i][j])
                return false;
        }
    }
    return true;
}
bool c4()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (former[i][j] != later[i][j])
                return false;
        }
    }
    return true;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &former[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", &later[i][j]);
        }
    }
    if (c1())
    {
        printf("1\n");
    }
    else if (c2())
    {
        printf("2\n");
    }
    else if (c3())
    {
        printf("3\n");
    }
    else if (c4())
    {
        printf("4\n");
    }
    else
    {
        printf("5\n");
    }
    return 0;
}