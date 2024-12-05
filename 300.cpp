#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int chafen[500];

int main() {
    memset(chafen,0,sizeof(chafen));
    scanf("%d",&chafen['A']);     
    int chaozuo;
    int maxx='A';
    scanf("%d",&chaozuo);
    while(chaozuo){
        if(chaozuo==1){
            char from,to;
            scanf("%c%c",&from,&to);
            chafen[from]--;
            chafen[to]++;
            if(to>maxx){
                maxx=to;
            }
        }
        else{
            char from,to;
            scanf("%c%c",&from,&to);
            chafen[from]++;
            chafen[to]--;
            if(to>maxx){
                maxx=to;
            }
        }
        scanf("%d",&chaozuo);
    }
    int min=chafen['A'];
    for(int i='A';i<maxx;i++){
        chafen[i]+=chafen[i-1];
        // printf("%d ",chafen[i]);
        if(chafen[i]<min){
            min=chafen[i];
        }
    }
    printf("%d\n",min);
    return 0;
}