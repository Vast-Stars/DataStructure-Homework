//建立无向图邻接矩阵.h
void creatgraph()
{
	int i,j,k;
	for(i=0;i<n;i++)
		g->vexs[i]=getchar();
	for(i=0;i<n;i++)
		for(j=0;j<n;j++)
			g->arcs[i][j]=0;
	for(k=0;k<e;k++)
	{
		cin>>i>>j;
		g->arcs[i][j]=g->arcs[j][i]=1;
	}
}
