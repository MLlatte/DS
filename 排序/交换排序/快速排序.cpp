#include <iostream>
using namespace std;
#define maxSize 100
void QuickSort(int R[], int low, int high)
//对从R[low]到R[high]的关键字进行排序
{
	int temp;
	int i = low, j = high;
	if (low < high)
	{
		temp = R[low];
/*下面这个循环完成了一趟排序，即将数组中小于temp的关键字放在左边，
大于temp的关键字放在右边*/
		while (i < j)
		{
			while (j > i&&R[j] >= temp) --j;//从右往左扫描，找到一个小于temp的关键字
			if (i < j)
			{
				R[i] = R[j];  //放在temp左边
				++i;          //i右移一位
			}
			while (i < j&&R[j] < temp)  ++i;//从左往右扫描，找到一个大于temp的关键字
			if (i < j)
			{
				R[j] = R[i];  //放在temp右边
				--j;         //j左移一位
			}
		}
		R[i] = temp;                 //将temp放在最终位置
		QuickSort(R, low, i - 1);   //递归地对temp左边的关键字进行排序
		QuickSort(R, i + 1, high); //递归对temp右边关键字进行排序
	}
}
int main()
{
	int a, n;
	int R[maxSize];
	cout << "输入排序个数" << endl;
	cin >> n;
	cout << "输入待排序元素" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		R[i] = a;
	}
	QuickSort(R, 0, n - 1);
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << " ";
	}
}
