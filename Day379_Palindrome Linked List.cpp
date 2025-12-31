// You are given the head of a singly linked list of positive integers. You have to check if the given linked list is palindrome or not.

// Examples:

// Input:

// Output: true
// Explanation: The given linked list is 1 -> 2 -> 1 -> 1 -> 2 -> 1, which is a palindrome.
// Input:

// Output: false
// Explanation: The given linked list is 10 -> 20 -> 30 -> 40 -> 50, which is not a palindrome.
// Constraints:
// 1 ≤ number of nodes ≤ 105
// 0 ≤ node->data ≤ 103
class Solution
{
public:
    bool isPalindrome(Node *head)
    {
        vector<int> nodevalues;
        Node *temp = head;
        while (temp != NULL)
        {
            nodevalues.push_back(temp->data);
            temp = temp->next;
        }
        int i = 0;
        int j = nodevalues.size() - 1;
        int flag = 0;
        while (i < j)
        {
            if (nodevalues[i] == nodevalues[j])
            {
                i++;
                j--;
            }
            else
            {
                flag = 1;
                break;
            }
        }
        if (flag == 1)
            return false;
        else
            return true;
    }
};