#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int zhibiao[110];
int k; // k是指标个数
int m, n;
struct hang
{
    int le_yuan_shu[110];
    bool operator<(const hang &a)
    {
        // printf("Hello");
        for (int i = 1; i <= k; i++)
        {
            int t = zhibiao[i];
            if (le_yuan_shu[t] != a.le_yuan_shu[t])
            {
                // printf("Hello");
                // printf("%d %s %d",le_yuan_shu[i],le_yuan_shu[i]<a.le_yuan_shu[i]?"<":">",a.le_yuan_shu[i]);
                return le_yuan_shu[t] < a.le_yuan_shu[t];
            }
        }
    }
    void operator=(const hang &a)
    {
        for (int i = 1; i <= n; i++)
        {
            le_yuan_shu[i] = a.le_yuan_shu[i];
        }
    }
} hang_yuan_shu[110];

void paixu(int l, int r)
{
    if (l == r)
        return;
    for (int i = l + 1; i <= r; i++)
    {
        if (hang_yuan_shu[i] < hang_yuan_shu[l])
        {
            hang temp;
            temp = hang_yuan_shu[i];
            hang_yuan_shu[i] = hang_yuan_shu[l];
            hang_yuan_shu[l] = temp;
        }
    }
    paixu(l + 1, r);
}

int main()
{
    cin >> m >> n;
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> zhibiao[i];
    }
    k++;
    zhibiao[k] = 1; // 把1也作为指标
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> hang_yuan_shu[i].le_yuan_shu[j];
        }
    }
    paixu(1, m);
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cout << hang_yuan_shu[i].le_yuan_shu[j] << " ";
        }
        cout << endl;
    }
    cout << endl;
    return 0;
}