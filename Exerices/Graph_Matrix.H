//单链表结构类型定义.h
#ifndef GRAPH_MATRIX
#define GRAPH_MATRIX
#include <stdio.h>
#include <stdlib.h>
#define MAX_VEX_NUM 50

typedef char VertexType;
typedef enum
{
    DG, UDG
}GraphType;

typedef struct
{
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} MGraph;
 
/**
 * 根据名称得到指定顶点在顶点集合中的下标
 * vex  顶点
 * return 如果找到，则返回下标，否则，返回０
 */
int getIndexOfVexs(char vex, MGraph *MG)
{
    int i;
    for (i = 1; i <= MG->vexnum; i++) {
        if (MG->vexs[i] == vex) {
            return i;
        }
    }
    return 0;
}
 
/**
 * 创建邻接矩阵
 */
void create_MG(MGraph *MG,GraphType type,int vexmun, int arcnum)
{
    int i, j, k;
    int v1, v2;
    char c1, c2;
    if (type == 0)
        MG->type = DG;
    else if (type == 1)
        MG->type = UDG;

    MG->vexnum=vexmun;
    MG->arcnum=arcnum;

    for (i = 1; i <= MG->vexnum; i++) {
        printf("Please input %dth vex(char):", i);
        scanf("%c", &MG->vexs[i]);
        getchar();
    }
    //初始化邻接矩阵
    for (i = 1; i <= MG->vexnum; i++) {
        for (j = 1; j <= MG->vexnum; j++) {
            MG->arcs[i][j] = 0;
        }
    }

    //输入边的信息，建立邻接矩阵
    for (k = 1; k <= MG->arcnum; k++) {
        printf("Please input %dth arc v1(char) v2(char) :" , k);
 
        scanf("%c %c", &c1, &c2);
        v1 = getIndexOfVexs(c1, MG);

        v2 = getIndexOfVexs(c2, MG);
        if (MG->type == UDG)
            MG->arcs[v1][v2] = MG->arcs[v2][v1] = 1;
        else
            MG->arcs[v1][v2] 	= 1;
        getchar();
    }
}
/**
 * 打印邻接矩阵和顶点信息
 */
void print_MG(MGraph MG) {
    int i, j;
    if(MG.type == DG)
        printf("Graph type: Direct graph\n");
    else
        printf("Graph type: Undirect graph\n");
 
    printf("Graph vertex number: %d\n",MG.vexnum);
    printf("Graph arc number: %d\n",MG.arcnum);
    //printf("Vertex set:\n");
    printf("Adjacency Matrix:\n");
    printf("\\   ");
    for (i = 1; i <= MG.vexnum; i++)
        printf("%c   ", MG.vexs[i]);
    printf("\n");
    for (i = 1; i <= MG.vexnum; i++) 
	{
        printf("%c   ", MG.vexs[i]);
        for (j = 1; j <=MG.vexnum; j++)
		{
            printf("%d   ", MG.arcs[i][j]);
        }
        printf("\n");
    }
}
#endif GRAPH_MATRIX