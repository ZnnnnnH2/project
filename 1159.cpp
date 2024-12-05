#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
#define ll long long

using namespace std;
int direction[9][2]={{0,0},{2,1},{2,-1},{-2,1},{-2,-1},{1,2},{1,-2},{-1,2},{-1,-2}};
ll dp[21][21];
int n, m, a, b;
bool Check(int x,int y){
    for (int i = 0; i < 9;i++){
        int nx=a+direction[i][0];   
        int ny=b+direction[i][1];
        if(x==nx&&y==ny)
            return true;
    }
    return false;
}

int main() {
    memset(dp, 0, sizeof(dp));
    scanf("%d %d %d %d", &n, &m, &a, &b);
    dp[0][0] = 1;
    for (int i = 0; i <= n;i++){
        for (int j = 0; j <= m;j++){
            if(i==0&&j==0){
                if(Check(i,j)){
                    dp[i][j] = 0;
                }
                else{
                    dp[i][j] = 1;
                }
            }
            else if(!Check(i,j)){
                dp[i][j] = dp[max(i - 1,0)][j] + dp[i][max(j - 1,0)];
            }
            else{
                dp[i][j] = 0;
            }
        }
    }
    printf("%lld\n", dp[n][m]);
    // for(int i=0;i<=n;i++){
    //     for(int j=0;j<=m;j++){
    //         printf("%lld ", dp[i][j]);
    //     }
    //     printf("\n");
    // }
    return 0;
}