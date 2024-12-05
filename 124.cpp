#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;
int n,m;
int hight[100][100];
int ans[100][100];
int direction[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
void dfs(int x, int y)
{
    for (int k = 0; k < 4; k++)
    {
        int nx = x + direction[k][0];
        int ny = y + direction[k][1];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m)
        {
            if (hight[nx][ny] > hight[x][y])
            {
                if (ans[nx][ny] < ans[x][y] + 1)
                {
                    ans[nx][ny] = ans[x][y] + 1;
                    dfs(nx, ny);
                }
            }
        }
    }
    return;
}
void print()
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}
int main()
{
    scanf("%d%d", &n,&m);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%d", &hight[i][j]);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (!ans[i][j])
            {
                ans[i][j] = 1;
                dfs(i, j);
                // print();
            }
        }
    }
    int finall = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (ans[i][j] > finall)
            {
                finall = ans[i][j];
            }
            // printf("%d ", ans[i][j]);
        }
        // printf("\n");
    }
    printf("%d\n", finall);
    return 0;
}