#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s)
{
    // Write your code here.
    vector<vector<int>> res;
    for (int i = 0; i < arr.size() - 1; i++)
    {
        for (int j = i + 1; j < arr.size(); j++)
        {
            if (arr[i] + arr[j] == s)
            {
                vector<int> tmp;
                tmp.push_back(min(arr[i], arr[j]));
                tmp.push_back(max(arr[i], arr[j]));
                res.push_back(tmp);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}