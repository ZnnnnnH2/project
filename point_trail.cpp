#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
char *strc(char *a, const char *b)
{
    // b is a const char* type
    b++; // ok for const char*
    // (*b)='a'; //error: assignment of read-only location ‘* b’
    printf("%c\n", *b);
    return a;
}
void t(int (*p)[4])
{
    cout << p << endl;
}
void t1(int (*p)[10][4])
{
    cout << p << endl;
}
int main()
{
    // int a[] = {0, 1, 2, 3, 4};
    // int *p1 = &a[1];
    // cout << ++*(p1) << endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     cout << a[i];
    // }
    // char b[] = "hello";
    // char c[] = "world";
    // strc(b, c);
    int a[10][4];
    t(a);
    t1(&a);
    int b[10];
    int c[2];
    int *arry[10];

    intt arr[3];
    arr[0] = b;
    arry[1] = b;
    arry[2] = c;
    return 0;
}