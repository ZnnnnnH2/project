#include<iostream>
#include<stdio.h>

using namespace std;
int n;
int cishu=0;//计数器
int a[200];
void xuansepaixu(int i){
    if(i==n){
        return;
    }
    int xiabiao=i;
    for(int j=i+1;j<=n;j++){
        if(a[xiabiao]>a[j]){
            xiabiao=j;
        }
    }
    if(xiabiao!=i){
        cishu++;
        swap(a[i],a[xiabiao]);
        int b[200];
        for(int k=1;k<=n;k++){
            b[k]=a[k];
        }
        xuansepaixu(i+1);
        printf("%d<->%d:",i,xiabiao);
        for(int k=1;k<=n;k++){
            printf("%d ",b[k]);
        }
        printf("\n");
    }
    else {
        xuansepaixu(i+1);
    }
}
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }    
    xuansepaixu(1);
    printf("Total steps:%d\n",cishu);
    printf("Right order:");
    for(int i=1;i<=n;i++){
        printf("%d ",a[i]);
    }
    return 0;
}