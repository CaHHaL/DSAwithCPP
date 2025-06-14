// Given the root of a binary tree, check whether it is symmetric, i.e., whether the tree is a mirror image of itself.

// A binary tree is symmetric if the left subtree is a mirror reflection of the right subtree.

// Examples:

// Input: root[] = [1, 2, 2, 3, 4, 4, 3]
//    ex-1_1
// Output: True
// Explanation: As the left and right half of the above tree is mirror image, tree is symmetric.
// Input: root[] = [1, 2, 2, N, 3, N, 3]
//    ex-2_1
// Output: False
// Explanation:  As the left and right half of the above tree is not the mirror image, tree is not symmetric.

class Solution
{
public:
    bool solve(Node *left, Node *right)
    {
        if (left == NULL || right == NULL)
            return left == right;
        if (left->data != right->data)
            return false;
        return solve(left->left, right->right) && solve(left->right, right->left);
    }
    bool isSymmetric(Node *root)
    {
        Node *left = root->left;
        Node *right = root->right;
        return solve(left, right);
    }
};