/*
#include "graph.h"
 
int main()
{
    Graph g(10); 
    
    // Adding vertices
    g.addVertex('A');
    g.addVertex('B');
    g.addVertex('C');
    g.addVertex('D');
    g.addVertex('E');
    g.addVertex('F');  
    g.addVertex('G');
    g.addVertex('H');
    g.addVertex('I');
    g.addVertex('J');

    // Adding edges
    g.addEdge('A', 'B', 1);
    g.addEdge('A', 'C', 2);
    g.addEdge('B', 'D', 3);
    g.addEdge('C', 'E', 4);
    g.addEdge('C', 'D', 5);
    g.addEdge('E', 'D', 6);
    g.addEdge('A', 'H', 7);
    g.addEdge('B', 'G', 8);
    g.addEdge('F', 'I', 9);
    g.addEdge('F', 'J', 10);
    g.addEdge('I', 'J', 11);
    g.addEdge('C', 'F', 12); 
    g.addEdge('D', 'F', 13);
    g.addEdge('C', 'H', 14);

    // Removing a vertex and some edges
    //g.removeVertex('F');
    // g.removeEdge('C', 'H');
    // g.removeEdge('D', 'E');

    // Display adjacency list and matrix
    g.displayAdjList();
    g.displayAdjMatrix();
    
    cout << endl;

    // Perform BFS and DFS starting from vertex 'A'
    g.bfsL('A');
    // g.bfsM('A');
    //g.dfsL('A');
    //g.dfsM('A');  


    cout << endl;


    return 0;
}
*/
#include <iostream>  // Include standard input/output stream
#include "graph.h"   // Include the header file for graph functions

int main() {
    // Create a graph with 5 vertices (example graph)
    Graph g(5);  // Initialize a graph with 5 vertices

    // Adding edges to the graph (undirected)
    g.addEdge(0, 1);  // Add edge between vertex 0 and 1
    g.addEdge(0, 2);  // Add edge between vertex 0 and 2
    g.addEdge(1, 3);  // Add edge between vertex 1 and 3
    g.addEdge(1, 4);  // Add edge between vertex 1 and 4
    g.addEdge(2, 3);  // Add edge between vertex 2 and 3

    // Displaying the graph using BFS with Matrix representation
    std::cout << "BFS (Matrix representation) starting from vertex 0:" << std::endl;
    g.bfsM(0);  // Perform BFS traversal using matrix representation starting from vertex 0

    // Displaying the graph using DFS with List representation
    std::cout << "DFS (List representation) starting from vertex 0:" << std::endl;
    g.dfsL(0);  // Perform DFS traversal using list representation starting from vertex 0

    // Displaying the graph using DFS with Matrix representation
    std::cout << "DFS (Matrix representation) starting from vertex 0:" << std::endl;
    g.dfsM(0);  // Perform DFS traversal using matrix representation starting from vertex 0

    // Removing an edge and performing DFS again
    std::cout << "Removing edge between 1 and 4" << std::endl;
    g.removeEdge(1, 4);  // Remove the edge between vertex 1 and 4

    std::cout << "DFS (List representation) after removing edge between 1 and 4:" << std::endl;
    g.dfsL(0);  // Perform DFS again after removing the edge, starting from vertex 0

    // Checking for cycle in the graph
    if (g.detectCycle()) {  // Check if the graph contains a cycle
        std::cout << "The graph contains a cycle." << std::endl;  // If cycle detected
    } else {
        std::cout << "The graph does not contain a cycle." << std::endl;  // If no cycle detected
    }

    // Adding a cycle to the graph (for testing cycle detection)
    g.addEdge(4, 0);  // Add an edge between vertex 4 and 0 to create a cycle: 0-1-4-0

    std::cout << "DFS (List representation) after adding a cycle:" << std::endl;
    g.dfsL(0);  // Perform DFS again after adding a cycle, starting from vertex 0

    // Check for cycle again after adding a cycle
    if (g.detectCycle()) {  // Check if the graph contains a cycle after adding the cycle
        std::cout << "The graph contains a cycle." << std::endl;  // If cycle detected
    } else {
        std::cout << "The graph does not contain a cycle." << std::endl;  // If no cycle detected
    }

    return 0;  // Exit the program
}
