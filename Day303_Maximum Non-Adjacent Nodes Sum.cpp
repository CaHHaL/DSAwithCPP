// Given the root of a binary tree with integer values. Your task is to select a subset of nodes such that the sum of their values is maximized, with the condition that no two selected nodes are directly connected that is, if a node is included in the subset, neither its parent nor its children can be included.

// Examples:

// Input: root = [11, 1, 2]

// Output: 11
// Explanation: The maximum sum is obtained by selecting the node 11.

// Input: root = [1, 2, 3, 4, N, 5, 6]

// Output: 16
// Explanation: The maximum sum is obtained by selecting the nodes 1, 4, 5 and 6, which are not directly connected to each other. Their total sum is 16.

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};
*/
class Solution
{
public:
    map<pair<Node *, int>, int> mp;
    int solve(Node *root, int take)
    {
        if (!root)
        {
            return 0;
        }
        if (mp.find({root, take}) != mp.end())
        {
            return mp[{root, take}];
        }
        int ans = 0;
        if (take == 1)
        {
            ans = root->data + solve(root->left, 0) + solve(root->right, 0);
            ans = max(ans, solve(root->left, 1) + solve(root->right, 1));
        }
        else
        {
            ans = max(ans, solve(root->left, 1) + solve(root->right, 1));
        }
        return mp[{root, take}] = ans;
    }
    int getMaxSum(Node *root)
    {
        mp.clear();
        return solve(root, 1);
    }
};