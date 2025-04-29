// Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

// Examples:

// Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

// Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2

// Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between.
// Input: head = 2 → 2 → 0 → 1

// Output: 0 → 1 → 2 → 2

// Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be 0 → 1 → 2 → 2.

class Solution
{
public:
    Node *segregate(Node *head)
    {
        int zeros = 0, ones = 0, twos = 0;
        Node *temp = head;
        while (temp)
        {
            if (temp->data == 0)
                zeros++;
            else if (temp->data == 1)
                ones++;
            else
                twos++;
            temp = temp->next;
        }
        temp = head;
        while (zeros)
        {
            temp->data = 0;
            zeros--;
            temp = temp->next;
        }
        while (ones)
        {
            temp->data = 1;
            ones--;
            temp = temp->next;
        }
        while (twos)
        {
            temp->data = 2;
            twos--;
            temp = temp->next;
        }
        return head;
    }
};