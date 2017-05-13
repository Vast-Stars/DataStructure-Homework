#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
typedef int ElemType;  
int i=0;

struct BinaryTree  
{  
    ElemType e;  
    BinaryTree *left;  
    BinaryTree *right;  
};  

typedef struct{
	BinaryTree* p;
    int rvisited;
}SNode;

typedef struct{
  SNode data[100];  
  int top;
  //int cnt=0;
}Sqstack;


Sqstack* STACK;


bool isempty(Sqstack *s)
{
  if (s->top == NULL)
    return true;
  else
    return false;
}

int Push(Sqstack *stack, SNode data)  
{  
    /*这里有一个复用方式，也就是顺序栈的长度和数组的下标进行复用s*/  
    stack -> data[stack -> top] = data;  
    stack -> top++;  
    return 1;  
}  

SNode* Pop (Sqstack *stack)  
{  
	SNode* tem;
    if (stack -> top == 0)  
    {  
        printf ("the stack is empty\n");  
        printf ("弹出已经被改变了的u的值");  
    }  
    else  
    {     
        stack -> top--;  
        tem = &(stack -> data[stack -> top]);  
    }  
    return tem;     
} 

Sqstack* InitStack ()  
{  
    Sqstack *ret = NULL;  
    ret = (Sqstack*)malloc (sizeof(Sqstack));  
    if (ret)  
    {  
        /*将栈的长度初始化为0*/   
        ret -> top = 0;  
    }  
    return ret;  
}  

//========================8============================================
 
BinaryTree * CreateTree(BinaryTree *bTree)   
{  
    int input;  
    scanf("%d",&input);         //按先序建立二叉树  
    if(input == 0) 
    {  
        bTree = NULL;   //置为NULL后结束  
        return bTree;     
    }  
    bTree = (BinaryTree *)malloc(sizeof(BinaryTree));  
    bTree ->e = input;  
    bTree->left = CreateTree(bTree->left);  
    bTree->right = CreateTree(bTree->right);  
    return bTree;  
}  

  
void VisitTree(BinaryTree *bTree)       //这个是先序遍历，先根，左子树，右子树  
{  
    if(bTree != NULL)  
    {  
        printf("%d ",bTree->e);
        VisitTree(bTree->left);  
        VisitTree(bTree->right);  
    }  
}  
//==========================================================================================

void VisitTree2(BinaryTree *bTree)      //后序遍历，左子树，右子树，根  
{  
  
    if(bTree != NULL)  
    {  
        VisitTree2(bTree->left);  
        VisitTree2(bTree->right);  
        printf("%d ",bTree ->e); 
    }  
}  

void lastOrderTraverse(BinaryTree *bt)
{
    BinaryTree *p = bt;
    SNode tem;
    SNode sn; 

	while(bt)
	{
printf("debug1 leftdown: %d ",bt->e);
		tem.rvisited=0,tem.p=bt;
		
		Push(STACK,tem); //push到栈中两个信息，一是结点指针，一是其右结点是否被访问过
		bt = bt->left;
	}
printf("Debug2\n");
	while(!isempty(STACK))
	{ //只要栈非空
		sn = STACK->data[0];
printf("top: %d ",sn.p->e);
//printf("Debug3\n");
		 // sn是栈顶结点
		//若其右孩子已经被访问过，或是该元素没有右孩子，则由后序遍历的定义，此时可以visit这个结点了。
		if( (sn.p->right)==NULL || sn.rvisited==1)
		{
printf("Debug4\n");
			p = Pop(STACK)->p;
			//visit(p);
			printf("%d ",p->e);
		}
		else //若它的右孩子存在且rvisited为0，说明以前还没有动过它的右孩子，于是就去处理一下其右孩子。
		{ 
printf("Debug5\n");
			//此时我们要从其右孩子结点开始一直往左下方走，直至走到尽头，将这条路径上的所有结点都入栈。

			//当然，入栈之前要先将该结点的rvisited设成1，因为其右孩子的入栈意味着它的右孩子必将先于它被访问(这很好理解，因为我们总是从栈顶取出元素来进行visit)。由此可知，下一次该元素再处于栈顶时，其右孩子必然已被visit过了，所以此处可以将rvisited设置为1。
			sn.rvisited = 1;
			//入栈
			p = sn.p->right;
			while(p != NULL){
				tem.p=p;
				tem.rvisited=0;
				Push(STACK,tem);
				p = p->left;
			}
		}
	}
}

int main()  
{  

    STACK=InitStack();
    BinaryTree *bTree;  
    bTree=CreateTree(bTree);  

    printf("  先序遍历结果为：\n");  
    VisitTree(bTree);  
    printf("\n");  

    printf("  后序序遍历结果为：\n");  
    VisitTree2(bTree);
    printf("\n");  
    
    printf("  非递归后序序遍历结果为：\n");  
    lastOrderTraverse(bTree);
    printf("\n");  

    return 0;  
}  
