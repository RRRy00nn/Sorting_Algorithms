#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
	int arr[10] = { 23,2,45,1,34,67,4,3,299,99 };
	//round loop
	for (int i = 0; i <=10- 1; i++)
	{	//each round
		int tmp;
		tmp = i;
		for (int j=i; j <10; j++)
		{
			if (arr[j] < arr[tmp])
				tmp = j;
		}
		if (tmp != i)
		{
			swap(arr[i], arr[tmp]);
		}
	}
	for(int i=0;i<10;i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
	
}