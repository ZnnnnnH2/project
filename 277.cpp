#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 40
#define M 300000

char allRes[M][N] = {0}; // 保存所有结果
char szRes[N] = {0};     // 全局变量，保存n对括号组成的一个序列

void genParentheses(int n,int shengyuleft,int shengyuringht,int k,int *nRes){
    if(k>=2*n){
        szRes[k] = '\0';
        strcpy(allRes[*nRes],szRes);
        (*nRes)++;
        return;
    }
    if(shengyuleft>0){
        szRes[k] = '(';
        genParentheses(n,shengyuleft-1,shengyuringht+1,k+1,nRes);
    }
    if(shengyuringht>0){
        szRes[k] = ')';
        genParentheses(n,shengyuleft,shengyuringht-1,k+1,nRes);
    }
    return;
}

int main()
{
    int n, nRes = 0, i;

    scanf("%d", &n);
    genParentheses(n,n,0,0,&nRes);

    printf("%d\n", nRes);
    for (i = 0; i < nRes; i++)
        printf("%s\n", allRes[i]);

    return 0;
}