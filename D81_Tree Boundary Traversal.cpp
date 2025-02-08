// Given a Binary Tree, find its Boundary Traversal. The traversal should be in the following order:

// Left Boundary: This includes all the nodes on the path from the root to the leftmost leaf node. You must prefer the left child over the right child when traversing. Do not include leaf nodes in this section.

// Leaf Nodes: All leaf nodes, in left-to-right order, that are not part of the left or right boundary.

// Reverse Right Boundary: This includes all the nodes on the path from the rightmost leaf node to the root, traversed in reverse order. You must prefer the right child over the left child when traversing. Do not include the root in this section if it was already included in the left boundary.

// Note: If the root doesn't have a left subtree or right subtree, then the root itself is the left or right boundary.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5, 6, 7, N, N, 8, 9, N, N, N, N]
// Output: [1, 2, 4, 8, 9, 6, 7, 3]
// Explanation:

// Input: root[] = [1, 2, N, 4, 9, 6, 5, N, 3, N, N, N, N 7, 8]
// Output: [1, 2, 4, 6, 5, 7, 8]
// Explanation:

// As the root doesn't have a right subtree, the right boundary is not included in the traversal.
// Input: root[] = [1, N, 2, N, 3, N, 4, N, N]
//     1
//      \
//       2
//        \
//         3
//          \
//           4

// Output: [1, 4, 3, 2]
// Explanation:
// Left boundary: [1] (as there is no left subtree)
// Leaf nodes: [4]
// Right boundary: [3, 2] (in reverse order)
// Final traversal: [1, 4, 3, 2]

class Solution
{
public:
    void left(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->left)
        {
            ans.push_back(root->data);
            left(root->left, ans);
        }
        else if (root->right)
        {
            ans.push_back(root->data);
            left(root->right, ans);
        }
    }

    void bottom(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->left == NULL && root->right == NULL)
        {
            ans.push_back(root->data);
            return;
        }
        if (root->left)
            bottom(root->left, ans);
        if (root->right)
            bottom(root->right, ans);
    }
    void right(Node *root, vector<int> &ans)
    {
        if (!root)
            return;
        if (root->right)
        {
            right(root->right, ans);
            ans.push_back(root->data);
        }
        else if (root->left)
        {

            right(root->left, ans);
            ans.push_back(root->data);
        }
    }
    vector<int> boundaryTraversal(Node *root)
    {
        // CodeGenius

        vector<int> ans;
        if (!root)
            return ans;
        ans.push_back(root->data);
        left(root->left, ans);
        bottom(root->left, ans);
        bottom(root->right, ans);
        right(root->right, ans);
        return ans;
    }
};