#ifndef SQLL_H
#define SQLL_H

#include <iostream>  // Standard input/output library
using namespace std; // Using the standard namespace

/* Node structure for linked list */
struct node
{
    int data;           // Value stored in the node
    struct node* next;  // Pointer to the next node
};

/* Adds a value to the front of the list */
void push(node *&head, int value);  

/* Removes the first node in the list */
void pop(node *&head);  

/* Adds a value to the end of the list */
void enqueue(node *&head, int value);  

/* Removes the first node in the list */
void dequeue(node *&head);  

/* Displays the entire list */
void displayList(node *&head);  

#endif  // Prevents multiple inclusion of the file



