#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 300000

char allRes[M][N] = {0}; // 保存所有结果
char szRes[N] = {0};     // 全局变量，保存n对括号组成的一个序列

void genParentheses(int n, int i, int l, int r, int *nRes)
{
    if (i == 2 * n)
    {
        strcpy(allRes[(*nRes)++], szRes);
        return;
    }
    if (l < n)
    {
        szRes[i] = '(';
        genParentheses(n, i + 1, l + 1, r, nRes);
        szRes[i] = 0;
    }
    if (l > r)
    {
        szRes[i] = ')';
        genParentheses(n, i + 1, l, r + 1, nRes);
        szRes[i] = 0;
    }
    return;
}

int main()
{
    int n, nRes = 0, i;

    scanf("%d", &n);
    genParentheses(n, 0, 0, 0, &nRes);

    printf("%d\n", nRes);
    for (i = 0; i < nRes; i++)
        printf("%s\n", allRes[i]);

    return 0;
}