#include<cstdio>
#include<iostream>

using namespace std;
int count=0;
void Hanoi(int n,char start,char end,char free){
    if(n==1){
        count++;
        printf("[step %d] move plate %d# from %c to %c\n",count,n,start,end);
        return;
    }
    Hanoi(n-1,start,free,end);
    count++;
    printf("[step %d] move plate %d# from %c to %c\n",count,n,start,end);
    Hanoi(n-1,free,end,start);
}

int main(){
	int n;
	cin>>n;
    Hanoi(n,'a','c','b');
    printf("%d\n",count);
	return 0;
}
