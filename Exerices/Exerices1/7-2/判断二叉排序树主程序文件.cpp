//判断二叉排序树主程序文件.cpp
#include<iostream.h>
#include<stdlib.h>
#include"二叉链表的结构类型定义.h"
#include"二叉树的建立.h"
#include"二叉树的输出.h"
#include"判断二叉排序树.h"
void main()
{
	bitree*pb;
	pb=creattree();
	preorder(pb);
	cout<<endl;
	inorder(pb);cout<<"是二叉排序树！"<<endl;
}

