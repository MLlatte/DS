#include<iostream>
using namespace std;
#define maxSize 100
void InsertSort(int R[], int n)   //待排关键字存储在R[]中，默认为整型，个数为n
{
	int i, j, temp;            //i,j是循环变量，temp用来暂存待插入的关键字
	for (i = 1; i < n; ++i)
	{
		temp = R[i];
		j = i - 1;              //i是无序序列中第一个元素，它左边的一个元素就是有序序列中最右边那个元素
		while (j >= 0 && temp < R[j])
		{
			R[j + 1] = R[j];
			--j;
		}
		R[j + 1] = temp;       //找到插入位置，将temp中暂存的待排关键字插入
	}
}
int main(){
	int a,n;
	int R[maxSize];
	cout << "输入排序个数" << endl;
	cin >> n;
	cout << "输入待排序元素" << endl;
	for (int i = 0; i < n; ++i) {
		cin >> a;
		R[i] = a;
	}
	InsertSort(R, n);
	for (int i = 0; i < n; i++)
	{
		cout << R[i]<<" ";
	}
}
