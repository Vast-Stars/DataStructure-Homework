//ɾ�������������������ļ�.cpp
#include<iostream.h>
#include<stdio.h>
#include"��������Ľṹ���Ͷ���.h"
#include"�������Ľ���.h"
#include"�����������.h"
#include"ɾ����������.h"
void main()
{
	bitree*root;
	datatype x;
	root=creattree();
	preorder(root);
	cout<<endl;
	cin>>x;
	root=delsubtree(root,x);
	preorder(root);
	cout<<endl;
}

