#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;

template <class T>

// void change(T* a,int Old,int New){  传递指针的过程中，无法对指针进行永久修改，只会对指针对应的值进行修改
//     T *temp = new T[New];
//     int len = min(Old,New);
//     for(int i=0;i<len;i++){
//         temp[i] = a[i];
//     }
//     delete [] a;
//     a = temp;
// }

void change(T*& a,int Old,int New){  //传递指针的引用，可以永久修改指针
    T *temp = new T[New];
    int len = min(Old,New);
    for(int i=0;i<len;i++){
        temp[i] = a[i];
    }
    delete [] a;
    a = temp;
}

int main(){
    int *a;
    char *b;
    a = new int[10];
    b = new char[10];
    change(a,10,20);
    change(b,10,20);
    a[15]=9;
    b[15]='a';
    printf("%d %c",a[15],b[15]);
    return 0;
}