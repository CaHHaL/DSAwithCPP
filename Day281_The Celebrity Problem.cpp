// A celebrity is a person who is known to all but does not know anyone at a party. A party is being organized by some people. A square matrix mat[][] of size n*n is used to represent people at the party such that if an element of row i and column j is set to 1 it means ith person knows jth person. You need to return the index of the celebrity in the party, if the celebrity does not exist, return -1.

// Note: Follow 0-based indexing.

// Examples:

// Input: mat[][] = [[1, 1, 0],
//                 [0, 1, 0],
//                 [0, 1, 1]]
// Output: 1
// Explanation: 0th and 2nd person both know 1st person and 1st person does not know anyone. Therefore, 1 is the celebrity person.
// Input: mat[][] = [[1, 1],
//                 [1, 1]]
// Output: -1
// Explanation: Since both the people at the party know each other. Hence none of them is a celebrity person.
// Input: mat[][] = [[1]]
// Output: 0

class Solution
{
public:
    int celebrity(vector<vector<int>> &mat)
    {
        int n = mat.size();
        int m = mat[0].size();
        for (int i = 0; i < n; i++)
        {
            bool flag = true;
            for (int j = 0; j < n; j++)
            {
                if (i == j)
                    continue;
                if ((mat[i][j] == 1 || mat[j][i] == 0))
                {
                    flag = false;
                    break;
                }
            }
            if (flag)
                return i;
        }
        return -1;
    }
};