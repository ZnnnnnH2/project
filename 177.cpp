#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <queue>

using namespace std;

priority_queue<int,vector<int>,greater<int> > q;

int main() {
    int n,k;
    scanf("%d%d",&n,&k);
    int tot=0;
    while(n--){
        int a;
        scanf("%d",&a);
        int a1=a;
        int sum=0;
        while(a1){
            sum+=a1%10;
            a1/=10;
        }
        if(sum%k==0){
            q.push(a);
            tot++;
        }
    }
    printf("%d\n",tot);
    while(!q.empty()){
        printf("%d\n",q.top());
        q.pop();
    }
    return 0;
}