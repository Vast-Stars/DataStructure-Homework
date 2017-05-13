#include<iomanip.h>
#include"数组结构类型的定义.h"
#include"对称矩阵的输入.h"
#include"矩阵的输出.h"
#include"对称矩阵相乘.h"
void main()
{
	array*pa;
	pa=new array;
	input(pa->A);//以行为主序输入矩阵A的下三角
	input(pa->B);//以行为主序输入矩阵B的下三角
	mult(pa);
	output(pa->C);//输出矩阵C
}
