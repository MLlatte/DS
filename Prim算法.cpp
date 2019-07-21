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
	vset[v0] = 1;//��v0��������
	sum = 0;  //��sum���������ۼ�����Ȩֵ
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
	cout << "���붥�����ͱ���,�ÿո�ֿ�" << endl;
	cin >> N >> E;
	g.n = N, g.e = E;
	fill(g.edges[0], g.edges[0] + maxSize * maxSize, INF);
	for (int i = 0; i < g.n; i++) {
		char d;
		cout << "��������Ϣ" << endl;
		cin >> d;
		g.vex[i] = d;
	}
	for (int i = 0; i < g.e; ++i) {
		int start, end, weight;
		cout << "�����һ�����㣬�ڶ�������,��������֮���Ȩ��" << endl;
		cin >> start >> end >> weight;
		g.edges[start][end] = weight;
		g.edges[end][start] = weight;
	}
	prim(g, 0, sum);
	cout << sum << endl;  //�����С��������Ȩֵ

	//��ӡ�ڽӾ���
	for (int i = 0; i < g.n; ++i) {
		for (int j = 0; j < g.n; ++j) {
			cout << g.edges[i][j] << " ";
		}
		cout << endl;
	}
	//��ӡ������Ϣ
	for (int i = 0; i < g.n; i++) 
		cout << g.vex[i] << " ";
    return 0;
}