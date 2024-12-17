#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <iostream>

using namespace std;
#define LINE_BUF_SIZE 2048

typedef struct

{

    char isbn[11]; // 10 digits isbn

    char name[LINE_BUF_SIZE];

    char author[LINE_BUF_SIZE];

    char publisher[LINE_BUF_SIZE];

    int year;

} book_record_t;
typedef struct
{

    // 指向一个存放所有图书数据的数组。

    // 特别注意：函数调用时，本数组并未分配空间，需要你根据读入的数据合理地动态分配空间

    book_record_t *data;

    int size; // 图书库中记录的条数（即数组元素的个数)

} book_manager_t;
int book_manager_load(book_manager_t *mgr, char *file_name);
int main()
{
    book_manager_t a;
    book_manager_load(&a, "in.txt");
    for (int i = 0; i < a.size; i++)
    {
        printf("%s\n%s\n%s\n%s\n%d\n\n", a.data[i].isbn, a.data[i].name, a.data[i].author, a.data[i].publisher, a.data[i].year);
    }
    return 0;
}

int book_manager_load(book_manager_t *mgr, char *file_name)
{
    FILE *fr = fopen(file_name, "r");
    if (fr == NULL)
    {
        return -1;
    }
    fscanf(fr, "%d", &mgr->size);
    mgr->data = new book_record_t[mgr->size];
    char c;
    for (int i = 0; i < mgr->size; i++)
    {
        c = fgetc(fr);
        c = fgetc(fr);
        fscanf(fr, "%[^\n]", (mgr->data)[i].isbn);
        c = fgetc(fr);
        fscanf(fr, "%[^\n]", (mgr->data)[i].name);
        c = fgetc(fr);
        fscanf(fr, "%[^\n]", (mgr->data)[i].author);
        c = fgetc(fr);
        fscanf(fr, "%[^\n]", (mgr->data)[i].publisher);
        c = fgetc(fr);
        fscanf(fr, "%d", &(mgr->data)[i].year);
        // c = fgetc(fr);
    }
    fclose(fr);
    return 0;
}
