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

int main() {
    FILE *fr, *fw;
    fr = fopen("innn.txt", "r");
    fw = fopen("output.txt", "w");
    if(fr==NULL || fw==NULL) {
        cout << "Error opening file" << endl;
        return 0;
    }
    char ch;
    while(!feof(fr)){
        if((ch=fgetc(fr))!=EOF){
            fputc(ch,fw);
        }
    }
    fclose(fr);
    fclose(fw);
    return 0;
}