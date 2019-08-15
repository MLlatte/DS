/*Dijkstra算法,用到了三个重要的数组，分别为dist[],path[],set[],最后利用
栈将最短路径打印出来*/
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

void Djkstra(MGraph g, int v, int dist[], int path[])
{
	int set[maxSize];
	int min, i, j, u;
	/*下面开始对各数组进行初始化*/
	for (i = 0; i < g.n; ++i)
	{
		dist[i] = g.edges[v][i];
		set[i] = 0;
		if (g.edges[v][i] < INF)
			path[i] = v;
		else
			path[i] = -1;
	}
	set[v] = 1; path[v] = -1;
	/*初始化结束*/

	/*关键操作开始*/
	for (i = 0; i < g.n - 1; ++i)
	{
		min = INF;
   
		/*这个循环每次从剩余顶点中选出一个顶点，
		通往这个顶点的路径在通往所有剩余顶点的路径中是长度最短的*/
		for(j=0;j<g.n;++j)
			if (set[j] == 0 && dist[j] < min)
			{
				u = j;
				min = dist[j];
			}
		set[u] = 1; //将选出的顶点并入最短路径

		/*这个循环以刚并入的顶点作为中间点，对所有通往剩余顶点的路径进行检测
		也即是对dist[]和path[]数组的更新*/
		for (j = 0; j < g.n; ++j)
		{
			/*这个if语句判断顶点u的加入是否会出现通往顶点j的更短的路径，
			如果出现，则改变原来的路径及长度，否则什么都不做*/
			if (set[j] == 0 && dist[u] + g.edges[u][j] < dist[j])
			{
				dist[j] = dist[u] + g.edges[u][j];
				path[j] = u;
			}
		}

	}
	/*关键操作结束*/
}
/*函数结束时，dist[]数组中存放了v点到其余顶点的最短路径长度，
path[]数组中存放v点到其余各顶点的最短路径*/



/*path[]数组中其实保存了一棵树,这是一棵用双亲存储结构存储的树,通过这棵树可以打印出
从源点到任何一个顶点最短路径上所经过的所有顶点。树的双亲表示法只能直接输出由叶子结点
到根结点路径上的结点，而不能逆向输出，因此需要借助一个栈来实现逆向输出，打印路径
函数如下*/
void printfPath(int path[], int a)
{
	int stack[maxSize], top = -1;
	
	//这个循环以由叶子结点到根结点的顺序将其入栈
	while (path[a] != -1)
	{
		stack[++top] = a;
		a = path[a];
	}
	stack[++top] = a;//将根结点入栈
	while (top != -1)
		cout << stack[top--] << " "; //出栈并打印出栈元素，实现了顶点的逆序打印
	cout << endl;
}



int main() {
	MGraph g;

	//图的顶点数和边数
	cout << "请输入顶点数和边数(用空格分开)" << endl;
	cin >> g.n >> g.e;

	int i, j, w;
	int dist[maxSize];
	int path[maxSize];

	cout << "输入顶点信息" << endl;
	for (int k = 0; k < g.n; k++)
	{
		int a;
		cin >> a;
	}

	//给图的邻接矩阵里的每一个元素赋上无穷大(即邻接矩阵初始化为无穷大)
	fill(g.edges[0], g.edges[0] + maxSize * maxSize, INF);
	
	for (int k = 0; k < g.e; k++)
	{
		cout << "请输入边(vi, vj)的上标i,下标j和权值w(空格分隔):" << endl;
		cin >> i >> j >> w;
		g.edges[i][j] = w;
	}
		Djkstra(g, 0, dist, path);
		for (int k = 1; k < g.n; ++k)
		{
			printfPath(path, k);
			cout << endl;
		}
		return 0;
}
