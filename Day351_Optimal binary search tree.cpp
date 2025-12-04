// You are given a set of distinct keys in sorted order, which is represent by keys[]. Each key ki represents a data record that is accessed during a seach operation. For all the keys, you are also given a frequency array freq[], which denotes how many times key ki is searched for.
// The cost of accessing a key in a binary search tree is calculated by multiplying its access frequency by the level at which it appears in the tree. Therefore different arrangements of keys in the BST gives different total search costs.

// Your task is to calculate the minimum total search cost required to construct a binary search tree containing all the keys.

// Note: Consider the root of the BST is at level 1.

// Examples:

// Input: keys[] = [10, 12], freq[] = [34, 50]
// Output: 118
// Explaination: There can be following two possible BSTs

// The cost of tree I is 34*1 + 50*2 = 134
// The cost of tree II is 50*1 + 34*2 = 118
// Input: keys[] = [10, 12, 20], freq[] = [34, 8, 50]
// Output: 142
// Explaination: There can be many possible BSTs

// Among all possible BSTs,
// cost of the 5th BST is minimum.
// Cost of this BST is 1*50 + 2*34 + 3*8 = 142
class Solution
{
public:
    int minCost(vector<int> &keys, vector<int> &freq)
    {
        int n = keys.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        vector<vector<int>> sum(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
        {
            sum[i][i] = freq[i];
            for (int j = i + 1; j < n; j++)
            {
                sum[i][j] = sum[i][j - 1] + freq[j];
            }
        }
        for (int len = 1; len <= n; len++)
        {
            for (int i = 0; i + len - 1 < n; i++)
            {
                int j = i + len - 1;
                if (i == j)
                {
                    dp[i][j] = freq[i];
                    continue;
                }
                dp[i][j] = INT_MAX;
                for (int r = i; r <= j; r++)
                {
                    int left = (r > i) ? dp[i][r - 1] : 0;
                    int right = (r < j) ? dp[r + 1][j] : 0;
                    dp[i][j] = min(dp[i][j], left + right + sum[i][j]);
                }
            }
        }
        return dp[0][n - 1];
    }
};