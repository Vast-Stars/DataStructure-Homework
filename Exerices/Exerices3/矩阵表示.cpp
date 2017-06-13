#include <stdio.h>
#include <stdlib.h>
#define MAX_VEX_NUM 50
typedef char VertexType;
typedef enum {
    DG, UDG
} GraphType;
typedef struct {
    VertexType vexs[MAX_VEX_NUM];
    int arcs[MAX_VEX_NUM][MAX_VEX_NUM];
    int vexnum, arcnum;
    GraphType type;
} MGraph;
 
/**
 * �������Ƶõ�ָ�������ڶ��㼯���е��±�
 * vex  ����
 * return ����ҵ����򷵻��±꣬���򣬷��أ�
 */
int getIndexOfVexs(char vex, MGraph *MG) {
    int i;
    for (i = 1; i <= MG->vexnum; i++) {
        if (MG->vexs[i] == vex) {
            return i;
        }
    }
    return 0;
}
 
/**
 * �����ڽӾ���
 */
void create_MG(MGraph *MG) {
    int i, j, k;
    int v1, v2, type;
    char c1, c2;
//    printf(Please input graph type DG(0) or UDG(1) :);
//    scanf(%d, &type);
    type = 0; 
    if (type == 0)
        MG->type = DG;
    else if (type == 1)
        MG->type = UDG;
    printf("Please input vexmun : \n");
    scanf("%d", &MG->vexnum);
    printf("Please input arcnum :\n" );
    scanf("%d", &MG->arcnum);
    getchar();
    for (i = 1; i <= MG->vexnum; i++) {
        printf("Please input %dth vex(char):", i);
        scanf("%c", &MG->vexs[i]);
        getchar();
    }
 
    //��ʼ���ڽӾ���
    for (i = 1; i <= MG->vexnum; i++) {
        for (j = 1; j <= MG->vexnum; j++) {
            MG->arcs[i][j] = 0;
        }
    }
  
    //����ߵ���Ϣ�������ڽӾ���
    for (k = 1; k <= MG->arcnum; k++) {
        printf("Please input %dth arc v1(char) v2(char) :" , k);
 
        scanf("%c %c", &c1, &c2);
        v1 = getIndexOfVexs(c1, MG);

        v2 = getIndexOfVexs(c2, MG);
        printf("debug:v1 v2: %d %d\n",v1,v2);
        if (MG->type == 1)
            MG->arcs[v1][v2] = MG->arcs[v2][v1] = 1;
        else
            MG->arcs[v1][v2] 	= 1;
        getchar();
    }
}
/**
 * ��ӡ�ڽӾ���Ͷ�����Ϣ
 */
void print_MG(MGraph MG) {
    int i, j;
    if(MG.type == DG){
        printf("Graph type: Direct graph\n");
    }
    else
	{
        printf("Graph type: Undirect graph\n");
    }
 
    printf("Graph vertex number: %d",MG.vexnum);
    printf("Graph arc number: %d",MG.arcnum);
 
    printf("Vertex set:\n");
    for (i = 1; i <= MG.vexnum; i++)
        printf("%c   ", MG.vexs[i]);
    printf("\n");
    printf("Adjacency Matrix:\n");
 

    for (i = 1; i <= MG.vexnum; i++) 
	{

        for (j = 1; j < MG.vexnum; j++) 
		{
            printf("%d   ", MG.arcs[i][j]);
        }
        printf("%d\n", MG.arcs[i][j]);
    }
}
 
/**
 * ������
 */
int main(void) 
{
    MGraph MG;
    create_MG(&MG);
    print_MG(MG);
    
	int count,i,j;
	 	printf("Input Degree :\n");
    for (i = 1; i <= MG.vexnum; i++) 
	{
		count=0;
        for (j = 1; j < MG.vexnum; j++) 
		{
            count+= MG.arcs[j][i];
        }
        count+= MG.arcs[j][i];
        printf("%d  ", count);
    }
    
    return EXIT_SUCCESS;
}
