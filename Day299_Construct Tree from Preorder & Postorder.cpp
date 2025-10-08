// Given two arrays pre[] and post[] that represent the preorder and postorder traversals of a full binary tree. Your task is to construct the binary tree and return its root.

// Note:  Full Binary Tree is a binary tree where every node has either 0 or 2 children. The preorder and postorder traversals contain unique values, and every value present in the preorder traversal is also found in the postorder traversal.

// Examples:

// Input: pre[] = [1, 2, 4, 8, 9, 5, 3, 6, 7], post[] = [8, 9, 4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7, 8, 9]
// Explanation: The tree will look like

// Input: pre[] = [1, 2, 4, 5, 3, 6, 7] , post[] = [4, 5, 2, 6, 7, 3, 1]
// Output: [1, 2, 3, 4, 5, 6, 7]
// Explanation: The tree will look like

/*
class Node {
public:
    int data;
    Node *left;
    Node *right;

    Node(int x) {
        data = x;
        left = NULL;
        right = NULL;
    }
};
*/

class Solution
{
    int preIndex;
    unordered_map<int, int> postMap;

    Node *constructFromPrePost(vector<int> &pre, vector<int> &post, int postStart, int postEnd)
    {
        if (postStart > postEnd)
            return nullptr;

        Node *root = new Node(pre[preIndex++]);

        if (postStart == postEnd)
            return root;

        int i = postMap[pre[preIndex]];

        root->left = constructFromPrePost(pre, post, postStart, i);
        root->right = constructFromPrePost(pre, post, i + 1, postEnd - 1);

        return root;
    }

public:
    Node *constructTree(vector<int> &pre, vector<int> &post)
    {
        preIndex = 0;
        postMap.clear();
        int n = pre.size();
        for (int i = 0; i < n; i++)
        {
            postMap[post[i]] = i;
        }
        return constructFromPrePost(pre, post, 0, n - 1);
    }
};