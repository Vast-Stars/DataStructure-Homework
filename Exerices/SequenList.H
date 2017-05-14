//顺序表的结构类型定义
#ifndef SequenList_H
#define SequenList_H

#include <iostream>

typedef char datatype;
const int maxsize = 1024;
typedef struct
{
    datatype data[maxsize];
    int last;
} SequenList;

//建立顺序表.H
void creat(SequenList *&L)
{
    L = new SequenList;
    L->last = 0;
    char ch;
    while ((ch = getchar()) != '*')
    {
        L->data[L->last] = ch;
        L->last++;
    }
}

//输出顺序表.H
void print(SequenList *L)
{
    for (int i = 0; i < L->last; i++)
        cout << L->data[i] << " ";
    cout << endl;
}

//顺序表逆置.H
void invert(SequenList *L)
{

}

#endif