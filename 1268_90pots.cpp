#include <iostream>
#include <string.h>
#include <stdio.h>
#include <time.h>
#include <unordered_map>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 5e6 + 5;
char s[N], t[N];
int len;
unordered_map<string, bool> mp;
bool Check(int *s1, int *s2)
{
    for (int i = 0; i < 26; i++)
    {
        if (s1[i] != s2[i])
        {
            // if (flag)
            //     cout << "false" << endl;
            return false;
        }
    }
    // if (flag)
    // cout << "true" << endl;
    return true;
}
void get_mun_s(int l, int r, int *a, char *str)
{
    for (int i = 0; i < 26; i++)
    {
        a[i] = 0;
    }
    for (int i = l; i <= r; i++)
    {
        a[str[i] - 'a']++;
    }
    return;
}
bool same(int ls, int lr, int lt, int rt)
{
    for (; ls <= lr; ls++, lt++)
    {
        if (s[ls] != t[lt])
        {
            return false;
        }
    }
    return true;
}
bool fenge(int ls, int rs, int lt, int rt)
{

    // if ((rs - ls + 1) % 3 != 0)
    // {
    bool aaaa = same(ls, rs, lt, rt);
    if (aaaa or (rs - ls + 1) % 3 != 0)
    {
        return aaaa;
    }
    int s1[3][26];
    int s2[3][26];
    int mids1 = (rs + (ls << 1)) / 3;
    int mids2 = ((rs << 1) + ls) / 3;
    int midt1 = (rt + (lt << 1)) / 3;
    int midt2 = ((rt << 1) + lt) / 3;
    get_mun_s(ls, mids1, s1[0], s);
    get_mun_s(mids1 + 1, mids2, s1[1], s);
    get_mun_s(mids2 + 1, rs, s1[2], s);
    get_mun_s(lt, midt1, s2[0], t);
    get_mun_s(midt1 + 1, midt2, s2[1], t);
    get_mun_s(midt2 + 1, rt, s2[2], t);
    bool chk11 = Check(s1[0], s2[0]);
    bool chk12 = Check(s1[0], s2[1]);
    bool chk13 = Check(s1[0], s2[2]);
    bool chk21 = Check(s1[1], s2[0]);
    bool chk22 = Check(s1[1], s2[1]);
    bool chk23 = Check(s1[1], s2[2]);
    bool chk31 = Check(s1[2], s2[0]);
    bool chk32 = Check(s1[2], s2[1]);
    bool chk33 = Check(s1[2], s2[2]);
    bool ans = 0;
    int fenge11 = -1;
    int fenge12 = -1;
    int fenge13 = -1;
    int fenge21 = -1;
    int fenge22 = -1;
    int fenge23 = -1;
    int fenge31 = -1;
    int fenge32 = -1;
    int fenge33 = -1;
    if (chk11 && chk22 && chk33)
    {
        if (fenge11 == -1)
        {
            fenge11 = fenge(ls, mids1, lt, midt1);
        }
        if (fenge22 == -1)
        {
            fenge22 = fenge(mids1 + 1, mids2, midt1 + 1, midt2);
        }
        if (fenge33 == -1)
        {
            fenge33 = fenge(mids2 + 1, rs, midt2 + 1, rt);
        }
        ans |= fenge11 && fenge22 && fenge33;
    }
    if (chk11 && chk23 && chk32 && !ans)
    {
        if (fenge11 == -1)
        {
            fenge11 = fenge(ls, mids1, lt, midt1);
        }
        if (fenge23 == -1)
        {
            fenge23 = fenge(mids1 + 1, mids2, midt2 + 1, rt);
        }
        if (fenge32 == -1)
        {
            fenge32 = fenge(mids2 + 1, rs, midt1 + 1, midt2);
        }
        ans |= fenge11 && fenge23 && fenge32;
    }
    if (chk12 && chk21 && chk33 && !ans)
    {
        if (fenge12 == -1)
        {
            fenge12 = fenge(ls, mids1, midt1 + 1, midt2);
        }
        if (fenge21 == -1)
        {
            fenge21 = fenge(mids1 + 1, mids2, lt, midt1);
        }
        if (fenge33 == -1)
        {
            fenge33 = fenge(mids2 + 1, rs, midt2 + 1, rt);
        }
        ans |= fenge12 && fenge21 && fenge33;
    }
    if (chk12 && chk23 && chk31 && !ans)
    {
        if (fenge12 == -1)
        {
            fenge12 = fenge(ls, mids1, midt1 + 1, midt2);
        }
        if (fenge23 == -1)
        {
            fenge23 = fenge(mids1 + 1, mids2, midt2 + 1, rt);
        }
        if (fenge31 == -1)
        {
            fenge31 = fenge(mids2 + 1, rs, lt, midt1);
        }
        ans |= fenge12 && fenge23 && fenge31;
    }
    if (chk13 && chk21 && chk32 && !ans)
    {
        if (fenge13 == -1)
        {
            fenge13 = fenge(ls, mids1, midt2 + 1, rt);
        }
        if (fenge21 == -1)
        {
            fenge21 = fenge(mids1 + 1, mids2, lt, midt1);
        }
        if (fenge32 == -1)
        {
            fenge32 = fenge(mids2 + 1, rs, midt1 + 1, midt2);
        }
        ans |= fenge13 && fenge21 && fenge32;
    }
    if (chk13 && chk22 && chk31 && !ans)
    {
        if (fenge13 == -1)
        {
            fenge13 = fenge(ls, mids1, midt2 + 1, rt);
        }
        if (fenge22 == -1)
        {
            fenge22 = fenge(mids1 + 1, mids2, midt1 + 1, midt2);
        }
        if (fenge31 == -1)
        {
            fenge31 = fenge(mids2 + 1, rs, lt, midt1);
        }
        ans |= fenge13 && fenge22 && fenge31;
    }
    return ans;
}
int main()
{
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
    clock_t start, end;
    start = clock();

    scanf("%s%s", s, t);
    len = strlen(s);
    int i = 0;
    bool c = fenge(0, len - 1, 0, len - 1);
    if (c)
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }
    end = clock();
    cout << "Time: " << (double)(end - start) << "ms" << endl;
    return 0;
}
