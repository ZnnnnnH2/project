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
struct node
{
    int n;
    char s[10]; // 修改为固定大小的字符数组
};
node Student[10];

int main(int argc, char *argv[])
{
    FILE *fr, *fw;
    fr = fopen(argv[1], "r");
    fw = fopen(argv[2], "wb");
    if (fr == NULL)
    {
        cout << "Can't open file input" << endl;
        return 0;
    }
    if (fw == NULL)
    {
        cout << "Can't open file output" << endl;
        return 0;
    }
    for (int i = 1; i <= 3; i++)
    {
        fscanf(fr, "%d", &Student[i-1].n);
        char s[10];
        fscanf(fr, "%s", s);
        strcpy(Student[i-1].s, s);
    }
    printf("%d\n", sizeof(node));
    fwrite(Student, sizeof(node), 3, fw);
    fclose(fr);
    fclose(fw);
    return 0;
}