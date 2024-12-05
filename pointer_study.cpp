#include<iostream>
#include<stdio.h>
using namespace std;

// int main(){
//     int a=10,b=20;
//     int *pmax;
//     if(a<b){
//         pmax=&b;
//     }
//     printf("%d",*pmax);
// }

// int main(){
//     int a[10]={1,2,3,4,5,6,7,8,9,10};
//     int *p;
//     p=a;
//     for(int i=0;i<10;i++){
//         cout<<*(p+i)<<endl;
//     }
// }

int main(){
    int a[10][10];
    int tot=0;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            a[i][j]=tot++;
        }
    }
    // int *p[][10]=a;
    for(int i=0;i<10;i++){
        for(int j=0;j<10;j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    printf("%d",*(*(a+0)+1));
}