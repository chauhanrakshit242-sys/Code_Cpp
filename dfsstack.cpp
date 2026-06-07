#include <iostream>
#include <vector>
#include <stack>
using namespace std;

void dfs(int start, vector<vector<int>>& graph)
{
    int n = graph.size();

    // Visited array to track visited nodes
    vector<bool> visited(n, false);

    // Stack for iterative DFS
    stack<int> st;

    // Push starting node
    st.push(start);

    while(!st.empty())
    {
        // Get top node from stack
        int node = st.top();
        st.pop();

        // If already visited, skip it
        if(visited[node])
            continue;

        // Mark node as visited
        visited[node] = true;

        // Print current node
        cout << node << " ";

        /*
           Push neighbours in REVERSE order.

           Example:
           graph[0] = {1, 2}

           Push:
           2 first
           1 second

           Stack:
           Top -> 1
                  2

           So 1 is processed before 2,
           giving the same order as recursive DFS.
        */
        for(int i = graph[node].size() - 1; i >= 0; i--)
        {
            int neighbour = graph[node][i];

            if(!visited[neighbour])
            {
                st.push(neighbour);
            }
        }
    }
}

int main()
{
    int V = 5;

    // Adjacency List
    vector<vector<int>> graph(V);

    /*
            0
           / \
          1   2
         / \
        3   4
    */

    graph[0] = {1, 2};
    graph[1] = {0, 3, 4};
    graph[2] = {0};
    graph[3] = {1};
    graph[4] = {1};

    cout << "DFS Traversal: ";

    dfs(0, graph);

    return 0;
}