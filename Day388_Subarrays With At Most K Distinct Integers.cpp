// You are given an array arr[] of positive integers and an integer k, find the number of subarrays in arr[] where the count of distinct integers is at most k.

// Note: A subarray is a contiguous part of an array.

// Examples:

// Input: arr[] = [1, 2, 2, 3], k = 2
// Output: 9
// Explanation: Subarrays with at most 2 distinct elements are: [1], [2], [2], [3], [1, 2], [2, 2], [2, 3], [1, 2, 2] and [2, 2, 3].
// Input: arr[] = [1, 1, 1], k = 1
// Output: 6
// Explanation: Subarrays with at most 1 distinct element are: [1], [1], [1], [1, 1], [1, 1] and [1, 1, 1].
// Input: arr[] = [1, 2, 1, 1, 3, 3, 4, 2, 1], k = 2
// Output: 24
// Explanation: There are 24 subarrays with at most 2 distinct elements.
// Constraints:
// 1 ≤ arr.size() ≤ 2*104
// 1 ≤ k ≤ 2*104
// 1 ≤ arr[i] ≤ 109
class Solution
{
public:
    int countAtMostK(vector<int> &s, int k)
    {
        unordered_map<int, int> m;
        int end = 0, ans = 0;
        int start = 0;
        while (end < s.size())
        {
            m[s[end]]++;
            while (start <= end && m.size() > k)
            {
                m[s[start]]--;
                if (m[s[start]] == 0)
                    m.erase(s[start]);
                start++;
            }
            ans += end - start + 1;
            end++;
        }
        return ans;
    }
};