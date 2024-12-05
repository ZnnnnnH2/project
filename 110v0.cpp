#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s1[2000], s2[2000];
    int len, g=0;
    cin >> s1;
    len = strlen(s1);
    if (len % 2 == 1)
    {
        for (int i = len - 1; i >= (len - 1) / 2; i--)
            s2[len - 1 - i] = s1[i];
        for (int j = 0; j <= (len - 1) / 2; j++)
        {
            if (s1[j] == s2[j])
            {
                g++;
                continue;
            }
            else
            {
                cout << "No";
                break;
            }
        }
        if (g == (len + 1) / 2)
            cout << "Yes";
    }
    if (len % 2 == 0)
    {
        for (int i = len - 1; i >= len / 2; i--)
            s2[len - 1 - i] = s1[i];
        for (int j = 0; j < len / 2; j++)
        {
            if (s1[j] == s2[j])
            {
                g++;
                continue;
            }
            else
            {
                cout << "No";
                break;
            }
        }
        if (g == len / 2)
            cout << "Yes";
    }
    return 0;
}