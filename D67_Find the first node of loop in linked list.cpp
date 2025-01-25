// Given a head of the singly linked list. If a loop is present in the list then return the first node of the loop else return NULL.

// Custom Input format:
// A head of a singly linked list and a pos (1-based index) which denotes the position of the node to which the last node points to. If pos = 0, it means the last node points to null, indicating there is no loop.

// Examples:

// Input:

// Output: 3
// Explanation: We can see that there exists a loop in the given linked list and the first node of the loop is 3.
// Input:

// Output: -1
// Explanation: No loop exists in the above linked list.So the output is -1.

class Solution
{
public:
    Node *findFirstNode(Node *head)
    {
        // your code here
        if (head == NULL)
            return NULL;

        Node *slow = head;
        Node *fast = head;

        while (fast != NULL && fast->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast)
            {
                slow = head;
                while (slow != fast)
                {
                    slow = slow->next;
                    fast = fast->next;
                }
                return slow;
            }
        }
        return NULL;
    }
};