#include<iostream>
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
	char data;            //顶点信息
	ArcNode *firstarc;   //指向第一条边的指针
}VNode;

//图的结构体设计
typedef struct
{
	VNode adjlist[maxSize];   //图的顶点数组(邻接表)
	int n, e;                //顶点数和边数
}AGraph;

//建立图的邻接表结构
void creatAGraph(AGraph *&g)
{
	g = (AGraph*)malloc(sizeof(AGraph));
	int i, j, k;
	ArcNode *p;             //p指向待插入的结点

	//输入顶点和边数
	cout << "输入顶点数和边数" << endl;
	cin >> g->n >> g->e;

	//输入顶点信息，建立顶点表
	cout << "输入顶点信息" << endl;
	for (i = 0; i < g->n; i++)
	{
		cin >> g->adjlist[i].data;
		g->adjlist[i].firstarc = NULL;    //将指向边表的指针初始化(置空)
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
		p->nextarc = g->adjlist[i].firstarc;    // 将p的指针指向当前顶点指向的结点
		g->adjlist[i].firstarc = p;            //将当前顶点的指针指向p
 
		//下面代码有向图无,无向图有 
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
	}
}

int visit[maxSize];            //全局数组，作为顶点的访问标记，初始时所有元素为0，表示所有顶点都未被访问
void BFS(AGraph *G, int v)    //v不是顶点，v是某个顶点所在顶点数组中的下标
{
	ArcNode *p;                               //指向ArcNode型变量的指针            
	int que[maxSize], front = 0, rear = 0;   //这是队列定义的简单写法
	int j;
	cout << G->adjlist[v].data << endl;    //访问顶点
	visit[v] = 1;                         //置已访问标记

	//当前顶点v进队
	rear = (rear + 1) % maxSize;          
	que[rear] = v;

	while (front != rear)              //队空的时候说明遍历完成
	{  
		//顶点出队
		front = (front + 1) % maxSize;   
		j = que[front];

		p = G->adjlist[j].firstarc;       //p指向出队顶点j的第一条边
		
		while (p != NULL)                //将p的所有邻接点钟未被访问的入队
		{
			if (visit[p->adjvex] == 0)  //当前邻接顶点未被访问，则进队
			{
				cout <<G-> adjlist[p->adjvex].data<< endl;  //访问顶点
				visit[p->adjvex] = 1;

				//该顶点进队
				rear = (rear + 1) % maxSize;  
				que[rear] = p->adjvex;
			}
			p = p->nextarc;       //p指向j的下一条边
		}
	}
}
int main() {
	AGraph *g;
	creatAGraph(*&g);
	BFS(*&g, 0);
}

