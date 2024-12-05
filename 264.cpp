#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
 
#define ll long long

using namespace std;
const int inf=0x3f3f3f3f;
const int N=1e5+5;
string s[N];

int main() {
    int n;
    cin >> n;
    char a[100];
    getchar();
    scanf("%[^\n]", a);
    char cmd[100];
    int mun;
    getchar();
    sscanf(a, "%s %d", cmd, &mun);
    // printf("%s %d\n", cmd, mun);
    if(cmd[0]=='h'){
        while(mun--){
            string str;
            getline(cin, str);
            cout << str<<endl;
        }
    }
    else{
        int t = n - mun;
        while(t--){
            string str;
            getline(cin, str);
        }
        while(mun--){
            string str;
            getline(cin, str);
            cout << str<<endl;
        }
    }
    return 0;
}