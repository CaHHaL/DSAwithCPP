// You are given the head of a doubly linked list. You have to reverse the doubly linked list and return its head.

// Examples:

// Input:

// Output: 5 <-> 4 <-> 3
// Explanation: After reversing the given doubly linked list the new list will be 5 <-> 4 <-> 3.

// Input:

// Output: 196 <-> 59 <-> 122 <-> 75
// Explanation: After reversing the given doubly linked list the new list will be 196 <-> 59 <-> 122 <-> 75.

class Solution
{
public
    Node reverse(Node head)
    {
        if (head == null || head.next == null)
            return head;
        Node curr = head, prev = null;
        while (curr != null)
        {
            prev = curr.prev;
            curr.prev = curr.next;
            curr.next = prev;
            curr = curr.prev;
        }
        return prev.prev;
    }
}