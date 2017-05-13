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
  
//三种递归遍历方法  
  
void VisitTree(BinaryTree *bTree)       //这个是先序遍历，先根，左子树，右子树  
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
  
void VisitTree1(BinaryTree *bTree)      //中序遍历，左子树，根，右子树  
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

void VisitTree2(BinaryTree *bTree)      //后序遍历，左子树，右子树，根  
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
    printf("  先序遍历结果为：\n");  
    VisitTree(bTree);  
    printf("\n");  
	printAnswer();
	
	clearAnswer();
    printf("  中序遍历结果为：\n");  
    VisitTree1(bTree);  
    printf("\n");  
  	printAnswer();
  	
  	clearAnswer();
    printf("  后序序遍历结果为：\n");  
    VisitTree2(bTree);  
    printf("\n");  
  	printAnswer();
    return 0;  
}  
