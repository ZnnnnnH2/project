#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int a,b;
    scanf("%d %d",&a,&b);
    long long ans=0;
    for(int i=a;i<=b;i++){
        int temp=i;
        temp*=temp;
        string s=to_string(temp);
        string s1=to_string(i);
        int len=s.length();
        int len1=s1.length();
        for(int j=len-1,k=len1-1;k>=0;j--,k--){ 
            if(s[j]!=s1[k]){
                goto NO;
            }
        }
        ans+=i;
        NO:;
    }
    printf("%lld\n",ans);
    return 0;
}