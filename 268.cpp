#include <queue>
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
const int N = 50 + 5;
vector<pair<int, int>> G[N];
int n, s, d;
int ans = inf;
vector<int> q;
vector<int> q_final;
bool vis[N];
void dfs(int u, int sum, int tot)
{
    if (sum > ans)
    {
        return;
    }
    if (u == d)
    {
        if (sum < ans)
        {
            ans = sum;
            q_final = q;
        }
        else if (sum == ans)
        {
            if (tot < q_final.size())
            {
                q_final = q;
            }
            else if (tot == q_final.size())
            {
                for (int i = 0; i < q.size(); i++)
                {
                    if (q[i] < q_final[i])
                    {
                        q_final = q;
                        break;
                    }
                    else if (q[i] > q_final[i])
                    {
                        break;
                    }
                }
            }
        }
        return;
    }
    for (int i = 0; i < G[u].size(); i++)
    {
        int v = G[u][i].first;
        int w = G[u][i].second;
        if (!vis[v])
        {
            vis[v] = 1;
            q.push_back(v);
            dfs(v, sum + w, tot + 1);
            vis[v] = 0;
            q.pop_back();
        }
    }
    return;
}
int main()
{
    scanf("%d%d%d", &n, &s, &d);
    // cout << s << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            scanf("%d", &x);
            if (x != -1)
            {
                G[i].push_back(make_pair(j, x));
            }
        }
    }
    q.push_back(s);
    vis[s] = 1;
    dfs(s, 0, 1);
    if(q_final.empty()){
        cout<<"-1"<<endl;
        return 0;
    }
    for (int i = 0;i<q_final.size()-1;i++)
    {
        printf("%d->", q_final[i]);
    }
    printf("%d\n", q_final.back());
    return 0;
}