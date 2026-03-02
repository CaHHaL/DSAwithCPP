#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    Node(int value)
    {
        data = value;
        next = prev = nullptr;
    }
};
class DoublyList
{
public:
    Node *head;
    Node *tail;
    DoublyList()
    {
        head = tail = nullptr;
    }
    void push_front(int value)
    {
        if (head == nullptr)
        {
            head = new Node(value);
            tail = head;
        }
        else
        {
            Node *newNode = new Node(value);
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
        }
    }
    void printdll()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data << "->";
            temp = temp->next;
        }
        cout << "NULL" << endl;
    }
    void push_back(int value)
    {
        if (tail == nullptr)
        {
            tail = new Node(value);
            head = tail;
        }
        else
        {
            Node *newNode = new Node(value);
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
    }
    void pop_front()
    {
        if (head == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
    void pop_back()
    {
        if (tail == nullptr)
        {
            cout << "List is empty" << endl;
            return;
        }
        Node *temp = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
};

int main()
{
    DoublyList dll;
    dll.push_front(10);
    dll.push_front(20);
    dll.push_front(30);
    dll.push_back(40);
    dll.printdll();
    dll.pop_back();
    dll.pop_front();
    dll.printdll();
    return 0;
}
