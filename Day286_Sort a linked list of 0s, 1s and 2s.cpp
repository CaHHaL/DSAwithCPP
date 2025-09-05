// Given the head of a linked list where nodes can contain values 0s, 1s, and 2s only. Your task is to rearrange the list so that all 0s appear at the beginning, followed by all 1s, and all 2s are placed at the end.

// Examples:

// Input: head = 1 → 2 → 2 → 1 → 2 → 0 → 2 → 2

// Output: 0 → 1 → 1 → 2 → 2 → 2 → 2 → 2
// Explanation: All the 0s are segregated to the left end of the linked list, 2s to the right end of the list, and 1s in between. The final list will be:

// Input: head = 2 → 2 → 0 → 1

// Output: 0 → 1 → 2 → 2
// Explanation: After arranging all the 0s, 1s and 2s in the given format, the output will be:
/* Node is defined as
  class Node {
  public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = nullptr;
    }
};
*/
class Solution
{
public:
    Node *segregate(Node *head)
    {
        int i = 0, j = 0, k = 0;
        Node *ptr = head;
        while (ptr != NULL)
        {
            if (ptr->data == 0)
                i++;
            else if (ptr->data == 1)
                j++;
            else
                k++;
            ptr = ptr->next;
        }
        ptr = head;
        while (ptr != NULL && i != 0)
        {
            ptr->data = 0;
            ptr = ptr->next;
            i--;
        }
        while (ptr != NULL && j != 0)
        {
            ptr->data = 1;
            ptr = ptr->next;
            j--;
        }
        while (ptr != NULL && k != 0)
        {
            ptr->data = 2;
            ptr = ptr->next;
            k--;
        }
        return head;
    }
};