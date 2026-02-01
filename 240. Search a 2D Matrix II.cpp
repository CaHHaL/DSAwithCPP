class Solution
{
public:
    bool searchMatrix(vector<vector<int>> &matrix, int target)
    {
        int row = matrix.size();
        int col = matrix[0].size();

        int rowi = 0;
        int coli = col - 1;

        while (rowi < row && coli >= 0)
        {
            if (matrix[rowi][coli] == target)
            {
                return 1;
            }
            else if (matrix[rowi][coli] < target)
            {
                rowi++;
            }
            else
            {
                coli--;
            }
        }
        return 0;
    }
};