#include <iostream>
using namespace std;
#define maxSize 100
void BubbleSort(int R[], int n)      //默认待排序关键字为整型
{
	int i, j, flag; int temp;
	for (i = n - 1; i >= 1; --i)
	{
		flag = 0;                   //变量flag用来标记本趟排序是否发生了交换
		for(j=1;j<=i;++j)
			if (R[j - 1] > R[j])
			{
				temp = R[j];
				R[j] = R[j - 1];
				R[j - 1] = temp;
				flag = 1;              //如果没发生交换，则flag的值为0
			}                       //如果发生交换，则flag的值为1

		if (flag == 0)        //一趟排序过程中没有发生关键字交换，则证明序列
			return;		         //有序，排序结束*		
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
	BubbleSort(R, n);
	for (int i = 0; i < n; i++)
	{
		cout << R[i] << " ";
	}
}
