#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
int getJIDian(int chengji)
{
    if (chengji >= 90)
    {
        return 40;
    }
    else if (chengji >= 86)
    {
        return 37;
    }
    else if (chengji >= 83)
    {
        return 33;
    }
    else if (chengji >= 80)
    {
        return 30;
    }
    else if (chengji >= 76)
    {
        return 27;
    }
    else if (chengji >= 73)
    {
        return 23;
    }
    else if (chengji >= 70)
    {
        return 20;
    }
    else if (chengji >= 66)
    {
        return 17;
    }
    else if (chengji >= 63)
    {
        return 13;
    }
    else if (chengji >= 60)
    {
        return 10;
    }
    return 0;
}
struct node
{
    int id;
    int weizhi;
    int val;
    int paiming;
    node()
    {
        id = 0;
        weizhi = 0;
        val = 0;
        paiming = 0;
    }
};
node score[2000];
int xuefen[20];
bool cmp1(node a, node b)
{
    return a.val > b.val;
}
bool cmp2(node a, node b)
{
    return a.weizhi < b.weizhi;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        scanf("%d", &xuefen[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &score[i].id);
        score[i].weizhi = i;
        for (int j = 1; j <= m; j++)
        {
            int x;
            scanf("%d", &x);
            score[i].val += xuefen[j] * getJIDian(x);
        }
    }
    sort(score + 1, score + n + 1, cmp1);
    int paiming = 1;
    for (int i = 1; i <= n; i++)
    {
        // printf("%d ", score[i].val);
        if (score[i].val != score[i - 1].val)
        {
            paiming = i;
        }
        score[i].paiming = paiming;
    }
    sort(score + 1, score + 1 + n, cmp2);
    for (int i = 1; i <= n; i++)
    {
        printf("%d %.1lf %d\n", score[i].id, score[i].val * 0.1, score[i].paiming);
    }
    return 0;
}
// ZnH2