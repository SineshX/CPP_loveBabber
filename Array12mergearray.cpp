#include <iostream>
#include <algorithm>
using namespace std;
void printArray(int arr[], int size);
void merge(int arr1[], int arr2[], int n, int m)
{
    //ascending order
    int i = 0, j = 0, k = n - 1;

    // Untill i less than equal to k // till last element of arr1

    // or j is less tha m //till end of array 2

    while (i <= k && j < m)
    {
        if (arr1[i] < arr2[j])
            i++;
        else
        {
            swap(arr2[j++], arr1[k--]);
            // j++ and k-- is done later :) post increament/decreament 
        }
    }

    // Sort first array
    sort(arr1, arr1 + n);

    // Sort second array
    sort(arr2, arr2 + m);
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
void printArray(int arr[],int size)
{	cout<<"Array :  ";
	for(int i = 0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}