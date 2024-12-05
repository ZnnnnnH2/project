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

int main() {
    freopen("out.txt","r",stdin);
    freopen("out1.txt","w",stdout);
    for (int i = 0; i <= 15000/2;i++){
        int a, b;
        scanf("%d : %d", &a, &b);
        printf("a[%d]=%d;\n", i, b);
    }
    return 0;
}