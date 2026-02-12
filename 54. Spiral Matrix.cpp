class Solution
{
public:
    vector<int> spiralOrder(vector<vector<int>> &matrix)
    {
        vector<int> ans;
        int rows = matrix.size();
        int cols = matrix[0].size();

        int total = rows * cols;

        int rst = 0;
        int rend = rows - 1;
        int cst = 0;
        int cend = cols - 1;
        int cnt = 0;
        while (cnt < total)
        {
            for (int i = cst; i <= cend && cnt < total; i++)
            {
                ans.push_back(matrix[rst][i]);
                cnt++;
            }
            rst++;
            for (int i = rst; i <= rend && cnt < total; i++)
            {
                ans.push_back(matrix[i][cend]);
                cnt++;
            }
            cend--;
            for (int i = cend; i >= cst && cnt < total; i--)
            {
                ans.push_back(matrix[rend][i]);
                cnt++;
            }
            rend--;
            for (int i = rend; i >= rst && cnt < total; i--)
            {
                ans.push_back(matrix[i][cst]);
                cnt++;
            }
            cst++;
        }
        return ans;
    }
};