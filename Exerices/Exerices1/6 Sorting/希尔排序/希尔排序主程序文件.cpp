//希尔排序主程序文件.cpp
#include<iostream.h>
#include"顺序表结构类型定义.h"
#include"建立顺序表.h"
#include"输出顺序表.h"
#include"希尔排序.h"
void main()
{
    rectype r[N+D1];//D1个元素存放监视哨，N个元素存放记录
    int d[3]={5,3,1};//设置3趟的增量	
	creat(r,N);//建立存放记录的顺序表
	print(r,N);//输出排序前的记录表
	shellsort(r,d);//希尔排序
	print(r,N);//输出排序后的记录表
}

