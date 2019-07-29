/*Kruskal算法用到了两个关键的数组，分别为边集数组road[]和并查集数组v[]*/
#include <iostream>
#include <algorithm>
using namespace std;
#define maxSize 100 // 最大顶点数，应由用户定义

//边集数组结构
typedef struct
{ 
	int a, b;                 //a,b为一条边所连的两个顶点
	int w;                   //边的权值
}Road;
Road road[maxSize];         //定义边集数组(存储边的数组)
int v[maxSize], n, e;      //定义并查集数组，顶点数和边数


//构建边集数组错误写法
/*void creatRoad() {
	for (int i = 0; i < g.e; ++i)
	{
		cout << "输入该边对应的两个顶点(用空格分开)，边对应的权值" << endl;
		cin >> road[maxSize].a >> road[maxSize].b >> road[maxSize].w;
	}
}*/



//构建边集数组(可以视为图的另一种存储结构)
void createRoad()
{
	int i, j, k, w;
	cout << "请输入顶点数和边数（空格分隔）：" << endl;
	cin >> n >> e;
	for (k = 0; k < e; k++)
	{
		cout << "请输入边（vi, vj)的上标i，下标j和权值w（空格分隔）:" << endl;
		cin >> i >> j >> w;
		road[k].a = i;
		road[k].b = j;
		road[k].w = w;
	}
}


//定义比较函数，按边的权值进行比较
bool cmp(Road x, Road y)   //bool cmp(const Road &x, const Road &y)
{
	return x.w < y.w;
}

//在并查集中查找根结点的函数
int getRoot(int p)             //函数参数这里传入的是要找其根结点的结点 
{
	while (p!= v[p])
		p = v[p];
	return p;
}

void Kruskal(int &sum, Road road[])
{
	int i;
	int N, E, a, b;
	N = n;
	E = e;
	sum = 0;

	/*并查集数组初始化，把每个下标位置上都赋上下标的值，
	代表把图中每一个顶点都做成一个根结点*/
	for (i = 0; i < N; ++i)
		v[i] = i;
	
	sort(road, road+E,cmp);      //对road数组中的E条边按其权值从小到大排序
	 
	//把权值从小到大打印出来
	cout << "边集数组中各边的权值为：";
	for (int i = 0; i < E; ++i)
	{
		cout << road[i].w <<" ";
	}
	cout << endl;

	cout << "最小生成树的各边的权值为：";
	for (i = 0; i < E; ++i)//此循环，即下面这些代码就是最小生成树的构建过程
	{

      //取边的两个顶点并找这两个顶点在并查集中其所在那棵树的根结点
		a = getRoot(road[i].a);
		b = getRoot(road[i].b);
		
		if (a != b)
		{ 
			v[a] = b;                     //把a挂在b的下边
			cout<< road[i].w <<" ";
			sum += road[i].w;           //求生成树的权值
		}
	}
	cout << endl;
	cout <<"最小生成树的权值为："<< sum << endl;
}
int main()
{
	int sum;
	createRoad();
	Kruskal(sum, road);
}
