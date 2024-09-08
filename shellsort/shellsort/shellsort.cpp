#include<iostream>
using namespace std;
void groupsort(int arr[], int len, int num, int step);
//sort in seperated single group
//actually its still insertion sort
void shellsort();//seperate array into small group
int main(int argc, char* argv[])
{
	int arr[] = { 2,4,1,45,2,7,45,3,434,3 };
	int len = sizeof(arr) / sizeof(int);
	shellsort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	return 0;
}
void shellsort(int* arr, unsigned int len)
{
	for (int step = len / 2; step > 0; step = step / 2)
	//seperate group
	{
		for (int i = 0; i < step; i++)
		//insertionsort in each group
		{
			groupsort(arr, len, i, step);
		}
	}
}
void groupsort(int arr[], int len, int num, int step)
{
	int itmp;
	for (int i = num + step; i < len; i = i + step)//insertionsort, but need to  skip numbs
	{
		//start from the rightest position 
		//move elem that bigger than itmp to the right
		int j;//counter need to move
		for (j = i - step; j >= 0; j = j - step)
		{
			if (arr[j] < itmp) break;
			arr[j + step] = arr[j];//back move each elem
		}
		arr[j + step] = itmp;//insert elem
	}
}