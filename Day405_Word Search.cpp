// You are given a matrix mat[][] of size n*m containing english alphabets and a string word. Check if the word exists on the mat[][] or not. The word can be constructed by using letters from adjacent cells, either horizontally or vertically. The same cell cannot be used more than once.

// Examples :

// Input: mat[][] = [['T', 'E', 'E'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: true
// Explanation: Word "GEEK" can be found in the given grid as follows.

// Input: mat[][] = [['T', 'E', 'U'], ['S', 'G', 'K'], ['T', 'E', 'L']], word = "GEEK"
// Output: false
// Explanation: Word "GEEK" cannot be found in the given grid.

// Input: mat[][] = [['A', 'B', 'A'], ['B', 'A', 'B']], word = "AB"
// Output: true
// Explanation: There are multiple ways to construct the word "AB".

// Constraints:
// 1 ≤ n, m ≤ 6
// 1 ≤ word.size() ≤ 15
// mat and word consists of only lowercase and uppercase English letters.
class Solution
{
public:
    bool isWordExist(vector<vector<char>> &board, string word)
    {
        int rows = board.size();
        int cols = board[0].size();
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < cols; ++j)
            {
                if (dfs(board, word, i, j, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }

private:
    bool dfs(vector<vector<char>> &board, const string &word, int i, int j, int index)
    {
        if (index == word.size())
        {
            return true;
        }
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || board[i][j] != word[index])
        {
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = dfs(board, word, i + 1, j, index + 1) ||
                     dfs(board, word, i - 1, j, index + 1) ||
                     dfs(board, word, i, j + 1, index + 1) ||
                     dfs(board, word, i, j - 1, index + 1);
        board[i][j] = temp;
        return found;
    }
};