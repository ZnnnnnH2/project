#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
string s0;
int len0;
void I()
{
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = len0 - 1; i >= 0; i--)
    {
        bool flag = true;
        for (int j = 0, k = len1 - 1; k >= 0; k--, j++)
        {
            if (s0[i - j] != str1[k])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            int index = i - len1 + 1;
            for (int j = 0; j < len0; j++)
            {
                if (j == index)
                {
                    for (int k = 0; k < len2; k++)
                    {
                        printf("%c", str2[k]);
                    }
                    printf("%c", s0[j]);
                }
                else
                {
                    printf("%c", s0[j]);
                }
            }
            return;
        }
    }
    cout << s0;
    return;
}
void D()
{
    string str;
    cin >> str;
    int len = str.length();
    for (int i = 0; i < len0; i++)
    {
        bool flag = true;
        for (int j = 0; j < len; j++)
        {
            if (s0[i + j] != str[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = i + len; j < len0; j++)
            {
                s0[j - len] = s0[j];
            }
            for (int j = 0; j < len0 - len; j++)
            {
                printf("%c", s0[j]);
            }
            return;
        }
    }
    cout<<s0;
    return;
}
void R()
{
    string str1, str2;
    cin >> str1 >> str2;
    int len1 = str1.length();
    int len2 = str2.length();
    for (int i = len0 - 1; i >= 0; i--)
    {
        bool flag = true;
        for (int j = 0, k = len1 - 1; k >= 0; k--, j++)
        {
            if (s0[i - j] != str1[k])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            for (int j = 0; j < len1; j++)
            {
                s0[i - j] = '*';
            }
        }
    }
    // for (int j = 0; j < len0; j++)
    //     printf("%c", s0[j]);
    // printf("\n");
    for (int j = 0; j < len0; j++)
    {
        if (s0[j] == '*')
        {
            for (int k = 0; k < len2; k++)
            {
                printf("%c", str2[k]);
            }
            while (s0[j+1] == '*')
                j++;
        }
        else
        {
            printf("%c", s0[j]);
        }
    }
    return;
}
int C()
{
    string str;
    cin >> str;
    int len = str.length();
    int ans = 0;
    for (int i = 0; i < len0; i++)
    {
        bool flag = true;
        for (int j = 0; j < len; j++)
        {
            if (s0[i + j] != str[j])
            {
                flag = false;
                break;
            }
        }
        if (flag)
        {
            ans++;
        }
    }
    return ans;
}

int main()
{
    //freopen("159.in", "r", stdin);
    getline(cin, s0);
    len0 = s0.length();
    char c;
    cin >> c;
    switch (c)
    {
    case 'C':
    {
        printf("%d\n", C());
        break;
    }
    case 'D':
    {
        D();
        break;
    }
    case 'I':
    {
        I();
        break;
    }
    case 'R':
    {
        R();
        break;
    }
    }
    return 0;
}