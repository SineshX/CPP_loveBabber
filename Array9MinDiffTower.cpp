#include <iostream>
#include <algorithm>
using namespace std;

int getMinDiff(int arr[], int n, int k);

int main()
{
    int n = 10, k = 5;
    int arr[] = {2, 6, 3, 4, 7, 2, 10, 3, 2, 1};

    int ans = getMinDiff(arr, n, k);
    cout << ans;
    cout << endl;
    return 0;
}// main function


int getMinDiff(int arr[], int n, int k)
{
    sort(arr, arr + n); // sort the array to get the
                        // corner cases ans.
    int minEle,
        maxEle;                       // these 2 variables will hold the
                                      // between elements max and min value
    int result = arr[n - 1] - arr[0]; // current result when arr[0]
                                      // iss min and arr[n-1] is max

    for (int i = 1; i <= n - 1; i++)
    {
        if (arr[i] >= k && arr[n - 1] >= k) // 2nd one is just seq check
        {
            maxEle = max(arr[i - 1] + k,
                         arr[n - 1] - k); //

            minEle = min(arr[0] + k, arr[i] - k);

            result = min(result, maxEle - minEle);
            // if the middle elements max and min
            // difference if less than result then update
            // result.
        }
    }
    return result; // return result.
}
