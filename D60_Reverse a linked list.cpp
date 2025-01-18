// Given the head of a linked list, the task is to reverse this list and return the reversed head.

// Examples:

// Input: head: 1 -> 2 -> 3 -> 4 -> NULL
// Output: head: 4 -> 3 -> 2 -> 1 -> NULL
// Explanation:

// Input: head: 2 -> 7 -> 10 -> 9 -> 8 -> NULL
// Output: head: 8 -> 9 -> 10 -> 7 -> 2 -> NULL
// Explanation:

// Input: head: 2 -> NULL
// Output: 2 -> NULL

class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        Node *prev = NULL;
        Node *current = head;
        Node *next = NULL;

        // Traverse the list and reverse the links
        while (current != NULL)
        {
            next = current->next; // Store the next node
            current->next = prev; // Reverse the current node's pointer
            prev = current;       // Move prev and current one step forward
            current = next;
        }

        // At the end, prev will be pointing to the new head of the reversed list
        return prev;
    }
};
