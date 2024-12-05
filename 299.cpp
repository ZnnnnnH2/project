#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;
    for(int i=2;i<=n;i++){
        int tot=0;
        while(n%i==0){
            tot++;
            n/=i;
        }
        if(tot>0){
            cout << i << ':' << tot <<endl;
        }
    }
    return 0;
}