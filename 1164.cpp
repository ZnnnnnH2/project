#include<iostream>
#include<stdio.h>

using namespace std;

int main(){
    int beichushu,chushu; //被除数 除数
    cin>>beichushu>>chushu;
    int m=beichushu,n=chushu;
    int shang=beichushu/chushu;
    int yushu=beichushu%chushu;
    while(yushu!=0){
        beichushu=chushu;
        chushu=yushu;
        shang=beichushu/chushu;
        yushu=beichushu%chushu;
    }
    printf("%d\n",m*n/chushu);
    return 0;
}