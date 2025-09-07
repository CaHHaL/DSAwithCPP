// Given an array arr[] of n sorted linked lists of different sizes. Your task is to merge all these lists into a single sorted linked list and return the head of the merged list.

// Examples:

// Input:

// Output: 1 -> 2 -> 3 -> 4 -> 7 -> 8 -> 9
// Explanation: The arr[] has 3 sorted linked list of size 3, 3, 1.
// 1st list: 1 -> 3 -> 7
// 2nd list: 2 -> 4 -> 8
// 3rd list: 9
// The merged list will be:

// Input:

// Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
// Explanation: The arr[] has 3 sorted linked list of size 2, 1, 3.
// 1st list: 1 -> 3
// 2nd list: 8
// 3rd list: 4 -> 5 -> 6
// The merged list will be:

/*
class Node {
  public:
    int data;
    Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
#define p pair<int, Node *>
    Node *mergeKLists(vector<Node *> &arr)
    {
        Node *newHead = new Node(-1);
        priority_queue<p, vector<p>, greater<p>> pq;
        for (int i = 0; i < arr.size(); i++)
        {
            Node *temp = arr[i];
            pq.push({temp->data, temp});
        }
        Node *temp = newHead;
        while (!pq.empty())
        {
            Node *curr = pq.top().second;
            pq.pop();
            temp->next = curr;
            temp = temp->next;
            if (curr->next)
                pq.push({curr->next->data, curr->next});
        }
        return newHead->next;
    }
};