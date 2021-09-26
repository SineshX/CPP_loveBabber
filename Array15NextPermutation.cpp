/*
Runtime: 3 ms, faster than 81.21% of C++ online submissions for Next Permutation.
Memory Usage: 12.1 MB, less than 36.47% of C++ online submissions for Next Permutation.
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void nextPermutation(vector<int> &nums);

int main()
{
    // vector<int> nums = {1,3,2};
    vector<int> nums = {5,4,3,2,1};

    nextPermutation(nums);

    for (auto itr : nums)
        cout << itr << " ";
    // cout <<nums<< endl;
    return 0;
}
void nextPermutation(vector<int> &nums)
{

    if (nums.size() < 2)
        return;
    int i = nums.size() - 1;

    while (nums[i - 1] >= nums[i])
    {
        if (i - 1 == 0)
        {
            //reverse or// sort
            sort(nums.begin(), nums.end());
            return;
        }
        i--;
    }
    // nums[i-1] has the smallest element
    // find just grater than nums[i-1] ele index;
    i--;

    int j = nums.size() - 1;
    while (nums[j] <= nums[i])
    {
        j--;
    }
    //swap i and j
    swap(nums[j], nums[i]);
    i++;
    sort(nums.begin() + i, nums.end());
    return;
}