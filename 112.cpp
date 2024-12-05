#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#define ll long long

using namespace std;

int main() {
    
    return 0;
}#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

int bisearch( int ary[], int left, int right, int num )

{

    printf("search %d from %d to %d", num, left, right );
    cout << endl;
    if( left > right )
    {
        return -1;
    }
    if( left == right )
    {
        if( ary[left] == num )
        {
            return left;
        }
        else
        {
            return -1;
        }
    }
    int mid = (left + right) / 2;
    if( ary[mid] == num )
    {
        return mid;
    }
    else if( ary[mid] > num )
    {
        return bisearch( ary, left, mid-1, num );
    }
    else
    {
        return bisearch( ary, mid+1, right, num );
    }
}

int main()
{
    int n, array[10000], i, num;
    scanf("%d", &n);
    scanf("%d", &num);
    for (i = 0; i < n; i ++ )
    {
        scanf("%d", &array[i]);
    }

    printf( "%d", bisearch(array, 0, n-1, num));
    cout << endl;
    return 0;
}    

