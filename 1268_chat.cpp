#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

// 使用 unordered_map 来缓存已计算的子字符串是否融洽
unordered_map<string, bool> memo;

// 辅助函数：计算字符串的字符频率
bool is_same_frequency(const string &S, const string &T)
{
    vector<int> freq(26, 0);
    for (char c : S)
    {
        freq[c - 'a']++;
    }
    for (char c : T)
    {
        freq[c - 'a']--;
    }
    for (int count : freq)
    {
        if (count != 0)
            return false;
    }
    return true;
}

// 递归判断字符串S和T是否融洽
bool is_cordial(const string &S, const string &T)
{
    // 如果已经计算过，直接返回缓存的结果
    if (memo.find(S + "|" + T) != memo.end())
    {
        return memo[S + "|" + T];
    }

    int n = S.size();

    // 1. 如果S和T相等，则它们融洽
    if (S == T)
    {
        memo[S + "|" + T] = true;
        return true;
    }

    // 2. 如果字符频率不同，它们不可能融洽
    if (!is_same_frequency(S, T))
    {
        memo[S + "|" + T] = false;
        return false;
    }

    // 3. 字符串长度必须能够被3整除
    if (n % 3 != 0)
    {
        memo[S + "|" + T] = false;
        return false;
    }

    // 4. 分割字符串并递归检查
    int third = n / 3;
    string S1 = S.substr(0, third), S2 = S.substr(third, third), S3 = S.substr(2 * third, third);
    string T1 = T.substr(0, third), T2 = T.substr(third, third), T3 = T.substr(2 * third, third);

    // 尝试所有排列
    bool result = (is_cordial(S1, T1) && is_cordial(S2, T2) && is_cordial(S3, T3)) ||
                  (is_cordial(S1, T2) && is_cordial(S2, T3) && is_cordial(S3, T1)) ||
                  (is_cordial(S1, T3) && is_cordial(S2, T1) && is_cordial(S3, T2));

    // 缓存结果
    memo[S + "|" + T] = result;
    return result;
}

int main()
{
    // freopen("in.txt", "r", stdin);
    string S, T;
    cin >> S >> T;

    if (is_cordial(S, T))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
