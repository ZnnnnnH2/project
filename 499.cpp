#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;
struct Pair
{
    int a, b, id;
    int ans[30];
    int sum = 0;
    Pair()
    {
        a = 0;
        b = 0;
        id = 0;
    }
    bool operator<(const Pair &p) const
    {
        return a > p.a;
    }
};

// priority_queue<Pair, vector<Pair> > pq;
Pair p[100];
int r[100][100];
void CopY(Pair *p, Pair *t){
    for(int i=1;i<=p->sum;i++){
        t->ans[i] = p->ans[i];
    }
    t->sum = p->sum;
    return;
}
int main()
{
    int v, l, k;
    scanf("%d%d%d", &v, &l, &k);
    for (int i = 1; i <= v; i++)
    {
        scanf("%d", &p[i].a);
        p[i].b = i;
        p[i].id = i;
        p[i].ans[++p[i].sum] = i;
    }
    for (int i = 1; i <= v; i++)
    {
        for (int j = 1; j <= v; j++)
        {
            scanf("%d", &r[i][j]);
        }
    }
    sort(p + 1, p + v + 1);
    // for(int i=1;i<=k;i++){
    // //     Pair p = pq.top();
    // //     pq.pop();
    //     printf("%d\n",p[i].a);
    // }
    // sort(p+1,p+v+1);
    // for(int i=1;i<=k;i++){
    //     Pair p;
    //     p.a = p[i];
    // }
    for (int i = 1; i < l; i++)
    {
        Pair *t = new Pair[4000];
        int mun = 0;
        for (int j = 1; j <= k; j++)
        {
            for (int o = 1; o <= v; o++)
            {
                mun++;
                t[mun].id = o;
                t[mun].a = p[j].a + r[p[j].id][o];
                CopY(&p[j],&t[mun]);
                t[mun].ans[++t[mun].sum] = o;
            }
        }
        sort(t + 1, t + mun + 1);
        for (int j = 1; j <= k; j++)
        {
            p[j] = t[j];
            // printf("%d ", p[j].a);
        }
        delete[] t;
    }
    for (int i = 1; i <= k; i++)
    {
        for(int j=1;j<=p[i].sum;j++)
            printf("%d ", p[i].ans[j]);
        printf("\n");
    }
    return 0;
}