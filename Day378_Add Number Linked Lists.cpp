// You are given the head of two singly linked lists head1 and head2 representing two non-negative integers. You have to return the head of the linked list representing the sum of these two numbers.

// Note: There can be leading zeros in the input lists, but there should not be any leading zeros in the output list.

// Examples:

// Input:

// Output:  1 -> 1 -> 2 -> 2
// Explanation: Given numbers are 123 and 999. There sum is 1122.

// Input:

// Output: 7 -> 0
// Explanation: Given numbers are 63 and 7. There sum is 70.

// Constraints:
// 1 ≤ Number of nodes in head1, head2 ≤ 105
// 0 ≤ node->data ≤ 9

/*
class Node {
  public:
    int data;
    Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};
*/
class Solution
{
public:
    Node *reverse(Node *head)
    {
        Node *prev = NULL;
        Node *curr = head;
        while (curr)
        {
            Node *next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }
        return prev;
    }
    Node *addTwoLists(Node *num1, Node *num2)
    {
        if (!num1)
            return num2;
        if (!num2)
            return num1;
        while (num1->next && num1->data == 0)
            num1 = num1->next;
        while (num2->next && num2->data == 0)
            num2 = num2->next;
        num1 = reverse(num1);
        num2 = reverse(num2);
        Node *ans = new Node(-1);
        Node *mptr = ans;
        Node *ptrA = num1;
        Node *ptrB = num2;
        int carry = 0;
        while (ptrA && ptrB)
        {
            int sum = ptrA->data + ptrB->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrA = ptrA->next;
            ptrB = ptrB->next;
        }
        while (ptrA)
        {
            int sum = ptrA->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrA = ptrA->next;
        }
        while (ptrB)
        {
            int sum = ptrB->data + carry;
            int digit = sum % 10;
            carry = sum / 10;
            mptr->next = new Node(digit);
            mptr = mptr->next;
            ptrB = ptrB->next;
        }
        if (carry != 0)
        {
            mptr->next = new Node(carry);
        }
        return reverse(ans->next);
    }
};