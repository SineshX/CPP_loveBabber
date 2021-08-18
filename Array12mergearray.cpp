#include <iostream>
using namespace std;
void printArray(int arr[],int size);
void merge(int arr1[], int arr2[], int n, int m)
{
    // code here
    // for ascending order
    if (arr2[0] >= arr1[n - 1])
        return;
    // tank fully reverse order me sorted nahi hai
    else
    {
        //pick small array :)
        if (n > m)
        {
            //switch
            int *temp = arr2;
            arr2 = arr1;
            arr1 = temp;
            int a = m;
            m = n;
            n = m;
        } // Todo // switch back with flag
        int i = 0, j = 0;
        while (i < n)
        {
            if (arr1[i] > arr2[0])
            {
                int temp = arr1[n - 1];

                // shift right arr1 // if possible
                for (int j = n - 1; j > i; j--)
                {
                    arr1[j] = arr1[j - 1];
                }

                // and insert arr2[0] //done
                arr1[i] = arr2[0];
                printArray(arr1, n);
                // inplace sort arr2// if needed
                j = 0;
                while (arr2[j+1] < temp)
                {
                    //shift left
                    arr2[j] = arr2[j + 1];
                    j++;
                }

                arr2[j] = temp;
                printArray(arr2, m);
                i += 2;
            }
            else
            {
                i++;
                //contunue;
            }
        }
    }
}// fking segmentation fault :_;

void printArray(int arr[],int size)
{	cout<<"Array :  ";
	for(int i = 0;i<size;i++)
	{
		cout<<arr[i]<<"\t";
	}
	cout<<endl;
}


int main()
{
    int arr1[] = {1, 3, 5, 7};
    int arr2[] = {0, 2, 6, 8, 9};
    int n = 4, m = 5;
    merge(arr1,arr2, n, m);
    printArray(arr1,n);
    printArray(arr2,m);
    cout << endl;
    return 0;
}