// You are given an array arr[] of positive integers and an integer k. You have to count the number of subarrays that contain exactly k odd numbers.

// Examples:

// Input: arr[] = [2, 5, 6, 9], k = 2
// Output: 2
// Explanation: There are 2 subarrays with 2 odds: [2, 5, 6, 9] and [5, 6, 9].
// Input: arr[] = [2, 2, 5, 6, 9, 2, 11], k = 2
// Output: 8
// Explanation: There are 8 subarrays with 2 odds: [2, 2, 5, 6, 9], [2, 5, 6, 9], [5, 6, 9], [2, 2, 5, 6, 9, 2], [2, 5, 6, 9, 2], [5, 6, 9, 2], [6, 9, 2, 11] and [9, 2, 11].
// Constraint:
// 1 ≤ k ≤ arr.size() ≤ 105
// 1 ≤ arr[i] ≤ 109
class Solution
{
public:
    int count(vector<int> &nums, int k)
    {
        int ans = 0;
        int odd = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++)
        {
            if (nums[j] % 2 != 0)
                odd++;
            while (odd > k)
            {
                if (nums[i] % 2 != 0)
                    odd--;
                i++;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
    int countSubarrays(vector<int> &arr, int k)
    {
        return count(arr, k) - count(arr, k - 1);
    }
};