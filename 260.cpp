#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int arr[1002];

void fast_sort(int l, int r)
{
    if (l >= r)
        return;
    int i = l, j = r;
    int mid = arr[(l + r) / 2];
    while (i <= j)
    {
        while (arr[i] < mid)
            i++;
        while (arr[j] > mid)
            j--;
        if (i <= j)
        {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        fast_sort(l, j);
    if (i < r)
        fast_sort(i, r);
    return;
}
int m;
int tot = 0;
int check(int l, int r)
{
    tot++;
    if (l == r)
    {
        if (arr[l] == m)
            return l;
        else
            return -1;
    }
    if (l > r)
    {
        return -1;
        // tot--;
    }
    int mid = (l + r) / 2;
    if (arr[mid] == m)
    {
        return mid;
    }
    else if (arr[mid] > m)
    {
        // tot++;
        if (l <= mid - 1)
            return check(l, mid - 1);
        else
            return -1;
    }
    else
    {
        // tot++;
        if (mid + 1 <= r)
            return check(mid + 1, r);
        else
            return -1;
    }
    return -1;
}
int main()
{
    int n;
    scanf("%d %d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    fast_sort(0, n - 1);
    int k = check(0, n - 1);
    printf("%d\n%d\n", k, tot);
    return 0;
}