// Given two binary arrays, a1[] and a2[]. Find the length of longest common span (i, j) where j>= i such that a1[i] + a1[i+1] + .... + a1[j] =  a2[i] + a2[i+1] + ... + a2[j].

// Examples:

// Input: a1[] = [0, 1, 0, 0, 0, 0], a2[] = [1, 0, 1, 0, 0, 1]
// Output: 4
// Explanation: The longest span with same sum is from index 1 to 4 following zero based indexing.
// Input: a1[] = [0, 1, 0, 1, 1, 1, 1], a2[] = [1, 1, 1, 1, 1, 0, 1]
// Output: 6
// Explanation: The longest span with same sum is from index 1 to 6 following zero based indexing.

class Solution
{
public:
    int longestCommonSum(vector<int> &a1, vector<int> &a2)
    {
        int n = a1.size();
        unordered_map<int, int> mp;
        int sum1 = 0, sum2 = 0, result = 0;

        for (int i = 0; i < n; i++)
        {
            sum1 += a1[i];
            sum2 += a2[i];
            int diff = sum1 - sum2;

            if (diff == 0)
            {
                result = max(result, i + 1);
            }
            else if (mp.count(diff))
            {
                result = max(result, i - mp[diff]);
            }
            else
            {
                mp[diff] = i;
            }
        }
        return result;
    }
};