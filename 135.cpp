#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
struct node{
    string allNum;
    int BirthNum;
    void gouzao(){
        for (int i = 6; i < 14;i++){
            BirthNum = BirthNum * 10 + allNum[i] - '0';
        }
    }
    bool operator < (const node &a)const {
        if(BirthNum != a.BirthNum)
            return BirthNum > a.BirthNum;
        else
            return allNum > a.allNum;
    }
};
node p[1000005];

int main() {
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        cin >> p[i].allNum;
        p[i].gouzao();
    }
    sort(p, p + n);
    for(int i = 0; i < n; i++){
        cout << p[i].allNum << endl;
    }
    return 0;
}