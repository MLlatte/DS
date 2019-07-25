#include<iostream>
#include<malloc.h>
using namespace std;
#define maxSize 100 // 最大顶点数，应由用户定义 
#define INF  65535 // 表示权值的无穷

typedef struct  //图的定义
{
	char vexs[maxSize];//存放顶点信息 
	int edges[maxSize][maxSize];// 邻接矩阵，可看作边表 
	int n,e;// 图中当前的顶点数和边数 
} MGraph;
MGraph g;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph &g)
{
	int i, j, k, w;
	cout << "请输入顶点数和边数（空格分隔）：" << endl;
	cin >> g.n >> g.e;
	cout << "请输入顶点信息（空格分隔）：" << endl;
	for (i = 0; i < g.n; i++)
		cin >> g.vexs[i];
	for (i = 0; i < g.n; i++)
	{
		for (j = 0; j < g.n; j++)
		{
			if (i == j)
				g.edges[i][j] = 0;// 顶点没有到自己的边
			else
				g.edges[i][j] = INF;// 邻接矩阵初始化 
		}
	}

	for (k = 0; k < g.e; k++)
	{
		cout << "请输入边（vi, vj)的上标i，下标j和权值w（空格分隔）:" << endl;
		cin >> i >> j >> w;
		g.edges[i][j] = w;
		g.edges[j][i] = g.edges[i][j];// 因为是无向图，矩阵对称 
	}
}

int main(void)
{
	CreateMGraph(g);
	for (int i = 0; i < g.n; ++i) {
		for (int j = 0; j < g.n; ++j) {
			cout << g.edges[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}
