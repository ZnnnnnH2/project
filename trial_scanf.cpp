#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    // int x,y;
    // char d;
    // scanf("%d%d", &x, &y); //input = 34f5   can't  5 in y
    // printf("%d %d", x, y);

    // cin>>x>>y;
    // printf("%d %d", x, y);

    // string a;
    // getline(cin, a);
    char b[1000];
    gets(b);
    int x;
    sscanf(b, "%d", &x);
    char t[1000];
    sprintf(t, "%o", x);
    printf("%s",t);
    return 0;
}