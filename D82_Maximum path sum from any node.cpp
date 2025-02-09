// Given a binary tree, the task is to find the maximum path sum. The path may start and end at any node in the tree.

// Examples:

// Input: root[] = [10, 2, 10, 20, 1, N, -25, N, N, N, N, 3, 4]
// Output: 42
// Explanation:

// Max path sum is represented using green colour nodes in the above binary tree.
// Input: root[] = [-17, 11, 4, 20, -2, 10]
// Output: 31
// Explanation:

// Max path sum is represented using green colour nodes in the above binary tree.

class Solution
{
public:
    int solve(Node *root, int &maxi)
    {
        if (!root)
            return 0;
        int leftSum = solve(root->left, maxi);
        int rightSum = solve(root->right, maxi);
        if (leftSum > 0 && rightSum > 0)
            maxi = max(maxi, root->data + leftSum + rightSum);
        else if (leftSum < 0 && rightSum < 0)
            maxi = max(maxi, root->data);
        else
            maxi = max(maxi, root->data + max(leftSum, rightSum));

        return max(0, root->data + max(leftSum, rightSum));
    }
    int findMaxSum(Node *root)
    {
        int maxi = INT_MIN;
        solve(root, maxi);
        return maxi;
    }
};