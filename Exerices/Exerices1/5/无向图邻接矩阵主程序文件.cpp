//����ͼ�ڽӾ����������ļ�.cpp
#include<iostream.h>
#include<stdio.h>
#include"ͼ���ڽӾ������Ͷ���.h"
#include"��������ͼ�ڽӾ���.h"
#include"���������������.h"
void main()
{
	creatgraph();
	int i;
	while(1)
	{
		for(i=0;i<n;i++)
			visited[i]=0;
		cout<<"�����������ţ�0-7��������-1������";
		cin>>i;
		if(i==-1) break;
	    dfsa(i);
	}
}

