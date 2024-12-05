#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    freopen("0000in.txt","r",stdin);
    freopen("0000out.txt","w",stdout);
    int n;
    scanf("%d", &n);
    for(int j=1;j<=n;j++){
        char s[200];
        memset(s, 0, sizeof(s));
        string str1,yuan,mubiao,ans;
        cin>>str1>>yuan>>mubiao;
        int len=str1.length();
        int len_yuan=yuan.length();
        int len_mubiao=mubiao.length();
        for(int i=0;i<len_yuan;i++){
            s[yuan[i]]=i;
        }
        long long sum=0;
        for(int i=0;i<len;i++){
            sum*=len_yuan;
            sum+=s[str1[i]];
        }
        // printf("%d\n",sum);
        int len_ans=0;
        while(sum){
            ans[len_ans++]=mubiao[sum%len_mubiao];
            sum/=len_mubiao;
        }
        printf("Case #%d:",j);
        for(int i=len_ans-1;i>=0;i--){
            printf("%c",ans[i]);
        }
        printf("\n");
    }
    return 0;
}