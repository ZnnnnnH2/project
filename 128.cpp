#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
struct person
{
    int k, s;
    person(int x = 0, int y = 0) : k(x), s(y) {}
};
person p[50004];
void maopao(int from, int to)
{ // bigger to smaller
    for (int i = from; i <= to - 1; i++)
    {
        for (int j = from; j <= to - i; j++)
        {
            if (p[j].s < p[j + 1].s or (p[j].s == p[j + 1].s and p[j].k > p[j + 1].k))
            {
                person temp = p[j];
                p[j] = p[j + 1];
                p[j + 1] = temp;
            }
        }
    }
}
void bijiao(int from, int to)
{ // bigger to smaller
    for (int i = from; i <= to - 1; i++)
    {
        for (int j = i + 1; j <= to; j++)
        {
            if (p[i].s < p[j].s or (p[i].s == p[j].s and p[i].k > p[j].k))
            {
                person temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }
}
void fastsort(int from, int to)
{
    if (from >= to)
        return;
    int flag = p[from].s;
    int i = from, j = to;
    while (i <= j)
    {
        while ((p[i].s < flag or (p[i].s == flag and p[i].k < from)) and i <= to)
            i++;
        while ((p[j].s > flag or (p[j].s == flag and p[j].k > to)) and j >= 1)
            j--;
        if (i < j)
        {
            swap(p[i], p[j]);
            i++;
            j--;
        }
    }
    fastsort(from, j);
    fastsort(i, to);
    return;
}
int main()
{
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d %d", &p[i].k, &p[i].s);
    }
    bijiao(1, n);
    // maopao(1, n);
    // fastsort(1, n);
    int renshu = m * 1.5;
    int i;
    while (p[renshu + 1].s == p[renshu].s)
        renshu++;
    printf("%d %d\n", p[renshu].s, renshu);
    for (i = 1; i <= renshu; i++)
    {
        printf("%d %d\n", p[i].k, p[i].s);
    }
    return 0;
}