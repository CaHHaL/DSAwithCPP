// Given the head of two sorted linked lists consisting of nodes respectively. The task is to merge both lists and return the head of the sorted merged list.

// Examples:

// Input: head1 = 5 -> 10 -> 15 -> 40, head2 = 2 -> 3 -> 20
// Output: 2 -> 3 -> 5 -> 10 -> 15 -> 20 -> 40
// Explanation:

// Input: head1 = 1 -> 1, head2 = 2 -> 4
// Output: 1 -> 1 -> 2 -> 4

#include <iostream>
using namespace std;

// Definition for singly-linked list.
class Node
{
public:
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
public:
    Node *sortedMerge(Node *head1, Node *head2)
    {
        // Create a dummy node to act as the starting point of the merged list
        Node *dummy = new Node(-1);
        Node *tail = dummy; // 'tail' will always point to the last node in the merged list

        // Traverse through both lists until we reach the end of one of them
        while (head1 != nullptr && head2 != nullptr)
        {
            if (head1->data < head2->data)
            {
                tail->next = head1;  // Add the smaller node to the merged list
                head1 = head1->next; // Move head1 to the next node
            }
            else
            {
                tail->next = head2;  // Add the smaller node to the merged list
                head2 = head2->next; // Move head2 to the next node
            }
            tail = tail->next; // Move the tail pointer to the last node in the merged list
        }

        // If there are any remaining nodes in either list, attach them to the merged list
        if (head1 != nullptr)
        {
            tail->next = head1;
        }
        else
        {
            tail->next = head2;
        }

        // The merged list is in dummy's next node, so return dummy->next
        return dummy->next;
    }
};

// Helper function to print the linked list
void printList(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

// Helper function to insert a node at the end of the list
void append(Node *&head, int data)
{
    Node *newNode = new Node(data);
    if (head == nullptr)
    {
        head = newNode;
    }
    else
    {
        Node *temp = head;
        while (temp->next != nullptr)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main()
{
    Solution sol;

    // Create two sorted linked lists
    Node *head1 = nullptr;
    append(head1, 5);
    append(head1, 10);
    append(head1, 15);
    append(head1, 40);

    Node *head2 = nullptr;
    append(head2, 2);
    append(head2, 3);
    append(head2, 20);

    // Merge the lists
    Node *mergedHead = sol.sortedMerge(head1, head2);

    // Print the merged list
    printList(mergedHead);

    return 0;
}
