#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int n, m;
struct NODE
{
    int l, r, w;
    NODE()
    {
        l = r = w = 0;
    }
    // bool operator < (const NODE &a) const{
    //     if(w==a.w){
    //         return l<a.l;
    //     }
    //     return w>a.w;
    // }
} node[20];
bool cmp(NODE a, NODE b)
{
    if (a.w == b.w)
    {
        return a.l < b.l;
    }
    return a.w > b.w;
}
bool cmp2(NODE a, NODE b)
{
    return a.l < b.l;
}
void object1()
{
    sort(node, node + m, cmp);
    for (int i = 0; i < m; i++)
    {
        if (node[i].w == 0)
        {
            break;
        }
        if (node[i].r == 100)
        {
            printf("[%2d,%3d]: %d\n", node[i].l, node[i].r, node[i].w);
        }
        else
        {
            printf("[%2d,%3d): %d\n", node[i].l, node[i].r, node[i].w);
        }
    }
    printf("\n");
}
void object2()
{
    sort(node, node + m, cmp2);
    int max = 0;
    for (int i = 0; i < m; i++)
    {
        if (node[i].w > max)
        {
            max = node[i].w;
        }
    }
    if (max <= 50)
    {
        for (int i = 0; i < m; i++)
        {
            // if (node[i].w == 0)
            // {
            //     continue;
            // }
            if (node[i].r == 100)
            {
                printf("[%2d,%3d]:", node[i].l, node[i].r);
            }
            else
            {
                printf("[%2d,%3d):", node[i].l, node[i].r);
            }
            for (int j = 0; j < node[i].w; j++)
            {
                printf("*");
            }
            printf("\n");
        }
    }
    else
    {
        double bili = 50.0 / max;
        for (int i = 0; i < m; i++)
        {
            // if (node[i].w == 0){
            //     continue;
            // }
            if (node[i].r == 100)
            {
                printf("[%2d,%3d]:", node[i].l, node[i].r);
            }
            else
            {
                printf("[%2d,%3d):", node[i].l, node[i].r);
            }
            // printf("%lld", (int)(node[i].w * bili));
            // printf("%.2lf",bili);
            for (int j = 0; j < node[i].w * 50 / max; j++)
            {

                printf("*");
            }
            printf("\n");
        }
    }
}
int main()
{
    // freopen("0000in.txt", "r", stdin);
    // freopen("0000out.txt", "w", stdout);
    int g;
    scanf("%d %d %d", &n, &m, &g);
    int jiange = 100 / m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        scanf("%d", &a);
        int t = a / jiange;
        if (a == 100)
        {
            t--;
        }
        node[t].w++;
    }
    for (int i = 0; i < m; i++)
    {
        node[i].l = i * jiange;
        node[i].r = (i + 1) * jiange;
    }
    if (g == 1)
    {
        object1();
    }
    else if (g == 2)
    {
        object2();
    }
    else
    {
        object1();
        printf("\n");
        object2();
    }
    return 0;
}