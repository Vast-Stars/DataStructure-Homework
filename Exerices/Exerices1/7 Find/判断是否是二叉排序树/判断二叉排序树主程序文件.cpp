//�ж϶����������������ļ�.cpp
#include<iostream.h>
#include<stdlib.h>
#include"��������Ľṹ���Ͷ���.h"
#include"�������Ľ���.h"
#include"�����������.h"
#include"�ж϶���������.h"
void main()
{
	bitree*pb;
	pb=creattree();
	preorder(pb);
	cout<<endl;
	inorder(pb);cout<<"�Ƕ�����������"<<endl;
}

