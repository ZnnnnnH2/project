#include <iostream>
#include <stdio.h>

#define ll long long

using namespace std;

const int inf=0x3f3f3f3f;
const int N=1e5+5;
const int mod = 10000;

int fb(int fn_2,int fn_1,int n){
    if(n==2){
        return fn_1;
    }
    return fb(fn_1,(fn_2+fn_1)%mod,n-1);
}
int main() {
    int n;
    scanf("%d", &n);
    if(n==0){
        printf("1\n");
        return 0;
    }
    if(n==1){
        printf("1\n");
        return 0;
    }
    else{
        printf("%d\n",fb(1,1,n));
    }
    return 0;
}