#include <iostream>
#include <stdio.h>

using namespace std;

int m, n;

void print(int arr[101][101][3])
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("R %d G %d B %d ", arr[i][j][0], arr[i][j][1], arr[i][j][2]);
        }
        printf("\n");
    }
    printf("\n");
}

int arrold[101][101][3];
int arrnew[101][101][3];
int direct[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void fugai()
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < 3; k++)
            {
                arrold[i][j][k] = arrnew[i][j][k];
            }
        }
    }
}

bool check(int arr[3])
{
    // int tot=0;
    for (int i = 0; i < 3; i++)
    {
        if (arr[i] != 0)
            return true;
    }
    return false;
}

int main()
{
    scanf("%d %d", &m, &n);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf(" R %d G %d B %d", &arrnew[i][j][0], &arrnew[i][j][1], &arrnew[i][j][2]);
        }
    }
    fugai();
    // print(arrold);

    int count = 1;
    while (count)
    {
        count = 0;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                int tot = 0;
                if (!check(arrold[i][j]))
                {
                    // printf("Hello %d %d \n",i,j);
                    for (int k = 0; k < 4; k++)
                    {
                        int x = i + direct[k][0];
                        int y = j + direct[k][1];
                        if ((x >= 0 && x < m && y >= 0 && y < n) and (check(arrold[x][y])))
                        {
                            arrnew[i][j][0] += arrold[x][y][0];
                            arrnew[i][j][1] += arrold[x][y][1];
                            arrnew[i][j][2] += arrold[x][y][2];
                            tot++;
                            count++;
                        }
                    }
                    if (tot != 0)
                    {
                        arrnew[i][j][0] = (arrnew[i][j][0] + tot - 1) / tot;
                        arrnew[i][j][1] = (arrnew[i][j][1] + tot - 1) / tot;
                        arrnew[i][j][2] = (arrnew[i][j][2] + tot - 1) / tot;
                    }
                }
            }
        }
        // print(arrnew);
        fugai();
        // print(arrold);
    }
    fugai();
    // print(arrnew);
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("R %d G %d B %d ", arrnew[i][j][0], arrnew[i][j][1], arrnew[i][j][2]);
        }
        printf("\n");
    }
    return 0;
}