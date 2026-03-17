#include <iostream>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};
class Queue
{
public:
    Node *head;
    Node *tail;
    Queue()
    {
        head = tail = NULL;
    }
    int front()
    {
        if (!empty())
        {
            return head->data;
        }
    }
    void push(int val)
    {
        Node *newNode = new Node(val);
        if (empty())
        {
            head = tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
    }
    void pop()
    {
        if (!empty())
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }
    bool empty()
    {
        return head == nullptr;
    }
};
int main()
{
    Queue q;
    q.push(10);
    q.push(20);
    q.push(30);
    cout << "Front element: " << q.front() << endl;

    q.pop();
    cout << "Front element after pop: " << q.front() << endl;
}