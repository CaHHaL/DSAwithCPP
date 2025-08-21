// Given an array arr[] of integers and an integer k, select k elements from the array such that the minimum absolute difference between any two of the selected elements is maximized. Return this maximum possible minimum difference.

// Examples:

// Input: arr[] = [2, 6, 2, 5], k = 3
// Output: 1
// Explanation: 3 elements out of 4 elements are to be selected with a minimum difference as large as possible. Selecting 2, 2, 5 will result in minimum difference as 0. Selecting 2, 5, 6 will result in minimum difference as 6 - 5 = 1.
// Input: arr[] = [1, 4, 9, 0, 2, 13, 3], k = 4
// Output: 4
// Explanation: Selecting 0, 4, 9, 13 will result in minimum difference of 4, which is the largest minimum difference possible.

class Solution
{
public:
    bool solve(vector<int> &arr, int &mid, int &k)
    {
        int n = arr.size();
        int cnt = 1;
        int prev = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (arr[i] - prev >= mid)
            {
                cnt++;
                prev = arr[i];
            }
            if (cnt >= k)
                return true;
        }
        return false;
    }
    int maxMinDiff(vector<int> &arr, int k)
    {
        sort(arr.begin(), arr.end());
        int n = arr.size();
        int s = 0;
        int e = arr[n - 1] - arr[0];
        int ans = 0;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            if (solve(arr, mid, k))
            {
                ans = mid;
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
        return ans;
    }
};