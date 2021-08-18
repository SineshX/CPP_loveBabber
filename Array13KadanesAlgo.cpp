#include <iostream>
using namespace std;

int maxSubArraySum(int arr[], int n)
{

    // Your code here
    int max_sum = arr[0];
    int curr_sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr_sum >= 0)
        {
            curr_sum += arr[i];
            max_sum = max(max_sum, curr_sum);
        }
        else
        { //restor
            curr_sum = arr[i];
            //in case of all neg element :)
            max_sum = max(max_sum, curr_sum);
        }
    }

    return max_sum;
}

int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; // 7 ans 
    int n = sizeof(a)/sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    cout << "Maximum contiguous sum is " << max_sum;
    return 0;
    cout << endl;
    return 0;
}