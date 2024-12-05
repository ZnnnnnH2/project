#include <stdio.h>
#include <stdlib.h>

void mySort(int *ary, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + ((right - left) >> 1);
    int pivot = ary[mid];
    int i = left, j = right;
    while (i <= j)
    {
        while (ary[i] < pivot)
        {
            i++;
        }
        while (ary[j] > pivot)
        {
            j--;
        }
        if (i <= j)
        {
            int temp = ary[i];
            ary[i] = ary[j];
            ary[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j)
    {
        mySort(ary, left, j);
    }
    if (i < right)
    {
        mySort(ary, i, right);
    }
    return;
}

int main()
{
    int array[100], i, n;

    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        scanf("%d", &array[i]);
    }

    mySort(array, 0, n - 1);

    for (i = 0; i < n; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
    return 0;
}