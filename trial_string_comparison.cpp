#include<iostream>
#include<string>
#include<cstring>
#include<algorithm>
#include<cstdio>

using namespace std;

int main(){
    char a[]="alice";
    char b[]="bob";
    int len=max(strlen(a), strlen(b));
        for(int i = 0; i < len; i++){
            if(a[i] < b[i]){
                printf("a<b\n");
            }else if(a[i] > b[i]){
                printf("a>b\n");
            }
        }
}