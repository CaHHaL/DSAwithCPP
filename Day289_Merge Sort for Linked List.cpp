// You are given the head of a linked list. You have to sort the given linked list using Merge Sort.

// Examples:

// Input:

// Output: 10 -> 20 -> 30 -> 40 -> 50 -> 60
// Explanation: After sorting the given linked list, the resultant list will be:

// Input:

// Output: 2 -> 5 -> 8 -> 9
// Explanation: After sorting the given linked list, the resultant list will be:
/*
class Node {
public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *getMiddle(Node *head)
    {
        if (!head)
            return head;
        Node *slow = head;
        Node *fast = head->next;
        while (fast && fast->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        return slow;
    }
    Node *merge(Node *left, Node *right)
    {
        if (!left)
            return right;
        if (!right)
            return left;
        Node *result = nullptr;
        if (left->data <= right->data)
        {
            result = left;
            result->next = merge(left->next, right);
        }
        else
        {
            result = right;
            result->next = merge(left, right->next);
        }
        return result;
    }
    Node *mergeSort(Node *head)
    {
        if (!head || !head->next)
            return head;
        Node *middle = getMiddle(head);
        Node *nextToMiddle = middle->next;
        middle->next = nullptr;
        Node *left = mergeSort(head);
        Node *right = mergeSort(nextToMiddle);
        return merge(left, right);
    }
};