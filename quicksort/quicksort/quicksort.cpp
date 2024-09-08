#include <iostream>
using namespace std;
void quicksort(int arr[], int len)
{
    if (len < 2) return;//recursion
    int mid = arr[0];//select first num as standard num
    int left = 0;
    int right = len - 1;//last elem in array
    int moving = 2;//move left/right 
    //1-left, 2-right
    while (left < right)//if left and right meets,reset area for sort
    {
        if (moving == 1)
        {
            if (arr[left] <= mid)
            {
                left++;
                continue;
            }
            //else put num into space
            arr[right] = arr[left];
            right--;//moving right to left
            moving = 2;
        }
        else//moving right
        {
            if (arr[right] >= mid)
            {
                right--;
                continue;
            }
            arr[left] = arr[right];
            left++;
            moving = 1;
        }

    }
    //if loop ends,put standard into space
    arr[left] = mid;
    quicksort(arr, left);
    quicksort(arr+left+1,len-left-1);
}
int main()
{
    int arr[] = { 2,4,1,45,2,7,45,3,434,3 };
    int len = sizeof(arr) / sizeof(int);
    quicksort(arr, len);
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    return 0;
}
