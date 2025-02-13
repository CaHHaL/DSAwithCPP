// Given the root of a Binary search tree(BST), where exactly two nodes were swapped by mistake. Your task is to fix (or correct) the BST by swapping them back. Do not change the structure of the tree.
// Note: It is guaranteed that the given input will form BST, except for 2 nodes that will be wrong. All changes must be reflected in the original linked list.

// Examples :
// Input: root = [10, 5, 8, 2, 20]

// Output: 1

// Explanation: The nodes 20 and 8 were swapped.
// Input: root = [5, 10, 20, 2, 8]

// Output: 1

// Explanation: The nodes 10 and 5 were swapped.

void compute(Node *root, Node *&prev, Node *&first, Node *&last)
{
    if (root == NULL)
        return;
    compute(root->left, prev, first, last);
    if (prev != NULL)
    {
        if (prev->data > root->data)
        {
            if (first == NULL)
                first = prev;
            last = root;
        }
    }
    prev = root;
    compute(root->right, prev, first, last);
}
class Solution
{
public:
    void correctBST(struct Node *root)
    {
        Node *prev = NULL;
        Node *first = NULL;
        Node *last = NULL;
        compute(root, prev, first, last);
        swap(first->data, last->data);
    }
};