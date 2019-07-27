#include<iostream>
#include<algorithm>
using namespace std;
#define maxSize 100
#define INF 9999 
typedef struct
{
	int edges[maxSize][maxSize];      //邻接矩阵定义
	int n, e;                         //顶点数和边数
	char vex[maxSize];               //存放结点信息
}MGraph;                                //图的邻接矩阵类型

//用图的邻接矩阵存储，因为目的是构造MST，所以存储结构越简单越好
void prim(MGraph g, int v0, int &sum)         //v0是构造最小生成树的起始顶点
{
	
	int lowcost[maxSize], vset[maxSize], v;       //v表示当前刚并入的那个顶点
	int i, j, k = 0, min;                        //用min选出与当前生成树相连的并且到图中剩余顶点之间的最小的边
	v = v0;  
	fill(vset, vset + maxSize, 0);
	for (int i = 0; i < g.n; ++i)
	{
		lowcost[i] = g.edges[v0][i];     //初值是v0到其余顶点的边的最小权值
		vset[i] = 0;
	}
	vset[v0] = 1;     //将v0并入树中
	sum = 0;         //将sum清零用来累计树的权值
	for (i = 0; i < g.n-1; ++i)
	{
		min = INF;     //INF是一个已经定义的比图中所有边权值都大的常量
		              //在这里某顶点到其自身的距离规定为无穷大，即INF
		
		/*下面这个循环用于选出候选边中最小者*/
		for (j = 0; j < g.n; j++)
			if (vset[j] == 0 && lowcost[j] < min)    //选出当前生成树到
			{                                       //其余顶点最短边中的最短的一条
				min = lowcost[j];
				k = j;                         //这里一定要把j赋给k,才能保留最短边对应的那个顶点
			}
		vset[k] = 1;
		v = k;
		sum += min;       //这里用sum记录了最小生成树的权值
		
		/*下面这个循环以刚进入的顶点v为媒介更新候选边*/
//考查所有剩余顶点vj,如果(v,vj)的权值比lowcost[vj]小，则用
		//(v,vj)的权值更新lowcost[vi]
		for (j = 0; j < g.n; j++) 
			if (vset[j] == 0 &&g.edges[v][j] < lowcost[j]) 
				lowcost[j] = g.edges[v][j];	
	}
}

int main()
{
	int sum = 0;
	MGraph g;
	cout << "输入顶点数和边数,用空格分开" << endl;
	cin >> g.n>> g.e;

	//用fill函数初始化边的权值为无穷大(INF)
	fill(g.edges[0], g.edges[0] + maxSize * maxSize, INF);

	cout << "输入结点信息" << endl;
	for (int i = 0; i < g.n; i++) {
		char data;
		cin >> data;
		g.vex[i] = data;
	}
	
	for (int i = 0; i < g.e; ++i) {
		int start, end, weight;
		cout << "输入边对应的两个顶点序号(空格分开),边的权重" << endl;
		cin >> start >> end >> weight;
		g.edges[start][end] = weight;
		g.edges[end][start] = weight;
	}

	prim(g, 0, sum);
	cout << sum << endl;          //输出最小生成树的权值

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
