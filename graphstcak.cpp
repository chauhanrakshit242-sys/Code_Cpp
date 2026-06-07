#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int main()
{
    int v, e;
    cin >> v >> e;

    vector<vector<int>> adj(v, vector<int>(v, 0));

    int u, w, val;
    for(int i = 0; i < e; i++)
    {
        cin >> u >> w >> val;
        adj[u][w] = val;
        adj[w][u] = val;
    }

    vector<bool> visited(v, false);
    vector<int> ans;
    stack<int> st;

    st.push(0);

    while(!st.empty())
    {
        int node = st.top();
        st.pop();

        if(!visited[node])
        {
            visited[node] = true;
            ans.push_back(node);

            // reverse order for correct traversal
            for(int j = v - 1; j >= 0; j--)
            {
                if(adj[node][j] != 0 && !visited[j])
                {
                    st.push(j);
                }
            }
        }
    }

    // print result
    for(int x : ans)
        cout << x << " ";

    return 0;
}