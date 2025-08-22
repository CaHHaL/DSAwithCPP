// Given a row-wise sorted matrix mat[][] of size n*m, where the number of rows and columns is always odd. Return the median of the matrix.

// Examples:

// Input: mat[][] = [[1, 3, 5],
//                 [2, 6, 9],
//                 [3, 6, 9]]
// Output: 5
// Explanation: Sorting matrix elements gives us [1, 2, 3, 3, 5, 6, 6, 9, 9]. Hence, 5 is median.
// Input: mat[][] = [[2, 4, 9],
//                 [3, 6, 7],
//                 [4, 7, 10]]
// Output: 6
// Explanation: Sorting matrix elements gives us [2, 3, 4, 4, 6, 7, 7, 9, 10]. Hence, 6 is median.
// Input: mat = [[3], [4], [8]]
// Output: 4
// Explanation: Sorting matrix elements gives us [3, 4, 8]. Hence, 4 is median.
class Solution
{
public:
    int count(vector<vector<int>> mat, int mid)
    {
        int count = 0;
        for (int i = 0; i < mat.size(); i++)
        {
            count += upper_bound(mat[i].begin(), mat[i].end(), mid) - mat[i].begin();
        }
        return count;
    }
    int median(vector<vector<int>> &mat)
    {
        int r = mat.size();
        int c = mat[0].size();
        int mini = mat[0][0];
        int maxi = mat[0][c - 1];
        for (int i = 0; i < r; i++)
        {
            mini = min(mini, mat[i][0]);
            maxi = max(maxi, mat[i][c - 1]);
        }
        int ans = -1;
        int low = mini;
        int high = maxi;
        int medianval = (r * c) / 2;
        while (low <= high)
        {
            int mid = low + (high - low) / 2;
            int smallerequals = count(mat, mid);
            if (smallerequals < medianval + 1)
            {
                low = mid + 1;
            }
            else
            {
                ans = mid;
                high = mid - 1;
            }
        }
        return ans;
    }
};