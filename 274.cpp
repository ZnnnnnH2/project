#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 300000

char allRes[M][N] = {0}; // 保存所有结果
char szRes[N] = {0};     // 全局变量，保存n对括号组成的一个序列

void genParentheses(____qcodep____)
{
    ____qcodep____
}

int main()
{
    int n, nRes = 0, i;

    scanf("%d", &n);
    genParentheses(____qcodep____);

    printf("%d\n", nRes);
    for (i = 0; i < nRes; i++)
        printf("%s\n", allRes[i]);

    return 0;
}