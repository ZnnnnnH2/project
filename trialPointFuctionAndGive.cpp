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
int a[N];
int n = 10, m = 10;
void function(int *c)
{
    cout << *(c+n+1) << endl;
}
int main()
{
    // memset(a, 0x7f, sizeof(a));
    // printf("%d", a[0]);
    // int n = 10;
    // int *p1 = new int[n]; // int a[10]; int *p=a;

    // int(*p2)[10] = new int[10][10];
    // *(*(p2 + 1) + 1) = 9;
    // delete[] p1;
    // delete[] p2;
    // int **p = new int *[10];
    // for (int i = 0; i < 10; i++)
    // {
    //     p[i] = new int[100];
    // }
    // for (int i = 0; i < 10; i++)
    // {
    //     delete[] p[i];
    // }
    // delete[] p;
    // try
    // {
    //     int *p = new int[1000000000000000000];
    // }
    // catch (bad_alloc &e)
    // {
    //     cout << "bad_alloc" << e.what() << endl;
    // }

    // int **p = new int *[n];
    // for (int i = 1; i <= n; i++)
    // {
    //     p[i] = new int[m];
    // }
    int b[10][10];
    b[1][1] = 10;
    function((int *)b);
    return 0;
}