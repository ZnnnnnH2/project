#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>

using namespace std;
int POW(int a, int n)
{
    return a*n;
}
int main()
{
    int sum;
    cin >> sum;
    for (int j = 10000; j <= 99999; j++)
    {
        string str=to_string(j);
        if(str[0]==str[1] or str[0]==str[2] or str[0]==str[3] or str[0]==str[4] or str[1]==str[2] or str[1]==str[3] or str[1]==str[4] or str[2]==str[3] or str[2]==str[4] or str[3]==str[4]){
            continue;
        }
        if(str[0]=='0' or str[1]=='0' or str[2]=='0' or str[3]=='0' or str[4]=='0'){
            continue;
        }
        if(str[0]>'5' or str[1]>'5' or str[2]>'5' or str[3]>'5' or str[4]>'5'){
            continue;
        }
        int i = j;
        int tot = 0;
        tot += i % 10;
        i /= 10;
        tot += POW(i % 10, 4);
        i /= 10;
        tot += POW(i % 10, 6);
        i /= 10;
        tot += POW(i % 10, 4);
        i /= 10;
        tot += POW(i % 10, 1);
        if (tot == sum)
        {
            
            for(int i=0;i<5;i++){
                cout << str[i] << " " ;
            }
            return 0;
        }
    }
    return 0;
}
