#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int t[200];
string score[105];
bool cmp(string a, string b)
{
    int head1=0;
    int head2=0;
    while(t[a[head1]]==0){
        head1++;
    }
    while(t[b[head2]]==0){
        head2++;
    }
    int lena=a.length();
    int lenb=b.length();
    if(lena-head1!=lenb-head2){
        return lena-head1>lenb-head2;
    }
    else{
        for(;head1<lena and head2<lenb;head1++,head2++){
            if(a[head1]!=b[head2]){
                return t[a[head1]]>t[b[head2]];
            }
        }
    }
    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    string str;
    cin >> str;
    int len = str.length();
    // int duijing=0;
    for (int i = 0; i < len; i++)
    {
        t[str[i]] = i;
    }
    for (int i = 0; i < n; i++){
        cin >> score[i];
    }
    sort(score, score + n, cmp);
    for (int i = 0; i < n; i++){
        cout << score[i] << " ";
    }
    cout << endl;
    long long ans=0;
    int lens=score[n-1].length();
    for(int i=0;i<lens;i++){
        ans*=len;
        ans+=t[score[n-1][i]];
    }
    printf("%lld\n",ans);
    return 0;
}