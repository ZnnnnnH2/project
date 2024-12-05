#include <stdio.h>

void word(char *s)
{
    int t[30];
    for (int i = 0; i < 26; i++)
    {
        t[i] = 0;
    }
    int minn = s[0] - 'a', maxx = s[0] - 'a';
    int len = 0;
    while (s[len] != '\0')
    {
        len++;
    }
    for (int i = 0; i < len; i++)
    {
        t[s[i] - 'a']++;
        if (t[s[i] - 'a'] > t[maxx])
        {
            maxx = s[i] - 'a';
        }
        if (t[s[i] - 'a'] < t[minn])
        {
            minn = s[i] - 'a';
        }
    }
    int d = t[maxx] - t[minn];
    // printf("%d %d\n", maxx, minn);
    if(d==0 or d==1){
        printf("No Answer\n");
        printf("0\n");  
        return;
    }
    for (int i = 2; i * i <= d; i++)
    {
        if (d % i == 0)
        {
            printf("No Answer\n");
            printf("0\n");
            return;
        }
    }
    printf("Lucky Word\n");
    printf("%d\n", d);
    return;
}
int main(void)
{
    char s[102];
    scanf("%s", s);
    word(s);
    return 0;
}
