#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
int partition(int ary[], int left, int right)
{
    int pivot = ary[left];
    while (left < right)
    {
        while (ary[right] > pivot and left < right)
        {
            right--;
        }
        if (left < right)
        {
            ary[left] = ary[right];
            left++;
        }
        while (ary[left] < pivot and left < right)
        {
            left++;
        }
        if (left < right)
        {
            ary[right] = ary[left];
            right--;
        }
    }
    ary[left] = pivot;
    return left;
}
void quicksort(int ary[], int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int m = partition(ary, left, right);
    quicksort(ary, left, m - 1);
    quicksort(ary, m + 1, right);
    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    int a[n];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    quicksort(a, 0, n - 1);
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    return 0;
}