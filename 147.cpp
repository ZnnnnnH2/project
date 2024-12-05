#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>

using namespace std;

int main()
{
    bool flag = false;
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int classroom[10] = {0, 120, 40, 85, 50, 100, 140, 70, 100};
    for (int i1 = 1; i1 <= 8; i1++)
    {
        for (int i2 = 1; i2 <= 8; i2++)
        {
            for (int i3 = 1; i3 <= 8; i3++)
            {
                for (int i4 = 1; i4 <= 8; i4++)
                {
                    if (i1 != i2 && i1 != i3 && i1 != i4 && i2 != i3 && i2 != i4 && i3 != i4)
                    {
                        if (classroom[i1] >= a && classroom[i2] >= b && classroom[i3] >= c && classroom[i4] >= d)
                        {
                            cout << i1 << " " << i2 << " " << i3 << " " << i4 << endl;
                            flag = true;
                        }
                    }
                }
            }
        }
    }
    if (!flag)
    {
        cout << "-1" << endl;
    }
    return 0;
}
