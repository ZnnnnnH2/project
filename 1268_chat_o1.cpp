#include <bits/stdc++.h>
using namespace std;

// 最大长度，根据题意可为 5e6，这里为演示示例
static const int MAXN = 5000000;

// 原字符串
static char s[MAXN + 5], t[MAXN + 5];
static int n;

// 单哈希示例，可改为双哈希加强抵抗冲突
static unsigned long long preS[MAXN + 5], preT[MAXN + 5], powerBase[MAXN + 5];
static const unsigned long long base = 131ULL;

// 获取区间 [l, r] 的哈希值
inline unsigned long long getHash(const unsigned long long *pre, int l, int r)
{
    return pre[r + 1] - pre[l] * powerBase[r - l + 1];
}

// 递归计算规范表示的哈希值
// 若长度无法被 3 整除，直接返回子串哈希
// 能被 3 整除则三等分，递归得到三段的规范哈希，排序后拼接
unsigned long long getCanonicalHash(const unsigned long long *pre, int l, int r)
{
    int length = r - l + 1;
    if (length < 3 || length % 3 != 0)
    {
        return getHash(pre, l, r);
    }
    int seg = length / 3;
    unsigned long long h[3];
    h[0] = getCanonicalHash(pre, l, l + seg - 1);
    h[1] = getCanonicalHash(pre, l + seg, l + 2 * seg - 1);
    h[2] = getCanonicalHash(pre, l + 2 * seg, r);
    sort(h, h + 3);
    // 合并三段哈希到一个值
    // 这里只是示例做法，拼接方式可根据实际需求设计
    unsigned long long combined = 0;
    for (int i = 0; i < 3; i++)
    {
        combined = combined * base + (h[i] & 0xffffffffULL);
    }
    return combined;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    n = strlen(s);
    if ((int)strlen(t) != n)
    {
        cout << "NO\n";
        return 0;
    }

    // 预处理哈希
    powerBase[0] = 1ULL;
    for (int i = 0; i < n; i++)
    {
        preS[i + 1] = preS[i] * base + (unsigned char)s[i];
        preT[i + 1] = preT[i] * base + (unsigned char)t[i];
        powerBase[i + 1] = powerBase[i] * base;
        cout<<powerBase[i+1]<<endl;
    }

    // 计算 S 和 T 的规范哈希进行比较
    unsigned long long sHash = getCanonicalHash(preS, 0, n - 1);
    unsigned long long tHash = getCanonicalHash(preT, 0, n - 1);
    cout << ((sHash == tHash) ? "YES\n" : "NO\n");
    return 0;
}