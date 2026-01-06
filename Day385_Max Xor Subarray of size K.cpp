// Given an array of integers arr[]  and a number k. Return the maximum xor of a subarray of size k.

// Note: A subarray is a contiguous part of any given array.

// Examples:

// Input: arr[] = [2, 5, 8, 1, 1, 3], k = 3
// Output: 15
// Explanation: arr[0] ^ arr[1] ^ arr[2] = 15, which is maximum.
// Input: arr[] = [1, 2, 4, 5, 6] , k = 2
// Output: 6
// Explanation: arr[1] ^ arr[2] = 6, which is maximum.
// Constraints:
// 1 ≤ arr.size() ≤ 106
// 0 ≤ arr[i] ≤ 106
// 1 ≤ k ≤ arr.size()

class Solution
{
public:
    int maxSubarrayXOR(vector<int> &arr, int k)
    {
        int ans = 0;
        int init = 0, last = 0;
        int curr = 0, cnt = 0;
        for (int i = 0; i < arr.size(); i++)
        {
            last = i;
            cnt = last - init + 1;
            curr ^= arr[i];
            if (cnt == k)
            {
                ans = max(curr, ans);
                curr ^= arr[init];
                init++;
            }
        }
        return ans;
    }
};