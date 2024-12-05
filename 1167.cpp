#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
#include <map>

using namespace std;

map<string, int> t;
map<string, int> q;
int main()
{
    int n, m;
    cin >> n >> m;
    int tot_1 = 0, tot_2 = 0;
    int ajiaob = 0, abingb = 0;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin >> k;
        int len = k.size();
        for (int j = 0; j < len; j++)
        {
            if (k[j] >= 'a' && k[j] <= 'z')
            {
                k[j] -= 32;
            }
        }
        // cout << k << endl;
        if (t.find(k) == t.end())
        {
            t[k] = 1;
            tot_1++;
        }
    }
    for (int i = 0; i < m; i++)
    {
        string k;
        cin >> k;
        int len = k.size();
        for (int j = 0; j < len; j++)
        {
            if (k[j] >= 'a' && k[j] <= 'z')
            {
                k[j] -= 32;
            }
        }
        // cout << k << endl;

        if (q.find(k) == q.end())
        {
            q[k] = 1;
            tot_2++;
            if (t.find(k) != t.end())
            {
                ajiaob++;
            }
        }
    }
    printf("%d\n%d", ajiaob, tot_1 + tot_2 - ajiaob);
    return 0;
}
