// You are given a Binary Search Tree (BST) containing unique positive integers greater than 0.

// Your task is to determine whether the BST contains a dead end.

// Note: A dead end is a leaf node in the BST such that no new node can be inserted in the BST at or below this node while maintaining the BST property and the constraint that all node values must be > 0.

// Examples:

// Input: root[] = [8, 5, 9, 2, 7, N, N, 1]

// Output: true
// Explanation: Node 1 is a Dead End in the given BST.
// Input: root[] = [8, 7, 10, 2, N, 9, 13]

// Output: true
// Explanation: Node 9 is a Dead End in the given BST.

class Solution
{
public:
    bool isDeadEnd(Node *root)
    {
        return check(root, 0, INT_MAX);
    }

private:
    bool check(Node *root, int min, int max)
    {
        if (root == nullptr)
        {
            return false;
        }

        if (min + 1 == root->data && max - 1 == root->data)
        {
            return true;
        }

        return check(root->left, min, root->data) ||
               check(root->right, root->data, max);
    }
};