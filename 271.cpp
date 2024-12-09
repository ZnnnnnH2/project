#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
char a[N];

int main()
{
    scanf("%[^\n]", a);
    int len = strlen(a);
    bool flag = false;
    for (int i = 0; i < len; i++)
    {
        if (a[i] == ' ' or a[i] == '_' or a[i] >= 'a' and a[i] <= 'z' or a[i] >= 'A' and a[i] <= 'Z')
        {
            flag = true;
            break;
        }
    }
    if (flag)
    {
        for (int i = 0; i < len; i++)
        {
            if (a[i] >= 'a' and a[i] <= 'z')
            {
                a[i] = a[i] - 32;
            }
            putchar(a[i]);
        }
    }
    else
    {
        flag = false;
        for (int i = 0; i < len; i++)
        {
            if (a[i] == '.')
            {
                flag = true;
                break;
            }
        }
        if(flag){
            int x=0;
            sscanf(a, "%d.%*d", &x);
            printf("%d", x);
        }
        else{
            int x;
            sscanf(a, "%d", &x);
            printf("%d", x+1);
        }
    }
    return 0;
}