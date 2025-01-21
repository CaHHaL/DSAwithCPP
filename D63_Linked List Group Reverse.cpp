// Given the head a linked list, the task is to reverse every k node in the linked list. If the number of nodes is not a multiple of k then the left-out nodes in the end, should be considered as a group and must be reversed.

// Examples:

// Input: head = 1 -> 2 -> 2 -> 4 -> 5 -> 6 -> 7 -> 8, k = 4
// Output: 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5

// Explanation: The first 4 elements 1, 2, 2, 4 are reversed first and then the next 4 elements 5, 6, 7, 8. Hence, the resultant linked list is 4 -> 2 -> 2 -> 1 -> 8 -> 7 -> 6 -> 5.
// Input: head = 1 -> 2 -> 3 -> 4 -> 5, k = 3
// Output: 3 -> 2 -> 1 -> 5 -> 4

// Explanation: The first 3 elements 1, 2, 3 are reversed first and then left out elements 4, 5 are reversed. Hence, the resultant linked list is 3 -> 2 -> 1 -> 5 -> 4.

class Solution
{
public:
    Node *reverseKGroup(Node *head, int k)
    {
        // code here
        int len = getLength(head);
        Node *origH = nullptr;
        Node *origT = nullptr;
        Node *tmpH = nullptr;
        Node *tmpT = nullptr;
        Node *curr = head;

        while (len > 0)
        {
            int j = k;
            j = std::min(j, len);
            while (j > 0)
            {
                Node *nex = curr->next;
                if (tmpH == nullptr)
                {
                    tmpH = curr;
                    tmpT = curr;
                }
                else
                {
                    curr->next = tmpH;
                    tmpH = curr;
                }
                curr = nex;
                j--;
                len--;
            }

            if (origH == nullptr)
            {
                origH = tmpH;
                origT = tmpT;
            }
            else
            {
                origT->next = tmpH;
                origT = tmpT;
            }

            tmpH = nullptr;
            tmpT = nullptr;
        }

        if (origT != nullptr)
        {
            origT->next = nullptr;
        }

        return origH;
    }

    int getLength(Node *head)
    {
        int len = 0;
        while (head != nullptr)
        {
            len++;
            head = head->next;
        }
        return len;
    }
};