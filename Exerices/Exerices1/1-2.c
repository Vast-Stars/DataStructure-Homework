//�ֽⵥ�����������ļ�.cpp
#include<iostream.h>
#include<stdio.h>

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

void resolve(linklist*head,linklist*letter,linklist*digit,linklist*other)
//����ĸ�����֡������ַ��ֽⵥ����
{
}