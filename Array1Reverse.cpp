/*
 * Reverse the integer Array 
 */


#include<iostream>

using namespace std;

void printArray(int arr[],int size)
{	cout<<"Array :  ";
	for(int i = 0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
int main(void)
{	

	int arr[] = {1,2,3,4,5,6,7,8,9};

	//getting size of array
	int n  = sizeof(arr)/sizeof(arr[0]);
	// cout<<len<<endl;

	//reversing array
	for (int i = 0, temp = 0; i < n/2; i++)
	{
		temp = arr[i];
		arr[i]= arr[n-(i+1)];
		arr[n-(i+1)] = temp;
	}

	printArray(arr,n);
	
	return 0;
}