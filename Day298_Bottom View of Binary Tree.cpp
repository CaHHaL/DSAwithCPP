// You are given the root of a binary tree, and your task is to return its bottom view. The bottom view of a binary tree is the set of nodes visible when the tree is viewed from the bottom.

// Note: If there are multiple bottom-most nodes for a horizontal distance from the root, then the latter one in the level order traversal is considered.

// Examples :

// Input: root = [1, 2, 3, 4, 5, N, 6]

// Output: [4, 2, 5, 3, 6]
// Explanation: The Green nodes represent the bottom view of below binary tree.

// Input: root = [20, 8, 22, 5, 3, 4, 25, N, N, 10, 14, N, N, 28, N]

// Output: [5, 10, 4, 28, 25]
// Explanation: The Green nodes represent the bottom view of below binary tree.

/*
class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};
*/

struct Pair
{
    Node *node;
    int width;
    Pair(Node *n, int w) : node(n), width(w) {}
};

class Solution
{
public:
    vector<int> bottomView(Node *root)
    {
        vector<int> result;
        if (root == nullptr)
            return result;

        queue<Pair> q;
        map<int, int> mp;

        q.push(Pair(root, 0));

        while (!q.empty())
        {
            Pair p = q.front();
            q.pop();

            Node *temp = p.node;
            int d = p.width;
            mp[d] = temp->data;

            if (temp->left != nullptr)
                q.push(Pair(temp->left, d - 1));

            if (temp->right != nullptr)
                q.push(Pair(temp->right, d + 1));
        }

        for (auto it : mp)
        {
            result.push_back(it.second);
        }

        return result;
    }
};