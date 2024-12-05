#include <iostream>
#include <stdio.h>

using namespace std;
bool t[1000];
void guiling()
{
    for (int i = 'A'; i <= 'H'; i++)
    {
        t[i] = false;
    }
}
int n;
bool panduan(){
    int ans=0;
    for (int i = 'A'; i <= 'H'; i++)
    {
        if(t[i]){
            ans++;
        }
    }
    if(ans==n){
        return true;
    }
    else{
        return false;
    }
}
int main()
{
    
    scanf("%d", &n);
    int ans=0;
    char a;
    for (int i = 'A'; i <= 'H'; i++)
    {
        guiling();
        if(i=='H' or i=='F'){
            t['A'] = true;
        }
        if(i=='B'){
            t['B']= true;
        }
        if(i=='G'){
            t['C'] = true;
        }
        if(i!='B'){
            t['D'] = true;
        }
        if(!t['A']){
            t['E'] = true;
        }
        if(i!='F' and i!='H'){
            t['F'] = true;
        }
        if(i!='C'){
            t['G'] = true;
        }
        if(t['A']){
            t['H'] = true;
        }
        if(panduan()){
            ans++;
            a=i;
        }
    }
    if(ans==1){
        printf("%c\n",a);
    }
    else{
        printf("DONTKNOW");
    }
    return 0;
}