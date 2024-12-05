#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <string.h>
#include <math.h>
 
using namespace std;

int main()
{
    string a;
    cin>>a;
    int n = a.size();
    for(int i=n-1;i>=0;i--){
        printf("%c,",a[i]);
    }
    cout<<n<<endl;
    return 0;
}
