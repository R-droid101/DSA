/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Objective: To find shortest path of each point within graph using Dijkstra's algorithm
*/

#include <iostream>
#include <vector>
#include <limits.h>

using namespace std;

int minimum_distance(int distance[], bool label[], int n)
{ // function to find the minimum distance and label it
    int min = INT_MAX, min_index;

    for (int vertice = 0; vertice < n; vertice++) // runs through vertices to check which one has the least distance of the lot
        if (label[vertice] == false && distance[vertice] <= min)
            min = distance[vertice], min_index = vertice;

    return min_index;
}

void dijkstra(int n, vector<vector<int>> &graph, int root, int distance[])
{                               // main function implementing the dijkstra algorithm
    bool label[n];              // function to label a vertice
    for (int i = 0; i < n; i++) // loop to initialize all vertices as per algorithm
    {
        distance[i] = INT_MAX;
        label[i] = false;
    }
    distance[root] = 0; // making the distance from root = 0

    for (int x = 0; x < n - 1; x++)
    {
        int u = minimum_distance(distance, label, n);
        label[u] = true;
        for (int v = 0; v < n; v++) // going through each vertice
            if (!label[v] && graph[u][v] && distance[u] != INT_MAX && distance[u] + graph[u][v] < distance[v])
                distance[v] = distance[u] + graph[u][v];
    }
}

int main()
{
    int n;
    vector<vector<int>> graph;
    int distance[n];
    int start;
    cout << "Read number of elements in graph:" << endl;
    cin >> n; // reading the number of elements in the graph
    cout << "Input the elements of graph as an adjacency matrix:" << endl;
    for (int i = 0; i < n; i++)
    { // reading the graph in the form of an adjacency matrix
        vector<int> row;
        int temp;
        for (int j = 0; j < n; j++)
        {
            cin >> temp;
            row.push_back(temp);
        }
        graph.push_back(row);
    }

    cout << "The numbers in the graph start from 1." << endl;

    cout << "Input root element:" << endl;
    cin >> start; // reading the root node in the graph so we know which node the BFS has to start from

    if (start == 0)
        start = 1;

    dijkstra(n, graph, start - 1, distance);

    cout << "Vertex -> Shortest Distance from Source" << endl; // printing the shortest distances
    for (int i = 0; i < n; i++)
        cout << i + 1 << "      ->       " << distance[i] << endl;
}
