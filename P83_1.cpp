#include <stdio.h>
#include <math.h>
#define EPS 1e-9
int main()
{
    double a, b, c, d, j;
    scanf("%lf %lf %lf %lf", &a, &b, &c, &d);
    for (double i = -100; i <= 100; i+=0.1)
    {
        if ((a * i * i * i + b * i * i + c * i + d) * (a * pow(i - 0.1, 3) + b * pow(i - 0.1, 2) + c * (i - 0.1) + d) <= 0)
        {
            for (j = (i - 1) * 1.00; j <= i * 1.00; j += 0.01)
            {
                if (abs(a * pow(j, 3) + b * pow(j, 2) + c * j + d) <= EPS)
                {
                    printf("%.2lf ", j);
                }
            }
        }
    }
    return 0;
}
