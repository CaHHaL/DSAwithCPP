// You are given root node of the BST and an integer key. You need to find the in-order successor and predecessor of the given key. If either predecessor or successor is not found, then set it to NULL.

// Note:- In an inorder traversal the number just smaller than the target is the predecessor and the number just greater than the target is the successor.

// Examples :

// Input: root[] = [8, 1, 9, N, 4, N, 10, 3, N, N, N], key = 8

// Output: 4 9
// Explanation: In the given BST the inorder predecessor of 8 is 4 and inorder successor of 8 is 9.
// Input: root[] = [10, 2, 11, 1, 5, N, N, N, N, 3, 6, N, 4, N, N], key = 11

// Output: 10 -1
// Explanation: In given BST, the inorder predecessor of 11 is 10 whereas it does not have any inorder successor.
// Input: root[] = [2, 1, 3], key = 3

// Output: 2 -1
// Explanation: In given BST, the inorder predecessor of 3 is 2 whereas it does not have any inorder successor.

class Solution
{
public:
    void inorder(Node *root, vector<Node *> &result)
    {
        if (!root)
        {
            return;
        }
        inorder(root->left, result);
        result.push_back(root);
        inorder(root->right, result);
    }
    vector<Node *> findPreSuc(Node *root, int key)
    {
        vector<Node *> result;
        inorder(root, result);
        Node *pre = NULL;
        Node *suc = NULL;
        for (int i = 0; i < result.size(); i++)
        {
            if (result[i]->data < key)
            {
                pre = result[i];
            }
            else if (result[i]->data > key)
            {
                suc = result[i];
                break;
            }
            else
            {
                if (i - 1 >= 0)
                {
                    pre = result[i - 1];
                }
                if (i + 1 < result.size())
                {
                    suc = result[i + 1];
                }
                break;
            }
        }
        return {pre, suc};
    }
};