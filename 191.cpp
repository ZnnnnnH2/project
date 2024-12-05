#include<iostream>
#include<cmath>
#include<cstring>
#include<cstdio>
#include<algorithm>

using namespace std;
struct student{
    int id;
    int score;
    student(){
        id=0;
        score=0;
    }
    bool operator <(const student &a)const{
        if(score==a.score){
            return id<a.id;
        }
        return score>a.score;
    }
};
int main(){
    int N,M;
    cin>>N>>M;
    int score[20];
    struct student a[20];
    for(int i=1;i<=M;i++){
        cin>>score[i];
    }
    for(int i=1;i<=N;i++){
        cin>>a[i].id;
        for(int j=1;j<=M;j++){
            int t;
            cin>>t;
            if(t>=60){
                a[i].score+=score[j];
            }
        }
    }
    sort(a+1,a+N+1);
    for(int i=1;i<=N;i++){
        cout<<a[i].id<<" "<<a[i].score<<endl;
    }
    return 0;
}