//�ֽⵥ�����������ļ�.cpp
#include<iostream.h>
#include<stdio.h>
#include"������ṹ���Ͷ���.h"
#include"����������.h"
#include"���������.h"
#include"���ѭ������.h"
#include"��ѭ�������в���.h"
#include"�ֽⵥ����.h"
void main()
{  linklist *head,*letter,*digit,*other;
   creat(head);
   print1(head);
   letter=new linklist;
   letter->next=letter;
   digit=new linklist;
   digit->next=digit;
   other=new linklist;
   other->next=other;
   resolve(head,letter,digit,other);//���÷ֽⵥ����ĺ���
   print2(letter);
   print2(digit);
   print2(other);
}

