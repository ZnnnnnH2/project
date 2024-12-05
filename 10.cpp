#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    double ans;
    ans=(n-32)*1.0*5/9;
    printf("%.2f",ans);
    return 0;
}