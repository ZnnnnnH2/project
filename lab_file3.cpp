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
const int inf=0x3f3f3f3f;
const int N=1e5+5;
struct node{
    int n;
    char s[10]; // 修改为固定大小的字符数组
};

int main() {
    FILE *fr, *fw;
    fr = fopen("sad.bin", "rb");
    fw = fopen("sad.txt", "w");
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
    for(int i=1;i<=3;i++){
        node Student;
        fread(&Student, sizeof(node), 1, fr);
        fprintf(fw, "!%d! %s\n", Student.n, Student.s); // 修正为写入到文件 fw
    }
    fclose(fr);
    fclose(fw);
    return 0;
}