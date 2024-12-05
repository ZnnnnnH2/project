#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;
int n, tot = 0;
int q[13];
void fs(int k)
{
    if (k > n)
    {
        tot++;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j < k; j++)
        {
            if (q[j] == i)
            {
                flag = false;
            }
            if (abs(j - k) == abs(q[j] - i))
            {
                flag = false;
            }
        }
        if (flag)
        {
            q[k] = i;
            fs(k + 1);
            q[k] = 0;
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        q[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        q[1] = i;
        fs(2);
    }
    printf("%d\n", tot);
    return 0;
}