#include<iostream>
using namespace std;

int minJumps(int arr[], int n)
{      
    int jump = 0;
    int i = 0;
    int temp_max = arr[0];
    int temp_index = 0;
    while (i < n)
    {
        if (arr[i] == 0 )
        {
            return -1;
        }
        // find max b/w  i and i+ a[i]
        if(arr[i] < n-i-1) 
        {   
            int j = i+1; // next index  
            while(j <= arr[i] + i )
            {
                if( temp_max < arr[j])
                {
                    temp_max = arr[j];
                    temp_index = j;
                }
                j++;
            }

        }
        else {  return ++jump; }   
        // if possible 
        //updete i
        jump++;
        i = temp_index;   
        
    }
    return -1;//no use
}
int minJumps1(int arr[], int n)
{
 
    // Base case: when source and
    // destination are same
    if (n == 1)
        return 0;
 
    // Traverse through all the points
    // reachable from arr[l]
    // Recursively, get the minimum number
    // of jumps needed to reach arr[h] from
    // these reachable points
    int res = INT_MAX;
    for (int i = n - 2; i >= 0; i--) {
        if (i + arr[i] >= n - 1) {
            int sub_res = minJumps(arr, i + 1);
            if (sub_res != INT_MAX)
                res = min(res, sub_res + 1);
        }
    }
 
    return res;
}
int minJumps2(int arr[], int n)
{
    // jumps[n-1] will hold the result
    int* jumps = new int[n];
    int i, j;
 
    if (n == 0 || arr[0] == 0)
        return INT_MAX;
 
    jumps[0] = 0;
 
    // Find the minimum number of jumps to reach arr[i]
    // from arr[0], and assign this value to jumps[i]
    for (i = 1; i < n; i++) {
        jumps[i] = INT_MAX;
        for (j = 0; j < i; j++) {
            if (i <= j + arr[j] && jumps[j] != INT_MAX) {
                jumps[i] = min(jumps[i], jumps[j] + 1);
                break;
            }
        }
    }
    return jumps[n - 1];
}

int minJumps3(int arr[], int n)
{
    // jumps[0] will hold the result
    int* jumps = new int[n];
    int min;
 
    // Minimum number of jumps needed
    // to reach last element from last
    // elements itself is always 0
    jumps[n - 1] = 0;
 
    // Start from the second element,
    // move from right to left and
    // construct the jumps[] array where
    // jumps[i] represents minimum number
    // of jumps needed to reach
    // arr[m-1] from arr[i]
    for (int i = n - 2; i >= 0; i--) {
        // If arr[i] is 0 then arr[n-1]
        // can't be reached from here
        if (arr[i] == 0)
            jumps[i] = INT_MAX;
 
        // If we can directly reach to
        // the end point from here then
        // jumps[i] is 1
        else if (arr[i] >= n - i - 1)
            jumps[i] = 1;
 
        // Otherwise, to find out the minimum
        // number of jumps needed to reach
        // arr[n-1], check all the points
        // reachable from here and jumps[]
        // value for those points
        else {
            // initialize min value
            min = INT_MAX;
 
            // following loop checks with all
            // reachable points and takes
            // the minimum
            for (int j = i + 1; j < n && j <= arr[i] + i; j++) {
                if (min > jumps[j])
                    min = jumps[j];
            }
 
            // Handle overflow
            if (min != INT_MAX)
                jumps[i] = min + 1;
            else
                jumps[i] = min; // or INT_MAX
        }
    }
 
    return jumps[0];
}

//4 // passed // by far best 
int minJumps4(int arr[], int n)
{
    int maxR = arr[0];
    int step = arr[0];
    int jump = 1;
    if(n==1) return 0;
    else if(arr[0]==0) return -1;
    else
    { // 1, 3, 6, 3, 2, 3, 6, 8, 9, 5 
        for(int i=1 ; i<n ; i++)
        {
            if(i == n-1){ return jump; }
            
            maxR = max(maxR, i+arr[i]);
            step --;
            if(step == 0)
            {
                jump++;
                if(i >= maxR) return -1;
            
            step = maxR-i;
            }
        }
    }
    
}
int main()
{
    int arr[] = { 1, 3, 6, 3, 2,
                  3, 6, 8, 9, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum number of jumps to";
    cout << " reach the end is " << minJumps(arr, n);
    return 0;
}