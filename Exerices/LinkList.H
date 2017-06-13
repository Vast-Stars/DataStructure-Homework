//单链表结构类型定义.h
#ifndef LinkList_H
#define LinkList_H
#include <iostream>
#include <malloc.h>
typedef char datatype;
typedef struct node
{
    datatype data;
    struct node *next;
} Node, LinkList;

//建立单链表.h
void Creat(LinkList *head)
//采用尾插法建立具有头结点的单链表
{
    head = (LinkList *) malloc(sizeof(Node));
    head->next = NULL;
    //head->data = NULL;
}

//在第i个位置插入元素。
bool Insert(LinkList *L, int i, datatype e)
{
    int j = 1;
    LinkList *p, *s;
    p = L;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        //j>i只有可能在i<1情况下，也就是用户输入错误。
        return false;
    s = (LinkList *) malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return true;
}

//插入元素到队尾
bool Insert(LinkList *L, datatype e)
{
    LinkList *p, *s;
    p = L;
    while (p)
    {
        p = p->next;
    }
    s = (LinkList *) malloc(sizeof(Node));
    s->data = e;
    s->next = NULL;
    p->next = s;
    return true;
}
//删除第i个元素
bool Delete(LinkList *L, int i, datatype *e)
{
    int j = 1;
    LinkList *p, *s;
    p = L;
    while (p->next && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p->next || j > i)
        return false;
    s = p->next;
    p->next = s->next;
    *e = s->data;
    free(s);
    return true;

}
//输出单链表
void print(LinkList *head)
{
    LinkList *p = head->next;
    while (p != NULL)
    {
        std::cout << p->data << " ";
        p = p->next;
    }
    std::cout << std::endl;
}

//求单链表长度.h
int length(LinkList *head)
{
    LinkList *p = head->next;
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->next;
    }
    return n;
}

//------------------------------循环链表-------------------------------
void print2(LinkList *head)
//输出循环链表
{
    LinkList *p = head->next;
    while (p != head)
    {
        std::cout << p->data;
        p = p->next;
    }
    std::cout << std::endl;
}

//在循环链表中插入.h
void insert(LinkList *h, LinkList *p)
{
    LinkList *q = h;
    while (q->next != h)
        q = q->next;
    q->next = p;
    p->next = h;
}

//------------------------------循环链表-------------------------------


#endif