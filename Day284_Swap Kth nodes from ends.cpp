// Given the head of a singly linked list and an integer k. Swap the kth node (1-based index) from the beginning and the kth node from the end of the linked list. Return the head of the final formed list and if it's not possible to swap the nodes return the original list.

// Examples:

// Input: k = 1,

// Output: 5 -> 2 -> 3 -> 4 -> 1
// Explanation: Here k = 1, hence after swapping the 1st node from the beginning and end the new list will be 5 -> 2 -> 3 -> 4 -> 1.

// Input: k = 2,

// Output: 5 -> 9 -> 8 -> 5 -> 10 -> 3
// Explanation: Here k = 2, hence after swapping the 2nd node from the beginning and end the new list will be 5 -> 9 -> 8 -> 5 -> 10 -> 3.

/*
class Node {
  public:
    int data;
    Node *next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *swapKth(Node *head, int k)
    {
        if (!head || !head->next)
            return head;
        int n = 0;
        Node *temp = head;
        while (temp)
        {
            n++;
            temp = temp->next;
        }
        if (k > n)
            return head;
        int pos1 = k;
        int pos2 = n - k + 1;
        if (pos1 == pos2)
            return head;
        Node *prev1 = nullptr, *node1 = head;
        for (int i = 1; i < pos1; i++)
        {
            prev1 = node1;
            node1 = node1->next;
        }
        Node *prev2 = nullptr, *node2 = head;
        for (int i = 1; i < pos2; i++)
        {
            prev2 = node2;
            node2 = node2->next;
        }
        if (prev1)
            prev1->next = node2;
        else
            head = node2;
        if (prev2)
            prev2->next = node1;
        else
            head = node1;
        Node *tmp = node1->next;
        node1->next = node2->next;
        node2->next = tmp;
        return head;
    }
};