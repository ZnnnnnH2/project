#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;

int main()
{
    int a[20];
    char c;
    char b[20];
    scanf("%c-%c%c%c-%c%c%c%c%c-%c", &b[1], &b[2], &b[3], &b[4], &b[5], &b[6], &b[7], &b[8], &b[9], &c);
    int tot = 0;
    for(int i = 1; i <= 9; i++)
    {
        a[i] = b[i] - '0';
    }
    for (int i = 1; i <= 9; i++)
    {
        tot += a[i] * i;
        tot %= 11;
    }
    if (0 <= tot && tot <= 9)
    {
        if (tot == c - '0')
        {
            printf("Right");
            return 0;
        }
        else
        {
            printf("%d-%d%d%d-%d%d%d%d%d-%d", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9], tot);
        }
    }
    else
    {
        if (tot == 10 && c == 'X')
        {
            printf("Right");
            return 0;
        }
        else
        {
            printf("%d-%d%d%d-%d%d%d%d%d-X", a[1], a[2], a[3], a[4], a[5], a[6], a[7], a[8], a[9]);
        }
    }
    return 0;
}
