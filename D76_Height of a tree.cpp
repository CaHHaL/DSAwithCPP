// Given a binary tree, find its height.

// The height of a tree is defined as the number of edges on the longest path from the root to a leaf node. A leaf node is a node that does not have any children.

// Examples:

// Input: root[] = [12, 8, 18, 5, 11]

// Output: 2
// Explanation: One of the longest path from the root (node 12) goes through node 8 to node 5, which has 2 edges.
// Input: root[] = [1, 2, 3, 4, N, N, 5, N, N, 6, 7]

// Output: 3
// Explanation: The longest path from the root (node 1) to a leaf node 6 with 3 edge.

class Solution
{
public:
    int height(Node *node)
    {
        if (!node)
            return -1;
        return max(height(node->left), height(node->right)) + 1;
    }
};