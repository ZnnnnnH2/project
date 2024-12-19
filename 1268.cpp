#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e6 + 5;
char s[N], t[N];
int len;
int a[N][26], b[N][26];
bool Check(int ls, int rs, int lt, int rt)
{
    for (int i = 0; i < 26; i++)
    {
        if (a[rs][i] - a[ls - 1][i] != b[rt][i] - b[lt - 1][i])
            return false;
    }
    return true;
}
bool fenge(int ls, int rs, int lt, int rt)
{
    if ((rs - ls + 1) % 3 != 0)
    {
        return Check(ls, rs, lt, rt);
    }
    int mids1 = (rs + ls) / 3;
    int mids2 = (rs + ls) * 2 / 3;
    int midt1 = (rt + lt) / 3;
    int midt2 = (rt + lt) * 2 / 3;
    bool chk11 = Check(ls, mids1, lt, midt1);
    bool chk12 = Check(ls, mids1, midt1 + 1, midt2);
    bool chk13 = Check(ls, mids1, midt2 + 1, rt);
    bool chk21 = Check(mids1 + 1, mids2, lt, midt1);
    bool chk22 = Check(mids1 + 1, mids2, midt1 + 1, midt2);
    bool chk23 = Check(mids1 + 1, mids2, midt2 + 1, rt);
    bool chk31 = Check(mids2 + 1, rs, lt, midt1);
    bool chk32 = Check(mids2 + 1, rs, midt1 + 1, midt2);
    bool chk33 = Check(mids2 + 1, rs, midt2 + 1, rt);
    bool ans = 0;
    if (chk11 && chk22 && chk33)
    {
        ans |= fenge(ls, mids1, lt, midt1) && fenge(mids1 + 1, mids2, midt1 + 1, midt2) && fenge(mids2 + 1, rs, midt2 + 1, rt);
    }
    if (chk11 && chk23 && chk32)
    {
        ans |= fenge(ls, mids1, lt, midt1) && fenge(mids1 + 1, mids2, midt1 + 1, midt2) && fenge(mids2 + 1, rs, midt2 + 1, rt);
    }
    if (chk12 && chk21 && chk33)
    {
        ans |= fenge(ls, mids1, midt1 + 1, midt2) && fenge(mids1 + 1, mids2, lt, midt1) && fenge(mids2 + 1, rs, midt2 + 1, rt);
    }
    if (chk12 && chk23 && chk31)
    {
        ans |= fenge(ls, mids1, midt1 + 1, midt2) && fenge(mids1 + 1, mids2, lt, midt1) && fenge(mids2 + 1, rs, midt2 + 1, rt);
    }
    if (chk13 && chk21 && chk32)
    {
        ans |= fenge(ls, mids1, midt2 + 1, rt) && fenge(mids1 + 1, mids2, lt, midt1) && fenge(mids2 + 1, rs, midt1 + 1, midt2);
    }
    if (chk13 && chk22 && chk31)
    {
        ans |= fenge(ls, mids1, midt2 + 1, rt) && fenge(mids1 + 1, mids2, midt1 + 1, midt2) && fenge(mids2 + 1, rs, lt, midt1);
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    scanf("%s%s", s, t);
    len = strlen(s);
    int i = 0;
    a[i][s[i] - 'a']++;
    b[i][t[i] - 'a']++;
    for (; i < len; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            a[i][j] = a[i - 1][j];
            b[i][j] = b[i - 1][j];
        }
        a[i][s[i] - 'a']++;
        b[i][t[i] - 'a']++;
    }
    bool c=fenge(0, len - 1, 0, len - 1);
    if(c)
    {
        cout<<"YES"<<endl;
    }
    else
    {
        cout<<"NO"<<endl;
    }
    return 0;
}
