#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>


using namespace std;

struct Student{
    int age=0;
    string name;
    float gpa=0.0;
};

// int main(){
//     Student s1;
//     s1.age=20;
//     Student *p;
//     p=&s1;
//     printf("%d\n",p->age);
//     p->age=23;
//     printf("%d\n",s1.age);
// }

int main(){
    Student s[10];
    for(int i=0;i<10;i++){
        s[i].age=i;
        s[i].name="Student "+to_string(i);
        s[i].gpa=i*1.0;
    }
    Student *p;
    p=s;
    for(int i=0;i<10;i++){
        printf("%d %s %.2f\n",p->age,p->name.c_str(),p->gpa);
        p++;
    }
}