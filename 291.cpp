#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
int mun1[2005], mun2[2005];
int len_mun1 = 0, len_mun2 = 0;
int ans[2005];
int len_ans = 0;
int Add(int a, int b)
{
    return a + b;
}
int Mns(int a, int b)
{
    return a - b;
}
char getc()
{
    char c;
    do
    {
        c = getchar();
    } while (c != '-' and c != '+' and (c < '0' or c > '9'));
    return c;
}
void changee(string str, int mun[], int &len)
{
    int head = 0;
    int flag = 1;
    if (str[0] == '-')
    {
        head = 1;
        flag = -1;
    }
    len = 0;
    for (int i = str.size() - 1; i >= head; i--)
    {
        mun[len] = str[i] - '0';
        mun[len] *= flag;
        len++;
    }
    return;
}
int len = 0;
void oper(int (*f)(int, int))
{
    for (int i = 0; i < len; i++)
    {
        ans[i] = f(mun1[i], mun2[i]);
    }
    return;
}
void chuli()
{
    int yinzi = ans[len - 1] < 0 ? -1 : 1;
    int jiewei = len - 1;
    int tot = 1;
    if (yinzi == 1)
    {
        for (int i = len - 2; i >= 0; i--)
        {
            tot *= 10;
            if (ans[i] < 0)
            {
                ans[i] += tot;
                // ans[i]--;
                if (ans[jiewei] == 0)
                {
                    while (ans[jiewei] == 0)
                    {
                        ans[jiewei] = 9;
                        jiewei++;
                    }
                    ans[jiewei]--;
                }
                else
                {
                    ans[jiewei]--;
                }
                tot = 1;
                jiewei = i;
            }
            else
            {
                jiewei = i;
                tot = 1;
            }
        }
        while (ans[len - 1] == 0)
        {
            len--;
        }
        for (int i = 0; i < len; i++)
        {
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        while (ans[len])
        {
            len++;
        }
        for (int i = len - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
        printf("\n");
    }
    else
    {
        tot = -1;
        for (int i = len - 2; i >= 0; i--)
        {
            tot *= 10;
            if (ans[i] > 0)
            {
                ans[i] += tot;
                // ans[i]++;
                if (ans[jiewei] == 0)
                {
                    while (ans[jiewei] == 0)
                    {
                        ans[jiewei] = -9;
                        jiewei++;
                    }
                    ans[jiewei]++;
                }
                else
                {
                    ans[jiewei]++;
                }
                tot = -1;
                jiewei = i;
            }
            else
            {
                jiewei = i;
                tot = -1;
            }
        }
        while (ans[len - 1] == 0)
        {
            len--;
        }
        for (int i = 0; i < len; i++)
        {
            ans[i] = abs(ans[i]);
        }
        for (int i = 0; i < len; i++)
        {
            // ans[i] = abs(ans[i]);
            ans[i + 1] += ans[i] / 10;
            ans[i] %= 10;
        }
        while (ans[len - 1] < 0)
        {
            len++;
        }
        putchar('-');
        for (int i = len - 1; i >= 0; i--)
        {
            cout << ans[i];
        }
    }
}
int main()
{
    freopen("291.in", "r", stdin);
    freopen("291.out", "w", stdout);
    memset(ans, 0, sizeof(ans));
    memset(mun1, 0, sizeof(mun1));
    memset(mun2, 0, sizeof(mun2));
    char c;
    c = getc();
    string str1;
    string str2;
    cin >> str1 >> str2;
    changee(str1, mun1, len_mun1);
    changee(str2, mun2, len_mun2);
    // for (int i = 0; i < len_mun1; i++)
    // {
    //     cout << mun1[i];
    // }
    // printf("\n");
    // for (int i = 0; i < len_mun2; i++)
    // {
    //     cout << mun2[i];
    // }
    len = max(len_mun1, len_mun2);
    if (c == '+')
    {
        oper(Add);
    }
    else
    {
        oper(Mns);
    }
    // for (int i = len - 1; i >= 0; i--)
    // {
    //     cout << ans[i];
    // }
    // cout << endl;
    chuli();
    // for (int i = len_ans - 1; i >= 0; i--)
    // {
    //     cout << ans[i];
    // }
    return 0;
}