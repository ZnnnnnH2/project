#include <stdio.h>

#include <string.h>

#include <stdlib.h>
///对指针不能进行大小比较！！！
#include<cmath>
#include<iostream>

using namespace std;

struct YellowPage{
    YellowPage *next; 
    YellowPage *pre;
    char name[40];
    int telNum;
    int jiarucixu;
    YellowPage(){
        next = NULL;
        pre = NULL;
    }
    bool operator<(const YellowPage& p){
        // printf("1\n");
        int len=max(strlen(name), strlen(p.name));
        for(int i = 0; i < len; i++){
            if(name[i] < p.name[i]){
                // printf("%c %c",name[i], p.name[i]);
                return true;
            }else if(name[i] > p.name[i]){
                // printf("%c %c",name[i], p.name[i]);
                return false;
            }
        }
        // printf("NO");
        return jiarucixu< p.jiarucixu;
    }
};
YellowPage *s;

YellowPage *create(){
    s = new YellowPage;
    s->next = NULL;
    s->pre = NULL;
    int N;
    scanf("%d", &N);
    scanf("%s %d", s->name, &s->telNum);
    s->jiarucixu = 0;
    for(int i = 1; i < N; i++){
        YellowPage *p = new YellowPage;
        scanf("%s %d", p->name, &p->telNum);
        p->next = NULL;
        p->pre = NULL;
        p->jiarucixu = i;
        YellowPage *q = s;
        // printf("%s %s %s\n",p->name, ((*p)<(*q))?"<":">",q->name);
        if((*p)<(*q)){
            p->next = q;
            q->pre = p;
            s = p;
        }
        else{
            while(q != NULL ){
                if(*q<*p){
                    if(q->next == NULL){
                        q->next = p;
                        p->pre = q;
                        break;
                    }
                    q = q->next;
                    continue;
                }
                else {
                    p->next = q;
                    q->pre->next = p;
                    p->pre = q->pre;
                    q->pre = p;
                    break;
                }
                q = q->next;
            }
        }
        
    }return s;
}
/// @brief 
/// @param head 
void realse(YellowPage *head)

{

    YellowPage *p = head, *pre;

    while (p != NULL)

    {

        pre = p, p = p->next;

        pre->next = NULL;

        free(pre);

    }

}



void display(YellowPage *head)

{

    YellowPage *node = head;

    printf("display data ");

    while (node != NULL)

    {

        printf("%s %d ", node->name, node->telNum);

        node = node->next;

    }

    realse(head);

}

int main()

{

    display(create());

    return 0;

}