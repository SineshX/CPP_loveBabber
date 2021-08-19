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

// for sorting on basis of 1nd column
bool sortcol(const vector<int> &v1,
             const vector<int> &v2)
{
    return v1[0] < v2[0];
}

vector<vector<int>> merge(vector<vector<int>> &intervals)
{
    // vector<vector<int>> v;
    int n = intervals.size(), i = 0;
    // Use of "sort()" for sorting on basis of 1nd column
    sort(intervals.begin(), intervals.end(), sortcol);
    //class wala 
    /*
    sort(intervals.begin(), intervals.end(), [this] (vector<int> v1, vector<int> v2) 
                                                    {return v1[0] < v2[0];}  );
    */
    // print2DVector(intervals);

    while (i < n - 1)
    {
        if (intervals[i + 1][0] >= intervals[i][0] && intervals[i + 1][0] <= intervals[i][1])
        {
            // starting point as it is
            //update end ponit max(last of arr1, last of arr2)
            intervals[i][1] = max(intervals[i][1], intervals[i + 1][1]);
            //TODO delete i+1 th element // also n--
            intervals.erase(intervals.begin() + i + 1);
            n--;
        }
        else
        {
            i++;
        }
    }

    return intervals;
}
int main()
{
    vector<vector<int>> intervals = {{6, 8}, {1, 9}, {2, 4}, {4, 7}};

    merge(intervals);
    // for (int i = 0; i < intervals.size(); i++)
    // {
    //     cout << intervals[i][0] << "," << intervals[i][1] << endl;
    // }
    // print2DVector(intervals);
    // cout << endl;
    print2DVector(intervals);
    cout << intervals.size() << endl;
    return 0;
}