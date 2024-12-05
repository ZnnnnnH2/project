#include<iostream>
#include<stdio.h>

using namespace std;
bool map[20][20];
int n,m;
bool jieguo=false;
void fs(int x,int y){
    if(jieguo==true) return;
    map[x][y]=0;
    if(x==0 or y==0 or x==n+1 or y==m+1){//边界
        return;
    }
    if(x==n and y==m){
        jieguo=true;
        return;
    }
    if(map[x+1][y]==1){
        fs(x+1,y);
    }if(jieguo==true) return;
    if(map[x-1][y]==1){
        fs(x-1,y);
    }if(jieguo==true) return;
    if(map[x][y+1]==1){
        fs(x,y+1);
    }if(jieguo==true) return;
    if(map[x][y-1]==1){
        fs(x,y-1);
    }if(jieguo==true) return;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=m;j++){
            cin>>map[i][j];
        }
    }
    if(map[1][1]==0){
        cout<<"NO"<<endl;
        return 0;
    }
    fs(1,1);
    if(jieguo==true){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }
    return 0;
}