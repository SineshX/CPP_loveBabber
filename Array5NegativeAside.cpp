// A C++ program to put all negative
// numbers before positive numbers
#include <iostream>
using namespace std;
//  M1
//  void rearrange(int arr[], int n)
// {
    // int j = 0;
	// for (int i = 0; i < n; i++) {
	// 	if (arr[i] < 0) 
    //     {
	// 		if (i != j)
	// 			swap(arr[i], arr[j]);
	// 		j++;
	// 	}
	// }
// }
// M2
void rearrange(int arr[], int n)
{
	int neg = 0, pos = n;
    while(neg < pos)
    {
        if (arr[neg] < 0 )
        {
            neg++;
        }
        else if(arr[neg] >= 0)
        {
            int temp = arr[neg];
            arr[neg] = arr[pos];
            arr[pos] = temp; 
        }
        if(arr[pos] >= 0)
        {
            pos--;
        }
        else if(arr[pos] < 0)
        {
            int temp = arr[pos];
            arr[pos] = arr[neg];
            arr[neg] = temp; 
        }
    }
}
// A utility function to print an array
void printArray(int arr[], int n)
{
	for (int i = 0; i < n; i++)
		printf("%d ", arr[i]);
}

// Driver code
int main()
{
	int arr[] = { -1, 2, -3, 4, 5, 6, -7, 8, 9 };
	int n = sizeof(arr) / sizeof(arr[0]);
	rearrange(arr, n);
	printArray(arr, n);
	return 0;
}
