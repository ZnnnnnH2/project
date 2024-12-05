#include<iostream>
#include<stdio.h>
#include<math.h>

using namespace std;   
double f(double x){
    if(abs(x)<=1){
        return abs(x-1)-2;
    }
    return 1/(1+x*x);
}
int main(){
    double x;
    cin>>x;
    printf("%.2lf",f(f(x)));
    return 0;
}