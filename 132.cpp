#include <stdio.h>
#include <stdlib.h>

int findMax(int *p, int nSize)
{
    int i, nMax = p[0], pos = 0;
    for (i = 1; i < nSize; i++)
    {
        if (p[i] > nMax){
            nMax = p[i];
            pos = i;
        }
    }
    int tmp = p[0];
    p[0] = p[pos];
    p[pos] = tmp;
    return nMax;
}

int main()
{
    int ary[2100] = {3, 2, 1, 5, 6, 7, 9, 10}, n = 8, nMax, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &ary[i]);

    nMax = findMax(ary, n);

    for (i = 0; i < n; i++)
        printf("%d ", ary[i]);
    printf("\n");

    printf("%d\n", nMax);
    return 0;
}