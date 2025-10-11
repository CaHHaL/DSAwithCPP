// Given the root of a binary tree, your task is to find the maximum path sum. The path may start and end at any node in the tree.

// Examples:

// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

// Input: root[] = [-17, 11, 4, 20, -2, 10]
// Output: 31
// Explanation: Max path sum is represented using green colour nodes in the above binary tree.

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    int fun(Node *root, int &ans)
    {
        if (!root)
            return 0;
        int l = fun(root->left, ans);
        int r = fun(root->right, ans);
        int maxi = max({0, l, r});
        int t1 = (root->data) + maxi;
        int t2 = (root->data) + l + r;
        ans = max(ans, max(t1, t2));
        return maxi + (root->data);
    }
    int findMaxSum(Node *root)
    {
        int ans = INT_MIN;
        fun(root, ans);
        return ans;
    }
};