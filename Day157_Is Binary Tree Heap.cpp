// You are given a binary tree, and the task is to determine whether it satisfies the properties of a max-heap.

// A binary tree is considered a max-heap if it satisfies the following conditions:

// Completeness: Every level of the tree, except possibly the last, is completely filled, and all nodes are as far left as possible.
// Max-Heap Property: The value of each node is greater than or equal to the values of its children.
// Examples:

// Input: root[] = [97, 46, 37, 12, 3, 7, 31, 6, 9]

// Output: true
// Explanation: The tree is complete and satisfies the max-heap property.
// Input: root[] = [97, 46, 37, 12, 3, 7, 31, N, 2, 4]

// Output: false
// Explanation: The tree is not complete and does not follow the Max-Heap Property, hence it is not a max-heap.

class Solution
{
public:
    int count(Node *tree)
    {
        if (!tree)
            return 0;
        return 1 + count(tree->left) + count(tree->right);
    }
    bool solve(Node *tree, int i, int total)
    {
        if (!tree)
            return true;
        if (i >= total)
            return false;
        if (tree->left && tree->data < tree->left->data)
            return false;
        if (tree->right && tree->data < tree->right->data)
            return false;
        return solve(tree->left, 2 * i + 1, total) && solve(tree->right, 2 * i + 2, total);
    }
    bool isHeap(Node *tree)
    {
        int total = count(tree);
        return solve(tree, 0, total);
    }
};