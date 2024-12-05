#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
static void function(int a, int b) {
    int c = a + b;
    cout << c << endl;
}
extern "C" void function(int a, int b) {
    int c = a + b;
    cout << c << endl;
}
int main() {
    function(1, 2);
    return 0;
}