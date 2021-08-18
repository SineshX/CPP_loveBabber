#include <iostream>
#include <algorithm>
using namespace std;
void printArray(int arr[], int size);
void merge(int arr1[], int arr2[], int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        bool flag = 0;
        if (arr1[i] > arr2[0])
        {
            flag = 1;
            swap(arr1[i], arr2[0]);
        }
        if (flag)
        {
            sort(arr2, arr2 + m);
        }
    }
} // fking segmentation fault :_;

void printArray(int arr[], int size)
{
    cout << "Array :  ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    cout << endl;
}

int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5;
    merge(arr1, arr2, n, m);
    printArray(arr1, n);
    printArray(arr2, m);
    cout << endl;
    return 0;
}