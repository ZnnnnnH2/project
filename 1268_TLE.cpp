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
string a[N], b[N];

int main()
{
    string s, t;
    cin >> s >> t;
    int len = s.size();
    int k = len;
    while (k % 3 == 0)
    {
        k /= 3;
    }
    int tot = 0;
    for (int i = 0; i < len; i += k)
    {
        for (int j = 0; j < k; j++)
        {
            a[tot] += s[i + j];
            b[tot] += t[i + j];
        }
        tot++;
    }
    sort(a, a + tot);
    sort(b, b + tot);
    for (int i = 0; i < tot; i++)
    {
        if (a[i] != b[i])
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}