// Given the head of two singly linked lists num1 and num2 representing two non-negative integers. The task is to return the head of the linked list representing the sum of these two numbers.

// For example, num1 represented by the linked list : 1 -> 9 -> 0, similarly num2 represented by the linked list: 2 -> 5. Sum of these two numbers is represented by 2 -> 1 -> 5.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

// Examples:

// Input: num1 = 4 - > 5, num2 = 3 -> 4 -> 5
// Output:  3 -> 9 -> 0

class Solution
{
public:
    Node *reverseList(struct Node *head)
    {
        Node *curr = head, *prev = NULL, *next = curr->next;
        while (curr)
        {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *addTwoLists(Node *num1, Node *num2)
    {
        num1 = reverseList(num1);
        num2 = reverseList(num2);
        int carry = 0;
        Node *ans = new Node(0);
        Node *first = ans;
        while (num1 || num2 || carry)
        {
            int sum = carry;
            if (num1)
            {
                sum += num1->data;
                num1 = num1->next;
            }
            if (num2)
            {
                sum += num2->data;
                num2 = num2->next;
            }
            ans->data = (sum % 10);
            carry = sum / 10;
            if (num1 || num2 || carry)
            {
                ans->next = new Node(0);
                ans = ans->next;
            }
        }
        reverseList(first);
        while (ans->data == 0 && ans->next)
            ans = ans->next;
        return ans;
    }
};