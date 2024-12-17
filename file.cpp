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

int main()
{
    FILE *fr = fopen("file.txt", "r");

    FILE *fw = fopen("file.txt", "w");
    FILE *fwb = fopen("file.bin", "wb");
    int a[] = {220394859, 2, 3, 67, 5};
    fwrite(a, sizeof(int), 5, fwb);
    fclose(fwb);
    int b[10];

    FILE *frb = fopen("file.bin", "rb");
    fread(b, sizeof(int), 5, frb);
    for (int i = 0; i < 5; i++)
    {
        cout << b[i] << " ";
    }
    // char s[] = "sadfasdf";
    // fwrite(s, sizeof(char), strlen(s), fwb);
    // for (int i = 0; i < 5; i++)
    // {
    //     fprintf(fw, "%d ", a[i]);
    // }
    fclose(fw);
    fclose(frb);
    fclose(fr);
    return 0;
}