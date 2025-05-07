/*
#include "graph.h"

Graph::Graph(int maxV)
{
    maxVertices = maxV;
    numVertices = 0;
    vertices = nullptr;

    adjMatrix = new int*[maxVertices]; // pointer of rows
    // each int* stores a row
    for(int i = 0; i < maxVertices; i++)
    {
        adjMatrix[i] = new int[maxVertices]; // create a new row (array of ints)
        for(int j = 0; j < maxVertices; j++)
            adjMatrix[i][j] = 0;
    }

    visited = new bool[maxVertices] {false};    
}

Graph::~Graph()
{
    delete[] visited;

    for(int i = 0; i < maxVertices; i++)
    {
        delete[] adjMatrix[i];
    }
    delete[] adjMatrix;

    vertex* tempVertex;
    while (vertices) 
    {
        edge* tempEdge;
        // free the memory of the neighbor list of that vertex
        while(vertices->aHead)
        {
            tempEdge = vertices->aHead;
            vertices->aHead = vertices->aHead->eNext;
            delete tempEdge;
        }
        // free that vertex itself
        tempVertex = vertices;
        vertices = vertices->vNext;
        delete tempVertex;

    }
}

void Graph::addVertex(char data)
{
    if(numVertices >= maxVertices)
    {
        cout << "Max number of vertices reached!" << endl;
        return;
    }

    vertex* newVertex = new vertex;
    newVertex->data = data;
    newVertex->vNext = vertices;
    newVertex->aHead = nullptr;
    newVertex->visited = 0;
    vertices = newVertex;

    numVertices++;
}

void Graph::addEdge(char src, char dest, int weight)
{
    vertex* srcVertex = vertices;
    vertex* destVertex = vertices;

    // find src and dest vertices
    while(srcVertex && srcVertex->data != src)
    {
        srcVertex = srcVertex->vNext;
    }
    while(destVertex && destVertex->data != dest)
    {
        destVertex = destVertex->vNext;
    }

    if(!srcVertex || !destVertex)
    {
        cout << "Vertices not found - can't add an edge" << endl;
        return;
    }

    // Adj list - undirected graph
    edge* newEdge = new edge;
    newEdge->dest = destVertex;
    newEdge->weight = weight;
    newEdge->eNext = srcVertex->aHead;
    srcVertex->aHead = newEdge;

    // Since undirected, add the reverse edge as well
    newEdge = new edge;
    newEdge->dest = srcVertex;
    newEdge->weight = weight;
    newEdge->eNext = destVertex->aHead;
    destVertex->aHead = newEdge;

    // Adj Matrix
    int srcIndex = srcVertex->data - 'A';
    int destIndex = destVertex->data - 'A';
    adjMatrix[srcIndex][destIndex] = weight;
    adjMatrix[destIndex][srcIndex] = weight;
}

void Graph::removeVertex(char data)
{
    // find the vertex
    vertex* temp = vertices;
    vertex* prev = nullptr;

    while(temp && temp->data != data)
    {
        prev = temp;
        temp = temp->vNext;
    }
    
    if(!temp)
    {
        cout << "Vertex not found - can't remove" << endl;
        return;
    }

    // remove that vertex from the adj list of all other vertices
    for(vertex* v = vertices; v != nullptr; v = v->vNext)
    {
        edge* e = v->aHead;
        edge* prevEdge = nullptr;
        while(e)
        {
            if(e->dest->data == data)
            {
                if(prevEdge)
                    prevEdge->eNext = e->eNext;
                else
                    v->aHead = e->eNext;
                delete e;
                break;
            }
            prevEdge = e;
            e = e->eNext;
        }
    }

    // remove the vertex
    if(prev)
        prev->vNext = temp->vNext;
    else
        vertices = temp->vNext;

    delete temp;

    // Adj matrix
    int index = temp->data - 'A';
    for(int i = 0; i < maxVertices; i++)
    {
        adjMatrix[i][index] = 0;
        adjMatrix[index][i] = 0;
    }

    numVertices--;
}

void Graph::displayAdjList()
{
    for(vertex* v = vertices; v != nullptr; v = v->vNext)
    {
        cout << v->data << " -> ";
        for(edge* e = v->aHead; e != nullptr; e = e->eNext)
        {
            cout << e->dest->data << " (" << e->weight << ") -> ";
        }
        cout << "null" << endl;
    }
    cout << endl;
}

void Graph::displayAdjMatrix()
{
    cout << "     ";
    for(int i = 0; i < maxVertices; i++)
    {
        cout << setw(3) << char('A' + i) << " "; // column headers
    }
    cout << endl;
    cout << "   ";
    
    for(int i = 0; i < maxVertices; i++)
    {
        cout << "-----";
    }
    cout << endl;

    for(int i = 0; i < maxVertices; i++)
    {
        cout << setw(3) << char('A' + i) << " |"; // row header
        for(int j = 0; j < maxVertices; j++)
        {
            cout << setw(3) << adjMatrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Graph::bfsL(char start)
{
    for(int i = 0; i < maxVertices; i++)
        visited[i] = false;

    // find the start vertex
    vertex* startVertex = vertices;
    while(startVertex && startVertex->data != start)
        startVertex = startVertex->vNext;

    if(!startVertex)
    {
        cout << "Start vertex not found - can't traverse" << endl;
        return;
    }

    // initialize queue for bfs
    node* queue = nullptr;
    enqueue(queue, start); 
    visited[startVertex->data - 'A'] = true;

    cout << "BFS traversal Adjacency List : ";
    while (queue)
    {
        // dequeue the front
        char currentData = queue->data;
        dequeue(queue);
        cout << currentData << " ";

        // find the vertex corresponding to the dequeued element
        vertex* currentVertex = vertices;
        while(currentVertex && currentVertex->data != currentData)
            currentVertex = currentVertex->vNext;

        // add all its neighbors to the queue
        for(edge* e = currentVertex->aHead; e != nullptr; e = e->eNext)
        {
            if(!visited[e->dest->data - 'A'])
            {
                enqueue(queue, e->dest->data);
                visited[e->dest->data - 'A'] = true;
            }
        }
    }
    cout << endl; 
}
*/


#include "graph.h"
#include <iostream>
#include <vector>
#include <list>
#include <queue>
#include <stack>

// Constructor
Graph::Graph(int V) {
    this->V = V;
    adjList.resize(V);
    adjMatrix.resize(V, std::vector<int>(V, 0));
}

// Add an edge from v to w in the graph (adjacency list)
void Graph::addEdge(int v, int w) {
    adjList[v].push_back(w);
    adjList[w].push_back(v); // For undirected graph
    adjMatrix[v][w] = 1;
    adjMatrix[w][v] = 1; // For undirected graph
}

// Remove an edge from v to w in the graph
void Graph::removeEdge(int v, int w) {
    adjList[v].remove(w);
    adjList[w].remove(v); // For undirected graph
    adjMatrix[v][w] = 0;
    adjMatrix[w][v] = 0; // For undirected graph
}

// BFS using matrix representation
void Graph::bfsM(int startVertex) {
    std::vector<bool> visited(V, false);
    std::queue<int> q;

    visited[startVertex] = true;
    q.push(startVertex);

    while (!q.empty()) {
        int current = q.front();
        q.pop();
        std::cout << current << " ";

        for (int i = 0; i < V; ++i) {
            if (adjMatrix[current][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
    std::cout << std::endl;
}

// DFS using list representation
void Graph::dfsL(int startVertex) {
    std::vector<bool> visited(V, false);
    std::stack<int> s;

    s.push(startVertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            std::cout << current << " ";

            for (auto& adjVertex : adjList[current]) {
                if (!visited[adjVertex]) {
                    s.push(adjVertex);
                }
            }
        }
    }
    std::cout << std::endl;
}

// DFS using matrix representation
void Graph::dfsM(int startVertex) {
    std::vector<bool> visited(V, false);
    std::stack<int> s;

    s.push(startVertex);

    while (!s.empty()) {
        int current = s.top();
        s.pop();

        if (!visited[current]) {
            visited[current] = true;
            std::cout << current << " ";

            for (int i = 0; i < V; ++i) {
                if (adjMatrix[current][i] == 1 && !visited[i]) {
                    s.push(i);
                }
            }
        }
    }
    std::cout << std::endl;
}

// Helper function for cycle detection (DFS-based)
bool Graph::detectCycleUtil(int v, std::vector<bool>& visited, std::vector<bool>& recStack) {
    visited[v] = true;  // Mark the current node as visited
    recStack[v] = true; // Add current node to the recursion stack

    // Visit all adjacent vertices (neighbors)
    for (auto& adjVertex : adjList[v]) {
        // If the neighbor hasn't been visited, perform DFS on it
        if (!visited[adjVertex] && detectCycleUtil(adjVertex, visited, recStack)) {
            return true;
        }
        // If the neighbor is already in the recursion stack, a cycle is detected
        else if (recStack[adjVertex]) {
            return true;
        }
    }

    // Remove the current vertex from the recursion stack (backtracking)
    recStack[v] = false;
    return false;
}

// Detect cycle in the graph
bool Graph::detectCycle() {
    std::vector<bool> visited(V, false);  // Keeps track of visited vertices
    std::vector<bool> recStack(V, false); // Keeps track of recursion stack

    // Start DFS from every unvisited vertex
    for (int i = 0; i < V; ++i) {
        if (!visited[i]) {
            if (detectCycleUtil(i, visited, recStack)) {
                return true; // Cycle found
            }
        }
    }
    return false; // No cycle found
}
