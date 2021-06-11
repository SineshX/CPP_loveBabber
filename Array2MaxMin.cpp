/*
 * Find Maximum and minimum element of an Array
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

	int arr[] = {54,2,7,4,76,6,0, 23,76};
    
	//getting size of array
	int n  = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);

    //finding min or max
	int min = arr[0],max = arr[0] ;
	for (int i = 1; i < n; i++)
	{
		if(arr[i] < min)
            min = arr[i];
        if(arr[i] > max)
            max = arr[i];
        
	}

    cout<<"Minimum  : "<<min
        <<"\nMaximum  : "<<max<<endl;

	
	return 0;
}