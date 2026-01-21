#include <bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> res;
    vector<int> min;
    min.push_back(-1);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                res.push_back(arr1[i]);
                arr2[j] = INT_MIN;
                break;
            }
        }
    }
    if (res.empty())
    {
        return min;
    }
    else
    {
        return res;
    }
}

// brute force

#include <bits/stdc++.h>
vector<int> findArrayIntersection(vector<int> &arr1, int n, vector<int> &arr2, int m)
{
    // Write your code here.
    vector<int> res;
    int j = 0;
    int i = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            res.push_back(arr1[i]);
            j++;
            i++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }

    return res;
}