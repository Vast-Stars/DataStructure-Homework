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
    /*������һ�����÷�ʽ��Ҳ����˳��ջ�ĳ��Ⱥ�������±���и���s*/  
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
        printf ("�����Ѿ����ı��˵�u��ֵ");  
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
        /*��ջ�ĳ��ȳ�ʼ��Ϊ0*/   
        ret -> top = 0;  
    }  
    return ret;  
}  

//========================8============================================
 
BinaryTree * CreateTree(BinaryTree *bTree)   
{  
    int input;  
    scanf("%d",&input);         //��������������  
    if(input == 0) 
    {  
        bTree = NULL;   //��ΪNULL�����  
        return bTree;     
    }  
    bTree = (BinaryTree *)malloc(sizeof(BinaryTree));  
    bTree ->e = input;  
    bTree->left = CreateTree(bTree->left);  
    bTree->right = CreateTree(bTree->right);  
    return bTree;  
}  

  
void VisitTree(BinaryTree *bTree)       //���������������ȸ�����������������  
{  
    if(bTree != NULL)  
    {  
        printf("%d ",bTree->e);
        VisitTree(bTree->left);  
        VisitTree(bTree->right);  
    }  
}  
//==========================================================================================

void VisitTree2(BinaryTree *bTree)      //���������������������������  
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
		
		Push(STACK,tem); //push��ջ��������Ϣ��һ�ǽ��ָ�룬һ�����ҽ���Ƿ񱻷��ʹ�
		bt = bt->left;
	}
printf("Debug2\n");
	while(!isempty(STACK))
	{ //ֻҪջ�ǿ�
		sn = STACK->data[0];
printf("top: %d ",sn.p->e);
//printf("Debug3\n");
		 // sn��ջ�����
		//�����Һ����Ѿ������ʹ������Ǹ�Ԫ��û���Һ��ӣ����ɺ�������Ķ��壬��ʱ����visit�������ˡ�
		if( (sn.p->right)==NULL || sn.rvisited==1)
		{
printf("Debug4\n");
			p = Pop(STACK)->p;
			//visit(p);
			printf("%d ",p->e);
		}
		else //�������Һ��Ӵ�����rvisitedΪ0��˵����ǰ��û�ж��������Һ��ӣ����Ǿ�ȥ����һ�����Һ��ӡ�
		{ 
printf("Debug5\n");
			//��ʱ����Ҫ�����Һ��ӽ�㿪ʼһֱ�����·��ߣ�ֱ���ߵ���ͷ��������·���ϵ����н�㶼��ջ��

			//��Ȼ����ջ֮ǰҪ�Ƚ��ý���rvisited���1����Ϊ���Һ��ӵ���ջ��ζ�������Һ��ӱؽ�������������(��ܺ���⣬��Ϊ�������Ǵ�ջ��ȡ��Ԫ��������visit)���ɴ˿�֪����һ�θ�Ԫ���ٴ���ջ��ʱ�����Һ��ӱ�Ȼ�ѱ�visit���ˣ����Դ˴����Խ�rvisited����Ϊ1��
			sn.rvisited = 1;
			//��ջ
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

    printf("  ����������Ϊ��\n");  
    VisitTree(bTree);  
    printf("\n");  

    printf("  ������������Ϊ��\n");  
    VisitTree2(bTree);
    printf("\n");  
    
    printf("  �ǵݹ������������Ϊ��\n");  
    lastOrderTraverse(bTree);
    printf("\n");  

    return 0;  
}  
