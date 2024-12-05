#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
int a[15];
int n;
void to(int b[],int c[]){
    for (int i = 1; i <= n;i++){
        b[i] = c[i];
    }
    return;
}
int Check(){
    int b[15];
    int c[15];
    memset(b, 0, sizeof(b));
    memset(c, 0, sizeof(c));
    to(b, a);
    for (int i = 1; i < n;i++){
        for (int j = 1; j <= n - i;j++){
            c[j] = b[j] + b[j + 1];
        }
        to(b, c);
        // for (int i = 1; i <= n;i++){
        //     printf("%d ", b[i]);
        // }
        // printf("\n");
    }
    return b[1];
}
int main()
{
    int sum;
    scanf("%d", &n);
    scanf("%d", &sum);
    for (int i = 1; i <= n; i++)
    {
        a[i] = i;
    }
    do
    {
        if (Check()==sum)
        {
            for (int i = 1; i <= n; i++)
            {
                printf("%d ", a[i]);
            }
            printf("\n");
            return 0;
        }
    } while (next_permutation(a + 1, a + n + 1));
    return 0;
}