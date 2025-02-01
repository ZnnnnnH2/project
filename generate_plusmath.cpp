#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <windows.h>
#include <time.h>

typedef long long ll;
typedef int *intt;
typedef char *charr;

using namespace std;
const int inf = 0x3f3f3f3f;
const int N = 1e5 + 5;
char getSign()
{
    return rand() % 2 == 0 ? '+' : '-';
}
int getmun(int a, int b, char sign)
{
    if (sign == '+')
    {
        return a + b;
    }
    else
    {
        return a - b;
    }
}
bool checker(int a)
{
    if (a < 0 or a > 100)
    {
        return false;
    }
    return true;
}
int main()
{
    srand(time(0));
    FILE *fp = fopen("math.doc", "w");
    FILE *fp2 = fopen("ans.txt", "w");
    for (int i = 1; i <= 50; i++)
    {
        int a = rand() % 50;
        int b = rand() % 50;
        int c = rand() % 50;
        char sign1 = getSign();
        char sign2 = getSign();
        if (rand() % 2 == 0)
        {
            int mun1 = getmun(a, b, sign1);
            if (checker(mun1))
            {
                int mun2 = getmun(mun1, c, sign2);
                if (checker(mun2))
                {
                    fprintf(fp,"%2d : %d %c %d %c %d = \n",i,a,sign1,b,sign2,c);
                    fprintf(fp2,"%2d : %d\n",i,mun2);
                }
                else
                {
                    i--;
                }
            }
            else{
                i--;
            }
        }
        else{
            int mun1 = getmun(b, c, sign2);
            if (checker(mun1))
            {
                int mun2 = getmun(a, mun1, sign1);
                if (checker(mun2))
                {
                    fprintf(fp,"%2d : %d %c (%d %c %d) = \n",i,a,sign1,b,sign2,c);
                    fprintf(fp2,"%2d : %d\n",i,mun2);
                }
                else
                {
                    i--;
                }
            }
            else{
                i--;
            }
        }
    }
    return 0;
}