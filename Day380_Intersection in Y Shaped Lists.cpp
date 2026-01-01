// You are given the heads of two non-empty singly linked lists, head1 and head2, that intersect at a certain point. Return that Node where these two linked lists intersect.

// Note: It is guaranteed that the intersected node always exists.

// In the custom input you have to give input for CommonList which pointed at the end of both head1 and head2 to form a Y-shaped linked list.
// Examples:

// Input: head1: 10 -> 15 -> 30, head2: 3 -> 6 -> 9 -> 15 -> 30
// Output: 15
// Explanation: From the above image, it is clearly seen that the common part is 15 -> 30, whose starting point is 15.

// Input: head1: 4 -> 1 -> 8 -> 5, head2: 5 -> 6 -> 1 -> 8 -> 5
// Output: 1
// Explanation: From the above image, it is clearly seen that the common part is 1 -> 8 -> 5, whose starting point is 1.

// Constraints:
// 2 ≤ total number of nodes ≤ 2*105
// -104 ≤ node->data ≤ 104

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
    Node *intersectPoint(Node *head1, Node *head2)
    {
        Node *tempA = head1;
        Node *tempB = head2;
        while (tempA != tempB)
        {
            if (tempA == nullptr)
            {
                tempA = head1;
            }
            else
                tempA = tempA->next;
            if (tempB == nullptr)
            {
                tempB = head2;
            }
            else
                tempB = tempB->next;
        }
        return tempA;
    }
};