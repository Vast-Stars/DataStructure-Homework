//ϣ�������������ļ�.cpp
#include<iostream.h>
#include"˳���ṹ���Ͷ���.h"
#include"����˳���.h"
#include"���˳���.h"
#include"ϣ������.h"
void main()
{
    rectype r[N+D1];//D1��Ԫ�ش�ż����ڣ�N��Ԫ�ش�ż�¼
    int d[3]={5,3,1};//����3�˵�����	
	creat(r,N);//������ż�¼��˳���
	print(r,N);//�������ǰ�ļ�¼��
	shellsort(r,d);//ϣ������
	print(r,N);//��������ļ�¼��
}

