#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100
#define INF 0xFFFFFFF
#define RST(N)memset(N, 0, sizeof(N))
using namespace std;

struct ArcNode     //边节点；
{
    int adjvex;    //有向边的另一个邻接点的序号；
    ArcNode *nextarc;  //指向下一个边节点的指针；
};

struct VNode       //顶点；
{
    int data;      //顶点信息；
    ArcNode *head1;  //出边表的表头指针；
    ArcNode *head2;  //入边表的表头指针；
};

struct LGraph      //图的邻接表存储结构；
{
    VNode vertexs[MAXN];   //顶点数组；
    int vexnum, arcnum;    //顶点数，边(弧)数；
};

LGraph lg;  //图(邻接表存储结构)

void CreateLG()     //构造有向图G；
{
    ArcNode *pi;
    int v1, v2;
    for(int i=0; i<lg.vexnum; i++) 
	{  //初始化表头指针为空；
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    }
    for(int i=0; i<lg.arcnum; i++) 
	{
        scanf("%d %d", &v1, &v2);
        v1--, v2--;
        pi = new ArcNode;     //添加出边；
        pi->adjvex = v2;
        pi->nextarc = lg.vertexs[v1].head1;
        lg.vertexs[v1].head1 = pi;
        pi = new ArcNode;     //添加入边；
        pi->adjvex = v1;
        pi->nextarc = lg.vertexs[v2].head2;
        lg.vertexs[v2].head2 = pi;
    }
}

//释放内存空间；
void Delete()
{
    ArcNode *pi;
    for(int i=0; i<lg.vexnum; i++) {
        pi = lg.vertexs[i].head1;
        while(pi != NULL) {
            lg.vertexs[i].head1 = pi->nextarc;
            delete pi;
            pi = lg.vertexs[i].head1;
        }
        pi = lg.vertexs[i].head2;
        while(pi != NULL) {
            lg.vertexs[i].head2 = pi->nextarc;
            delete pi;
            pi = lg.vertexs[i].head2;
        }
    }
}

int main(int argc, char *argv[])
{
    ArcNode *pi;
    int in_num, out_num;
    printf("****************************************\n请输入图的节点数和边数：\n"); 
    while(~scanf("%d %d", &lg.vexnum, &lg.arcnum)) 
	{
        if(lg.vexnum == 0) break;
        CreateLG();

        /****输出每条边的出度****/
        printf("输出所有出度：\n");
        for(int i=0; i<lg.vexnum; i++) {
            out_num = 0;
            pi = lg.vertexs[i].head1;
            while(pi != NULL) 
			{
                out_num++;
                pi = pi->nextarc;
            }
            printf("%d", out_num);
            i == lg.vexnum-1 ? printf("\n") : printf(" ");
        }

        /****输出每条边的入度****/
        printf("输出所有入度：\n");
        for(int i=0; i<lg.vexnum; i++) {
            in_num = 0;
            pi = lg.vertexs[i].head2;
            while(pi != NULL) {
                in_num++;
                pi = pi->nextarc;
            }
            printf("%d", in_num);
            i == lg.vexnum-1 ? printf("\n") : printf(" ");
         }
         Delete();
        printf("****************************************\n请输入图的节点数和边数：\n"); 
    }
    return 0;
}

