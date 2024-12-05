#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    // char str[3]={'9','x','g'};
    // printf("%s\n",str);

    // char str[100];
    // str="sadfdsaf";
    // printf("%s\n",str);

    // string str;
    // str="asdfasdf";
    // cout<<str<<endl;

    // char str[100];
    // gets(str);
    // puts(str);

    // char str[100];
    // fgets(str,10,stdin);
    // puts(str);

    // char str[]={"你好"};
    // printf("%s\n",str);
    // int len=strlen(str);
    // printf("%d\n",len);

    // char a[100];
    // scanf("%s",a);
    // char *b=a;
    // printf("%s\n",b);

    char str[100] = "o238";
    // char tar[100];
    // strcpy(tar,str);
    // printf("%s\n",tar);

    // strrev(str);

    char str1[] = "lak";
    // strcat(str,str1);

    // printf("%s\n",str);
    // printf("%d\n",strcmp(str,str1));
    int ans = 0;
    for (int i = 0; str[i] != '\0'; i++)
    {
        ans++;
    }
    printf("%d\n", ans);
    return 0;
}