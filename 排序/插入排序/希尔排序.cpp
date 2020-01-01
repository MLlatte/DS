#include <iostream>
using namespace std;
#define maxSize 100
void shellSort(int R[], int n)
{
	int temp;
	for (int gap = n / 2; gap > 0; gap /= 2)
	{
		for (int i = gap; i < n; ++i)
		{
			temp = R[i];
			int j;
			for (j = i; j >= gap && R[j - gap] > temp; j -= gap)
				R[j] = R[j - gap];
			R[j] = temp;
		}
	}
}
int main()
{
	int a, n;
	int R[maxSize];
	cout << "输入排序个数" << endl;
	cin >> n;
	cout << "输入待排序元素" << endl;
	for (int i = 0; i < n; ++i)
	{
		cin >> a;
		R[i] = a;
	}
	shellSort(R, n);
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << " ";
	}
		
}
