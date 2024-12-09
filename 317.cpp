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
const int N = 1e5 + 5;

int main()
{
    string str;
    getline(cin, str);
    ll ans = 0;
    int len = str.length();
    ll temp = 0;
    str += 'a';
    for (int i = 0; i <= len; i++)
    {
        if (str[i] >= '0' and str[i] <= '9')
        {
            temp *= 10;
            temp += str[i] - '0';
        }
        else
        {
            // cout << temp << endl;
            ans += temp;
            temp = 0;
        }
    }
    printf("%lld\n", ans);
    return 0;
}