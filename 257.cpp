#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    double s=0;
    int k;
    cin>>k;
    int n=1;
    while(s<=k){
        s+=1.0/n;
        n++;
    }
    printf("%d",n-1 );
    return 0;
}