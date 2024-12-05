#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
 
using namespace std;

int main()
{
    char s[10002];
    scanf("%s",s);
    int len = strlen(s);
    int i=0,j=len-1;
    while(i<j){
        if(s[i]!=s[j]){
            printf("No\n");
            return 0;
        }
        i++;
        j--;
    }
    printf("Yes\n");
    return 0;
}
