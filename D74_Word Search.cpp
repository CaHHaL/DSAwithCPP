// You are given a two-dimensional mat[][] of size n*m containing English alphabets and a string word. Check if the word exists on the mat. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

// Examples :

// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true
// Explanation:

// The letter cells which are used to construct the "GEEK" are colored.

class Solution
{
public:
    bool solve(vector<vector<char>> &mat, string &word, int i, int j, int idx, vector<vector<bool>> &vis)
    {
        if (idx == word.length())
            return true;
        if (i < 0 || j < 0 || i >= mat.size() || j >= mat[0].size() || vis[i][j] || mat[i][j] != word[idx])
            return false;
        vis[i][j] = true;
        if (solve(mat, word, i - 1, j, idx + 1, vis) || solve(mat, word, i + 1, j, idx + 1, vis) || solve(mat, word, i, j - 1, idx + 1, vis) || solve(mat, word, i, j + 1, idx + 1, vis))
            return true;
        vis[i][j] = false;
        return false;
    }
    bool isWordExist(vector<vector<char>> &mat, string &word)
    {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<bool>> vis(n, vector<bool>(m, false));
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (mat[i][j] == word[0])
                {
                    if (solve(mat, word, i, j, 0, vis))
                        return true;
                }
            }
        }
        return false;
    }
};