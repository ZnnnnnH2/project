#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

unordered_map<unsigned long long, bool> memo;

// 计算子串的哈希值
unsigned long long get_hash(const string &s, int l, int r)
{
    unsigned long long hash = 0;
    for (int i = l; i < r; i++)
    {
        hash = hash * 131 + s[i];
    }
    return hash;
}

bool is_cordial(const string &S, const string &T, int sl, int sr, int tl, int tr)
{
    if (sr - sl != tr - tl)
        return false;
    int len = sr - sl;

    // 计算当前子问题的哈希值
    unsigned long long key = get_hash(S, sl, sr) * 131 + get_hash(T, tl, tr);
    if (memo.count(key))
        return memo[key];

    // 检查是否相等
    if (S.substr(sl, len) == T.substr(tl, len))
    {
        return memo[key] = true;
    }

    // 长度不能被3整除
    if (len % 3 != 0)
    {
        return memo[key] = false;
    }

    // 检查字符频率
    vector<int> freq(26, 0);
    for (int i = sl; i < sr; i++)
        freq[S[i] - 'a']++;
    for (int i = tl; i < tr; i++)
        freq[T[i] - 'a']--;
    for (int i : freq)
        if (i != 0)
            return memo[key] = false;

    int third = len / 3;
    // 只需要检查不同的排列组合
    bool result = false;
    for (int i = 0; i < 3 && !result; i++)
    {
        for (int j = 0; j < 3 && !result; j++)
        {
            if (j == i)
                continue;
            int k = 3 - i - j;
            result |= (is_cordial(S, T, sl, sl + third, tl + i * third, tl + (i + 1) * third) &&
                       is_cordial(S, T, sl + third, sl + 2 * third, tl + j * third, tl + (j + 1) * third) &&
                       is_cordial(S, T, sl + 2 * third, sr, tl + k * third, tl + (k + 1) * third));
        }
    }
    return memo[key] = result;
}

int main()
{
    freopen("in.txt", "r", stdin);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string S, T;
    cin >> S >> T;
    cout << (is_cordial(S, T, 0, S.length(), 0, T.length()) ? "YES" : "NO");
    return 0;
}