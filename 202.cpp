#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

#define ll long long

using namespace std;
bool via[15];
vector<int> v[15];
int a[5005][15];
int n;
int tot = 0;
void dfs(int id, vector<int> ans)
{
    if (id > n)
    {
        tot++;
        for (int i = 0; i < ans.size(); i++)
        {
            a[tot][i] = ans[i];
        }
        return;
    }
    for (int i = 0; i < v[id].size(); i++)
    {
        if (via[v[id][i]])
        {
            continue;
        }
        via[v[id][i]] = true;
        ans.push_back(v[id][i]);
        dfs(id + 1, ans);
        ans.pop_back();
        via[v[id][i]] = false;
    }
    return;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            char x;
            do
            {
                x = getchar();
            } while (x != '0' && x != '1');
            if (x == '1')
            {
                v[i].push_back(j);
            }
        }
    }
    vector<int> ans;
    dfs(1, ans);
    if(tot==0){
        printf("NO\n");
        return 0;
    }
    printf("%d\n", tot);
    for(int i=1;i<=tot;i++){
        for(int j=0;j<n;j++){
            printf("B%d", a[i][j]);
        }
        printf("\n");
    }
    return 0;
}