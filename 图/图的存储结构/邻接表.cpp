#include <iostream>
using namespace std;
#define maxSize 1000

//边结点结构体设计
typedef struct ArcNode
{
	int adjvex;  //领接顶点(该边所指向的结点的位置，即下一条边的始点编号)
	struct ArcNode *nextarc; //链域(指向下一条边的指针)
	int info;   //存储权值
}ArcNode;

//图的顶点结构体设计
typedef struct
{
	char data;         //顶点信息
	ArcNode *firstarc; //指向第一条边的指针
}VNode;

//图的结构体设计
typedef struct
{
	VNode adjlist[maxSize];  //图的顶点数组(邻接表)
	int n, e;               //顶点数和边数
}AGraph;
AGraph *g; 
void creatAGraph(AGraph *&g)
{
	g= (AGraph*)malloc(sizeof(AGraph));
	int i, j, k;
	ArcNode *p;     //p指向待插入的结点

	//输入顶点和边数
	cout << "输入顶点数和边数" << endl;
	cin >> g->n >> g->e;

	//输入顶点信息，建立顶点表
	cout << "输入顶点信息" << endl;
	for (i = 0; i < g->n; i++)
	{
		cin >> g->adjlist[i].data;
		g->adjlist[i].firstarc = NULL; //将指向边表的指针初始化(置空)
	}

	//建立边表
	for (k = 0; k < g->e; k++)
	{
		cout << "输入边(vi,vj)上的顶点序号" << endl;
		cin >> i >> j;

		//单链表中的头插法
		p= (ArcNode*)malloc(sizeof(ArcNode));//向内存申请空间，生成边表结点

		p->adjvex = j;  //存储弧头

		//头插法建立边链表
		p->nextarc = g->adjlist[i].firstarc;  // 将p的指针指向当前顶点指向的结点
		g->adjlist[i].firstarc = p;//将当前顶点的指针指向p

		//下面代码有向图无,无向图有 
		p = (ArcNode*)malloc(sizeof(ArcNode));
		p->adjvex = i;
		p->nextarc = g->adjlist[j].firstarc;
		g->adjlist[j].firstarc = p;
	}
	
}

//打印邻接表
void Print(AGraph *&g) {
	int i; // 用来遍历元素
	ArcNode *q;

	cout << "顶点表的值为" << endl;         //printf("顶点表的值为：\n");
	// 打印顶点表
	for (i = 0; i < g->n; i++) {
		cout<<"v" << i<<": " << g->adjlist[i].data << endl;     //printf("v%d: %c\n", i, g->adjlist[i].data);
	}

	cout << "边表的值为" << endl;          //printf("边表的值为：\n");
	//打印边表
	for (i = 0; i < g->n; i++) {
		cout << "v" << i;     //printf("v%d ", i);

		q = g->adjlist[i].firstarc; // q指向顶点i的边表

		while (q) {          // 边表未遍历完
			cout << "->" << q->adjvex;//printf("-> %d", q->adjvex); // 打印邻接点
			q = q->nextarc; // q移动到下一个边表节点
		}
		cout << endl;//printf("\n");
	}
}

int main() {
	AGraph *g;
	creatAGraph(*&g);
	Print(*&g);
	return 0;
}
