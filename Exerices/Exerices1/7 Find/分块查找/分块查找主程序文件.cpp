//分块查找主程序文件.cpp
#include<iostream.h>
#include"类型定义.h"
#include"分块查找.h"
void main()
{
	record r[recN]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
	index idx[idxN]={{22,0,5},{48,6,11},{86,12,17}};
	keytype key;
	int loc;
	cout<<"输入所要查找记录的关键字：";
	cin>>key;
	loc=blksearch(r,idx,key,idxN);
	if(loc!=-1) cout<<"查找到，是第"<<loc+1<<"个记录。"<<endl;
	else cout<<"记录查找不到！"<<endl;
}

