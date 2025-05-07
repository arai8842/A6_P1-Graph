#include "sqll.h"  // Include header file for linked list functions

// Adds a new node with the given value to the front of the list
void push(node *&head, int value) {
    node *newNode = new node;  // Create a new node
    newNode->data = value;     // Set the node's data to the given value
    newNode->next = nullptr;   // Set the next pointer to null (it'll be the first node)

    // Insert at index 0 (make the new node the head of the list)
    newNode->next = head;      // Point new node to the current head
    head = newNode;            // Update head to the new node
}

// Removes the first node from the list
void pop(node *&head) {
    if(head == nullptr) {      // Check if the list is empty
        cout << "Empty list, nothing to pop" << endl;  // Output message if list is empty
        return;  // Exit function
    }

    // Remove the head node
    node *dltTemp = head;      // Store the current head temporarily
    head = head->next;         // Move head to the next node
    delete dltTemp;            // Free memory by deleting the old head node
}

// Adds a new node with the given value to the end of the list
void enqueue(node *&head, int value) {
    node *newNode = new node;  // Create a new node
    newNode->data = value;     // Set the node's data to the given value
    newNode->next = nullptr;   // Set the next pointer of the new node to null (it'll be the last node)

    if(head == nullptr) {      // Check if the list is empty
        head = newNode;         // If empty, make the new node the head
        return;                 // Exit the function
    }

    // Insert at the end (traverse the list until reaching the last node)
    node *walker = head;       // Start from the head
    while(walker->next != nullptr) {  // Traverse to the last node
        walker = walker->next;        // Move to the next node
    }
    walker->next = newNode;     // Set the last node's next pointer to the new node
}

// Removes the first node from the list (same as pop)
void dequeue(node *&head) {
    if (head == nullptr) {     // Check if the list is empty
        cout << "Empty list, nothing to dequeue!" << endl;  // Output message if list is empty
        return;  // Exit function
    }

    // Remove the head node
    node *dltTemp = head;      // Store the current head temporarily
    head = head->next;         // Move head to the next node
    delete dltTemp;            // Free memory by deleting the old head node
}

// Displays all nodes in the list
void displayList(node *&head) {
    node *walker = head;  // Start from the head

    while(walker != nullptr) {  // Traverse the list
        cout << walker->data << " ";  // Print the data of each node
        walker = walker->next;        // Move to the next node
    }
    cout << endl;  // Print a new line after displaying the list
}
