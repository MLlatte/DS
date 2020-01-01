#include <iostream>
using namespace std;
#define maxSize 100
void shellSort(int R[], int n)
{
	int temp;
	for (int gap = n / 2; gap > 0; gap /= 2)//gap为增量
	{
		/* i是用来选出无序序列中的一个关键字，然后把它
		插入到有序序列中合适的位置*/

		/*i从gap开始，gap之前的关键字，都是其所在子序列的第一个关键字，
		也就是有序序列的关键字*/

		/*通过gap划分出来的多个子序列，它们的第一个关键字全都落在了
		gap之前，gap之后(包括gap)就是所有子序列的无序序列的关键字所在范围，
		就是用i从这些关键字中每次挑选出一个插入到它所在的子序列中的
		有序序列中*/
		for (int i = gap; i < n; ++i) //i往后移动一个位置，就是对下一个子序列的处理了
		{
			temp = R[i];
			int j;
			//i所指的关键字是无序序列中的第一个关键字
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
