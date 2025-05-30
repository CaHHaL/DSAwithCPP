// Given the root of a binary search tree and a number k, find the greatest number in the binary search tree that is less than or equal to k.

// Examples:

// Input: root = [10, 7, 15, 2, 8, 11, 16], k = 14

// Output: 11
// Explanation: The greatest element in the tree which is less than or equal to 14, is 11.
// Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 24

// Output: 21
// Explanation: The greatest element in the tree which is less than or equal to 24, is 21.
// Input: root = [5, 2, 12, 1, 3, 9, 21, N, N, N, N, N, N, 19, 25], k = 4

// Output: 3
// Explanation: The greatest element in the tree which is less than or equal to 4, is 3.

class Solution
{
public:
    int findMaxFork(Node *root, int k)
    {
        int ans = -1;
        Node *curr = root;
        while (curr)
        {
            if (curr->data <= k)
            {
                ans = curr->data;
                curr = curr->right;
            }
            else
            {
                curr = curr->left;
            }
        }
        return ans;
    }
};