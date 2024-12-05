#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

template <class T>

void print(T a){
    cout<<a<<endl;
}

int main(){
    int a;
    cin>>a;
    print(a);
    char b;
    cin>>b;
    print(b);
    return 0;
}