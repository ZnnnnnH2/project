#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int t[10];
void print_16(int n);

int main() {
    int n;
    scanf("%d", &n);
    int ans=0;
    for(int i=1;i<=n;i++){
        memset(t, 0, sizeof(t));
        for(int j=1;j<=6;j++){
            int a;
            scanf("%d", &a);
            t[a]++;
        }
        if(t[4]==4 and t[1]==2){
            ans+=2048;
        }
        else if(t[4]==6){
            ans+=1024;
        }
        else if(t[1]==6){
            ans+=512;
        }
        else if(t[2]==6){
            ans+=256;
        }
        else if(t[4]==5){
            ans+=128;
        }
        else if(t[2]==5){
            ans+=64;
        }
        else if(t[4]==4){
            ans+=32;
        }
        else if(t[1]==1 and t[2]==1 and t[3]==1 and t[5]==1 and t[6]==1 and t[4]==1){
            ans+=16;
        }
        else if(t[4]==3){
            ans+=8;
        }
        else if(t[2]==4){
            ans+=4;
        }
        else if(t[4]==2){
            ans+=2;
        }
        else if(t[4]==1){
            ans+=1;
        }
        else{
            break;
        }
    }
    print_16(ans);
    return 0;
}
int a[1000];

void print_16(int n){
    int i=0;
    if(n==0){
        printf("0\n");
        return;
    }
    while(n){
        a[i++]=n%16;
        n/=16;
    }
    for(int j=i-1;j>=0;j--){
        if(a[j]>=10){
            printf("%c", a[j]-10+'a');
        }
        else{
            printf("%d", a[j]);
        }
    }
    printf("\n");
}