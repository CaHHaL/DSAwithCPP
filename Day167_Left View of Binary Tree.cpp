// You are given the root of a binary tree. Your task is to return the left view of the binary tree. The left view of a binary tree is the set of nodes visible when the tree is viewed from the left side.

// If the tree is empty, return an empty list.

// Examples :

// Input: root[] = [1, 2, 3, 4, 5, N, N]

// Output: [1, 2, 4]
// Explanation: From the left side of the tree, only the nodes 1, 2, and 4 are visible.

// Input: root[] = [1, 2, 3, N, N, 4, N, N, 5, N, N]

// Output: [1, 2, 4, 5]
// Explanation: From the left side of the tree, the nodes 1, 2, 4, and 5 are visible.

// Input: root[] = [N]
// Output: []

class Solution
{
public:
    void solve(Node *root, vector<int> &ans, int level)
    {
        if (!root)
            return;
        if (ans.size() == level)
            ans.push_back(root->data);
        solve(root->left, ans, level + 1);
        solve(root->right, ans, level + 1);
    }
    vector<int> leftView(Node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};