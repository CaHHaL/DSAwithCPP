// Given a linked list containing n head nodes where every node in the linked list contains two pointers:
// (i) next points to the next node in the list.
// (ii) bottom points to a sub-linked list where the current node is the head.
// Each of the sub-linked lists nodes and the head nodes are sorted in ascending order based on their data. Flatten the linked list such that all the nodes appear in a single level while maintaining the sorted order.

// Note:
// 1. ↓ represents the bottom pointer and → represents the next pointer.
// 2. The flattened list will be printed using the bottom pointer instead of the next pointer.

// Examples:

// Input:

// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
// Explanation:
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 10 is pointing to 20 and so on.
// So, after flattening the linked list the sorted list will be
// 5 -> 7 -> 8 -> 10 -> 19 -> 20 -> 22 -> 28 -> 40 -> 45.
// Input:

// Output: 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50
// Explanation:
// Bottom pointer of 5 is pointing to 7.
// Bottom pointer of 7 is pointing to 8.
// Bottom pointer of 8 is pointing to 30 and so on.
// So, after flattening the linked list the sorted list will be
// 5 -> 7 -> 8 -> 10 -> 19 -> 22 -> 28 -> 30 -> 50.
// Constraints:
// 0 ≤ n ≤ 100
// 1 ≤ number of nodes in sub-linked list(mi) ≤ 50
// 1 ≤ node->data ≤ 104
/*
class Node {
public:
    int data;
    Node* next;
    Node* bottom;

    Node(int x) {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};
*/

class Solution
{
public:
    Node *merge(Node *a, Node *b)
    {
        Node *temp = new Node(0);
        Node *newHead = temp;
        while (a != NULL && b != NULL)
        {
            if (a->data < b->data)
            {
                temp->bottom = a;
                a = a->bottom;
                temp = temp->bottom;
            }
            else
            {
                temp->bottom = b;
                b = b->bottom;
                temp = temp->bottom;
            }
        }
        if (a != NULL)
            temp->bottom = a;
        else
            temp->bottom = b;
        return newHead->bottom;
    }
    Node *flatten(Node *root)
    {
        if (root == NULL || root->next == NULL)
            return root;
        root->next = flatten(root->next);
        root = merge(root, root->next);
        return root;
    }
};