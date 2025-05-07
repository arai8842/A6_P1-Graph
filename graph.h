/*
#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <iomanip>
#include <string>
#include "sqll.h"  // for our traversal algorithms

using namespace std;

struct edge
{
    struct vertex* dest;
    edge* eNext;
    int weight;
};

struct vertex
{
    char data;
    vertex* vNext;
    edge* aHead;

    // for traversal
    short visited;
};

// implementing both adj list and adj matrix for an undirected weighed graph
class Graph 
{
    private:
        vertex* vertices; // list of vertices
        int** adjMatrix; 
        bool* visited;
        int maxVertices;
        int numVertices;

    public:
        Graph(int maxV);
        ~Graph();

        // core operations
        void addVertex(char data);
        void addEdge(char src, char dest, int weight);
        void removeVertex(char data);
        void removeEdge(char src, char dest);  // complete this

        // display
        void displayAdjList();
        void displayAdjMatrix();

        // traversal/search algorithms
        void bfsL(char start);
        void bfsM(char start); // complete this
        void dfsL(char start); // complete this
        void dfsM(char start); // complete this

        // ---------------- Extra Credits - Pick one of the two ----------------------------- 
        // Detect cycle with DFS - Option 1
        // bool detectCycleDFS();

        // Print Connected Components - Option 2
        // void connectedComponents();
};

#endif

*/

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <list>

class Graph {
public:
    Graph(int V); // Constructor
    void addEdge(int v, int w); // Adds an edge to the graph (adjacency list)
    void removeEdge(int v, int w); // Removes an edge from the graph
    void bfsM(int startVertex); // BFS using matrix representation
    void dfsL(int startVertex); // DFS using list representation
    void dfsM(int startVertex); // DFS using matrix representation
    bool detectCycle(); // Detects if a cycle exists in the graph
    
private:
    int V; // Number of vertices
    std::vector<std::list<int>> adjList; // Adjacency list representation
    std::vector<std::vector<int>> adjMatrix; // Adjacency matrix representation
    bool detectCycleUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack); // Helper function for cycle detection
};

#endif
