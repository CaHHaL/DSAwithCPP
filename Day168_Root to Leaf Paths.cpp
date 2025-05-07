// Given a Binary Tree, you need to find all the possible paths from the root node to all the leaf nodes of the binary tree.

// Note: The paths should be returned such that paths from the left subtree of any node are listed first, followed by paths from the right subtree.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5, N, N]
// ex-3
// Output: [[1, 2, 4], [1, 2, 5], [1, 3]]
// Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 -> 4, 1 -> 2 -> 5 and 1 -> 3
// Input: root[] = [1, 2, 3]

// Output: [[1, 2], [1, 3]]
// Explanation: All the possible paths from root node to leaf nodes are: 1 -> 2 and 1 -> 3
// Input: root[] = [10, 20, 30, 40, 60, N, N]

// Output: [[10, 20, 40], [10, 20, 60], [10, 30]]
// Explanation: All the possible paths from root node to leaf nodes are: 10 -> 20 -> 40, 10 -> 20 -> 60 and 10 -> 30

class Solution
{
public:
    void solve(Node *root, vector<vector<int>> &ans, vector<int> path)
    {
        if (!root)
        {
            return;
        }
        path.push_back(root->data);
        if (root->left == NULL and root->right == NULL)
        {
            ans.push_back(path);
            return;
        }
        solve(root->left, ans, path);
        solve(root->right, ans, path);
    }
    vector<vector<int>> Paths(Node *root)
    {
        vector<vector<int>> ans;
        vector<int> path;
        solve(root, ans, path);
        return ans;
    }
};