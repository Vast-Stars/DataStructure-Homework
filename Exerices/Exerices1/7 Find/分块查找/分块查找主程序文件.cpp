//�ֿ�����������ļ�.cpp
#include<iostream.h>
#include"���Ͷ���.h"
#include"�ֿ����.h"
void main()
{
	record r[recN]={22,12,13,8,9,20,33,42,44,38,24,48,60,58,74,49,86,53};
	index idx[idxN]={{22,0,5},{48,6,11},{86,12,17}};
	keytype key;
	int loc;
	cout<<"������Ҫ���Ҽ�¼�Ĺؼ��֣�";
	cin>>key;
	loc=blksearch(r,idx,key,idxN);
	if(loc!=-1) cout<<"���ҵ����ǵ�"<<loc+1<<"����¼��"<<endl;
	else cout<<"��¼���Ҳ�����"<<endl;
}

