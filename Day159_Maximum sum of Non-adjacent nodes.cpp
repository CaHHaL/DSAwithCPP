// Given a binary tree with a value associated with each node. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root[] = [11, 1, 2]

// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.

// Input: root[] = [1, 2, 3, 4, N, 5, 6]

// Output: 16
// Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5, and 6, which are not directly connected to each other. Their total sum is 16.

class Solution
{
public:
    pair<int, int> solve(Node *root)
    {
        if (!root)
            return {0, 0};
        auto l = solve(root->left);
        auto r = solve(root->right);

        int include = root->data + l.second + r.second;
        int exclude = max(l.first, l.second) + max(r.first, r.second);
        return {include, exclude};
    }
    int getMaxSum(Node *root)
    {
        auto ans = solve(root);
        return max(ans.first, ans.second);
    }
};
