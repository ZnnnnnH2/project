#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <Windows.h>
typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;

int main()
{
    while (1)
    {
        int tottask;
        int wrongmun;
        cin >> tottask >> wrongmun;
        double ans;
        ans = (double)(tottask - wrongmun) / tottask * 100;
        cout << ans << endl;
    }
    return 0;
}