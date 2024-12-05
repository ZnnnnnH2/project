#include<iostream>
#include<cstring>
#include<stdio.h>

using namespace std;

void buildLPSArray(char *pat, int* arr){
    int len = strlen(pat);
    // for(int i=0;i<len;i++){
    //     arr[i]=0;
    // }
    arr[0]=0;
    int i=1;
    int j=0;
    while(i<len){
        // printf("hello\n");
        if(pat[i]==pat[j]){
            arr[i]=++j;
            i++;
        }
        else{
            if(j==0){
                arr[i]=0;
                i++;
            }
            else{
                j=arr[j-1];
            }
        }
    }
    return;
}

void compare(char* pat,char* txt){
    int pas[1000011];
    buildLPSArray(pat,pas);
    int i=0,j=0;
    int len=strlen(txt);
    int len_pat=strlen(pat);
    for(;i<len;){
        // if(i==len-1){
        //     if(txt[i]==pat[j]){
        //         printf("%d\n",i-len_pat+2);
        //     }
        //     break;
        // }
        if(txt[i]==pat[j]){
            if(j==len_pat-1){
                printf("%d\n",i-len_pat+2);
                // return ;
                j=pas[j-1];
            }
            else{
                i++;
                j++;
            }
        }
        else{
            if(j==0){
                i++;
                if(i==len) break;
                continue;
            }
            while(j!=0 and txt[i]!=pat[j]){
                j=pas[j-1];
            }
        }
    }
    for(int k=0;k<len_pat;k++){
        printf("%d ",pas[k]);
    }
    return ;
}

int main(){
    char txt[1000011];
    char pat[1000011];
    scanf("%s %s",txt,pat);
    compare(pat,txt);
    return 0;
}

/*
ABABAABAABAC
ABAABAC
*/