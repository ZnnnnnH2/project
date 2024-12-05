#include <stdio.h>

#include <string.h>

void f(char s[], int l, int r){

    //在此补充代码
    if(l==r) return;
    char temp = s[l];
    s[l] = s[r];
    s[r] = temp;

    //补充结束
    f(s,l+1,r-1);

}

int main(){

    char s[10001];

    scanf("%s", s);

    f(s,0,strlen(s)-1);

    printf("%s",s);

}