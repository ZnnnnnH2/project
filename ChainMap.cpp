#include<iostream>
#include<stdio.h>

using namespace std;

struct ChainMap
{
    int Number=0;
    ChainMap *next=NULL;
    ChainMap *prev=NULL;
};


int main(){
    ChainMap *Head;
    ChainMap *point;
    Head=new ChainMap;
    point=Head;
    for(int i=0;i<10;i++){
        point->Number=i;
        point->next=new ChainMap;
        ChainMap *temp=point;
        point=point->next;
        point->prev=temp;
    }
    point=Head;
    while(point!=NULL){
        cout<<point->Number<<endl;
        point=point->next;
    }
    return 0;
}