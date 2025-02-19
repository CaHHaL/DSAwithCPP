// Given an array arr[] of n sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list, then return the head of the merged linked list.

// Examples:

// Input: arr[] = [1 -> 2 -> 3, 4 -> 5, 5 -> 6, 7 -> 8]
// Output: 1 -> 2 -> 3 -> 4 -> 5 -> 5 -> 6 -> 7 -> 8
// Explanation:
// The arr[] has 4 sorted linked list of size 3, 2, 2, 2.
// 1st list: 1 -> 2-> 3
// 2nd list: 4 -> 5
// 3rd list: 5 -> 6
// 4th list: 7 -> 8
// The merged list will be:

// Input: arr[] = [1 -> 3, 8, 4 -> 5 -> 6]
// Output: 1 -> 3 -> 4 -> 5 -> 6 -> 8
// Explanation:
// The arr[] has 3 sorted linked list of size 2, 3, 1.
// 1st list: 1 -> 3
// 2nd list: 8
// 3rd list: 4 -> 5 -> 6
// The merged list will be:

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