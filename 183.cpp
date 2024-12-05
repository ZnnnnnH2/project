#include <stdio.h>
#include <math.h>
#include <iostream>
using namespace std;

#define EPS 1e-8
#define K 1
int main()
{
    freopen("in.txt", "r", stdin);
    freopen("o23ut.txt", "w", stdout);
    double a, b, c, d, j;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for (double i = -100; i <= 100; i += K)
    {
        if (i == 1 or i == 2)
        {
            printf("%.0lf %.40lf i=%.40lf i-1=%.40lf\n", i,(a * i * i * i + b * i * i + c * i + d) * (a * pow(i - K, 3) + b * pow(i - K, 2) + c * (i - K) + d),(a * i * i * i + b * i * i + c * i + d),(a * pow(i - K, 3) + b * pow(i - K, 2) + c * (i - K) + d));
        }
        if ((a * i * i * i + b * i * i + c * i + d) * (a * pow(i - K, 3) + b * pow(i - K, 2) + c * (i - K) + d) <= 0)
        {

            for (j = (i - 1) * 1.00; j <= i * 1.00; j += 0.01)
            {
                // cout<<j<<endl;
                // printf("%.10lf   %.40lf \n",i,j);
                if (abs(a * pow(j, 3) + b * pow(j, 2) + c * j + d) <= EPS)
                {
                    // printf("%.2lf ", j);
                }
            }
        }
        // printf(" ");
    }
    return 0;
}
