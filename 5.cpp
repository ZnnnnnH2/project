#include<cstdio>
#include<iostream>

using namespace std;

int main(){
	char a;
	scanf("%c",&a);
	if('a'<=a and a<='z'){
		printf("%c",a-32);
	}
	else{
		printf("%c",a+32);
	}
	return 0;
}

