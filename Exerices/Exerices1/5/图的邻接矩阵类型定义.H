//图的邻接矩阵类型定义.h
const int n=8;
const int e=10;
typedef char vextype;
typedef int adjtype;
typedef struct
{
	vextype vexs[n];
	adjtype arcs[n][n];
}graph;
graph*g=new graph;
int visited[n];
