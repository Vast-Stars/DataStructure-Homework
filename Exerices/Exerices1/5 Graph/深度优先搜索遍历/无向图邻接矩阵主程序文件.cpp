//无向图邻接矩阵主程序文件.cpp
#include<iostream.h>
#include<stdio.h>
#include"图的邻接矩阵类型定义.h"
#include"建立无向图邻接矩阵.h"
#include"深度优先搜索遍历.h"
void main()
{
	creatgraph();
	int i;
	while(1)
	{
		for(i=0;i<n;i++)
			visited[i]=0;
		cout<<"输入出发点序号（0-7），输入-1结束：";
		cin>>i;
		if(i==-1) break;
	    dfsa(i);
	}
}

