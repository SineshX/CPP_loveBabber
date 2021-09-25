#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void print2DVector(vector<vector<int>> &vect)
{ // Number of rows;
    int m = vect.size();
    // Number of columns
    int n = vect[0].size();

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << vect[i][j] << " ";
        cout << endl;
    }
}
/*

Runtime: 16 ms, faster than 90.32% of C++ online submissions for Merge Intervals.
Memory Usage: 14.2 MB, less than 57.27% of C++ online submissions for Merge Intervals.
*/
vector<vector<int>> merge(vector<vector<int>> &interval)
{
    if (interval.empty())
        return interval;
    // to store
    vector<vector<int>> res;
    // to sort
    sort(interval.begin(), interval.end());
    // print2DVector(interval);
    // cout << endl;

    res.push_back(interval[0]);
    for (int i = 1, n = interval.size(), j = 0; i < n; i++)
    {
        if (res[j].back() < interval[i].front())
        {
            res.push_back(interval[i]);
            j++;
        }
        else
        {
            res[j].back() = max(res[j].back(), interval[i].back());
        }
    }
    return res;
}

int main()
{
    vector<vector<int>> interval = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};

    vector<vector<int>> res = merge(interval);
    print2DVector(res);
    cout << endl;
    cout << res.size() << endl;
    return 0;
}