/*以邻接表为存储结构的图的深度优先深搜遍历算法(递归过程)*/
/*DFS算法的执行过程用到了两个关键的数组，分别为adjlist[]和visit[]*/
/*采用DFS算法进行逆拓扑排序*/
#include <iostream>
using namespace std;
# define maxSize 100
typedef struct ArcNode
{
	int adjvex;                //领接顶点(vertex（vex）是顶点的意思)
	struct ArcNode *nextarc;  //指向下一条边的指针
	int info;                //边对应的权值
}ArcNode;
typedef struct
{
	char data;                //顶点信息
	ArcNode *firstarc;       //指向第一条边的指针
}VNode;                   //(arc是"弧"的意思，有向图中,边称为弧)
typedef struct
{
	VNode adjlist[maxSize];     //图的顶点数组(邻接表)
	int n, e;                  //顶点数和边数
}AGraph;

void creatAGraph(AGraph *&g)
{
	g = (AGraph*)malloc(sizeof(AGraph));
	int i, j, k;
	ArcNode *p;            //p指向待插入的结点

	//输入顶点和边数
	cout << "输入顶点数和边数" << endl;
	cin >> g->n >> g->e;

	//输入顶点信息，建立顶点表
	cout << "输入顶点信息" << endl;
	for (i = 0; i < g->n; i++)
	{
		cin >> g->adjlist[i].data;
		g->adjlist[i].firstarc = NULL;   //将指向边表的指针初始化(置空)
	}

	//建立边表
	for (k = 0; k < g->e; k++)
	{
		cout << "输入边(vi,vj)上的顶点序号" << endl;
		cin >> i >> j;

		//单链表中的头插法
		p = (ArcNode*)malloc(sizeof(ArcNode));     //向内存申请空间，生成边表结点

		p->adjvex = j;  //存储弧头

		//头插法建立边链表
		p->nextarc = g->adjlist[i].firstarc;   // 将p的指针指向当前顶点指向的结点
		g->adjlist[i].firstarc = p;           //将当前顶点的指针指向p

		//下面代码有向图无,无向图有 
/*      p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;            */
	}
}

int visit[maxSize];                  //全局数组，作为顶点的访问标记，初始时所有元素为0，表示所有顶点都未被访问

void DFS(AGraph *G, int v)          //v不是顶点，v是某个顶点所在顶点数组中的下标
{
	ArcNode *p;                     //指向ArcNode型变量的指针
	visit[v] = 1;                  //置已访问标记
	
	p = G->adjlist[v].firstarc;        //p指向顶点v的第一条边(即通过v找到其对应的顶点，进而找到顶点所引出的第一条边)
	while (p != NULL)
	{
		if (visit[p->adjvex] == 0)          //若顶点未访问，则递归访问它
			DFS(G, p->adjvex);
		p = p->nextarc;                     //p指向顶点v的下一条边的终点(原路返回，看还有没有其他未访问的顶点)
	}
	cout << G->adjlist[v].data << endl;  //访问顶点
}
int main() {
	AGraph *g;
	creatAGraph(*&g);
	DFS(*&g, 0);
}
