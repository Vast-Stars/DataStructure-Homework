//单链表结构类型定义.h
#ifndef LinkList_H
#define LinkList_H

#include <iostream>

typedef char datatype;
typedef struct node {
    datatype data;
    struct node *next;
} LinkList;


//建立单链表.h
void creat(LinkList *&head)
//采用尾插法建立具有头结点的单链表
//字符串输入，以*结尾
{
    char ch;
    LinkList *s, *r;
    head = new LinkList;
    r = head;
    while ((ch = getchar()) != '*') {
        s = new LinkList;
        s->data = ch;
        r->next = s;
        r = s;
    }
    r->next = NULL;
}

//输出单链表
void print(LinkList *head) {
    LinkList *p = head->next;
    while (p != NULL) {
        std::cout << p->data << " ";
        p = p->next;
    }
    cout << endl;
}


//单链表逆置.h


//------------------------------循环链表-------------------------------
void print2(linklist*head)
//输出循环链表
{  linklist *p=head->next;
    while(p!=head)
    {  cout<<p->data;
        p=p->next;
    }
    cout<<endl;
}

//在循环链表中插入.h
void insert(linklist*h,linklist*p)
{  linklist *q=h;
    while(q->next!=h) q=q->next;
    q->next=p;
    p->next=h;
}

//------------------------------循环链表-------------------------------


#endif