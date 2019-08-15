/*Floyd算法用到了两个关键的二维数组，分别为A[]和Path[],最后用一个递归
函数将最短路径打印出来*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxSize 100 // 最大顶点数，应由用户定义 
#define INF  65535 // 表示权值的无穷

typedef struct  //图的定义
{
	int vexs[maxSize];//存放顶点信息 
	int edges[maxSize][maxSize];// 邻接矩阵，可看作边表 
	int n, e;// 图中当前的顶点数和边数 
} MGraph;

void Floyd(MGraph g, int Path[][maxSize])
{
	int i, j, k;
	int A[maxSize][maxSize];

	//这个双循环对数组A[][]和Path[][]进行了初始化
	for (i = 0; i < g.n; ++i)
		for (j = 0; j < g.n; ++j)
		{
			A[i][j] = g.edges[i][j];
			Path[i][j] = -1;
		}

	//下面这个三重循环是本算法的主要操作，完成了以k为中间点对
	//所有的顶点对{i,j}进行检测和修改
	for (k = 0; k < g.n; ++k)
		for (i = 0; i < g.n; ++i)
			for (j = 0; j < g.n; ++j)
				if (A[i][j] > A[i][k] + A[k][j])
				{
					A[i][j] = A[i][k] + A[k][j];
					Path[i][j] = k;
				}
}

//输出从u到v的最短路径上顶点序列
void printPath(int u, int v, int path[][maxSize])
{
	if (path[u][v] == -1)
		cout << v << endl;//输出最短路径的顶点
	else
	{
		int mid = path[u][v];   //中间点
		printPath(u, mid, path);//处理mid前半段路径
		printPath(mid, v, path);//处理mid后半段路径
	}
}

int main()
{
	MGraph g;

	//图的顶点数和边数
	cout << "请输入顶点数和边数(用空格分开)" << endl;
	cin >> g.n >> g.e;
	
	int i, j, w;
	int Path[maxSize][maxSize];

	cout << "输入顶点信息" << endl;
	for (int k = 0; k < g.n; k++)
	{
		int a;
		cin >> a;
	}

	fill(g.edges[0], g.edges[0] + maxSize * maxSize, INF);

	for (int k = 0; k < g.e; k++)
	{
		cout << "请输入边(vi, vj)的上标i,下标j和权值w(空格分隔):" << endl;
		cin >> i >> j >> w;
		g.edges[i][j] = w;
	}
	Floyd(g, Path);

	int u, v;
	cout << "请输入目标顶点u,v" << endl;
	cin >> u >> v;
	cout << u << endl;   //输出第一个顶点
	printPath(u, v, Path);
}


	
