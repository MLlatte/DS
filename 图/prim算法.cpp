#include<iostream>
#include<malloc.h>
#include<algorithm>
using namespace std;
#define maxSize 5
#define INF 9999
typedef struct
{
	int edges[maxSize][maxSize];
	int n, e;
	char vex[maxSize];
}MGraph;
int lowcost[maxSize];
void prim(MGraph g, int v0, int &sum)
{
	int vset[maxSize], v;
	int i, j, k = 0, min;
	v = v0;  
	fill(vset, vset + maxSize, 0);
	for (int i = 0; i < g.n; ++i)
	{
		lowcost[i] = g.edges[v0][i];
		vset[i] = 0;
	}
	vset[v0] = 1;//将v0并入树中
	sum = 0;  //将sum清零用来累计树的权值
	for (i = 0; i < g.n-1; ++i)
	{
		min = INF;
		for (j = 0; j < g.n; j++)
			if (vset[j] == 0 && lowcost[j] < min)
			{
				min = lowcost[j];
				k = j;
			}
		vset[k] = 1;
		v = k;
		sum += min;
		for (j = 0; j < g.n; j++) 
			if (vset[j] == 0 &&g.edges[v][j] < lowcost[j]) 
				lowcost[j] = g.edges[v][j];	
	}
}

int main()
{
	int sum = 0;
	MGraph g;
	int N, E;
	cout << "输入顶点数和边数,用空格分开" << endl;
	cin >> N >> E;
	g.n = N, g.e = E;
	fill(g.edges[0], g.edges[0] + maxSize * maxSize, INF);
	for (int i = 0; i < g.n; i++) {
		char d;
		cout << "输入结点信息" << endl;
		cin >> d;
		g.vex[i] = d;
	}
	for (int i = 0; i < g.e; ++i) {
		int start, end, weight;
		cout << "输入第一个顶点，第二个顶点,两个顶点之间的权重" << endl;
		cin >> start >> end >> weight;
		g.edges[start][end] = weight;
		g.edges[end][start] = weight;
	}
	prim(g, 0, sum);
	cout << sum << endl;  //输出最小生成树的权值

	//打印邻接矩阵
	for (int i = 0; i < g.n; ++i) {
		for (int j = 0; j < g.n; ++j) {
			cout << g.edges[i][j] << " ";
		}
		cout << endl;
	}
	//打印顶点信息
	for (int i = 0; i < g.n; i++) 
		cout << g.vex[i] << " ";
    return 0;
}
