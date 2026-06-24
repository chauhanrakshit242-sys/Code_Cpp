#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> adj;
vector<int> color;
vector<int> dp;
vector<int> ans;

void dfs1(int node, int parent)
{
    dp[node] = color[node];

    for(auto child : adj[node])
    {
        if(child == parent) continue;

        dfs1(child, node);

        dp[node] += max(0, dp[child]);
    }
}

void dfs2(int node, int parent)
{
    for(auto child : adj[node])
    {
        if(child == parent) continue;

        ans[child] =
            dp[child]
            + max(0, ans[node] - max(0, dp[child]));

        dfs2(child, node);
    }
}

int main()
{
    int n;
    cin >> n;

    color.resize(n + 1);
    dp.resize(n + 1);
    ans.resize(n + 1);
    adj.resize(n + 1);

    for(int i = 1; i <= n; i++)
    {
        cin >> color[i];

        if(color[i] == 0)
            color[i] = -1;
    }

    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    dfs1(1, 0);

    ans[1] = dp[1];

    dfs2(1, 0);

    for(int i = 1; i <= n; i++)
    {
        cout << ans[i] << " ";
    }

    cout << "\n";

    return 0;
}