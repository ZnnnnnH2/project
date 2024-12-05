#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <string.h>
 
using namespace std;
long long cipin[200];
long long howmuch[200];

int main()
{
    memset(cipin,0,sizeof(cipin));
    memset(howmuch,0,sizeof(howmuch));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++){
        int t;
        scanf("%d",&t);
        bool fla[105];
        memset(fla,0,sizeof(fla));
        for(int j=1;j<=t;j++){
            int a;
            scanf("%d",&a);
            cipin[a]++;
            if(!fla[a]){
                howmuch[a]++;
                fla[a]=1;
            }
        }
    }
    for(int i=1;i<=m;i++){
        printf("%lld %lld\n",howmuch[i],cipin[i]);
    }
    return 0;
}
