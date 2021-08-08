// Kaden's Algorithm

#include <iostream>
#include <numeric>    
using namespace std;
//all neg me fail ho jayega ??
int max(int a,int b)
{
    return (a>b)?a:b;
}
int maxSubArraySum(int arr[], int n)
{
    int curr_sum = 0;
    int max_sum = arr[0];
    for(int i = 0; i<n;i++)
    {   
        if(curr_sum >= 0 )
        {
            curr_sum += arr[i];
            max_sum = max(curr_sum , max_sum);

        }
        else 
        {   
            curr_sum = arr[i];
            max_sum = max(curr_sum , max_sum);

        }
    }
    return max_sum;
}
int main(void)
{

    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
}
