#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e3 + 5;
class node
{
public:
    int mun, id;
    node(int mun = 0, int id = 0)
    {
        this->mun = mun;
        this->id = id;
    }
    bool operator<(const node &a) const
    {
        return mun > a.mun;
    }
};
class pos
{
public:
    node p;
    int lie;
    // pos(node a,int b){
    //     this->p=a;
    //     this->lie=b;
    // }
    bool operator<(const pos &a) const
    {
        return p < a.p;
    }
};

pos fnl[N * N];
int m[N][N];

priority_queue<node> q;
int head[N];
int n;
int bs(int mun)
{
    int l = 1, r = n * n;
    while (l <= r)
    {
        int mid = (l + r) >> 1;
        if (fnl[mid].p.mun == mun)
        {
            return mid;
        }
        else if (fnl[mid].p.mun > mun)
        {
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }
    return -1;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            scanf("%d", &m[i][j]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        q.push(node(m[i][1], i));
        head[i] = 2;
    }
    int len = 0;
    while (!q.empty())
    {
        node t = q.top();
        q.pop();
        len++;
        fnl[len].p = t;
        fnl[len].lie = head[t.id] - 1;
        if (head[t.id] <= n)
        {
            q.push(node(m[t.id][head[t.id]++], t.id));
        }
    }
    // for(int i=1;i<=n*n;i++){
    //     printf("%d %d %d\n",fnl[i].p.mun,fnl[i].p.id,fnl[i].lie);
    // }
    int t;
    scanf("%d", &t);
    for (int i = 1; i <= t; i++)
    {
        int x;
        scanf("%d", &x);
        int ans = bs(x);
        if (ans == -1)
        {
            printf("-1\n");
        }
        else
        {
            printf("%d %d\n", fnl[ans].p.id - 1, fnl[ans].lie - 1);
        }
    }
    return 0;
}