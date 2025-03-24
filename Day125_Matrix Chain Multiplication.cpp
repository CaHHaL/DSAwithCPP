// Given an array arr[] which represents the dimensions of a sequence of matrices where the ith matrix has the dimensions (arr[i-1] x arr[i]) for i>=1, find the most efficient way to multiply these matrices together. The efficient way is the one that involves the least number of multiplications.

// Examples:

// Input: arr[] = [2, 1, 3, 4]
// Output: 20
// Explanation: There are 3 matrices of dimensions 2 × 1, 1 × 3, and 3 × 4, Let this 3 input matrices be M1, M2, and M3. There are two ways to multiply: ((M1 x M2) x M3) and (M1 x (M2 x M3)), note that the result of (M1 x M2) is a 2 x 3 matrix and result of (M2 x M3) is a 1 x 4 matrix.
// ((M1 x M2) x M3)  requires (2 x 1 x 3) + (2 x 3 x 4) = 30
// (M1 x (M2 x M3))  requires (1 x 3 x 4) + (2 x 1 x 4) = 20.
// The minimum of these two is 20.
// Input: arr[] = [1, 2, 3, 4, 3]
// Output: 30
// Explanation: There are 4 matrices of dimensions 1 × 2, 2 × 3, 3 × 4, 4 × 3. Let this 4 input matrices be M1, M2, M3 and M4. The minimum number of multiplications are obtained by ((M1 x M2) x M3) x M4). The minimum number is (1 x 2 x 3) + (1 x 3 x 4) + (1 x 4 x 3) = 30.
// Input: arr[] = [3, 4]
// Output: 0
// Explanation: As there is only one matrix so, there is no cost of multiplication.

class Solution
{
public:
    int helper(int start, int end, vector<int> &arr, vector<vector<int>> &dp)
    {
        if (end - start == 1)
            return 0;
        if (dp[start][end] != -1)
            return dp[start][end];
        int ans = INT_MAX;
        for (int k = start + 1; k < end; k++)
        {
            int left = helper(start, k, arr, dp);
            int right = helper(k, end, arr, dp);
            ans = min(ans, left + right + arr[start] * arr[k] * arr[end]);
        }
        return dp[start][end] = ans;
    }
    int matrixMultiplication(vector<int> &arr)
    {
        int n = arr.size();
        vector<vector<int>> dp(n, vector<int>(n, -1));
        return helper(0, n - 1, arr, dp);
    }
};