//���������������������ļ�.cpp
#include<iostream.h>
#include<stdio.h>
#include"��������Ľṹ���Ͷ���.h"
#include"�������Ľ���.h"
#include"�����������.h"
#include"������������.h"
void main()
{
	bitree*pb;
	pb=creattree();
	preorder(pb);
	cout<<endl;
	swap(pb);
	preorder(pb);
	cout<<endl;
}

