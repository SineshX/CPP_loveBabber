#include <iostream>
#include <vector>
#include <numeric> 
using namespace std;

int findDuplicate1(vector<int> &nums)
{
    int sum = accumulate(nums.begin(), nums.end(), 0);
    int n = nums.size();
    int duplicate = sum - (((n -1) * n ) / 2);
    return duplicate;
    // will fail at : [2,2,2,2,2]
}
//marker approad 
// it will also modify the array

int findDuplicate2(vector<int> &nums)
{   //worked 
    int n = nums.size();
    int temp;
    for(int i = 0;i<n;i++)
    {   
        temp = nums[abs(nums[i])];
        if(temp > 0)
        {   // array modified 
            nums[abs(nums[i])] *= (-1);
        }else{//neg
            return abs(nums[i]); 
        }
    }
    return 0;//-1
}
int findDuplicate3(vector<int> &nums)
{   
    for(int i = 0,n= nums.size() ; i < n-1;i++)
    {
        for(int j = i+1; j<n ; j++)
        {
            if(nums[i] == nums[j]) return nums[i];

        }
    }
    return 0;//-1
}
// runner approach // ref : medium article
int findDuplicate4(vector<int> &nums)
{
    int slow = nums[0];
    int fast = nums[nums[0]];
    while(slow != fast) 
    {
        slow = nums[slow];
        fast = nums[nums[fast]];
    }

    slow = 0;
    while(slow != fast)
    {
        slow = nums[slow];
        fast = nums[fast];
    }
    return slow;

}
int main()
{
    vector<int> nums = { 1, 2, 3, 1, 3, 6, 6 };
    int duplicate = findDuplicate3(nums);
    cout <<duplicate<< endl;
    return 0;
}