#include<iostream>

using namespace std;

int main(){
    long long int a,b;
    char c;
    cin>>a>>b>>c;
    switch(c){
        case '+':
            cout<<a+b<<endl;
            break;
        case '-':
            cout<<a-b<<endl;
            break;
        case '*':
            cout<<a*b<<endl;
            break;
        case '/':
            if(b==0) goto end;
            cout<<a/b<<endl;
            break;
        case '%':
            if(b==0) goto end;
            cout<<a%b<<endl;
            break;
        default:
            end:;
            cout<<"NO"<<endl;
    }
    return 0;
}