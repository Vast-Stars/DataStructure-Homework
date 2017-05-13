//选择法排序主程序文件.cpp
#include<iostream.h>
#include"单链表结构类型定义.h"
#include"建立单链表.h"
#include"输出单链表.h"
#include"选择法排序.h"
void main()
{  linklist *head;
   head=creat();
   print(head);
   selectsort(head);//调用选择法排序的函数
   print(head);
}

