// Given a root of a binary tree with n nodes, the task is to find its level order traversal. Level order traversal of a tree is breadth-first traversal for the tree.

// Examples:

// Input: root[] = [1, 2, 3]

// Output: [[1], [2, 3]]
// Input: root[] = [10, 20, 30, 40, 50]

// Output: [[10], [20, 30], [40, 50]]
// Input: root[] = [1, 3, 2, N, N, N, 4, 6, 5]

// Output: [[1], [3, 2], [4], [6, 5]]

class Solution
{
public:
    vector<vector<int>> levelOrder(Node *root)
    {
        vector<vector<int>> result;
        queue<Node *> q;
        q.push(root);
        while (!q.empty())
        {
            vector<int> ans;
            Node *curr = q.front();
            q.pop();
            ans.push_back(curr->data);
            if (curr->left)
                q.push(curr->left);
            if (curr->right)
                q.push(curr->right);
            result.push_back(ans);
        }
        return result;
    }
};