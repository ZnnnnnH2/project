#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;
int Hash[200];
int shoupai[5][15];
int gongpai[5][15];
struct pai
{
    int shoupai;
    int gongpai;
    pai()
    {
        shoupai = 0;
        gongpai = 0;
    }
};

bool check_THS()
{
    for (int i = 1; i <= 4; i++)
    {
        shoupai[i][1] = shoupai[i][14];
        gongpai[i][1] = gongpai[i][14];
    }
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 1; j <= 10; j++)
        {
            int usesShouPai = 0, useGongPai = 0;
            for (int k = 0; k <= 4; k++)
            {
                if (shoupai[i][j + k])
                {
                    usesShouPai++;
                }
                else if (gongpai[i][j + k])
                {
                    useGongPai++;
                }
                else
                {
                    break;
                }
            }
            if (usesShouPai == 2 and useGongPai == 3)
            {
                return true;
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        shoupai[i][1] = 0;
        gongpai[i][1] = 0;
    }
    return false;
}
bool check_TH()
{
    pai p[5];
    for (int i = 1; i <= 4; i++)
    {
        for (int j = 2; j <= 14; j++)
        {
            if (shoupai[i][j])
            {
                p[i].shoupai += shoupai[i][j];
            }
            if (gongpai[i][j])
            {
                p[i].gongpai += gongpai[i][j];
            }
        }
    }
    for (int i = 1; i <= 4; i++)
    {
        if (p[i].shoupai == 2 and p[i].gongpai >= 3)
        {
            return true;
        }
    }
    return false;
}
bool check_SZ()
{
    pai p[20];
    for (int i = 2; i <= 14; i++)
    {
        for (int j = 1; j <= 4; j++)
        {
            if (shoupai[j][i])
            {
                p[i].shoupai += shoupai[j][i];
            }
            if (gongpai[j][i])
            {
                p[i].gongpai += gongpai[j][i];
            }
        }
    }
    p[1].shoupai = p[14].shoupai;
    p[1].gongpai = p[14].gongpai;
    for (int i = 1; i <= 10; i++)
    {
        int usesShouPai = 0, useGongPai = 0;
        for (int j = 0; j <= 4; j++)
        {
            if (p[i + j].shoupai)
            {
                usesShouPai++;
            }
            else if (p[i + j].gongpai)
            {
                useGongPai++;
            }
            else
            {
                break;
            }
        }
        if (usesShouPai == 2 and useGongPai == 3)
        {
            return true;
        }
    }
    return false;
}

char getc()
{
    char c;
    do
    {
        c = getchar();
    } while ((!(c >= '0' and c <= '9')) and (!(c >= 'A' and c <= 'Z')));
    return c;
}
int main()
{
    freopen("0000in.txt", "r", stdin);
    freopen("0000out.txt", "w", stdout);
    int n;
    scanf("%d", &n);
    Hash['A'] = 14;
    for (int i = 2; i <= 9; i++)
        Hash[i + '0'] = i;
    Hash['1'] = 10;
    Hash['J'] = 11;
    Hash['Q'] = 12;
    Hash['K'] = 13;
    Hash['H'] = 4;
    Hash['S'] = 2;
    Hash['C'] = 3;
    Hash['D'] = 1;
    while (n--)
    {
        memset(shoupai, 0, sizeof(shoupai));
        memset(gongpai, 0, sizeof(gongpai));
        for (int i = 1; i <= 2; i++)
        {
            char Hs, Ds;
            Hs = getc();
            Ds = getc();
            if (Ds == '1')
            {
                getc();
            }
            shoupai[Hash[Hs]][Hash[Ds]]++;
        }
        for (int i = 1; i <= 5; i++)
        {
            char Hs, Ds;
            Hs = getc();
            Ds = getc();
            if (Ds == '1')
            {
                getc();
            }
            gongpai[Hash[Hs]][Hash[Ds]]++;
        }
        if (check_THS())
        {
            printf("THS\n");
        }
        else if (check_TH())
        {
            printf("TH\n");
        }
        else if (check_SZ())
        {
            printf("SZ\n");
        }
        else
        {
            printf("GP\n");
        }
    }
    return 0;
}
//ZnH2