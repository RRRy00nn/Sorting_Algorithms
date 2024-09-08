#include <iostream>
using namespace std;
void arrminmax(int arr[], int len, int& minvalue, int& maxvalue)
{
    //find max and min value in the array
    int i = 0;
    minvalue = maxvalue = arr[0];
    for (i; i < len; i++)
    {
        if (maxvalue < arr[i])
            maxvalue = arr[i];
        if (minvalue > arr[i])
            minvalue = arr[i];
    }
}
void counsort(int arr[], int len)
{
    if (len < 2)
        return;
    int max, min;
    arrminmax(arr, len, min, max);
    //set a temp array to store value
    int* arrtmp = new int[max - min + 1];
    memset(arrtmp, 0, sizeof(int) * (max - min + 1));
    for (int i = 0; i < len; i++)
    {
        arrtmp[arr[i] - min]++;
    }
    for (int i = 0, j = 0; j < max - min + 1; j++)
    {
        for (int k = 0; k < arrtmp[j]; k++)
            arr[i++] = j + min;
    }

    delete[]arrtmp;
}
int main(int argc, char* argv)
{
    int arr[] = { 2,3,5,6,2,14,2,7,8,4,2,1,13,13,3,4,17,19 };
    int len = sizeof(arr) / sizeof(int);
    counsort(arr, len);
    //show result
    for (int i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;


}
