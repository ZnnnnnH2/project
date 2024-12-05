#include <stdio.h>
#include <stdlib.h>

int power( int x, int y)
{
    long long int answer = 1;
    while(y>0){
        answer *= x;
        y--;
    }
    return answer;
}

int main()
{
    int x, y;
    scanf("%d%d", &x, &y);
    printf("%d", power(x, y));
    return 0;

}