#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

int main() {
    char s[10][100]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday","Monday"};
    int a,b;
    cin>>a>>b;
    printf("%s\n%s",s[a+1],s[b-1]);
    return 0;
}