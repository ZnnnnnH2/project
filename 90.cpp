#include <iostream>
#include <stdio.h>
using namespace std;
struct student
{
    int sno; // 学号
    int p;
    bool bianhao[1000] = {0};
    int zongshu = 0; // 总成绩
    bool operator>(const student &a) const
    {
        if (zongshu == a.zongshu)
        {
            return sno < a.sno;
        }
        else
        {
            return zongshu > a.zongshu;
        }
    }
} st[101]; // 定义一个结构体数组，用来存储学生信息
int n;
int m, k;
bool tihao[1000] = {0}; // 存储题号
int tihaomax = 1;       // 存储题号的最大值
void duibi(int i)
{
    int k = 0; // 用来记录学生i的得分
    for (int j = 0; j <= tihaomax; j++)
    {
        if (tihao[j] == true and st[i].bianhao[j] == true)
        {
            k++;
        }
    }
    st[i].zongshu = k;
}
void paixu()
{
    for (int i = 1; i <= m; i++)
    {
        for (int j = i + 1; j <= m; j++)
        {
            if (!(st[i] > st[j]))
            {
                student temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 0; i <= 1000; i++)
    {
        tihao[i] = 0;
    }
    for (int i = 1; i <= n; i++)
    {
        int bian;
        cin >> bian;
        if (bian > tihaomax)
        {
            tihaomax = bian;
        }
        tihao[bian] = 1;
    }
    cin >> m >> k;
    for (int i = 0; i <= m; i++)
    {
        for (int j = 1; j <= tihaomax; j++)
        {
            st[i].bianhao[j] = 0;
        }
    }
    for (int i = 1; i <= m; i++)
    {
        cin >> st[i].sno >> st[i].p;
        for (int j = 1; j <= st[i].p; j++)
        {
            int bian;
            cin >> bian;
            st[i].bianhao[bian] = 1;
        }
        duibi(i);
    }
    paixu();
    // for(int j=1;j<=m;j++){
    //     cout<<st[j].zongshu<<endl;
    //     for(int k=1;k<=tihaomax;k++){
    //         if(st[j].bianhao[k]==1){
    //             cout<<k<<" ";
    //         }
    //     }
    //     cout<<endl;
    // }
    int shuchule = 1;
    int now = st[1].zongshu;
    for (int i = 1; i <= m; i++)
    {
        if (now != st[i].zongshu)
        {
            now = st[i].zongshu;
            shuchule++;
        }
        if (shuchule > k)
        {
            // cout<<st[i].sno<<endl;
            return 0;
        }
        printf("%d ", st[i].sno);
    }
    return 0;
}