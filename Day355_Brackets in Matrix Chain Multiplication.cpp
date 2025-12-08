// Given an array arr[] of length n used to denote the dimensions of a series of matrices such that the dimension of i'th matrix is arr[i] * arr[i+1]. There are a total of n-1 matrices. Find the most efficient way to multiply these matrices together.
// Your task is to return the string which is formed of A - Z (only Uppercase) denoting matrices & Brackets( "(" ")" ) denoting multiplication symbols. For example, if n = 11, the matrixes can be denoted as A - K as n <= 26 & multiplication of A and B is denoted as (AB).

// NOTE:

// Each multiplication is denoted by putting open & closed brackets to the matrices multiplied & also, please note that the order of matrix multiplication matters, as matrix multiplication is non-commutative A*B != B*A
// As there can be multiple possible answers, the console would print "true" for the correct string and "false" for the incorrect string. You need to only return a string that performs a minimum number of multiplications.
// Examples:

// Input: arr[] = [40, 20, 30, 10, 30]
// Output: true
// Explanation: Let's divide this into matrix(only 4 are possible) [ [40, 20] -> A, [20, 30] -> B, [30, 10] -> C, [10, 30] -> D ]
// First we perform multiplication of B & C -> (BC), then we multiply A to (BC) -> (A(BC)), then we multiply D to (A(BC)) -> ((A(BC))D)
// So the solution returned the string ((A(BC))D), which performs minimum multiplications. The total number of multiplications are 20*30*10 + 40*20*10 + 40*10*30 = 26,000.
// Input: arr[] = [10, 20, 30]
// Output: true
// Explanation: There is only one way to multiply two matrices: (AB): The cost for the multiplication will be 6000
// Input: arr = [10, 20, 30, 40]
// Output: true
// Explanation: There are two possible ways to multiply three matrices:
// ((AB)C): The cost for the multiplication will be 18,000
// (A(BC)): The cost for the multiplication will be 32,000
// So the solution returned the string ((AB)C), which performs minimum multiplications.
// Constraints:
// 2 ≤ arr.size() ≤ 50
// 1 ≤ arr[i] ≤ 100

class Solution
{
private:
    string build(int i, int j, vector<vector<int>> &split)
    {
        if (i == j)
            return string(1, 'A' + i);
        int k = split[i][j];
        return "(" + build(i, k, split) + build(k + 1, j, split) + ")";
    }

public:
    string matrixChainOrder(vector<int> &arr)
    {
        int n = arr.size();
        int m = n - 1;
        vector<vector<long long>> dp(m, vector<long long>(m, 0));
        vector<vector<int>> split(m, vector<int>(m, -1));
        for (int len = 2; len <= m; len++)
        {
            for (int i = 0; i + len - 1 < m; i++)
            {
                int j = i + len - 1;
                dp[i][j] = LLONG_MAX;
                for (int k = i; k < j; k++)
                {
                    long long cost = dp[i][k] + dp[k + 1][j] + 1LL * arr[i] * arr[k + 1] * arr[j + 1];
                    if (cost < dp[i][j])
                    {
                        dp[i][j] = cost;
                        split[i][j] = k;
                    }
                }
            }
        }
        return build(0, m - 1, split);
    }
};