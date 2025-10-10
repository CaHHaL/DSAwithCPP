// Given the root of a binary tree. You have to find the zig-zag level order traversal of the binary tree.
// Note: In zig zag traversal we traverse the nodes from left to right for odd-numbered levels, and from right to left for even-numbered levels.

// Examples:

// Input: root = [1, 2, 3, 4, 5, 6, 7]

// Output: [1, 3, 2, 4, 5, 6, 7]
// Explanation:
// Level 1 (left to right): [1]
// Level 2 (right to left): [3, 2]
// Level 3 (left to right): [4, 5, 6, 7]
// Final result: [1, 3, 2, 4, 5, 6, 7]
// Input: root = [7, 9, 7, 8, 8, 6, N, 10, 9]

// Output: [7, 7, 9, 8, 8, 6, 9, 10]
// Explanation:
// Level 1 (left to right): [7]
// Level 2 (right to left): [7, 9]
// Level 3 (left to right): [8, 8, 6]
// Level 4 (right to left): [9, 10]
// Final result: [7, 7, 9, 8, 8, 6, 9, 10]

/*
class Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution
{
public:
    vector<int> zigZagTraversal(Node *root)
    {
        queue<Node *> q;
        vector<int> ans;
        bool right = false;
        q.push(root);
        while (!q.empty())
        {
            right = !right;
            int n = q.size();
            deque<int> dq;
            while (n--)
            {
                auto z = q.front();
                q.pop();
                dq.push_back(z->data);
                if (z->left)
                    q.push(z->left);
                if (z->right)
                    q.push(z->right);
            }
            if (right)
            {
                while (dq.size() > 0)
                {
                    ans.push_back(dq.front());
                    dq.pop_front();
                }
            }
            else
            {
                while (dq.size() > 0)
                {
                    ans.push_back(dq.back());
                    dq.pop_back();
                }
            }
        }
        return ans;
    }
};