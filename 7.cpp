#include<cstdio>
#include<iostream>
#include<cmath>

using namespace std;

int main(){
	double a,b,c;
	scanf("%lf %lf %lf",&a,&b,&c);
	double p=(a+b+c)/2;
//	printf("%.2lf",p);
	double s=sqrt(p*(p-a)*(p-b)*(p-c));
	printf("%.2lf",s);
	return 0;
}

