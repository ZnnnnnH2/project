#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int a,b,n,k,m;
    cin>>a>>b>>n>>k>>m;
    int mu=1;
    for(int i=1;i<=m-1;i++){
        mu=mu*10;
    }
    int flag=0;
    for(int i=a;i<=b;i++){
        if(i%10==n and i%k==0 and i/mu>0 and i/mu<=9){
            flag++;
        }
    }
    cout<<flag<<endl;
    return 0;
}