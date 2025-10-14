// Given the root of a Binary Search Tree and two integers l and r, the task is to find the sum of all nodes that lie between l and r, including both l and r.

// Examples

// Input: root = [22, 12, 30, 8, 20], l = 10, r = 22

// Output: 54
// Explanation: The nodes in the given Tree that lies in the range [10, 22] are {12, 20, 22}. Therefore, the sum of nodes is 12 + 20 + 22 = 54.
// Input: root = [8, 5, 11, 3, 6, N, 20], l = 11, r = 15

// Output: 11
// Explanation: The nodes in the given Tree that lies in the range [11, 15] is {11}. Therefore, the sum of node is 11.

/*
class Node {
  public:
    int data;
    Node* left;
    Node* right;

    // Constructor to initialize a new node
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
    virtual int fun(Node *root, int &l, int &r)
    {
        if (!root)
            return 0;
        int lCall = fun(root->left, l, r);
        int rCall = fun(root->right, l, r);
        int t = root->data;
        if ((l <= t) && (t <= r))
            return t + lCall + rCall;
        return lCall + rCall;
    }
    int nodeSum(Node *root, int l, int r)
    {
        return fun(root, l, r);
    }
};