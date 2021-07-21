/*
    Name: Raggav Subramani
    Registration Number: 20BCT0127
    Objective: To implement DFS traversal on a given graph
*/
#include <iostream>
#include <stack>
#include <vector>

using namespace std;

void DFS_implementation(vector<vector<int>> &graph, vector<int> &DFS, int start)
{                         // function to implement DFS on the given graph
    int count[100] = {0}; // array to store the location of traversal within the matrix at a particular row
    int visit[100] = {0}; // array to check if we have already traversed through that vertex
    stack<int> s;         // stack to implement DFS traversal
    s.push(start);        // pushing root node into stack
    DFS.push_back(start); // storing it in the final vector
    visit[start] = 1;     // marking it as it has been visited
    while (!s.empty())
    {
        start = s.top();                         // makes start the top most value in the stack
        if (count[start] >= graph[start].size()) // to end search within a particular row
        {
            s.pop();
            continue;
        }

        if (graph[start][count[start]] == 1 && visit[count[start]] != 1)
        {                                // to check for the edges of a particular vertex
            s.push(count[start]);        // if edge exists, we push it into the stack
            DFS.push_back(count[start]); // this is to store the final DFS tree for printing order of traversal
            visit[count[start]] = 1;     // marking the vertex
        }
        count[start]++; // moving on
    }
}

int main()
{
    int n;
    vector<vector<int>> graph;
    vector<int> DFS;
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

    DFS_implementation(graph, DFS, start-1);

    cout << "DFS traversal as adjacency list:" << endl;

    for (auto &it : DFS) // printing out the final BFS result in the form of adjacency list
        cout << it + 1 << " ";

    return 0;
}