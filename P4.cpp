// Akash has implemented a simple stack using an array with a maximum size of 10.



// The program provides the following operations:

// Push: Add an integer to the stack.
// Pop: Remove an integer from the top of the stack.
// Check if Stack is Full: Determine if the stack is full.
// Check if Stack is Empty: Determine if the stack is empty.
// Exit: Terminate the program.


// Company Tags: Capgemini 

// Input format :
// The choice represents the operation to be performed:

// 1: Push an integer onto the stack. The following input is the element to be pushed.

// 2: Pop an integer from the stack.

// 3: Check if the stack is full.

// 4: Check if the stack is empty.

// 5: Exit the program.

// Output format :
// The output prints one of the following messages:

// If the choice is 1 (Push), there is no output.

// If the choice is 2 (Pop) and the stack is empty, print "Stack is empty!".

// If the choice is 3 (Check if Full), and the stack is full, print "Stack is full!", and if the stack is not full, print "Stack is not full"

// If the choice is 4 (Check if Empty), and the stack is empty, print "Stack is empty!", and if the stack is not empty, print "Stack is not empty"

// If the choice is 5 (Exit), the program should terminate immediately.

// If the choice is more than 6, it prints "Invalid choice".



// Refer to the sample output for the formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// Valid choice = 1, 2, 3, 4, 5

// 1 ≤ stack elements ≤ 100

// Sample test cases :
// Input 1 :
// 1 2
// 1 6
// 2
// 3
// 4
// 5
// Output 1 :
// Stack is not full
// Stack is not empty
// Input 2 :
// 1 3
// 1 4
// 1 5
// 1 7
// 1 18
// 1 19
// 1 20
// 1 21
// 1 34
// 1 76
// 4
// 3
// 5
// Output 2 :
// Stack is not empty
// Stack is full!
// Input 3 :
// 1 2
// 1 4
// 1 5
// 1 76
// 1 89
// 1 34
// 1 23
// 1 65
// 1 45
// 1 23
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 2
// 4
// 5
// Output 3 :
// Stack is empty!
// Input 4 :
// 1 6
// 1 7
// 9
// 5
// Output 4 :
// Invalid choice
// Input 5 :
// 1 4
// 2
// 2
// 5
// Output 5 :
// Stack is empty!




// You are using GCC
#include<iostream>
using namespace std;
int arr[10];
int top=-1;
int n =10;
void push(){
    int x;
    cin>>x;
    if(top==n-1){
        cout<<"Stack is full!"<<endl;
    }else{
        top++;
        arr[top]=x;
    }
}
void pop(){
   if(top==-1){
      cout<<"Stack is empty!"<<endl;
    int y;
   } else{
       top--;
   }
}
void CheckFull(){
    if(top==n-1){
        cout<<"Stack is full!"<<endl;
    }else{
        cout<<"Stack is not full"<<endl;
    }
}
void CheckEmpty(){
    if(top==-1){
        cout<<"Stack is empty!"<<endl;
        
    }else{
        cout<<"Stack is not empty"<<endl;
    }
}
int main(){
    int input;
    do{
        cin>>input;
    switch(input){
    case 1:
    push();
    break;
    case 2:
    pop();
    break;
    case 3:
    CheckFull();
    break;
    case 4:
    CheckEmpty();
    break;
    case 5:
    input=5;
    break;
    default:
    cout<<"Invalid choice"<<endl;
        
    };}
    while(input!=5);{
       int y; 
    }
    
}

// Rithi is building a simple text editor that allows users to type characters, undo their typing, and view the current text. She has decided to implement this text editor using an array-based stack data structure.



// She has to develop a basic text editor with the following features:

// Type a Character (Push): Users can type a character and add it to the text editor.
// Undo Typing (Pop): Users can undo their typing by removing the last character they entered from the editor.
// View Current Text (Display): Users can view the current text in the editor, which is the sequence of characters in the buffer.
// Exit: Users can exit the text editor application.


// Write a program that simulates this text editor's undo feature using a character stack and implements the push, pop, and display operations accordingly.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the character onto the stack. If the choice is 1, the following input is a character, representing the character to be pushed onto the stack in the next line.

// Choice 2: Pop the character from the stack.

// Choice 3: Display the characters in the stack.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the stack:

// If the choice is 1, push the given character to the stack and display the character.
// If the choice is 2, undo the character from the stack and display the character that is removed.
// If the choice is 2, and if the stack is empty without any characters, print "Text editor buffer is empty. Nothing to undo."
// If the choice is 3, print the characters in the stack.
// If the choice is 3, and there are no characters in the stack, print "Text editor buffer is empty."
// If the choice is 4, exit the program.
// If any other choice is entered, print "Invalid choice"


// Refer to the sample output for the exact format.

// Code constraints :
// The maximum size of the stack is defined as 100.

// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 
// H
// 1 
// A
// 3
// 4
// Output 1 :
// Typed character: H
// Typed character: A
// Current text: A H 
// Input 2 :
// 1 
// H
// 1 
// E
// 3
// 2
// 3
// 4
// Output 2 :
// Typed character: H
// Typed character: E
// Current text: E H 
// Undo: Removed character E
// Current text: H 
// Input 3 :
// 3
// 4
// Output 3 :
// Text editor buffer is empty.

// You are using GCC
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

class TextEditor {
private:
    std::vector<char> stack;
    const int maxSize = 100;

public:
    void push(char c) {
        if (stack.size() < maxSize) {
            stack.push_back(c);
            std::cout << "Typed character: " << c << std::endl;
        } else {
            std::cout << "Stack is full. Cannot add more characters." << std::endl;
        }
    }

    void pop() {
        if (!stack.empty()) {
            char removedChar = stack.back();
            stack.pop_back();
            std::cout << "Undo: Removed character " << removedChar << std::endl;
        } else {
            std::cout << "Text editor buffer is empty. Nothing to undo." << std::endl;
        }
    }

    void display() {
        if (!stack.empty()) {
            std::cout << "Current text: ";
            for (auto it = stack.rbegin(); it != stack.rend(); ++it) {
                std::cout << *it << " ";
            }
            std::cout << std::endl;
        } else {
            std::cout << "Text editor buffer is empty." << std::endl;
        }
    }
};

int main() {
    TextEditor editor;
    int choice;
    
    while (true) {
        // std::cout << "Enter choice (1: Push, 2: Pop, 3: Display, 4: Exit): ";
        std::cin >> choice;

        if (choice == 1) {
            char c;
            // std::cout << "Enter character to type: ";
            std::cin >> c;
            editor.push(c);
        } else if (choice == 2) {
            editor.pop();
        } else if (choice == 3) {
            editor.display();
        } else if (choice == 4) {
            break;
        } else {
            std::cout << "Invalid choice" << std::endl;
        }
    }

    return 0;
}





// Meet Alex, a computer science student who loves solving programming challenges. 



// Today, Alex is tasked with creating a program to simulate a stack data structure using linked lists. 



// The objective is to provide a menu-driven interface for performing essential stack operations: 

// Push elements onto the stack
// Pop elements from the stack 
// Display the current stack contents


// Additionally, Alex needs to ensure that the program handles stack underflow conditions. Help him to accomplish the task.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Push the integer value onto the stack. If the choice is 1, the following input is a space-separated integer, representing the element to be pushed onto the stack.

// Choice 2: Pop the integer from the stack.

// Choice 3: Display the elements in the stack.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the stack:

// If the choice is 1, push the given integer to the stack and display the following: "[value] is pushed onto the stack"
// If the choice is 2, pop the integer from the stack and display the following: "[value] is popped from the stack"
// If the choice is 2, and if the stack is empty without any elements, print "Stack Underflow"
// If the choice is 3, print the elements in the stack in the format: "Elements in the stack: ", followed by the space-separated values.
// If the choice is 3, and there are no elements in the stack, print "Stack is empty"
// If the choice is 4, exit the program and display the following: "Exiting the program"
// If any other choice is entered, print "Invalid choice"


// Refer to the sample output for the exact text.

// Code constraints :
// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 6
// 1 7
// 3
// 2
// 4
// Output 1 :
// 6 is pushed onto the stack
// 7 is pushed onto the stack
// Elements in the stack: 7 6 
// 7 is popped from the stack
// Exiting the program
// Input 2 :
// 5
// 4
// Output 2 :
// Invalid choice
// Exiting the program
// Input 3 :
// 2
// 4
// Output 3 :
// Stack Underflow
// Exiting the program
// Input 4 :
// 3
// 4
// Output 4 :
// Stack is empty
// Exiting the program


// You are using GCC
#include <iostream>

class Node {
public:
    int data;
    Node* next;

    Node(int value) {
        data = value;
        next = nullptr;
    }
};

class Stack {
private:
    Node* top;

public:
    Stack() {
        top = nullptr;
    }

    ~Stack() {
        while (top != nullptr) {
            pop();
        }
    }

    void push(int value) {
        Node* newNode = new Node(value);
        newNode->next = top;
        top = newNode;
        std::cout << value << " is pushed onto the stack" << std::endl;
    }

    void pop() {
        if (top == nullptr) {
            std::cout << "Stack Underflow" << std::endl;
            return;
        }
        Node* temp = top;
        top = top->next;
        std::cout << temp->data << " is popped from the stack" << std::endl;
        delete temp;
    }

    void display() {
        if (top == nullptr) {
            std::cout << "Stack is empty" << std::endl;
            return;
        }
        Node* current = top;
        std::cout << "Elements in the stack: ";
        while (current != nullptr) {
            std::cout << current->data << " ";
            current = current->next;
        }
        std::cout << std::endl;
    }
};

int main() {
    Stack stack;
    int choice;

    while (true) {
        // std::cout << "Enter choice (1: Push, 2: Pop, 3: Display, 4: Exit): ";
        std::cin >> choice;
        
        if (choice == 1) {
            int value;
            std::cin >> value;
            stack.push(value);
        } else if (choice == 2) {
            stack.pop();
            
        } else if (choice == 3) {
            stack.display();
            
        } else if (choice == 4) {
            std::cout << "Exiting the program" << std::endl;
            break;
        } else {
            std::cout << "Invalid choice" << std::endl;
            
        }
        
    }
    

    return 0;
}



// In a bustling IT department, staff regularly submit helpdesk tickets to request technical assistance. Managing these tickets efficiently is vital for providing quality support.



// Your task is to develop a program that uses an array-based queue to handle and prioritize helpdesk tickets based on their unique IDs.



// Implement a program that provides the following functionalities:

// Enqueue Helpdesk Ticket: Add a new helpdesk ticket to the end of the queue. Provide a positive integer representing the ticket ID for the new ticket.
// Dequeue Helpdesk Ticket: Remove and process the next helpdesk ticket from the front of the queue. The program will display the ticket ID of the processed ticket.
// Display Queue: Display the ticket IDs of all the helpdesk tickets currently in the queue.
// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Enqueue the ticket ID into the queue. If the choice is 1, the following input is a space-separated integer, representing the ticket ID to be enqueued into the queue.

// Choice 2: Dequeue a ticket from the queue.

// Choice 3: Display the ticket IDs in the queue.

// Choice 4: Exit the program.

// Output format :
// The output displays messages according to the choice and the status of the queue:



// If the choice is 1:

// Insert the given ticket ID into the queue and display "Helpdesk Ticket ID [id] is enqueued." where [id] is the ticket ID that is inserted.
// If the queue is full, print "Queue is full. Cannot enqueue."
// If the choice is 2:

// Dequeue a ticket ID from the queue and display "Dequeued Helpdesk Ticket ID: " followed by the corresponding ID that is dequeued.
// If the queue is empty without any elements, print "Queue is empty."
// If the choice is 3:

// The output prints "Helpdesk Ticket IDs in the queue are: " followed by the space-separated ticket IDs present in the queue.
// If there are no elements in the queue, print "Queue is empty."
// If the choice is 4:

// Exit the program and print "Exiting the program"
// If any other choice is entered, print "Invalid option."



// Refer to the sample output for formatting specifications.

// Code constraints :
// Maximum number of helpdesk tickets stored in the queue is 5.

// Choice: 1, 2, 3, or 4

// Sample test cases :
// Input 1 :
// 1 101
// 1 202
// 1 203
// 1 204
// 1 205
// 1 206
// 3
// 2
// 3
// 4
// Output 1 :
// Helpdesk Ticket ID 101 is enqueued.
// Helpdesk Ticket ID 202 is enqueued.
// Helpdesk Ticket ID 203 is enqueued.
// Helpdesk Ticket ID 204 is enqueued.
// Helpdesk Ticket ID 205 is enqueued.
// Queue is full. Cannot enqueue.
// Helpdesk Ticket IDs in the queue are: 101 202 203 204 205
// Dequeued Helpdesk Ticket ID: 101
// Helpdesk Ticket IDs in the queue are: 202 203 204 205
// Exiting the program
// Input 2 :
// 2
// 1 105
// 5
// 4
// Output 2 :
// Queue is empty.
// Helpdesk Ticket ID 105 is enqueued.
// Invalid option.
// Exiting the program
// Input 3 :
// 1 105
// 3
// 2
// 3
// 2
// 4
// Output 3 :
// Helpdesk Ticket ID 105 is enqueued.
// Helpdesk Ticket IDs in the queue are: 105
// Dequeued Helpdesk Ticket ID: 105
// Queue is empty.
// Queue is empty.
// Exiting the program






// You are using GCC
#include <iostream>
using namespace std;

class HelpdeskQueue {
private:
    static const int MAX_SIZE = 5; // Maximum number of tickets
    int tickets[MAX_SIZE];
    int front, rear, count;

public:
    HelpdeskQueue() : front(0), rear(-1), count(0) {}

    void enqueue(int ticketID) {
        if (count == MAX_SIZE) {
            cout << "Queue is full. Cannot enqueue." << endl;
            return;
        }
        rear = (rear + 1) % MAX_SIZE; // Circular increment
        tickets[rear] = ticketID;
        count++;
        cout << "Helpdesk Ticket ID " << ticketID << " is enqueued." << endl;
    }

    void dequeue() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Dequeued Helpdesk Ticket ID: " << tickets[front] << endl;
        front = (front + 1) % MAX_SIZE; // Circular increment
        count--;
    }

    void display() {
        if (count == 0) {
            cout << "Queue is empty." << endl;
            return;
        }
        cout << "Helpdesk Ticket IDs in the queue are: ";
        for (int i = 0; i < count; i++) {
            cout << tickets[(front + i) % MAX_SIZE] << " ";
        }
        cout << endl;
    }
};

int main() {
    HelpdeskQueue queue;
    int choice;

    while (true) {
        // cout << "Enter choice (1: Enqueue, 2: Dequeue, 3: Display, 4: Exit): ";
        cin >> choice;

        if (choice == 1) {
            int ticketID;
            cin >> ticketID;
            queue.enqueue(ticketID);
        } else if (choice == 2) {
            queue.dequeue();
        } else if (choice == 3) {
            queue.display();
        } else if (choice == 4) {
            cout << "Exiting the program" << endl;
            break;
        } else {
            cout << "Invalid option." << endl;
        }
    }

    return 0;
}


// Aaron is learning data structures, and his teacher gave him a task related to the queue data structure. The queue should be implemented as a linked list, where each node holds a customer's ID.



// He is required to implement a simple program that supports the following operations:

// Enqueue: Add a customer's ID to the end of the queue.
// Dequeue: Remove and return the customer's ID from the front of the queue.
// Display: Display the current customer IDs in the queue.


// Your task is to help Aaron implement the operations mentioned above.

// Input format :
// The input consists of integers corresponding to the operation that needs to be performed:

// Choice 1: Enqueue the customer ID into the queue. If the choice is 1, the following input is a space-separated integer, representing the customers' ID to be enqueued into the queue.

// Choice 2: Dequeue a customer ID from the queue.

// Choice 3: Display the customer IDs in the queue.

// Choice 4: Exit the queue

// Output format :
// The output displays messages according to the choice and the status of the queue:



// If the choice is 1:

// Insert the given customer ID into the queue and display "Customer ID X is enqueued" where X is the customer ID that is inserted.
// If the choice is 2:

// Dequeue a customer ID from the queue and display "Dequeued customer ID: " followed by the corresponding ID that is dequeued.
// If the queue is empty without any elements, print "Queue is empty".
// If the choice is 3:

// The output prints "Customer IDs in the queue are: " followed by the space-separated customer IDs present in the queue.
// If there are no elements in the queue, print "Queue is empty".
// If the choice is 4:

// Exit the program.
// If any other choice is entered, print "Invalid option".



// Refer to the sample output for the exact text and format.

// Code constraints :
// Choice: 1, 2, or 3.

// Sample test cases :
// Input 1 :
// 1 24
// 1 36
// 1 47
// 3
// 2
// 2
// 3
// 4
// Output 1 :
// Customer ID 24 is enqueued
// Customer ID 36 is enqueued
// Customer ID 47 is enqueued
// Customer IDs in the queue are: 24 36 47 
// Dequeued customer ID: 24
// Dequeued customer ID: 36
// Customer IDs in the queue are: 47 
// Input 2 :
// 1 54
// 1 36
// 3
// 2
// 2
// 2
// 3
// 4
// Output 2 :
// Customer ID 54 is enqueued
// Customer ID 36 is enqueued
// Customer IDs in the queue are: 54 36 
// Dequeued customer ID: 54
// Dequeued customer ID: 36
// Queue is empty
// Queue is empty
// Input 3 :
// 1 15
// 1 19
// 3
// 2
// 3
// 4
// Output 3 :
// Customer ID 15 is enqueued
// Customer ID 19 is enqueued
// Customer IDs in the queue are: 15 19 
// Dequeued customer ID: 15
// Customer IDs in the queue are: 19 
// Input 4 :
// 5
// 3
// 4
// Output 4 :
// Invalid option
// Queue is empty


#include <iostream>
using namespace std;

// Node structure for linked list
struct Node {
    int customerID;
    Node* next;
    
    Node(int id) : customerID(id), next(nullptr) {}
};

// Queue class
class Queue {
private:
    Node* front; // Points to the front of the queue
    Node* rear;  // Points to the end of the queue

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int customerID) {
        Node* newNode = new Node(customerID);
        if (rear == nullptr) { // If the queue is empty
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
        cout << "Customer ID " << customerID << " is enqueued" << endl;
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) { // If the queue is empty
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Dequeued customer ID: " << front->customerID << endl;
        Node* temp = front;
        front = front->next; // Move front to the next node
        if (front == nullptr) { // If the queue is now empty
            rear = nullptr; // Reset rear as well
        }
        delete temp; // Free the memory
    }

    // Display operation
    void display() {
        if (front == nullptr) { // If the queue is empty
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Customer IDs in the queue are: ";
        Node* current = front;
        while (current != nullptr) {
            cout << current->customerID << " ";
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    Queue queue;
    int choice;

    while (true) {
        cout << "Enter choice (1: Enqueue, 2: Dequeue, 3: Display, 4: Exit): ";
        cin >> choice;

        if (choice == 1) {
            int customerID;
            cin >> customerID;
            queue.enqueue(customerID);
        } else if (choice == 2) {
            queue.dequeue();
        } else if (choice == 3) {
            queue.display();
        } else if (choice == 4) {
            break; // Exit the loop
        } else {
            cout << "Invalid option" << endl;
        }
    }

    return 0;
}


// Design a system for an emergency room where patients arrive with varying medical conditions, each assigned a severity score. Create a priority queue to manage patient treatment based on severity, ensuring those with higher scores are treated first. 



// Patients are dequeued in order of severity for treatment.

// Input format :
// The first line of input consists of an integer N, representing the number of patients in the emergency room.

// The next N lines consist of two space-separated values each:

// A string representing the patient's name.
// An integer value representing the severity score.
// Output format :
// For each patient being treated, the output displays a line: "Treating patient: X (Severity: Y)" where X is the patient's name and Y is the severity score.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ severity score ≤ 20

// Patient names are strings with a maximum length of 50 characters.

// Sample test cases :
// Input 1 :
// 6
// Frank 8
// Grace 1
// Hank 4
// Ivy 2
// Jack 6
// Karen 5
// Output 1 :
// Treating patient: Frank (Severity: 8)
// Treating patient: Jack (Severity: 6)
// Treating patient: Karen (Severity: 5)
// Treating patient: Hank (Severity: 4)
// Treating patient: Ivy (Severity: 2)
// Treating patient: Grace (Severity: 1)
// Input 2 :
// 5
// Alice 4
// Bob 6
// Carol 3
// David 7
// Eve 5
// Output 2 :
// Treating patient: David (Severity: 7)
// Treating patient: Bob (Severity: 6)
// Treating patient: Eve (Severity: 5)
// Treating patient: Alice (Severity: 4)
// Treating patient: Carol (Severity: 3)
// Input 3 :
// 7
// Liam 7
// Mia 5
// Noah 6
// Olivia 3
// Penelope 8
// Quinn 2
// Riley 4
// Output 3 :
// Treating patient: Penelope (Severity: 8)
// Treating patient: Liam (Severity: 7)
// Treating patient: Noah (Severity: 6)
// Treating patient: Mia (Severity: 5)
// Treating patient: Riley (Severity: 4)
// Treating patient: Olivia (Severity: 3)
// Treating patient: Quinn (Severity: 2) in c++

#include <iostream>
#include <queue>
#include <vector>
#include <string>

using namespace std;

// Patient structure to hold name and severity
struct Patient {
    string name;
    int severity;

    // Constructor
    Patient(string n, int s) : name(n), severity(s) {}

    // Operator to create a max-heap based on severity
    bool operator<(const Patient& other) const {
        return severity < other.severity; // For max-heap
    }
};

int main() {
    int N;
    cout << "Enter number of patients: ";
    cin >> N;

    priority_queue<Patient> pq; // Max-heap based priority queue

    // Input patients
    for (int i = 0; i < N; ++i) {
        string name;
        int severity;
        cin >> name >> severity;
        pq.push(Patient(name, severity));
    }

    // Treat patients based on severity
    while (!pq.empty()) {
        Patient p = pq.top();
        pq.pop();
        cout << "Treating patient: " << p.name << " (Severity: " << p.severity << ")" << endl;
    }

    return 0;
}





// You are tasked with implementing a double-ended queue data structure using a linked list. A deque is a linear data structure that supports operations for adding and removing elements at both ends. 



// Your program should provide the following functionality:

// Initialize an empty deque.
// Check if the deque is empty.
// Insert elements in the deque.
// Display the odd and even elements separately.
// Input format :
// The input consists of the elements that should be inserted in the deque. The input is terminated by entering -1.

// Output format :
// The output prints the even and odd elements in the given deque.



// Refer to the sample output for the exact text and format.

// Code constraints :
// 1 ≤ deque elements ≤ 100

// Sample test cases :
// Input 1 :
// 1
// 2
// 3
// 4
// -1
// Output 1 :
// Even elements: 2 4 
// Odd elements: 1 3 
// Input 2 :
// 1
// 2
// -1
// Output 2 :
// Even elements: 2 
// Odd elements: 1 

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
    Node* prev;

    Node(int val) : data(val), next(nullptr), prev(nullptr) {}
};

// Deque class
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert at the front
    void insertFront(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->next = front;
            front->prev = newNode;
            front = newNode;
        }
    }

    // Insert at the rear
    void insertRear(int value) {
        Node* newNode = new Node(value);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            newNode->prev = rear;
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Display odd and even elements
    void displayOddEven() {
        Node* current = front;
        cout << "Even elements: ";
        while (current != nullptr) {
            if (current->data % 2 == 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;

        current = front;
        cout << "Odd elements: ";
        while (current != nullptr) {
            if (current->data % 2 != 0) {
                cout << current->data << " ";
            }
            current = current->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Deque deque;
    int value;

    cout << "Enter elements for the deque (-1 to end):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        deque.insertRear(value); // You can change this to insertFront if needed
    }

    // Display odd and even elements
    deque.displayOddEven();

    return 0;
}





// In a hospital, patients are added to a waiting list in the order they arrive. When a doctor becomes available, the first patient on the list is treated and removed from the list. 



// Implement a program to manage this waiting list using a double-ended queue.

// Input format :
// The first line of input consists of an integer n, denoting the number of patients.

// The second line consists of n space-separated integers, denoting the patient's ID.

// Output format :
// After treating the first patient, the output prints the IDs of the remaining patients in the deque.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 30

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// 2 3 4 5 
// Input 2 :
// 8
// 34 56 82 93 25 71 89 61
// Output 2 :
// 56 82 93 25 71 89 61 

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int patientID;
    Node* next;
    Node* prev;

    Node(int id) : patientID(id), next(nullptr), prev(nullptr) {}
};

// Deque class for managing the waiting list
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert patient ID at the rear
    void insertRear(int id) {
        Node* newNode = new Node(id);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Treat the first patient (remove from front)
    void treatPatient() {
        if (isEmpty()) {
            return; // No patients to treat
        }
        Node* temp = front;
        front = front->next;
        if (front != nullptr) {
            front->prev = nullptr;
        } else {
            rear = nullptr; // Queue is now empty
        }
        delete temp; // Free the memory
    }

    // Display remaining patients
    void displayPatients() {
        Node* current = front;
        while (current != nullptr) {
            cout << current->patientID << " ";
            current = current->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            treatPatient();
        }
    }
};

int main() {
    int n;
    cout << "Enter number of patients: ";
    cin >> n;

    Deque waitingList;
    cout << "Enter patient IDs: ";
    for (int i = 0; i < n; ++i) {
        int patientID;
        cin >> patientID;
        waitingList.insertRear(patientID);
    }

    // Treat the first patient
    waitingList.treatPatient();

    // Display remaining patients
    waitingList.displayPatients();

    return 0;
}




// Olivia is working on a data processing project that involves analyzing a list of user IDs. As part of her task, she needs to display the user IDs without duplicates using a double-ended queue.



// Write a program that Olivia can use to print the user IDs without duplicates from the deque.

// Input format :
// The input consists of the elements of the deque. The input is terminated by entering -1.

// Output format :
// The output prints the elements in the given deque, without duplicates.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ deque elements ≤ 1000

// Sample test cases :
// Input 1 :
// 4
// 3
// 3
// 2
// 2
// 1
// -1
// Output 1 :
// 4 3 2 1 
// Input 2 :
// 11
// 2
// -1
// Output 2 :
// 11 2 



#include <iostream>
#include <unordered_set>
using namespace std;

// Node structure for the linked list
struct Node {
    int userID;
    Node* next;
    Node* prev;

    Node(int id) : userID(id), next(nullptr), prev(nullptr) {}
};

// Deque class for managing user IDs
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert user ID at the rear
    void insertRear(int id) {
        Node* newNode = new Node(id);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            newNode->prev = rear;
            rear = newNode;
        }
    }

    // Display user IDs without duplicates
    void displayUniqueIDs() {
        unordered_set<int> seen; // To track seen user IDs
        Node* current = front;
        while (current != nullptr) {
            if (seen.find(current->userID) == seen.end()) {
                cout << current->userID << " ";
                seen.insert(current->userID); // Mark this ID as seen
            }
            current = current->next;
        }
        cout << endl;
    }

    ~Deque() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
    }
};

int main() {
    Deque deque;
    int value;

    cout << "Enter user IDs (-1 to end):" << endl;
    while (true) {
        cin >> value;
        if (value == -1) {
            break;
        }
        deque.insertRear(value);
    }

    // Display unique user IDs
    deque.displayUniqueIDs();

    return 0;
}



// Imagine you are working on a text processing system for a search engine. As part of the system, you need to implement a pattern-matching algorithm using a sliding window approach. 



// Given a large text document and a pattern, you are required to find all occurrences of the pattern in the text document efficiently.



// Your task is to write a program that performs the following operations:

// Read the large text document and store it in memory.
// Read the pattern from the user.
// Implement a sliding window algorithm using a linked list-based deque to find all occurrences of the pattern in the text document.
// Display the positions (starting indices) of all occurrences of the pattern in the text document.


// Write a program to implement the above operations and display the positions of all occurrences of the pattern in the text document.



// Company Tags: TCS

// Input format :
// The first line of input consists of a sequence of strings.

// The second line consists of the pattern to be found in the given string.

// Output format :
// If the pattern is found in the string, print the index or indexes where the pattern occurs (index starts from 0)

// If the pattern is not found, print "Pattern not found".

// If the pattern is longer than the string, print "Pattern is longer than the string".



// Refer to the sample output for the exact text and format.

// Code constraints :
// The strings are case-sensitive.

// Sample test cases :
// Input 1 :
// abcdabcdeabcdabcdeabcdabcde
// abcd
// Output 1 :
// Pattern found at index 0
// Pattern found at index 4
// Pattern found at index 9
// Pattern found at index 13
// Pattern found at index 18
// Pattern found at index 22
// Input 2 :
// abcdefghij
// abcdefghijkl
// Output 2 :
// Pattern is longer than the string
// Input 3 :
// Harry Potter
// harry
// Output 3 :
// Pattern not found



#include <iostream>
#include <string>
using namespace std;

// Node structure for the linked list
struct Node {
    char data;
    Node* next;

    Node(char ch) : data(ch), next(nullptr) {}
};

// Deque class using linked list to store characters
class Deque {
private:
    Node* front;
    Node* rear;

public:
    Deque() : front(nullptr), rear(nullptr) {}

    // Check if the deque is empty
    bool isEmpty() {
        return front == nullptr;
    }

    // Insert character at the rear
    void insertRear(char ch) {
        Node* newNode = new Node(ch);
        if (isEmpty()) {
            front = rear = newNode;
        } else {
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Check if the content of the deque matches the pattern
    bool matches(const string& pattern) {
        Node* current = front;
        for (char ch : pattern) {
            if (current == nullptr || current->data != ch) {
                return false;
            }
            current = current->next;
        }
        return true;
    }

    // Clear the deque
    void clear() {
        while (!isEmpty()) {
            Node* temp = front;
            front = front->next;
            delete temp;
        }
        rear = nullptr;
    }

    ~Deque() {
        clear();
    }
};

void findPatternInText(const string& text, const string& pattern) {
    if (pattern.length() > text.length()) {
        cout << "Pattern is longer than the string" << endl;
        return;
    }

    Deque deque;

    // Fill deque with the first 'pattern.length()' characters
    for (size_t i = 0; i < pattern.length(); ++i) {
        deque.insertRear(text[i]);
    }

    // Check the initial window
    int index = 0;
    if (deque.matches(pattern)) {
        cout << "Pattern found at index " << index << endl;
    }

    // Slide the window across the text
    for (size_t i = pattern.length(); i < text.length(); ++i) {
        // Remove the front character
        deque.clear();
        for (size_t j = i - pattern.length() + 1; j <= i; ++j) {
            deque.insertRear(text[j]);
        }
        index++;

        if (deque.matches(pattern)) {
            cout << "Pattern found at index " << index << endl;
        }
    }
}

int main() {
    string text, pattern;

    cout << "Enter the text: ";
    getline(cin, text);
    
    cout << "Enter the pattern: ";
    getline(cin, pattern);

    findPatternInText(text, pattern);

    return 0;
}



// Write a program to implement a specialized queue data structure capable of deleting the smallest element within its contents. The program should also handle standard enqueue and dequeue operations.

// Input format :
// The first line of input consists of an integer N, representing the number of elements in the queue.

// The following N lines consist of N floating-point numbers, separated by space, representing the elements of the queue.

// Output format :
// If the queue is empty, N = 0, output "Queue is empty".

// Otherwise, output the elements of the queue after deleting the smallest element.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The queue should have a fixed maximum size of 100 elements.

// Sample test cases :
// Input 1 :
// 5
// 45.6
// 36.4
// 12.3
// 74.5
// 94.1
// Output 1 :
// 45.6 36.4 74.5 94.1 
// Input 2 :
// 2
// 2.5
// 3.5
// Output 2 :
// 3.5 
// Input 3 :
// 0
// Output 3 :
// Queue is empty


#include <iostream>
#include <vector>
#include <limits>
using namespace std;

class SpecializedQueue {
private:
    vector<double> queue;  // Vector to store queue elements
    const int MAX_SIZE = 100;  // Maximum size of the queue

public:
    // Enqueue an element to the queue
    void enqueue(double value) {
        if (queue.size() < MAX_SIZE) {
            queue.push_back(value);
        } else {
            cout << "Queue is full. Cannot enqueue." << endl;
        }
    }

    // Dequeue an element from the queue (removes the first element)
    void dequeue() {
        if (!queue.empty()) {
            queue.erase(queue.begin());
        } else {
            cout << "Queue is empty. Cannot dequeue." << endl;
        }
    }

    // Delete the smallest element from the queue
    void deleteSmallest() {
        if (queue.empty()) {
            cout << "Queue is empty. Cannot delete smallest element." << endl;
            return;
        }
        
        // Find the index of the smallest element
        double minValue = numeric_limits<double>::max();
        int minIndex = -1;
        
        for (int i = 0; i < queue.size(); i++) {
            if (queue[i] < minValue) {
                minValue = queue[i];
                minIndex = i;
            }
        }

        // Remove the smallest element
        if (minIndex != -1) {
            queue.erase(queue.begin() + minIndex);
        }
    }

    // Display the elements in the queue
    void display() {
        if (queue.empty()) {
            cout << "Queue is empty" << endl;
        } else {
            for (const auto& element : queue) {
                cout << element << " ";
            }
            cout << endl;
        }
    }
};

int main() {
    int N;
    cin >> N;

    SpecializedQueue sq;

    // Handle case when N is 0
    if (N == 0) {
        cout << "Queue is empty" << endl;
        return 0;
    }

    // Read N floating-point numbers into the queue
    for (int i = 0; i < N; i++) {
        double value;
        cin >> value;
        sq.enqueue(value);
    }

    // Delete the smallest element
    sq.deleteSmallest();

    // Display the remaining elements in the queue
    sq.display();

    return 0;
}



// You are tasked with implementing a program to simulate multiple queues using linked lists. The program should allow enqueue and dequeue operations on the queues and display the contents of each queue. 



// The program should prompt the user for the number of queues (k) and the total number of customers (n). Then, for each customer, the program should prompt for the item and the queue number the customer wants to join. 



// After enqueuing all the customers, the program should print the contents of each queue in order, indicating the queue number and the items in each queue.

// Input format :
// The input begins with two integers k and n separated by a newline character.

// Then, n lines follow, each containing two integers: item and queueNumber, separated by space.

// Output format :
// The output consists of k lines.

// Each line represents a queue and contains the elements in that queue after dequeuing, separated by space.



// Refer to the sample output for the exact text and format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n, k ≤ 20

// 1 ≤ item ≤ 100

// Sample test cases :
// Input 1 :
// 2
// 5
// 1 0
// 2 1
// 3 0
// 4 1
// 5 0
// Output 1 :
// Queue 0: 1 3 5 
// Queue 1: 2 4 
// Input 2 :
// 3
// 8
// 10 2
// 20 1
// 30 0
// 40 2
// 50 1
// 60 0
// 70 2
// 80 0
// Output 2 :
// Queue 0: 30 60 80 
// Queue 1: 20 50 
// Queue 2: 10 40 70 



#include <iostream>
#include <vector>
#include <memory>
using namespace std;

// Node structure for linked list
struct Node {
    int item;
    shared_ptr<Node> next;
    
    Node(int val) : item(val), next(nullptr) {}
};

// Queue class using linked list
class Queue {
private:
    shared_ptr<Node> front;
    shared_ptr<Node> rear;

public:
    Queue() : front(nullptr), rear(nullptr) {}

    // Enqueue operation
    void enqueue(int item) {
        auto newNode = make_shared<Node>(item);
        if (rear) {
            rear->next = newNode;
        } else {
            front = newNode; // If queue is empty
        }
        rear = newNode;
    }

    // Display the queue contents
    void display(int queueNumber) {
        cout << "Queue " << queueNumber << ":";
        shared_ptr<Node> current = front;
        while (current) {
            cout << " " << current->item;
            current = current->next;
        }
        cout << endl;
    }
};

int main() {
    int k, n;
    cin >> k >> n; // Number of queues and number of customers

    vector<Queue> queues(k); // Create k queues

    // Read n customers
    for (int i = 0; i < n; i++) {
        int item, queueNumber;
        cin >> item >> queueNumber; // Read item and queue number
        if (queueNumber >= 0 && queueNumber < k) {
            queues[queueNumber].enqueue(item); // Enqueue the item in the specified queue
        }
    }

    // Display the contents of each queue
    for (int i = 0; i < k; i++) {
        queues[i].display(i); // Display each queue's contents
    }

    return 0;
}   


// Write a program to implement a priority queue using an array-based approach. 



// The priority queue should support the following operations: insert an element into the priority queue with a specified priority, remove the element with the highest priority from the priority queue, and print the elements in the order of their priorities.



// Company Tags: Wipro

// Input format :
// The first line of input consists of an integer N, representing the number of elements to be inserted into the priority queue.

// This is followed by N lines, each containing two space-separated integers: element and priority. 1 has the highest priority.

// Output format :
// The first line of output prints the initial state of the priority queue after inserting all the elements, based on priority.

// The second line prints the state of the priority queue after performing the dequeue operation.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The priority queue can store up to 100 elements (MAX_SIZE = 100).

// Sample test cases :
// Input 1 :
// 5
// 4 2
// 3 1
// 6 4
// 2 3
// 1 5
// Output 1 :
// Priority Queue: 3 4 2 6 1 
// Priority Queue: 4 2 6 1 
// Input 2 :
// 3
// 9 1
// 2 2
// 7 3
// Output 2 :
// Priority Queue: 9 2 7 
// Priority Queue: 2 7 




#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class PriorityQueue {
private:
    static const int MAX_SIZE = 100; // Maximum size of the priority queue
    vector<pair<int, int>> elements; // Pair of <element, priority>

public:
    // Insert an element with its priority
    void insert(int element, int priority) {
        if (elements.size() < MAX_SIZE) {
            elements.push_back(make_pair(element, priority));
        }
    }

    // Remove the element with the highest priority (lowest priority number)
    void dequeue() {
        if (elements.empty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        // Find the index of the element with the highest priority
        auto it = min_element(elements.begin(), elements.end(), 
            [](const pair<int, int>& a, const pair<int, int>& b) {
                return a.second < b.second; // Lower number means higher priority
            });
        elements.erase(it); // Remove the element with the highest priority
    }

    // Print the elements in the priority queue based on their priorities
    void print() {
        if (elements.empty()) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        for (const auto& elem : elements) {
            cout << elem.first << " ";
        }
        cout << endl;
    }

    // Helper function to get the size of the queue
    int size() {
        return elements.size();
    }
};

int main() {
    PriorityQueue pq;
    int N;

    cout << "Enter the number of elements to insert into the priority queue: ";
    cin >> N;

    cout << "Enter element and priority pairs:" << endl;
    for (int i = 0; i < N; i++) {
        int element, priority;
        cin >> element >> priority;
        pq.insert(element, priority);
    }

    cout << "Priority Queue: ";
    pq.print();

    pq.dequeue(); // Remove the element with the highest priority

    cout << "Priority Queue: ";
    pq.print();

    return 0;
}




// Suppose you are assigned the task of developing a package delivery system for a logistics company. The system should enable efficient management of packages for delivery, including prioritizing deliveries based on certain criteria.



// The program utilizes a priority queue to manage packages for delivery. Each package is represented by its destination and delivery priority. The delivery priority is a value between 1 and 5, with lower values indicating higher priority for delivery (1 has the highest priority, next 2, and so on)



// The system offers the following options: Add package, Deliver package, View next package for delivery, and Exit.

// Input format :
// The input consists of an integer representing the choice from the menu.

// Choice 1: Add package

// Choice 2: Deliver the package

// Choice 3: View the next package for delivery

// Choice 4: Exit



// For Choice 1, the program expects the following inputs on separate lines:

// Package destination (string with spaces allowed)
// Delivery priority (integer between 1 and 5, inclusive)


// For choice 2, choice 3, and for choice 4, no additional input is required.

// Output format :
// The program outputs messages based on the user's choices.

// When adding a package to the delivery queue, the program outputs: "Package added to the delivery queue."

// When delivering a package, the program outputs: "Delivered package to: [Package Destination]"

// When delivering a package, if the queue is empty, print "No packages in the delivery queue."

// When viewing the next package for delivery, the program outputs: "Next package for delivery: [Package Destination]"

// When there are no packages in the delivery queue, the program outputs: "No packages in the delivery queue."

// When exiting the application, the program outputs: "Exiting the application."

// For invalid choices, the program outputs: "Invalid choice."



// Refer to the sample output for the exact text and format.

// Code constraints :
// The maximum queue size is 100.

// Sample test cases :
// Input 1 :
// 1
// Paris
// 3
// 1
// San Francisco
// 2
// 2
// 4
// Output 1 :
// Package added to the delivery queue.
// Package added to the delivery queue.
// Delivered package to: San Francisco
// Exiting the application.
// Input 2 :
// 1
// New York
// 2
// 2
// 4
// Output 2 :
// Package added to the delivery queue.
// Delivered package to: New York
// Exiting the application.
// Input 3 :
// 1
// London
// 4
// 3
// 4
// Output 3 :
// Package added to the delivery queue.
// Next package for delivery: London
// Exiting the application.
// Input 4 :
// 5
// 4
// Output 4 :
// Invalid choice.
// Exiting the application.
// Input 5 :
// 2
// 4
// Output 5 :
// No packages in the delivery queue.
// Exiting the application. 


#include <iostream>
#include <queue>
#include <string>
#include <vector>

using namespace std;

class Package {
public:
    string destination;
    int priority;

    Package(string dest, int pri) : destination(dest), priority(pri) {}

    // Comparison operator for the priority queue
    bool operator<(const Package& other) const {
        return priority > other.priority; // Higher priority (lower number) comes first
    }
};

class DeliverySystem {
private:
    priority_queue<Package> packageQueue;

public:
    void addPackage() {
        string destination;
        int priority;

        cout << "Enter package destination: ";
        cin.ignore(); // Clear the input buffer
        getline(cin, destination);
        cout << "Enter delivery priority (1-5): ";
        cin >> priority;

        if (priority < 1 || priority > 5) {
            cout << "Invalid priority. It must be between 1 and 5." << endl;
            return;
        }

        packageQueue.push(Package(destination, priority));
        cout << "Package added to the delivery queue." << endl;
    }

    void deliverPackage() {
        if (packageQueue.empty()) {
            cout << "No packages in the delivery queue." << endl;
            return;
        }
        
        Package nextPackage = packageQueue.top();
        packageQueue.pop();
        cout << "Delivered package to: " << nextPackage.destination << endl;
    }

    void viewNextPackage() {
        if (packageQueue.empty()) {
            cout << "No packages in the delivery queue." << endl;
            return;
        }
        
        cout << "Next package for delivery: " << packageQueue.top().destination << endl;
    }

    void run() {
        int choice;

        do {
            cout << "1. Add package\n2. Deliver package\n3. View next package for delivery\n4. Exit\n";
            cout << "Enter your choice: ";
            cin >> choice;

            switch (choice) {
                case 1:
                    addPackage();
                    break;
                case 2:
                    deliverPackage();
                    break;
                case 3:
                    viewNextPackage();
                    break;
                case 4:
                    cout << "Exiting the application." << endl;
                    break;
                default:
                    cout << "Invalid choice." << endl;
                    break;
            }
        } while (choice != 4);
    }
};

int main() {
    DeliverySystem system;
    system.run();
    return 0;
}



// Write a program to implement a priority queue using an array-based approach. 



// The priority queue should support the following operations: insert an element into the priority queue with a specified priority, remove the element with the highest priority from the priority queue, and print the elements in the order of their priorities.



// Company Tags: Wipro

// Input format :
// The first line of input consists of an integer N, representing the number of elements to be inserted into the priority queue.

// This is followed by N lines, each containing two space-separated integers: element and priority. 1 has the highest priority.

// Output format :
// The first line of output prints the initial state of the priority queue after inserting all the elements, based on priority.

// The second line prints the state of the priority queue after performing the dequeue operation.



// Refer to the sample output for the exact text and format.

// Code constraints :
// The priority queue can store up to 100 elements (MAX_SIZE = 100).

// Sample test cases :
// Input 1 :
// 5
// 4 2
// 3 1
// 6 4
// 2 3
// 1 5
// Output 1 :
// Priority Queue: 3 4 2 6 1 
// Priority Queue: 4 2 6 1 
// Input 2 :
// 3
// 9 1
// 2 2
// 7 3
// Output 2 :
// Priority Queue: 9 2 7 
// Priority Queue: 2 7

#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class PriorityQueue {
private:
    int elements[MAX_SIZE];
    int priorities[MAX_SIZE];
    int size;

public:
    PriorityQueue() : size(0) {}

    void insert(int element, int priority) {
        if (size < MAX_SIZE) {
            elements[size] = element;
            priorities[size] = priority;
            size++;
            // Sort the elements based on priority (higher priority has lower value)
            for (int i = size - 1; i > 0; i--) {
                if (priorities[i] < priorities[i - 1]) {
                    // Swap
                    swap(elements[i], elements[i - 1]);
                    swap(priorities[i], priorities[i - 1]);
                } else {
                    break;
                }
            }
        }
    }

    void remove() {
        if (size > 0) {
            // Shift all elements left to remove the first element
            for (int i = 1; i < size; i++) {
                elements[i - 1] = elements[i];
                priorities[i - 1] = priorities[i];
            }
            size--;
        }
    }

    void print() const {
        if (size == 0) {
            cout << "Priority Queue is empty." << endl;
            return;
        }
        cout << "Priority Queue: ";
        for (int i = 0; i < size; i++) {
            cout << elements[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    PriorityQueue pq;
    int N;

    cin >> N;

    for (int i = 0; i < N; i++) {
        int element, priority;
        cin >> element >> priority;
        pq.insert(element, priority);
    }

    pq.print(); // Print the initial state of the priority queue

    pq.remove(); // Perform the dequeue operation

    pq.print(); // Print the state of the priority queue after dequeueing

    return 0;
}



// Imagine you are designing an event registration system for a conference. As part of the system, you need to implement a queue data structure using an array that stores only the even numbers representing the registration IDs of the participants. 



// The queue will be used to keep track of the order in which participants register for the event.

// Input format :
// The first line of input consists of an integer n, representing the number of participants to register.

// The second line consists of n integers, representing the registration IDs of the participants.

// Output format :
// The output prints only the even number registration IDs of the participants in the order they registered, separated by space.

// For odd registration IDs, print "Invalid element [element], only even numbers can be enqueued".



// Refer to the sample output for formatting specifications.

// Code constraints :
// The maximum size of the queue is 100.

// Sample test cases :
// Input 1 :
// 6
// 2 4 6 8 10 12
// Output 1 :
// 2 4 6 8 10 12 
// Input 2 :
// 4
// 14 36 55 48
// Output 2 :
// Invalid element 55, only even numbers can be enqueued
// 14 36 48 
// Input 3 :
// 5
// 45 67 24 65 78
// Output 3 :
// Invalid element 45, only even numbers can be enqueued
// Invalid element 67, only even numbers can be enqueued
// Invalid element 65, only even numbers can be enqueued
// 24 78 


#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class EvenQueue {
private:
    int queue[MAX_SIZE];
    int front, rear;

public:
    EvenQueue() {
        front = -1;
        rear = -1;
    }

    bool isFull() {
        return rear == MAX_SIZE - 1;
    }

    bool isEmpty() {
        return front == -1 || front > rear;
    }

    void enqueue(int id) {
        if (id % 2 == 0) { // Check if the ID is even
            if (!isFull()) {
                if (front == -1) {
                    front = 0; // First element being added
                }
                rear++;
                queue[rear] = id;
            }
        } else {
            cout << "Invalid element " << id << ", only even numbers can be enqueued" << endl;
        }
    }

    void printQueue() const {
        // if (isEmpty()) {
        //     return; // No need to print anything
        // }
        for (int i = front; i <= rear; i++) {
            cout << queue[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    EvenQueue eq;
    int n;

    cin >> n; // Number of participants
    int id;

    for (int i = 0; i < n; i++) {
        cin >> id; // Read registration ID
        eq.enqueue(id); // Try to enqueue the ID
    }

    eq.printQueue(); // Print the queue contents

    return 0;
}

// You have been given the responsibility of designing a queue data structure by utilizing an array-based methodology.



// Write a program that performs the following:

// Enqueue Operation: Implement the enqueue operation to insert integers into the queue. 
// Dequeue Operation: After enqueuing all the elements, perform the dequeue operation. Print the dequeued elements in the order they were enqueued, separated by space. The dequeue operation should continue until the queue is empty.
// Input format :
// The first line of input consists of an integer N, representing the size.

// The second line consists of N integers, representing the elements inside the queue.

// Output format :
// The output prints "Dequeuing elements: " followed by the space-separated dequeued integer elements.



// Refer to the sample output for the exact text and format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ N ≤ 20

// 1 ≤ elements of the queue ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Dequeuing elements: 1 2 3 4 5 
// Input 2 :
// 8
// 45 69 85 25 36 94 17 49
// Output 2 :
// Dequeuing elements: 45 69 85 25 36 94 17 49


#include <iostream>

using namespace std;

class Queue {
private:
    int queue[20]; // Fixed size array for the queue
    int front, rear;
    int maxSize;

public:
    Queue(int size) {
        maxSize = size;
        front = 0; // Points to the front of the queue
        rear = -1; // Points to the last element in the queue
    }

    // Enqueue operation
    void enqueue(int value) {
        if (rear < maxSize - 1) {
            rear++;
            queue[rear] = value; // Add the element to the queue
        } else {
            cout << "Queue is full!" << endl; // Handle overflow
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front > rear) {
            cout << "Queue is empty!" << endl; // Handle underflow
        } else {
            cout << "Dequeuing elements: ";
            for (int i = front; i <= rear; i++) {
                cout << queue[i] << " "; // Print all elements
            }
            cout << endl;
            front = rear + 1; // Reset front to indicate the queue is now empty
        }
    }
};

int main() {
    int N;
    cin >> N; // Read the size of the queue

    Queue q(N); // Create a queue of size N

    for (int i = 0; i < N; i++) {
        int element;
        cin >> element; // Read each element
        q.enqueue(element); // Enqueue the element
    }

    q.dequeue(); // Perform the dequeue operation and print results

    return 0;
}



// Suppose you have been assigned the challenge of developing a queue data structure using a linked list. The program should allow users to interact with the queue by enqueuing positive integers and subsequently dequeuing and displaying elements.

// Input format :
// The input consists of a series of integers, one per line. Enter positive integers into the queue.

// Enter -1 to terminate input.

// Output format :
// The output prints the space-separated dequeued elements.



// Refer to the sample output for the exact text and format.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 1
// 2
// 3
// 4
// -1
// Output 1 :
// Dequeued elements: 1 2 3 4 
// Input 2 :
// 56
// 74
// 36
// 94
// 15
// 34
// -1
// Output 2 :
// Dequeued elements: 56 74 36 94 15 34


#include <iostream>

using namespace std;

// Node structure for linked list
struct Node {
    int data;
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(int value) {
        Node* newNode = new Node();
        newNode->data = value;
        newNode->next = nullptr;
        
        if (rear == nullptr) {
            // If the queue is empty, front and rear point to the new node
            front = rear = newNode;
        } else {
            // Add the new node to the end of the queue and update rear
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Dequeue operation
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty!" << endl; // Handle empty queue
            return;
        }

        Node* temp = front; // Temporarily hold the front node
        front = front->next; // Move front to the next node

        // If the queue is now empty, update rear
        if (front == nullptr) {
            rear = nullptr;
        }

        cout << temp->data << " "; // Print dequeued element
        delete temp; // Free memory
    }

    // Function to display all dequeued elements
    void displayDequeuedElements() {
        cout << "Dequeued elements: ";
        while (front != nullptr) {
            dequeue(); // Dequeue and print until empty
        }
        cout << endl;
    }
};

int main() {
    Queue q; // Create a queue object
    int value;

    // Read positive integers until -1 is entered
    while (true) {
        cin >> value;
        if (value == -1) {
            break; // Terminate input on -1
        }
        if (value > 0) {
            q.enqueue(value); // Enqueue only positive integers
        }
    }

    // Display all dequeued elements
    q.displayDequeuedElements();

    return 0;
}

// Alex is organizing a to-do list using a queue data structure for better task management. 



// He needs to implement a queue with the following functionalities: enqueue a task to add a new task to the end, get the front task to retrieve the description of the first task and get the rear task to retrieve the description of the last task. 



// Can you write a program that supports these operations using a linked list-based queue?

// Input format :
// The first line of input consists of an integer n, representing the number of tasks to enqueue.

// The following n lines consist of the descriptions of the tasks, one per line.



// Note: Use cin.ignore() to ignore the newline character after reading the value of n.

// Output format :
// The output displays the description of the tasks that are in the front and rear.



// Refer to the sample output for the exact text and format.

// Code constraints :
// 2 ≤ n ≤ 20

// The length of each task description is at most 500 characters.

// Sample test cases :
// Input 1 :
// 7
// Finish report
// Schedule meeting
// Send emails
// Attend training
// Prepare presentation
// Review documents
// Submit expenses
// Output 1 :
// Front Task: Finish report
// Rear Task: Submit expenses
// Input 2 :
// 5
// Buy groceries
// Pay bills
// Walk the dog
// Call mom
// Do laundry
// Output 2 :
// Front Task: Buy groceries
// Rear Task: Do laundry

#include <iostream>
#include <cstring>

using namespace std;

// Node structure for linked list
struct Node {
    char task[501]; // Array to hold task description (max 500 characters)
    Node* next;
};

// Queue class using linked list
class Queue {
private:
    Node* front;
    Node* rear;

public:
    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Enqueue operation
    void enqueue(const char* taskDescription) {
        Node* newNode = new Node();
        strncpy(newNode->task, taskDescription, 500);
        newNode->task[500] = '\0'; // Ensure null-termination
        newNode->next = nullptr;

        if (rear == nullptr) {
            // If the queue is empty, both front and rear point to the new node
            front = rear = newNode;
        } else {
            // Add the new node to the end of the queue
            rear->next = newNode;
            rear = newNode;
        }
    }

    // Get front task
    const char* getFront() {
        if (front != nullptr) {
            return front->task;
        }
        return nullptr;
    }

    // Get rear task
    const char* getRear() {
        if (rear != nullptr) {
            return rear->task;
        }
        return nullptr;
    }
};

int main() {
    Queue taskQueue; // Create a queue object
    int n;

    // Read the number of tasks
    cin >> n;
    cin.ignore(); // Ignore the newline character after reading n

    // Read task descriptions
    for (int i = 0; i < n; ++i) {
        char taskDescription[501]; // Array to hold the task description
        cin.getline(taskDescription, 501); // Read the entire line
        taskQueue.enqueue(taskDescription); // Enqueue the task
    }

    // Get and display the front and rear tasks
    const char* frontTask = taskQueue.getFront();
    const char* rearTask = taskQueue.getRear();

    if (frontTask != nullptr) {
        cout << "Front Task: " << frontTask << endl;
    }
    if (rearTask != nullptr) {
        cout << "Rear Task: " << rearTask << endl;
    }

    return 0;
}



// John is managing a list of numbers using a stack implemented as an array. He wants to push numbers onto the stack, calculate the average of the numbers in the stack, and pop a number from the stack while displaying the current average. Write a program to assist him with these tasks.

// Input format :
// The first line of input contains an integer n, representing the number of elements to be pushed onto the stack.

// The second line contains n space-separated integers, each representing an element to be pushed onto the stack.

// Output format :
// After pushing elements onto the stack, the first line of output prints the initial elements on the stack.

// The second line prints the average of the stack values, rounded off to two decimal places.

// If an element is popped from the stack, the third line prints the popped value.

// The fourth line prints the updated average of the stack, rounded off to two decimal places.



// Refer to the sample output for the exact format.

// Code constraints :
// The maximum size of the stack is 10.

// Sample test cases :
// Input 1 :
// 3
// 1 2 3
// Output 1 :
// Initial Stack: 3 2 1 
// Average: 2.00
// Popped Value: 3
// Updated Average: 1.50
// Input 2 :
// 6
// 23 78 94 27 19 74
// Output 2 :
// Initial Stack: 74 19 27 94 78 23 
// Average: 52.50
// Popped Value: 74
// Updated Average: 48.20

#include <iostream>
#include <iomanip>

using namespace std;

class Stack {
private:
    int arr[10]; // Stack array with a maximum size of 10
    int top;     // Top of the stack
    int count;   // Number of elements in the stack

public:
    Stack() : top(-1), count(0) {} // Constructor to initialize stack

    // Push an element onto the stack
    void push(int value) {
        if (top < 9) { // Check for stack overflow
            arr[++top] = value;
            count++;
        } else {
            cout << "Stack overflow!" << endl;
        }
    }

    // Pop an element from the stack
    int pop() {
        if (top >= 0) { // Check for stack underflow
            count--;
            return arr[top--];
        }
        return -1; // Return -1 if the stack is empty
    }

    // Calculate the average of the elements in the stack
    double average() {
        if (count == 0) return 0.0; // Avoid division by zero
        double sum = 0.0;
        for (int i = 0; i <= top; i++) {
            sum += arr[i];
        }
        return sum / count;
    }

    // Display the elements in the stack
    void display() {
        for (int i = top; i >= 0; i--) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    Stack stack; // Create a stack object
    int n;

    // Read the number of elements to be pushed onto the stack
    cin >> n;

    // Read the elements and push onto the stack
    for (int i = 0; i < n; i++) {
        int value;
        cin >> value;
        stack.push(value);
    }

    // Display initial stack elements
    cout << "Initial Stack: ";
    stack.display();

    // Calculate and display the average
    double avg = stack.average();
    cout << "Average: " << fixed << setprecision(2) << avg << endl;

    // Pop an element from the stack
    int poppedValue = stack.pop();
    if (poppedValue != -1) {
        cout << "Popped Value: " << poppedValue << endl;

        // Calculate and display the updated average
        double updatedAvg = stack.average();
        cout << "Updated Average: " << fixed << setprecision(2) << updatedAvg << endl;
    } else {
        cout << "No element to pop!" << endl;
    }

    return 0;
}



// In a busy hospital, beds are allocated to patients as they arrive. You are an administrator at a hospital in charge of managing the allocation of beds. 



// You need to perform the following tasks:

// Allocate Beds: As new patients arrive, their beds are assigned and pushed onto the stack.
// View Allocation: After allocating a series of beds, you need to view the stack of beds in the order they were allocated (i.e., from the most recently allocated to the oldest).
// Sort Beds: To optimize bed management, you need to sort the stack of bed IDs in ascending order based on their IDs.


// Write a program to implement the above operations using a stack with a linked list.

// Input format :
// The first line of input contains an integer n, representing the number of beds to be allocated.

// The second line contains n space-separated integers, each denoting a bed ID.

// Output format :
// The first line of output prints the original stack of bed IDs in the order they were allocated.

// The second line prints the stack of bed IDs sorted in ascending order.



// Refer to the sample output for formatting specifications.

// Code constraints :
// 1 ≤ n ≤ 10

// 1 ≤ ID ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 4 5 6 3 2
// Output 1 :
// Original Stack: 2 3 6 5 4 
// Sorted Stack: 2 3 4 5 6 
// Input 2 :
// 8
// 3 2 4 5 6 9 8 7
// Output 2 :
// Original Stack: 7 8 9 6 5 4 2 3 
// Sorted Stack: 2 3 4 5 6 7 8 9

#include <iostream>
using namespace std;

// Node structure for the linked list
struct Node {
    int bedID;
    Node* next;
};

// Stack class using a linked list
class Stack {
private:
    Node* top;

public:
    Stack() : top(nullptr) {} // Constructor to initialize the stack

    // Push a bed ID onto the stack
    void push(int bedID) {
        Node* newNode = new Node();
        newNode->bedID = bedID;
        newNode->next = top;
        top = newNode;
    }

    // Pop a bed ID from the stack
    int pop() {
        if (top == nullptr) return -1; // Return -1 if stack is empty
        int bedID = top->bedID;
        Node* temp = top;
        top = top->next;
        delete temp;
        return bedID;
    }

    // Display the stack elements
    void display() {
        Node* current = top;
        while (current != nullptr) {
            cout << current->bedID << " ";
            current = current->next;
        }
    }

    // Sort the stack using bubble sort
    void sort() {
        if (top == nullptr) return; // No elements to sort

        // Convert stack to array for sorting
        int arr[10]; // Max size as per the problem statement
        int count = 0;
        Node* current = top;
        
        while (current != nullptr) {
            arr[count++] = current->bedID;
            current = current->next;
        }

        // Bubble sort
        for (int i = 0; i < count - 1; i++) {
            for (int j = 0; j < count - i - 1; j++) {
                if (arr[j] > arr[j + 1]) {
                    // Swap arr[j] and arr[j + 1]
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                }
            }
        }

        // Reconstruct the stack from the sorted array
        top = nullptr; // Reset stack
        for (int i = count - 1; i >= 0; i--) {
            push(arr[i]);
        }
    }
};

int main() {
    Stack stack; // Create a stack object
    int n;

    // Read the number of beds to be allocated
    cin >> n;
    
    // Read bed IDs and push onto the stack
    for (int i = 0; i < n; i++) {
        int bedID;
        cin >> bedID;
        stack.push(bedID);
    }

    // Display original stack
    cout << "Original Stack: ";
    stack.display();
    cout << endl;

    // Sort the stack
    stack.sort();

    // Display sorted stack
    cout << "Sorted Stack: ";
    stack.display();
    cout << endl;

    return 0;
}