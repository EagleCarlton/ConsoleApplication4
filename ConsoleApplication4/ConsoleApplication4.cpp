// ConsoleApplication4.cpp : 定义控制台应用程序的入口点。
//划分数组元素：第一个元素为支点，得到数组，支点左端均小于支点，右端均大于支点
//若在节点后输入与节点相同的数，则程序有误
#include "stdafx.h"
#include "stdio.h"
int partition(int p[], int left, int right);
void display_array(const int p[], int n);
int main()
{
	int a[10], i;
	printf("input 10 integers:\n");
	for (i = 0; i < 10; ++i)
		scanf_s("%d", &a[i]);
	printf("%d\n", partition(a, 0, 9));
	display_array(a, 10);
    return 0;
}
int partition(int p[], int left, int right)
{
	int pivot = p[left];
	while (left < right)
	{
		while (p[right] >= pivot&&right > left)
			right--;
		if (right > left)
			p[left++] = p[right];
		else
			break;
		while (p[left] < pivot&&left < right)
			left++;
		if (left < right)
			p[right--] = p[left];
		else
			break;
	}
	p[left] = pivot;
	return left;
}
void display_array(const int p[], int n)
{
	int i;
	for (i = 0; i < n; ++i)
		printf("%d\t", p[i]);
	printf("\n");
}

