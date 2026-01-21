#include <bits/stdc++.h>
vector<vector<int>> findTriplets(vector<int> arr, int n, int K)
{
    // Write your code here.
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 2; i++)
    {
        for (int j = i + 1; j < arr.size() - 1; j++)
        {
            for (int l = j + 1; l < arr.size(); l++)
            {
                if (arr[i] + arr[j] + arr[l] == K)
                {
                    vector<int> temp = {arr[i], arr[j], arr[l]};
                    // temp.push_back(arr[i]);
                    // temp.push_back(arr[j]);
                    // temp.push_back(arr[l]);
                    ans.push_back(temp);
                }
            }
        }
    }
    set<vector<int>> s(ans.begin(), ans.end());
    ans.assign(s.begin(), s.end());

    return ans;
}