#include<stdio.h>
#include<iostream>
#include<string.h>

using namespace std;
int main()
{
    int n,g=0;
    scanf("%d",&n);
    int b[n],c[n];//对的数、对的位
    char a[n][5];//每一位
    int s[4];//循环的数
    memset(a,0,sizeof(a));
    memset(s,0,sizeof(s));
    memset(b,0,sizeof(b));
    memset(c,0,sizeof(c));
    for(int i=0;i<n;i++) scanf("%s %d %d",a[i],&b[i],&c[i]);
    int ku[n][10]={0},ye[n]={0};//ku为每个数出现的个数
    memset(ku,0,sizeof(ku));
    memset(ye,0,sizeof(ye));
    for(int i=0;i<n;i++){
        for(int j=0;j<=3;j++) ku[i][a[i][j]-'0']++;//统计每一个输入的数中每一个数字的个数
    }
    // for(int i=0;i<n;i++){
    //     for(int j=0;j<10;j++) printf("%d ",ku[i][j]);
    //     printf("\n");
    // }
    int yes=0,cun[4];
    memset(cun,0,sizeof(cun));
    for(s[0]=0;s[0]<=9;s[0]++){
        for(s[1]=0;s[1]<=9;s[1]++){
            for(s[2]=0;s[2]<=9;s[2]++){
                for(s[3]=0;s[3]<=9;s[3]++){//遍历
                    int ku1[10]={0};//每一次遍历到的数各数字个数
                    for(int i=0;i<=3;i++) ku1[s[i]]++;
                    // for(int i=0;i<10;i++) printf("%d ",ku1[i]);
                    // printf("\n");
                    for(int t=0;t<n;t++){
                        int ku2[12]={0};//ku与ku1的最小值
                        for(int i=0;i<=9;i++) ku2[i]=ku1[i]<ku[t][i]?ku1[i]:ku[t][i];//算最小值
                        for(int i=0;i<=9;i++) ku2[10]+=ku2[i];//ku2[10]是猜对的个数
                        for(int i=0;i<=3;i++){
                            if(a[t][i]-'0'==s[i]) ku2[11]++;//ku2[11]是正确的位数
                        }
                        if(ku2[10]==b[t]&&ku2[11]==c[t]) ye[t]=1;
                        // for(int i=0;i<10;i++) printf("%d ",ku2[i]);
                        // printf("\n");
                        // printf("%d %d\n",ku2[10],ku2[11]);
                    }
                    for(int i=0;i<n;i++) yes+=ye[i];
                    // for(int i=0;i<n;i++) printf("%d ",ye[i]);
                    // printf("\n");
                    if(yes==n){
                        g++;
                        for(int i=0;i<=3;i++) cun[i]=s[i];
                    }
                    memset(ye,0,sizeof(ye));
                }
            }
        }
    }
    if(g==1) for(int i=0;i<=3;i++) printf("%d",cun[i]);
    else printf("Not sure");
    // printf("%d",g);
}