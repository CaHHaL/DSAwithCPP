// Given an positive integer n, find a subset of numbers from 1 to n (inclusive), where each number can be used at most once, such that:

// The XOR of all elements in the subset is exactly n.
// The size of the subset is as large as possible.
// If multiple such subsets exist, choose the lexicographically smallest one.
// Lexicographical Order : A subset A[] is lexicographically smaller than subset B[] if at the first index where they differ, A[i] < B[i] (based on character ASCII/Unicode values).
// If all elements match but one subset ends earlier, the shorter subset is considered smaller.

// Examples:

// Input: n = 4
// Output: [1, 2, 3, 4]
// Explanation: We choose all the elements from 1 to 4. Its xor value is equal to n. This is the maximum possible size of the subset.
// Input: n = 3
// Output: [1, 2]
// Explanation: 1 ^ 2 = 3, This is the smallest lexicographical answer possible with maximum size of subset i.e 2.
// Constraints:
// 1 ≤ n ≤ 105
class Solution
{
public:
    vector<int> subsetXOR(int n)
    {
        int maxxor = 0;
        for (int i = 1; i <= n; i++)
        {
            maxxor ^= i;
        }
        vector<int> ans(n);
        if (maxxor == n)
        {
            for (int i = 1; i <= n; i++)
            {
                ans[i - 1] = i;
            }
            return ans;
        }
        vector<int> a;
        for (int i = n; i > 0; i--)
        {
            int curr = maxxor ^ i;
            if ((maxxor != n) && (curr == n))
            {
                maxxor ^= i;
                continue;
            }
            else
            {
                a.push_back(i);
            }
        }
        reverse(a.begin(), a.end());
        return a;
    }
};