#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#define MAXN 100
#define INF 0xFFFFFFF
#define RST(N)memset(N, 0, sizeof(N))
using namespace std;

struct ArcNode     //�߽ڵ㣻
{
    int adjvex;    //����ߵ���һ���ڽӵ����ţ�
    ArcNode *nextarc;  //ָ����һ���߽ڵ��ָ�룻
};

struct VNode       //���㣻
{
    int data;      //������Ϣ��
    ArcNode *head1;  //���߱�ı�ͷָ�룻
    ArcNode *head2;  //��߱�ı�ͷָ�룻
};

struct LGraph      //ͼ���ڽӱ�洢�ṹ��
{
    VNode vertexs[MAXN];   //�������飻
    int vexnum, arcnum;    //����������(��)����
};

LGraph lg;  //ͼ(�ڽӱ�洢�ṹ)

void CreateLG()     //��������ͼG��
{
    ArcNode *pi;
    int v1, v2;
    for(int i=0; i<lg.vexnum; i++) 
	{  //��ʼ����ͷָ��Ϊ�գ�
        lg.vertexs[i].head1 = lg.vertexs[i].head2 = NULL;
    }
    for(int i=0; i<lg.arcnum; i++) 
	{
        scanf("%d %d", &v1, &v2);
        v1--, v2--;
        pi = new ArcNode;     //��ӳ��ߣ�
        pi->adjvex = v2;
        pi->nextarc = lg.vertexs[v1].head1;
        lg.vertexs[v1].head1 = pi;
        pi = new ArcNode;     //�����ߣ�
        pi->adjvex = v1;
        pi->nextarc = lg.vertexs[v2].head2;
        lg.vertexs[v2].head2 = pi;
    }
}

//�ͷ��ڴ�ռ䣻
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
    printf("****************************************\n������ͼ�Ľڵ����ͱ�����\n"); 
    while(~scanf("%d %d", &lg.vexnum, &lg.arcnum)) 
	{
        if(lg.vexnum == 0) break;
        CreateLG();

        /****���ÿ���ߵĳ���****/
        printf("������г��ȣ�\n");
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

        /****���ÿ���ߵ����****/
        printf("���������ȣ�\n");
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
        printf("****************************************\n������ͼ�Ľڵ����ͱ�����\n"); 
    }
    return 0;
}

