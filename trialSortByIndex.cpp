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
    int mun;
    string name;
} person[N];
int a[N];
bool cmp(int x, int y)
{
    if (person[x].mun == person[y].mun)
    {
        return person[x].name < person[y].name;
    }
    return person[x].mun < person[y].mun;
}
int main()
{
    for (int i = 1; i <= 10; i++)
    {
        person[i].mun = i + person[i - 1].mun;
        person[i].mun *= 10086;
        person[i].mun %= 1000007;
        person[i].name = "name" + to_string(i);
    }
    for (int i = 1; i <= 10; i++)
    {
        a[i] = i;
    }
    sort(a + 1, a + 10 + 1, cmp);
    for (int i = 1; i <= 10; i++)
    {
        cout << person[a[i]].mun << " " << person[a[i]].name << endl;
    }
    return 0;
}