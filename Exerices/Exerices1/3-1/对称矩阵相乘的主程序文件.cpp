#include<iomanip.h>
#include"����ṹ���͵Ķ���.h"
#include"�Գƾ��������.h"
#include"��������.h"
#include"�Գƾ������.h"
void main()
{
	array*pa;
	pa=new array;
	input(pa->A);//����Ϊ�����������A��������
	input(pa->B);//����Ϊ�����������B��������
	mult(pa);
	output(pa->C);//�������C
}
