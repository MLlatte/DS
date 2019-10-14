#include<iostream>
using namespace std;
#define maxSize 100
void SelectSort(int R[], int n)
{
	int i, j, k;
	int temp;
	for (i = 0; i < n; ++i)
	{
		k = i;

		/*这个是算法的关键，它从无序序列中挑出一个最小关键字*/
		for (j = i + 1; j < n; ++j)
			if (R[k] > R[j])
				k = j;

		/*以下3句完成最小关键字与无序序列中第一个关键字的交换*/
		temp = R[i];
		R[i] = R[k];
		R[k] = temp;
	}
}
int main() {
	int a, n;
	int R[maxSize];
	cout << "输入排序个数" << endl;
	cin >> n;
	cout << "输入待排序元素" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		R[i] = a;
	}
	SelectSort(R, n);
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << " ";
	}
}
