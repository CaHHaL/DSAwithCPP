// Given the root of a Binary Search Tree (BST) and two integers l and r, remove all the nodes whose values lie outside the range [l, r].

// Note: The modified tree should also be BST and the sequence of the remaining nodes should not be changed.

// Examples:

// Input: root = [6, -13, 14, N, -8, 13, 15, N, N, 7], l = -10, r = 13

// Output: [6, -8, 13, N, N, 7]
// Explanation: All the nodes outside the range [-10, 13] are removed and the modified tree is a valid BST.

// Input: root = [14, 4, 16, 2, 8, 15, N, -8, 3, 7, 10], l = 2, r = 6

// Output: [4, 2, N, N, 3]
// Explanation: All the nodes outside the range [2, 6] are removed and the modified tree is a valid BST.

// Constraints:
// 1 ≤ number of nodes ≤ 104
// 1 ≤ node->data ≤ 104
// 1 ≤ l ≤ r ≤ 104

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
public:
    Node *removekeys(Node *root, int l, int r)
    {
        if (!root)
            return NULL;
        root->left = removekeys(root->left, l, r);
        root->right = removekeys(root->right, l, r);
        int data = root->data;
        if (data < l)
            return root->right;
        if (data > r)
            return root->left;
        return root;
    }
};