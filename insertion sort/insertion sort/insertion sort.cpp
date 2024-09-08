#include<iostream>
using namespace std;
void insertionsort(int arr[], int len)
{
	if (len < 2) return;
	int itmp;
	for (int i = 1; i < len; i++)
	{
		itmp = arr[i];
		int j = 0;
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] <= itmp)
				break;
			arr[j + 1] = arr[j];
		}
		arr[j + 1] = itmp;
	}
}
int main()
{
	int arr[] = { 2,4,1,45,2,7,45,3,434,3 };
	int len = sizeof(arr) / sizeof(int);
	insertionsort(arr, len);
	for (int i = 0; i < len; i++)
		cout << arr[i] << " ";
	return 0;
}