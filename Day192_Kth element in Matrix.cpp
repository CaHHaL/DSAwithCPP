// Given a matrix mat[][] of size n*n, where each row and column is sorted in non-decreasing order. Find the kth smallest element in the matrix.

// Examples:
// Input: n = 4, mat[][] = [[16, 28, 60, 64], [22, 41, 63, 91], [27, 50, 87, 93], [36, 78, 87, 94]], k = 3
// Output: 27
// Explanation: 27 is the 3rd smallest element.
// Input: n = 4, mat[][] = [[10, 20, 30, 40], [15, 25, 35, 45], [24, 29, 37, 48], [32, 33, 39, 50]], k = 7
// Output: 30
// Explanation: 30 is the 7th smallest element.

class Solution
{
public:
    int count(vector<vector<int>> &matrix, int ele)
    {
        int n = matrix.size();
        int cnt = 0;
        int r = 0;
        int c = n - 1;
        while (r < n && c >= 0)
        {
            if (matrix[r][c] <= ele)
            {
                cnt += c + 1;
                r++;
            }
            else
                c--;
        }
        return cnt;
    }
    int kthSmallest(vector<vector<int>> &matrix, int k)
    {
        int n = matrix.size();
        int s = matrix[0][0];
        int e = matrix[n - 1][n - 1];
        int ans = 0;
        while (s <= e)
        {
            int mid = s + (e - s) / 2;
            int cnt = count(matrix, mid);

            if (cnt < k)
                s = mid + 1;
            else
            {
                ans = mid;
                e = mid - 1;
            }
        }
        return ans;
    }
};