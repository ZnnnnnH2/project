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
const int N = 1e4 + 5;
struct baby
{
    int id, month, day;
    bool sex;
} b[N];
struct node
{
    int mun;
    int mun_male;
    int from_month, from_day, to_month, to_day, from_totday, to_totday;
    int id;
    node()
    {
        mun = 0;
        mun_male = 0;
        from_month = 0;
        from_day = 0;
        to_month = 0;
        to_day = 0;
        from_totday = 0;
        to_totday = 0;
        id = 0;
    }
    bool operator<(const node &a) const
    {
        if (mun == a.mun)
        {
            return from_totday < a.from_totday;
        }
        return mun > a.mun;
    }
} week[80];
int Month[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int getday(int year)
{
    if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
    {
        return 366;
    }
    return 365;
}
void getdate(int &month, int &day, int mun)
{
    month = 1;
    while (mun > Month[month])
    {
        mun -= Month[month];
        month++;
    }
    day = mun;
    return;
}
void print(node a)
{
    int from_month, from_day, to_month, to_day;
    getdate(from_month, from_day, a.from_totday);
    getdate(to_month, to_day, a.to_totday);
    printf("[%2d.%2d-%2d.%2d]:%d(B%d)\n", from_month, from_day, to_month, to_day, a.mun, a.mun_male);
    return;
}
int tot = 0;
int getweek(int day)
{
    for (int i = 1; i <= tot; i++)
    {
        if (day >= week[i].from_totday && day <= week[i].to_totday)
        {
            return i;
        }
    }
    printf("NOOOO!");
    return tot;
}
int main()
{
    int year;
    int n, m;
    cin >> year >> n >> m;
    if(year%400==0||(year%4==0&&year%100!=0)){
        Month[2]=29;
    }
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i].id >> b[i].month >> b[i].day >> b[i].sex;
    }
    int xingqi = 3;
    for (int i = 1969; i < year; i++)
    {
        xingqi += getday(i);
        xingqi %= 7;
    }
    // cout << xingqi << endl;
    int totday = getday(year);
    tot++;
    week[tot].from_totday = 1;
    week[tot].to_totday = 7 - ((xingqi == 7) ? 0 : xingqi);
    for (int i = week[tot].to_totday + 1; i <= totday; i += 7)
    {
        tot++;
        week[tot].from_totday = i;
        week[tot].to_totday = i + 6;
    }
    week[tot].to_totday = totday;
    for (int i = 1; i <= n; i++)
    {
        int day = 0;
        for (int j = 1; j < b[i].month; j++)
        {
            day += Month[j];
        }
        day += b[i].day;
        int k = getweek(day);
        week[k].mun++;
        if (b[i].sex == 1)
        {
            week[k].mun_male++;
        }
    }
    sort(week + 1, week + tot + 1);
    for (int i = 1; i <= m; i++)
    {
        print(week[i]);
    }
    // while (week[m + 1].mun == week[m].mun and m <= tot)
    // {
    //     m++;
    //     print(week[m]);
    // }
    return 0;
}