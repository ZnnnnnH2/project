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
int a[25][105];
int b[N];
int tot;
int getmun(int &i){
    int sum = 1;
    while(b[i] == b[i + 1]){
        sum++;
        i++;
    }
    return sum;
}
int main()
{
    int n;
    scanf("%d", &n);
    // int maxx = 0, minn = inf;
    for (int i = 1; i <= n; i++)
    {
        int x;
        scanf("%d", &x);
        for (int i = 1; i <= x; i++)
        {
            int k;
            scanf("%d", &k);
            b[++tot] = k;
        }
    }
    sort(b + 1, b + tot + 1);
    bool flag = 0;
    for (int i = 1; i <= tot; i++)
    {
        int k = getmun(i);
        if(k==n){
            printf("%d ",b[i]);
            flag = 1;
        }
    }
    if (!flag)
        printf("NO\n");
    return 0;
}