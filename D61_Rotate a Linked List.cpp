// Given the head of a singly linked list, your task is to left rotate the linked list k times.

// Examples:

// Input: head = 10 -> 20 -> 30 -> 40 -> 50, k = 4
// Output: 50 -> 10 -> 20 -> 30 -> 40
// Explanation:
// Rotate 1: 20 -> 30 -> 40 -> 50 -> 10
// Rotate 2: 30 -> 40 -> 50 -> 10 -> 20
// Rotate 3: 40 -> 50 -> 10 -> 20 -> 30
// Rotate 4: 50 -> 10 -> 20 -> 30 -> 40

// Input: head = 10 -> 20 -> 30 -> 40 , k = 6
// Output: 30 -> 40 -> 10 -> 20

class Solution
{
public:
    Node *rotate(Node *head, int k)
    {
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            temp = temp->next;
            n++;
        }
        k = k % n;
        if (!(k) || n == 1)
            return head;
        temp = head;
        while (--k)
        {
            temp = temp->next;
        }
        Node *nh = temp->next;
        temp->next = NULL;
        temp = nh;
        while (temp->next)
        {
            temp = temp->next;
        }
        temp->next = head;
        return nh;
    }
};