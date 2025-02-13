// Given a Binary Search Tree(BST) and a target. Check whether there's a pair of Nodes in the BST with value summing up to the target.

// Examples:

// Input: root = [7, 3, 8, 2, 4, N, 9], target = 12
//        bst
// Output: True
// Explanation: In the binary tree above, there are two nodes (8 and 4) that add up to 12.
// Input: root = [9, 5, 10, 2, 6, N, 12], target = 23
//           bst-3
// Output: False
// Explanation: In the binary tree above, there are no such two nodes exists that add up to 23.

class Solution
{
public:
    void inorder(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        inorder(root->left, ans);
        ans.push_back(root->data);
        inorder(root->right, ans);
    }
    bool findTarget(Node *root, int target)
    {
        vector<int> ans;
        inorder(root, ans);
        int s = 0, e = ans.size() - 1;
        while (s < e)
        {
            if (ans[s] + ans[e] == target)
                return true;
            else if (ans[s] + ans[e] > target)
                e--;
            else
                s++;
        }
        return false;
    }
};