#include<iostream>
#include<cstdio>

using namespace std;
int map[200][200];

int main(){
    int n;
    cin>>n;
    if(n==1){
        cout<<"1"<<endl;
        return 0;
    }
    if(n==2){
        printf("1 2\n3 4");
        return 0;
    }
    map[1][1]=1;
    map[1][2]=2;
    map[2][1]=4;
    map[2][2]=3;
    int mun=5;//当前应该填入的数字
    for(int i=3;i<=n;i++){
        if(i%2==1){
            for(int j=1;j<=i;j++){
            map[i][j]=mun;
            mun++;
        }
        int j=i-1;
        for(;j>=1;j--){
            map[j][i]=mun;
            mun++;
        }
        }
        else{
            for(int j=1;j<=i;j++){
            map[j][i]=mun;
            mun++;
        }
        int j=i-1;
        for(;j>=1;j--){
            map[i][j]=mun;
            mun++;
        }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d ",map[i][j]);
        }
        printf("\n");
    }
}