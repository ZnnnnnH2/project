#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
struct person
{
    int id, score, rank;
    person()
    {
        id = score = rank = 0;
    }
    bool operator<(const person &a) const{
        if (score == a.score)
            return id < a.id;
        return score > a.score;
    }
} st[1005];
void falst_sort(int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    int flag = st[l].score;
    while (i <= j)
    {
        while (i <= r and (st[i].score > flag or (st[i].score == flag and st[i].id < st[l].id)))
            i++;
        while (j >= l and (st[j].score < flag or (st[j].score == flag and st[j].id > st[l].id)))
            j--;
        if (i <= j)
        {
            swap(st[i], st[j]);
            i++;
            j--;
        }
    }
    if(l<j)falst_sort(l, j);
    if(i<r)falst_sort(i, r);
    return;
}
int main()
{
    // freopen("150.out", "w", stdout);
    // freopen("150.in", "r", stdin);
    //freopen("
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d%d", &st[i].id, &st[i].score);
    }
    // falst_sort(1, n);
    sort(st + 1, st + n + 1);
    int rank=0;
    for (int i = 1; i <= n; i++)
    {
        rank++;
        if (st[i].score == st[i - 1].score)
        {
            st[i].rank = st[i - 1].rank;
        }
        else{
            st[i].rank = rank;
        }
        printf("%d %d %d\n",st[i].rank, st[i].id, st[i].score);
    }
    return 0;
}