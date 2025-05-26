// Given a sorted circular linked list, the task is to insert a new node in this circular linked list so that it remains a sorted circular linked list.

// Examples:

// Input: head = 1->2->4, data = 2
// Output: 1->2->2->4
// Explanation: We can add 2 after the second node.

// Input: head = 1->4->7->9, data = 5
// Output: 1->4->5->7->9
// Explanation: We can add 5 after the second node.

class Solution
{
public:
    Node *sortedInsert(Node *head, int data)
    {
        Node *NN = new Node(data), *temp = head;
        if (head->data > data)
        {
            NN->next = head;
            while (temp->next != head)
                temp = temp->next;
            temp->next = NN;
            return NN;
        }
        while (temp->next != head && temp->next->data <= data)
            temp = temp->next;
        NN->next = temp->next;
        temp->next = NN;
        return head;
    }
};