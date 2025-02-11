// Given the root of a binary tree. Check whether it is a BST or not.
// Note: We are considering that BSTs can not contain duplicate Nodes.
// A BST is defined as follows:

// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
// Examples:

// Input: root = [2, 1, 3, N, N, N, 5]

// Output: true
// Explanation: The left subtree of every node contains smaller keys and right subtree of every node contains greater keys. Hence, the tree is a BST.
// Input: root = [2, N, 7, N, 6, N, 9]

// Output: false
// Explanation: Since the node to the right of node with key 7 has lesser key value, hence it is not a valid BST.
// Input: root = [10, 5, 20, N, N, 9, 25]

// Output: false
// Explanation: The node with key 9 present in the right subtree has lesser key value than root node.

class Solution
{
public:
    void inorder(Node *root, vector<int> &temp)
    {
        if (!root)
            return;
        inorder(root->left, temp);
        temp.push_back(root->data);
        inorder(root->right, temp);
    }
    bool isBST(Node *root)
    {
        if (!root->left && !root->right)
            return true;
        vector<int> temp;
        inorder(root, temp);
        for (int i = 0; i < temp.size() - 2; i++)
        {
            if (temp[i] > temp[i + 1])
                return false;
        }
        return true;
    }
};