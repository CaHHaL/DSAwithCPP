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

// Node structure for the linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the beginning of the linked list
void insertAtBeginning(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;
    newNode->next = head;
    head = newNode;
    cout << "Node inserted" << endl;
}

// Function to display the linked list
void displayLinkedList(Node* head) {
    cout << "Linked List: ";
    Node* current = head;
    while (current != nullptr) {
        cout << current->data << " ";
        current = current->next;
    }
    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize the head of the linked list
    int n, choice;

    while (true) {
        // cout << "Enter an integer to insert: ";
        cin >> n;

        // Insert the integer at the beginning of the list
        insertAtBeginning(head, n);

        // cout << "Do you want to continue inserting? (0 for yes, 1 for no): ";
        cin >> choice;

        if (choice == 1) {
            break; // Exit the loop if user chooses to stop
        }
    }

    // Display the final linked list
    displayLinkedList(head);
    cout << "Node ended" << endl;

    // Clean up the allocated memory
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }

    return 0;
}






// Imagine you are developing a contact management application where users can maintain a singly linked list of names. 



// Initially, users can enter a sequence of names to form a list of contacts. Later, they can insert a new name at a specific position within the list to rearrange their contacts, ensuring the list is updated and displayed correctly.

// Input format :
// The first line of input consists of an integer n, representing the number of initial names.

// The next n lines each contain a single name, representing the initial list of contacts.

// The last line consists of a name and an integer pos, representing the new contact to be added and its position in the list.

// Output format :
// The output prints the updated list of contacts after inserting the new contact at the specified position.



// Refer to the sample output for formatting specifications.

// Code constraints :
// The given test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ length of each name ≤ 100

// Sample test cases :
// Input 1 :
// 4
// John
// Alice
// Bob
// Emma
// Michael 3
// Output 1 :
// John Alice Michael Bob Emma 
// Input 2 :
// 3
// Emma
// Daniel
// Sophia
// Charlotte 1
// Output 2 :
// Charlotte Emma Daniel Sophia



#include <iostream>
#include <string>

struct Node {
    std::string name;
    Node* next;
};

class ContactList {
private:
    Node* head;

public:
    ContactList() : head(nullptr) {}

    // Function to insert a name at the end of the list
    void insertAtEnd(const std::string& name) {
        Node* newNode = new Node{name, nullptr};
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    // Function to insert a name at a specific position
    void insertAtPosition(const std::string& name, int pos) {
        Node* newNode = new Node{name, nullptr};
        if (pos == 0) {
            newNode->next = head;
            head = newNode;
            return;
        }

        Node* temp = head;
        for (int i = 0; i < pos - 1 && temp != nullptr; ++i) {
            temp = temp->next;
        }

        if (temp != nullptr) {
            newNode->next = temp->next;
            temp->next = newNode;
        } else {
            // If position is greater than length, add at the end
            insertAtEnd(name);
        }
    }

    // Function to display the contact list
    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->name;
            if (temp->next != nullptr) {
                std::cout << " ";
            }
            temp = temp->next;
        }
        std::cout << std::endl;
    }

    // Destructor to clean up memory
    ~ContactList() {
        Node* current = head;
        while (current != nullptr) {
            Node* nextNode = current->next;
            delete current;
            current = nextNode;
        }
    }
};

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); // To ignore the newline character after reading n

    ContactList contacts;

    // Read initial names
    for (int i = 0; i < n; ++i) {
        std::string name;
        std::getline(std::cin, name);
        contacts.insertAtEnd(name);
    }

    // Read the new contact and position
    std::string newName;
    int position;
    std::cin >> newName >> position;

    // Insert the new contact at the specified position
    contacts.insertAtPosition(newName, position-1);
    
    // Display the updated list
    contacts.display();

    return 0;
}




// Kamal wants to create a linked list and perform the following operations on it:

// Insert a node at the beginning of the linked list.
// After inserting, append a node at the end of the linked list.
// Print the final linked list.


// Write a program that takes the number of nodes to be inserted, followed by their values, as input. After inserting the nodes, the program should ask for a new value and append a node with that value at the end of the linked list. Finally, the program should print the contents of the linked list.



// Example



// Input:

// 5

// 1 2 3 4 5

// 6



// Output:

// Created Linked list: 5 4 3 2 1

// Final list: 5 4 3 2 1 6 // after appending the new value



// Explanation:

// The input specifies that there are 5 nodes, and their values are 1, 2, 3, 4, and 5 which are inserted at the beginning. So the created list is 5 4 3 2 1. 

// After inserting these nodes, the new value 6 is inserted at the end of the linked list. The final list is 5 4 3 2 1 6



// Company tags: Capgemini

// Input format :
// The first line consists of an integer, n, representing the number of nodes to be initially inserted into the linked list.

// The second line of input consists of n space-separated integers, representing the elements of the linked list.

// The third line of input consists of an integer, m, representing the value of the new node to be inserted at the end of the linked list.

// Output format :
// The first line of output prints "Created Linked list: " followed by the initial linked list elements, separated by space.

// The second line of output prints "Final list: " followed by the final linked list elements, after appending the new node, separated by space.



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 10

// 1 ≤ elements, m ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// 6
// Output 1 :
// Created Linked list: 5 4 3 2 1
// Final list: 5 4 3 2 1 6
// Input 2 :
// 3
// 10 20 30
// 40
// Output 2 :
// Created Linked list: 30 20 10
// Final list: 30 20 10 40



// You are given the task of developing a program that operates on a circular header linked list, a variant of the standard linked list. In this circular header linked list, the last node points back to the header node, forming a circular structure.



// Your goal is to implement a program that inserts elements at the end of the circular linked list and prints the data values of alternate nodes.



// Company Tags: TCS

// Input format :
// The first line contains an integer n, representing the number of elements in the circular linked list.

// The second line contains n space-separated integers, representing the elements to be inserted into the linked list.

// Output format :
// The output displays "Alternate Nodes: " followed by the data of every alternate node in the circular linked list.

// If no elements are inserted, print "Linked List is empty".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Alternate Nodes: 1 3 5 
// Input 2 :
// 0
// Output 2 :
// Linked List is empty


#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == nullptr) {
        head = newNode;
        head->next = head; // Point to itself, making it circular
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the new node at the end
        newNode->next = head; // Complete the circle
    }
}

// Function to print alternate nodes of the circular linked list
void printAlternateNodes(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }

    cout << "Alternate Nodes: ";
    Node* current = head;
    bool alternate = true; // Flag to track alternate nodes

    do {
        if (alternate) {
            cout << current->data << " ";
        }
        alternate = !alternate; // Toggle alternate flag
        current = current->next; // Move to the next node
    } while (current != head); // Stop when we circle back to the head

    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize the head of the circular linked list
    int n;

    cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked List is empty" << endl;
        return 0; // Exit if no elements to insert
    }

    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        insertAtEnd(head, element);
    }

    // Print alternate nodes
    printAlternateNodes(head);

    // Clean up the allocated memory
    if (head != nullptr) {
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    return 0;
}



// You are given the task of developing a program that operates on a circular header linked list, a variant of the standard linked list. In this circular header linked list, the last node points back to the header node, forming a circular structure.



// Your goal is to implement a program that inserts elements at the end of the circular linked list and prints the data values of alternate nodes.



// Company Tags: TCS

// Input format :
// The first line contains an integer n, representing the number of elements in the circular linked list.

// The second line contains n space-separated integers, representing the elements to be inserted into the linked list.

// Output format :
// The output displays "Alternate Nodes: " followed by the data of every alternate node in the circular linked list.

// If no elements are inserted, print "Linked List is empty".



// Refer to the sample output for formatting specifications.

// Code constraints :
// In this scenario, the test cases fall under the following constraints:

// 1 ≤ n ≤ 15

// 1 ≤ elements ≤ 100

// Sample test cases :
// Input 1 :
// 5
// 1 2 3 4 5
// Output 1 :
// Alternate Nodes: 1 3 5 
// Input 2 :
// 0
// Output 2 :
// Linked List is empty




#include <iostream>

using namespace std;

// Node structure for the circular linked list
struct Node {
    int data;
    Node* next;
};

// Function to insert a node at the end of the circular linked list
void insertAtEnd(Node*& head, int newData) {
    Node* newNode = new Node();
    newNode->data = newData;

    if (head == nullptr) {
        head = newNode;
        head->next = head; // Point to itself, making it circular
    } else {
        Node* temp = head;
        while (temp->next != head) {
            temp = temp->next; // Traverse to the last node
        }
        temp->next = newNode; // Link the new node at the end
        newNode->next = head; // Complete the circle
    }
}

// Function to print alternate nodes of the circular linked list
void printAlternateNodes(Node* head) {
    if (head == nullptr) {
        cout << "Linked List is empty" << endl;
        return;
    }

    cout << "Alternate Nodes: ";
    Node* current = head;
    bool alternate = true; // Flag to track alternate nodes

    do {
        if (alternate) {
            cout << current->data << " ";
        }
        alternate = !alternate; // Toggle alternate flag
        current = current->next; // Move to the next node
    } while (current != head); // Stop when we circle back to the head

    cout << endl;
}

int main() {
    Node* head = nullptr; // Initialize the head of the circular linked list
    int n;

    // cout << "Enter the number of elements: ";
    cin >> n;

    if (n <= 0) {
        cout << "Linked List is empty" << endl;
        return 0; // Exit if no elements to insert
    }

    // cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        int element;
        cin >> element;
        insertAtEnd(head, element);
    }

    // Print alternate nodes
    printAlternateNodes(head);

    // Clean up the allocated memory
    if (head != nullptr) {
        Node* current = head;
        Node* nextNode;
        do {
            nextNode = current->next;
            delete current;
            current = nextNode;
        } while (current != head);
    }

    return 0;
}
