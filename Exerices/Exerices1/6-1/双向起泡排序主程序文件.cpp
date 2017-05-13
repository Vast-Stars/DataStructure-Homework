//双向起泡排序主程序文件.cpp
#include<iostream.h>
#include<stdlib.h>
#include<time.h>
#include"顺序表结构类型定义.h"
#include"建立顺序表.h"
#include"输出顺序表.h"
#include"双向起泡排序.h"
void main()
{
	const int n=10;
	sequenlist r[n+1];
	creat(r,n);
	print(r,n);
	dbubblesort(r,n);
	print(r,n);
}

