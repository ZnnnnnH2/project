#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int n;
    cin>>n;
    int zhanwei=n-1;
    for(int i=1;i<=n;i++){
        char j='A';
        // printf("%c\n",j+i-1);
        for(int k=0;k<zhanwei;k++){
            cout<<" ";
        }
        for(;j<'A'+i;j++){
            cout<<j;
        }
        j--;
        j--;
        for(;j>='A';j--){
            cout<<j;
        }
        for(int k=0;k<zhanwei;k++){
            cout<<" ";
        }
        zhanwei--;
        cout<<endl;
    }
    return 0;
}