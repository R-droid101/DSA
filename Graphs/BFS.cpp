/*
    Name: Raggav Subramani
    Registration number: 20BCT0127
    Objective: To perform BFS traversal on a graph with adjacency matrix representation
*/

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

void BFS_implementation(vector<vector<int>> &graph, vector<int> &BFS, int start)
{                         // function to implement the BFS on the graph
    int visit[100];       // array to check if a particular node is visited
    int count = 0;        // counter to traverse through the graph while performing the BFS
    queue<int> q;         // queue to implement BFS
    q.push(start);        // pushing the first node into the queue
    BFS.push_back(start); // pushing into the final BFS vector
    visit[start] = 1;     // marking the node as it has been visited
    while (!q.empty())
    {
        if (count >= graph[count].size())
        {                      // condition to move to the node in the graph
                               // this means moving to the next row in the adjacency matrix
            count = 0;         // making count = 0 to restart from the first column of the next row
            q.pop();           // popping the previous node
            start = q.front(); // making start the next node within the queue
        }
        if (graph[start][count] == 1 and visit[count] != 1)
        {                         // if the node in the graph has an edge to another node and that node has not been visited
                                  // in the adjacency matrix if the particular element is 1, it means that the edge connecting the two nodes exist
            q.push(count);        // pushing the node into q
            BFS.push_back(count); // pushing the node into the final BFS veector
            visit[count] = 1;     // marking the node as it has been visited
        }
        count++; // going to the next edge, in the adjacency matrix moving to the next element in the same row
    }
}

int main()
{
    int n;
    vector<vector<int>> graph;
    vector<int> BFS;
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

    if (start == 0) // to make life simpler
        start = 1;

    BFS_implementation(graph, BFS, start - 1);

    cout << "BFS tree as adjacency list:" << endl;

    for (auto &it : BFS) // printing out the final BFS result in the form of adjacency list
        cout << it + 1 << " ";

    return 0;
}