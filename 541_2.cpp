#include <stdio.h>
#include <string.h>
#include <cstring>
#include <iostream>
using namespace std;

char parseCmd(char *cmdStr, char *str1, char *str2)
{
    char cmd;
    cmd = cmdStr[0];
    switch (cmd)
    {
    case 'C':
    {
        sscanf(cmdStr, "%c %s", &cmd, str1);
        break;
    }
    case 'D':
    {
        sscanf(cmdStr, "%c %s", &cmd, str1);
        break;
    }
    case 'I':
    {
        sscanf(cmdStr, "%c %s %s", &cmd, str1, str2);
        break;
    }
    case 'R':
    {
        sscanf(cmdStr, "%c %s %s", &cmd, str1, str2);
        break;
    }
    }
    return cmd;
}
int countStr(char *s0, char *str)
{
    int len0 = strlen(s0);
    int len = strlen(str);
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
void deleteStr(char *s0, char *str)
{
    int len0 = strlen(s0);
    int len = strlen(str);
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
            s0[0] = '\0';
            return;
        }
    }
    cout << s0;
    s0[0] = '\0';
    return;
}
void insertStr(char *s0, char *str1, char *str2)
{
    int len0 = strlen(s0);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
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
            s0[0] = '\0';
            return;
        }
    }
    cout << s0;
    s0[0] = '\0';
    return;
}
char *replaceStr(char *s0, char *str1, char *str2)
{
    int len0 = strlen(s0);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
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
            while (s0[j + 1] == '*')
                j++;
        }
        else
        {
            printf("%c", s0[j]);
        }
    }
    s0[0]='\0';
    return s0;
}
int main()
{
    // freopen("0000in.txt", "r", stdin);
    // freopen("0000out.txt", "w", stdout);
    char s[500], cmdStr[500], str1[500], str2[500], cmd;

    gets(s);
    gets(cmdStr);

    cmd = parseCmd(cmdStr, str1, str2);

    switch (cmd)
    {
    case 'C':
        printf("%d\n", countStr(s, str1));
        break;
    case 'D':
        deleteStr(s, str1);
        printf("%s\n", s);
        break;
    case 'I':
        insertStr(s, str1, str2);
        printf("%s\n", s);
        break;
    case 'R':
        printf("%s\n", replaceStr(s, str1, str2));
        break;
    }
    return 0;
}
