#include <bits/stdc++.h>
using namespace std;

// -------------------- Memoization --------------------
int solveMemo(vector<int>& cost, int n, vector<int>& dp)
{
    if(n == 0)
        return cost[0];

    if(n == 1)
        return cost[1];

    if(dp[n] != -1)
        return dp[n];

    dp[n] = cost[n] +
            min(solveMemo(cost, n - 1, dp),
                solveMemo(cost, n - 2, dp));

    return dp[n];
}

// -------------------- Tabulation --------------------
int solveTab(vector<int>& cost)
{
    int n = cost.size();

    vector<int> dp(n);

    dp[0] = cost[0];
    dp[1] = cost[1];

    for(int i = 2; i < n; i++)
    {
        dp[i] = cost[i] + min(dp[i - 1], dp[i - 2]);
    }

    return min(dp[n - 1], dp[n - 2]);
}

// -------------------- Space Optimized --------------------
int solveSO(vector<int>& cost)
{
    int n = cost.size();

    int prev2 = cost[0];
    int prev1 = cost[1];

    for(int i = 2; i < n; i++)
    {
        int curr = cost[i] + min(prev1, prev2);

        prev2 = prev1;
        prev1 = curr;
    }

    return min(prev1, prev2);
}

int main()
{
    int n;
    cin >> n;

    vector<int> cost(n);

    for(int i = 0; i < n; i++)
    {
        cin >> cost[i];
    }

    // Memoization
    vector<int> dp(n, -1);
    int ans = min(solveMemo(cost, n - 1, dp),
                  solveMemo(cost, n - 2, dp));

    cout << ans << endl;

    // Agar Tabulation use karna ho:
    // cout << solveTab(cost) << endl;

    // Agar Space Optimized use karna ho:
    // cout << solveSO(cost) << endl;

    return 0;
}