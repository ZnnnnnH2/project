#include <math.h>
#include <stdio.h>
#include <string.h>

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;
struct node
{
    char str[5];
    int right_mun;
    int right_position;
};
node cai[20];
int N;
bool check(int mun)
{
    int unchange = mun;
    int munn = mun;
    for (int i = 0; i < N; i++)
    {
        mun = unchange;
        munn = unchange;
        int tong[10] = {0};
        for (int j = 0; j < 4; j++)
        {
            tong[cai[i].str[j] - '0']++;
        }
        int tot = 0;
        while (mun)
        {
            int a = mun % 10;
            mun /= 10;

            if (tong[a])
            {
                tong[a]--;
                tot++;
            }
        }
        if (tot == cai[i].right_mun)
        {
            int k = 0;
            for (int j = 0; j < 4; j++)
            {
                if (cai[i].str[3 - j] == (munn % 10 + '0'))
                {
                    k++;
                }
                munn /= 10;
            }
            if (!(k == cai[i].right_position))
            {
                return false;
            }
        }
        else
        {
            return false;
        }
    }
    return true;
}
int main()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> cai[i].str;
        cin >> cai[i].right_mun;
        cin >> cai[i].right_position;
    }
    // check(3585);
    int tot = 0;
    int ans = 0;
    for (int i = 1000; i <= 9999; i++)
    {
        if (check(i))
        {
            ans = i;
            tot++;
        }
    }
    if (tot == 1)
    {
        cout << ans << endl;
    }
    else
    {
        cout << "Not sure" << endl;
    }
    return 0;
}
