/*
 * Find Maximum and minimum element of an Array
 * using function 
 */

#include<iostream>

using namespace std;

struct Pair{
    int min = 0 ;
    int max = 0 ;
};// name of my structure 

void printArray(int arr[],int size);
Pair minmaxFun(int arr[],int size);

int main(void)
{	

	int arr[] = {54,2,7,4,76,6,0, 23,76};
    
	//getting size of array
	int n  = sizeof(arr)/sizeof(arr[0]);

	printArray(arr,n);

	Pair mypair; // Pair is user defined DS
    mypair = minmaxFun(arr,n);

    cout<<"Minimum  : "<<mypair.min
        <<"\nMaximum  : "<<mypair.max<<endl;

	
	return 0;
} // end of main function

Pair minmaxFun(int arr[],int size)
{
    Pair mypair;

    //init mypair
    if(size == 1)
    {
        mypair.min = arr[0];
        mypair.max = arr[0];
    }
    else if (arr[0] < arr[1])
    {
        mypair.min = arr[0];
        mypair.max = arr[1];
    }
    else{
        mypair.min = arr[1];
        mypair.max = arr[0];
    }

    //finding minmax pair
    for (int i = 2; i < size; i++)
    {
        if(arr[i] < mypair.min)
            mypair.min = arr[i];
        else if(arr[i] > mypair.max)
            mypair.max = arr[i];
    }
    
    return mypair;
}

void printArray(int arr[],int size)
{	cout<<"Array :  ";
	for(int i = 0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}
