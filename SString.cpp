#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
struct SString{
    char *ch;
    int length;
    SString(){
        this->ch=NULL;
        this->length=0;
    }
    SString(char *ch){
        this->ch=ch;
        this->length=strlen(ch);
    }

    bool operator==(SString &s){
        if(this->length!=s.length){
            return false;
        }
        for(int i=0;i<this->length;i++){
            if(this->ch[i]!=s.ch[i]){
                return false;
            }
        }
        return true;
    }
    void operator=(SString &s){
        this->ch=s.ch;
        this->length=s.length;
    }
    void operator=(char *ch){
        this->ch=ch;
        this->length=strlen(ch);
    }

    int Length(){
        return this->length;
    }
    int Find_slow(SString &s){
        for(int i=0;i<this->length;i++){
            if(this->ch[i]==s.ch[0]){
                int j=1;
                for(;j<s.length;j++){
                    if(this->ch[i+j]!=s.ch[j]){
                        break;
                    }
                }
                if(j==s.length){
                    return i;
                }
            }
        }
        return -1;
    }
};