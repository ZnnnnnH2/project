#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
const int N = 10;
int n, m;
int a[N][N];
bool via[N][N];
int dx[][2] = {{1, 0}, {0, -1}, {0, 1}};
int ans = -0x3f3f3f3f;
void dfs(int val,int x,int y,vector<int>path)
{
    if(x==n and y==m){
        if(ans<val){
            ans = val;
            // for(int t:path){
            //     printf("%d ", t);
            // }

            // printf("%d \n", val);
        }
        return;
    }
    for(int i=0;i<3;i++){
        int nx = x+dx[i][0];
        int ny = y+dx[i][1];
        if(nx>=1 and nx<=n and ny>=1 and ny<=m and !via[nx][ny]){
            via[nx][ny] = true;
            path.push_back(a[nx][ny]);
            dfs(val+a[nx][ny],nx,ny,path);
            via[nx][ny] = false;
            path.pop_back();
        }
    }
    return;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            scanf("%d", &a[i][j]);
        }
    }
    vector<int>path;
    via[1][1] = true;
    path.push_back(a[1][1]);    
    dfs(a[1][1],1,1,path);
    printf("%d\n", ans);
    return 0;
}