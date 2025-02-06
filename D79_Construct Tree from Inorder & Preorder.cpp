// Given two arrays representing the inorder and preorder traversals of a binary tree, construct the tree and return the root node of the constructed tree.

// Note: The output is written in postorder traversal.

// Examples:

// Input: inorder[] = [1, 6, 8, 7], preorder[] = [1, 6, 7, 8]
// Output: [8, 7, 6, 1]
// Explanation: The tree will look like

// Input: inorder[] = [3, 1, 4, 0, 2, 5], preorder[] = [0, 1, 3, 4, 2, 5]
// Output: [3, 4, 1, 5, 2, 0]
// Explanation: The tree will look like

// Input: inorder[] = [2, 5, 4, 1, 3], preorder[] = [1, 4, 5, 2, 3]
// Output: [2, 5, 4, 3, 1]
// Explanation: The tree will look like

class Solution
{
public:
    unordered_map<int, int> mp;
    Node *solve(vector<int> &preorder, int s, int e, int &preInd)
    {
        if (s > e)
            return NULL;
        int val = preorder[preInd];
        Node *root = new Node(preorder[preInd++]);
        root->left = solve(preorder, s, mp[val] - 1, preInd);
        root->right = solve(preorder, mp[val] + 1, e, preInd);
        return root;
    }
    Node *buildTree(vector<int> &inorder, vector<int> &preorder)
    {
        for (int i = 0; i < inorder.size(); i++)
        {
            mp[inorder[i]] = i;
        }
        int preInd = 0;
        return solve(preorder, 0, inorder.size() - 1, preInd);
    }
};