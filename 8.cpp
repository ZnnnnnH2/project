#include<iostream>

using namespace std;

int main(){
    int n;
    cin>>n;
    if(n>=90) cout<<"4.0";
    else if(n>=86) cout<<"3.7";
    else if(n>=83) cout<<"3.3";
    else if(n>=80) cout<<"3.0";
    else if(n>=76) cout<<"2.7";
    else if(n>=73) cout<<"2.3";
    else if(n>=70) cout<<"2.0";
    else if(n>=66) cout<<"1.7";
    else if(n>=63) cout<<"1.3";
    else if(n>=60) cout<<"1.0";
    else cout<<"0";
    return 0;
}