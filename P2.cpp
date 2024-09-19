// Lisa wants to create a linked list sorted in ascending order. She wants to insert nodes in such a way that the linked list remains sorted after insertion.



// Write a program that takes the number of nodes to be inserted, followed by their values in non-decreasing order. The program should then ask for a new value and insert a node with that value at the appropriate position to maintain the sorted order.



// Finally, the program should print the updated linked list.



// Example



// Input:

// 5

// 1 3 5 7 9

// 4



// Output:

// 1 3 4 5 7 9



// Explanation:

// The program first creates a sorted linked list using the given input values: 1, 3, 5, 7, and 9. After creating the initial sorted linked list, the program asks for a new value, which is 4. It then inserts a node with value 4 at the appropriate position to maintain the sorted order. Finally, the program prints the updated linked list, which is 1, 3, 4, 5, 7, and 9 in ascending order.



// Company tags: Wipro

// Input format :
// The first line of input consists of an integer n, representing the number of elements in the initial sorted linked list.

// The second line of input consists of n space-separated integers, representing the elements of the sorted linked list.

// The third line of input consists of integer data, which represents the element to be inserted into the linked list.

// Output format :
// The output displays the updated linked list after inserting the new element, separated by space.

// The linked list should remain sorted in ascending order.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// -100 ≤ elements, data ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 3 5 7 9
// 4
// Output 1 :
// 1 3 4 5 7 9 
// Input 2 :
// 6
// -15 -10 0 5 9 10
// 7
// Output 2 :
// -15 -10 0 5 7 9 10 


#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};
void sortedInsert(Node** head_ref, int new_data) {
    Node* newNode = new Node;
    newNode->data = new_data;
    newNode->next = nullptr;

    if (*head_ref == nullptr || (*head_ref)->data >= new_data) {
      
        newNode->next = *head_ref;
        *head_ref = newNode;
    } else {
        Node* curr = *head_ref;
        while (curr->next != nullptr && curr->next->data < new_data) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

void printList(Node* head) {
    Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;
    int n, data;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> data;
        sortedInsert(&head, data);
    }

    cin >> data;
    sortedInsert(&head, data);

    printList(head);
    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}



// Kathir is a software engineer working on a project that involves managing a linked list of integers. His task is to develop a program that allows the user to insert integers at the beginning of the list and then display the entire list. The program should continue inserting elements until the user decides to stop(1).



// Company tags: Wipro

// Input format :
// The first line of input consists of an integer n, representing the item to be inserted at the beginning of the linked list.

// The second line of input consists of an integer (0 or 1), representing the choice to continue or stop the insertion process.

// Input 0 to continue inserting more integers.
// Input 1 to stop inserting and display the linked list.
// Output format :
// The output displays "Node inserted" each time a new integer is inserted into the linked list in a new line.

// After insertion, the output displays "Linked List: " followed by the integers in the linked list in insertion order.

// The final line of output displays "Node ended" after displaying the linked list.



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 3500

// Sample test cases :
// Input 1 :
// 2
// 0
// 4
// 1
// Output 1 :
// Node inserted
// Node inserted
// Linked List: 4 2 
// Node ended
// Input 2 :
// 4
// 1
// Output 2 :
// Node inserted
// Linked List: 4 
// Node ended


#include <iostream>
using namespace std;
struct Node {
    int data;
    Node* next;
};

void insertAtBeginning(Node*& head, int value) {
    Node* newNode = new Node;
    newNode->data = value;
    newNode->next = head;
    head = newNode;
}

void displayList(const Node* head) {
    const Node* curr = head;
    while (curr != nullptr) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr;

    int n;
    int choice;

    do {
        cin >> n;
        insertAtBeginning(head, n);
        cout << "Node inserted" << endl;
        cin >> choice;
    } while (choice == 0);

    cout << "Linked List: ";
    displayList(head);
    cout << "Node ended" << endl;

    while (head != nullptr) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }

    return 0;
}

