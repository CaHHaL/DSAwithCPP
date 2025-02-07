// Given a Binary Tree, your task is to return its In-Order Traversal.

// An inorder traversal first visits the left child (including its entire subtree), then visits the node, and finally visits the right child (including its entire subtree).

// Follow Up: Try solving this with O(1) auxiliary space.

// Examples:

// Input: root[] = [1, 2, 3, 4, 5]

// Output: [4, 2, 5, 1, 3]
// Explanation: The in-order traversal of the given binary tree is [4, 2, 5, 1, 3].
// Input: root[] = [8, 1, 5, N, 7, 10, 6, N, 10, 6]

// Output: [1, 7, 10, 8, 6, 10, 5, 6]
// Explanation: The in-order traversal of the given binary tree is [1, 7, 10, 8, 6, 10, 5, 6].

class Solution
{
public:
    vector<int> inOrder(Node *root)
    {
        vector<int> ans;
        stack<Node *> st;
        while (root != nullptr)
        {
            st.push(root);
            root = root->left;
        }

        while (!st.empty())
        {
            Node *tmp = st.top();
            st.pop();
            ans.push_back(tmp->data);

            if (tmp->right != nullptr)
            {
                tmp = tmp->right;
                while (tmp != nullptr)
                {
                    st.push(tmp);
                    tmp = tmp->left;
                }
            }
        }

        return ans;
    }
};