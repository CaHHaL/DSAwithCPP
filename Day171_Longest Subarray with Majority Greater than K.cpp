// Given an array arr[] and an integer k, the task is to find the length of longest subarray in which the count of elements greater than k is more than the count of elements less than or equal to k.

// Examples:

// Input: arr[] = [1, 2, 3, 4, 1], k = 2
// Output: 3
// Explanation: The subarray [2, 3, 4] or [3, 4, 1] satisfy the given condition, and there is no subarray of length 4 or 5 which will hold the given condition, so the answer is 3.
// Input: arr[] = [6, 5, 3, 4], k = 2
// Output: 4
// Explanation: In the subarray [6, 5, 3, 4], there are 4 elements > 2 and 0 elements <= 2, so it is the longest subarray.

class Solution
{
public:
    int longestSubarray(vector<int> &arr, int k)
    {
        unordered_map<int, int> mp;
        mp[0] = -1;
        int prefixsum = 0, maxlen = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            prefixsum += (arr[i] > k) ? 1 : -1;
            if (prefixsum > 0)
                maxlen = i + 1;

            if (mp.count(prefixsum - 1))
            {
                maxlen = max(maxlen, i - mp[prefixsum - 1]);
            }

            if (!mp.count(prefixsum))
                mp[prefixsum] = i;
        }
        return maxlen;
    }
};