// Given an unsorted array arr[] of integers, find the number of subarrays whose sum exactly equal to a given number k.

// Examples:

// Input: arr[] = [10, 2, -2, -20, 10], k = -10
// Output: 3
// Explaination: Subarrays: arr[0...3], arr[1...4], arr[3...4] have sum exactly equal to -10.
// Input: arr[] = [9, 4, 20, 3, 10, 5], k = 33
// Output: 2
// Explaination: Subarrays: arr[0...2], arr[2...4] have sum exactly equal to 33.
// Input: arr[] = [1, 3, 5], k = 0
// Output: 0
// Explaination: No subarray with 0 sum.

class Solution
{
public:
    int cntSubarrays(vector<int> &arr, int k)
    {
        int ans = 0, sum = 0, n = arr.size();
        unordered_map<int, int> mp;
        mp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            sum += arr[i];
            ans += mp[sum - k];
            mp[sum]++;
        }
        return ans;
    }
};