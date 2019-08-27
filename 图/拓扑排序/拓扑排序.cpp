/*拓扑排序代码既可以输出一个图的拓扑排序序列，又可以判断一个图中是否有环*/
#include <iostream>
using namespace std;
#define maxSize 100

//边结点结构体设计
typedef struct ArcNode
{
	int adjvex;                  //领接顶点(该边所指向的结点的位置，即下一条边的始点编号)
	struct ArcNode *nextarc;    //链域(指向下一条边的指针)
	int info;                  //存储权值
}ArcNode;

//图的顶点结构体设计
typedef struct
{
	int data;               //顶点信息
	int count;             //用count来统计顶点当前的入度
	ArcNode *firstarc;    //指向第一条边的指针
}VNode;

//图的结构体设计
typedef struct
{
	VNode adjlist[maxSize];    //图的顶点数组(邻接表)
	int n, e;                 //顶点数和边数
}AGraph;  

//建立图的邻接表结构
void creatAGraph(AGraph *&g)
{
	g = (AGraph*)malloc(sizeof(AGraph));
	int i, j, k;
	ArcNode *p;                 //p指向待插入的结点

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
		p = (ArcNode*)malloc(sizeof(ArcNode));         //向内存申请空间，生成边表结点

		p->adjvex = j;  //存储弧头

		//头插法建立边链表
		p->nextarc = g->adjlist[i].firstarc;         // 将p的指针指向当前顶点指向的结点
		g->adjlist[i].firstarc = p;                  //将当前顶点的指针指向p

		//下面代码有向图无,无向图有 
/*		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;             */
	}

}


void TopSort(AGraph *G)
{
	int i, j, n = 0;                //n用来统计当前已经输出的拓扑序列中顶点的个数
	
	/*用栈来保存当前图中所有入度为0的顶点，因此这里的栈只是一个容器，
	换成队列或数组也可以*/
	int stack[maxSize], top = -1;
	
	ArcNode *p;                  //p是用来遍历顶点后面那条边链表的辅助变量
	
	//count的初始化操作
	for (i = 0; i < G->n; ++i) {
		G->adjlist[i].count = 0;
	}

	//计算图中每个顶点的入度，保存在count中
	for (i = 0; i < G->n; ++i)
	{
		p = G->adjlist[i].firstarc;
		while (p != NULL) {
			G->adjlist[p->adjvex].count++;
			p = p->nextarc;
		}
	}

	//扫描图中所有顶点，把入度为0的顶点压入栈中
	for (i = 0; i < G->n; ++i)
		if (G->adjlist[i].count == 0)
			stack[++top] = i;
	
	/*关键操作开始*/
	while (top != -1)
	{
		i = stack[top--];                        //顶点出栈
		++n;                                    //计数器加1，统计当前顶点
		cout << i << "";                       //输出当前顶点
		p = G->adjlist[i].firstarc;
		
		/*遍历刚才出栈顶点的所有边，并且通过这些边找到其相邻的顶点，
		然后修改其相邻顶点的count值(把count值减1)，把count值变为0的顶点
		入栈，以待输出*/
		while (p != NULL)
		{
			j = p->adjvex;
			--(G->adjlist[j].count);
			if (G->adjlist[j].count == 0)
				stack[++top] = j;
			p = p->nextarc;
		}
		
	}
	/*关键操作结束*/

	cout << endl;
	if (n == G->n)
		cout << "拓扑排序成功" << endl;
	else
		cout << "拓扑排序失败" << endl;
}

int main()
{
	AGraph *G;
	G = (AGraph*)malloc(sizeof(AGraph));
	creatAGraph(*&G);
	TopSort(G);
}
