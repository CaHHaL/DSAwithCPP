// Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Examples:
// Input: mat[][] = [[16, 28, 60, 64], k = 3
//                 [22, 41, 63, 91],
//                 [27, 50, 87, 93],
//                 [36, 78, 87, 94]]
// Output: 27
// Explanation: 27 is the 3rd smallest element.
// Input: mat[][] = [[10, 20, 30, 40], k = 7
//                 [15, 25, 35, 45],
//                 [24, 29, 37, 48],
//                 [32, 33, 39, 50]]
// Output: 30
// Explanation: 30 is the 7th smallest element.
// Constraints:
// 1 ≤ n ≤ 500
// 1 ≤ mat[i][j] ≤ 104
// 1 ≤ k ≤ n*n
class Solution
{
public:
    int kthSmallest(vector<vector<int>> &mat, int k)
    {
        int n = mat.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                temp.push_back(mat[i][j]);
            }
        }
        sort(temp.begin(), temp.end());
        return temp[k - 1];
    }
};