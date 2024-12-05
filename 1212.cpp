#include<stdio.h>
#include<iostream>
using namespace std;
int main()
{
    int n;
    cin>>n;
    int ku[n][7];
    int a[n][6]={0};
    for(int i=0;i<n;i++){
        for(int j=0;j<6;j++){
            cin>>a[i][j];
            ku[i][a[i][j]]++;
        }
        if(ku[i][4]==4&&ku[i][1]==2) continue;
            else if(ku[i][4]==6) continue;
            else if(ku[i][1]==6) continue;
            else if(ku[i][2]==6) continue;
            else if(ku[i][4]==5) continue;
            else if(ku[i][2]==5) continue;
            else if(ku[i][4]==4) continue;
            else if(ku[i][1]==1&&ku[i][2]==1&&ku[i][3]==1&&ku[i][4]==1&&ku[i][5]==1&&ku[i][6]==1) continue;
            else if(ku[i][4]==3) continue;
            else if(ku[i][2]==4) continue;
            else if(ku[i][4]==2) continue;
            else if(ku[i][4]==1) continue;
            else break;
    }
    int fen=0;
    for(int i=0;i<n;i++){
        if(ku[i][4]==4&&ku[i][1]==2) fen+=2048;
        else if(ku[i][4]==6) fen+=1024;
        else if(ku[i][1]==6) fen+=512;
        else if(ku[i][2]==6) fen+=256;
        else if(ku[i][4]==5) fen+=128;
        else if(ku[i][2]==5) fen+=64;
        else if(ku[i][4]==4) fen+=32;
        else if(ku[i][1]==1&&ku[i][2]==1&&ku[i][3]==1&&ku[i][4]==1&&ku[i][5]==1&&ku[i][6]==1) fen+=16;
        else if(ku[i][4]==3) fen+=8;
        else if(ku[i][2]==4) fen+=4;
        else if(ku[i][4]==2) fen+=2;
        else if(ku[i][4]==1) fen+=1;
        else break;
    }
    printf("%x",fen);
}