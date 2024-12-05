#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
 
using namespace std;

int main()
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    int len1=s1.length();
    int len2=s2.length();
    for(int i=0;i<len1;i++)
    {
        if(s1[i]!=s2[i])
        {
            cout<<s1[i]-s2[i]<<endl;
            return 0;
        }
    }
    cout<<0<<endl;
    return 0;
}
