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
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int e, f;
    f = b * d;
    e = a * d + b * c;
    int g = __gcd(e, f);
    cout << e / g << "/" << f / g << endl;
    return 0;
}