#include <iostream>
using namespace std;

void using_scanf (){
    int a;
    int b;
    scanf("%d",&a);
    printf("%d",a);
    scanf("%3d%d",&a,&b);
    printf("%d",a); 
    printf("%d",b);
}

int main()
{
    // int a;
    // cin >> a;
    // cout << a;
    double d;
    char a,c;
    cin >> d >> a>>c;
    cout << d << a<<c;
    // using_scanf();
    return 0;
}