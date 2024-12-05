#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;
struct node{
    int x,y,z;
    node(int a=0,int b=0,int c=0):x(a),y(b),z(c){}
    bool operator <(const node &a)const{
        if(x!=a.x) return x<a.x;
        if(y!=a.y) return y<a.y;
        return z<a.z;
    }
}nd[100000];
int main()
{
    int n;
    cin >> n;
    double ddl=n*0.9;
    int tot=0;
    for(int i=1;i<=16;i++){   //ak47
        for(int j=1;j<=100;j++){   //killer
            if(i*6+j>n){
                break;
            }
            if(j%10!=8) continue;
            // if(!(i/10==0 and j/10>0 and j/100==0)) continue;
            int MIN=min(i,j);
            int MAX=max(i,j);
            int k=MIN;   //bomb
            if(MIN%2!=0)  k=MIN+1;
            for(;k<=MAX;k+=2){
                if(i/10==0){
                    if(k/10<=0 or k/100>0) continue;
                }
                if(i==j or j==k or i==k) continue;
                int money=i*6+j+2*k;
                if((double)money-ddl>1e-7 and money<=n) {
                    tot++;
                    nd[tot].x=k;
                    nd[tot].y=i;
                    nd[tot].z=j;
                }
            }
        }
    }
    if(tot==0){
        printf("no answer\n");
        return 0;
    }
    sort(nd+1,nd+tot+1);
    for(int i=1;i<=tot;i++){
        printf("%d %d %d\n",nd[i].x,nd[i].y,nd[i].z);
    }
    return 0;
}
