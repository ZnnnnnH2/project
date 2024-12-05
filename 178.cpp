#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
bool p[2000];

int main()
{
    p[1] = 1;
    int t = sqrt(1000);
    for (int i = 2; i <= t; i++)
    {
        if (p[i] == 0)
        {
            for (int j = 2; i * j <= 1000; j++)
            {
                p[i * j] = 1;
            }
        }
    }
    int n;
    cin >> n;
    while (n)
    {
        n--;
        int a;
        cin >> a;
        if (!p[a])
        {
            cout << "YES ";
        }
        else
        {
            cout << "NO ";
        }
    }
    return 0;
}