#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    int a;
    scanf("%d", &a);
    while (a != 0)
    {
        int ans = 0;
        for (int i = 1; i <= a; i++)
        {
            int temp = i;
            int sum = i;
            while (temp)
            {
                sum += temp % 10;
                temp /= 10;
            }
            if (sum == a)
            {
                ans = i;
                break;
            }
        }
        printf("%d\n", ans);
        scanf("%d", &a);
    }
    return 0;
}