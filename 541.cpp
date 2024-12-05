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
int countStr(char *s, char *str1)
{
    int count = 0;
    char *p = s;
    while ((p = strstr(p, str1)) != NULL)
    {
        count++;
        p+=strlen(str1);
    }
    return count;
}
void deleteStr(char *s, char *str1)
{
    char *p = s;
    if ((p = strstr(p, str1)) != NULL)
    {
        int len_str1 = strlen(str1);
        memmove(p, p + len_str1, strlen(p + len_str1) + 1); // 使用 memmove 代替 strcpy
    }
    return;
}
void insertStr(char *s, char *str1, char *str2)
{
    char *p = s;
    char *pFront=NULL;
    while ((p = strstr(p, str1)) != NULL)
    {
        pFront = p;
    }
    if(pFront==NULL){
        return;
    }
    int len_str2 = strlen(str2);
    char *ary = new char[100];
    strcpy(ary, pFront);
    strcpy(pFront, str2);
    strcpy(pFront + len_str2, ary);
    delete[] ary;
    return;
}
char* replaceStr(char *s, char *str1, char *str2)
{
    char *p = s;
    int len_str1 = strlen(str1);
    int len_str2 = strlen(str2);
    while ((p = strstr(p, str1)) != NULL)
    {
        if (len_str1 == len_str2)
        {
            for (int i = 0; i < len_str1; i++)
            {
                p[i] = str2[i];
            }
            p+=len_str1;
        }
        else if (len_str1 > len_str2)
        {
            for (int i = 0; i < len_str2; i++)
            {
                p[i] = str2[i];
            }
            strcpy(p + len_str2, p + len_str1);
            p+=len_str2;
        }
        else
        {
            char lishi[100];
            strcpy(lishi, p + len_str1);
            for (int i = 0; i < len_str2; i++)
            {
                p[i] = str2[i];
            }
            strcpy(p + len_str2, lishi);
            p+=len_str2;
        }
    }
    return s;
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
