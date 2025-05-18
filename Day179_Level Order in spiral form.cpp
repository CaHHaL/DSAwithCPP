// Given a binary tree and the task is to find the spiral order traversal of the tree and return the list containing the elements.
// Spiral order Traversal mean: Starting from level 0 for root node, for all the even levels we print the node's value from right to left and for all the odd levels we print the node's value from left to right.
// For below tree, function should return [1, 2, 3, 4, 5, 6, 7]

// Examples:

// Input: root = [1, 3, 2]

// Output: [1, 3, 2]
// Explanation: Start with root (1), print level 0 (right to left), then level 1 (left to right).
// Input: root = [10, 20, 30, 40, 60]

// Output: [10, 20, 30, 60, 40]
// Explanation: Start with root (10), print level 0 (right to left), level 1 (left to right), and continue alternating.

class Solution
{
public:
    vector<int> findSpiral(Node *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        queue<Node *> que;
        que.push(root);

        bool direction = false;

        while (!que.empty())
        {
            int n = que.size();
            vector<int> row(n);

            for (int i = 0; i < n; i++)
            {
                Node *node = que.front();
                que.pop();

                int idx = direction ? i : (n - 1 - i);
                row[idx] = node->data;

                if (node->left)
                {
                    que.push(node->left);
                }

                if (node->right)
                {
                    que.push(node->right);
                }
            }

            for (int val : row)
            {
                result.push_back(val);
            }

            direction = !direction;
        }
        return result;
    }
};