#include <iostream>
using namespace std;
int isleapyear(int year)
{
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
int daysinmonth(int year, int month)
{
    switch (month)
    {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
        return 31;
    case 4:
    case 6:
    case 9:
    case 11:
        return 30;
    default:
        if (isleapyear(year) == 0)
        {
            return 28;
        }
        else
        {
            return 29;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    long long year[n], month[n], weekno[n], yearday[n] = {0}, i, j, firstweekno[n], dayinyear[n] = {0}, m;
    for (j = 0; j < n; j++)
    {
        cin >> year[j] >> weekno[j];
        for (i = 1900; i < year[j]; i++)
        {
            if (isleapyear(i) == 0)
            {
                yearday[j] += 365;
            }
            else
            {
                yearday[j] += 366;
            }
        }
        firstweekno[j] = (yearday[j] % 7);
        if (weekno[j] == 1 && firstweekno[j] > 1)
        {
            cout << "-1"<<endl;
        }
        else
        {
            dayinyear[j] += (7 - firstweekno[j]);
            dayinyear[j] += 7 * (weekno[j] - 2) + 2;
            for (m = 1; (dayinyear[j] - daysinmonth(year[j], m)) > 0; m++)
            {
                dayinyear[j] -= daysinmonth(year[j], m);
            }
            if (m < 10)
            {
                cout << year[j] << "0" << m << dayinyear[j] << endl;
            }
            else if (m >= 10 && m <= 12)
            {
                cout << year[j] << m << dayinyear[j] << endl;
            }
            else
            {
                cout << "-1"<<endl;
            }
        }
    }
    return 0;
}