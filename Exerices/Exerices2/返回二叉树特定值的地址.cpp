#include <stdio.h>  
#include <stdlib.h>  
#include <string.h>
typedef int ElemType;  
int i=0;

ElemType Want; 
ElemType* (Answer[100])={NULL};

struct BinaryTree  
{  
    ElemType e;  
    BinaryTree *left;  
    BinaryTree *right;  
};  
               
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
  
//���ֵݹ��������  
  
void VisitTree(BinaryTree *bTree)       //���������������ȸ�����������������  
{  
    if(bTree != NULL)  
    {  
    	
        printf("%d ",bTree->e);

		if (bTree->e == Want)
		{
			Answer[i]=&(bTree->e);
			i++;
		} 
        VisitTree(bTree->left);  
        VisitTree(bTree->right);  
    }  
}  
  
void VisitTree1(BinaryTree *bTree)      //���������������������������  
{  
    if(bTree != NULL)  
    {  
        VisitTree1(bTree->left);  
        printf("%d ",bTree ->e);  
		if (bTree->e == Want)
		{
			Answer[i]=&(bTree->e);
			i++;
		}         
        VisitTree1(bTree ->right);  
    }  
}  

void VisitTree2(BinaryTree *bTree)      //���������������������������  
{  
  
    if(bTree != NULL)  
    {  
        VisitTree2(bTree->left);  
        VisitTree2(bTree->right);  
        printf("%d ",bTree ->e); 
		if (bTree->e == Want)
		{
			Answer[i]=&(bTree->e);
			i++;
		}  
    }  
}  

 

void printAnswer()
{
	int count=0;
	if(Answer[0]==NULL)
	{
		printf("Not Find Target:%d\n",Want);
	}
	else
	{
		while(Answer[count]!=NULL)
		{
			printf("%p ",Answer[count]);
			count++;
		}
		printf("\n");
	}
}

void clearAnswer()
{
	memset(Answer,0,100);
	i=0;
}

int main()  
{  

    BinaryTree *bTree;  
    bTree=CreateTree(bTree);  
    scanf("%d",&Want);
    printf("Search %d ...:",Want);
    clearAnswer();
    printf("  ����������Ϊ��\n");  
    VisitTree(bTree);  
    printf("\n");  
	printAnswer();
	
	clearAnswer();
    printf("  ����������Ϊ��\n");  
    VisitTree1(bTree);  
    printf("\n");  
  	printAnswer();
  	
  	clearAnswer();
    printf("  ������������Ϊ��\n");  
    VisitTree2(bTree);  
    printf("\n");  
  	printAnswer();
    return 0;  
}  
