#include <bits/stdc++.h>
using namespace std;

// ---------------- RECURSION ----------------

int solveRec(vector<int>& wt, vector<int>& val,
             int index, int W)
{
    if(index == 0)
    {
        if(wt[0] <= W)
            return val[0];
        return 0;
    }

    int include = 0;

    if(wt[index] <= W)
        include = val[index] +
                  solveRec(wt, val,
                           index - 1,
                           W - wt[index]);

    int exclude =
        solveRec(wt, val, index - 1, W);

    return max(include, exclude);
}

int knapsackRec(vector<int> wt,
                vector<int> val,
                int n, int W)
{
    return solveRec(wt, val, n - 1, W);
}

// ---------------- MEMOIZATION ----------------

int solveMemo(vector<int>& wt, vector<int>& val,
              int index, int W,
              vector<vector<int>>& dp)
{
    if(index == 0)
    {
        if(wt[0] <= W)
            return val[0];
        return 0;
    }

    if(dp[index][W] != -1)
        return dp[index][W];

    int include = 0;

    if(wt[index] <= W)
        include = val[index] +
                  solveMemo(wt, val,
                            index - 1,
                            W - wt[index], dp);

    int exclude =
        solveMemo(wt, val,
                  index - 1, W, dp);

    return dp[index][W] =
           max(include, exclude);
}

int knapsackMemo(vector<int> wt,
                 vector<int> val,
                 int n, int W)
{
    vector<vector<int>> dp(
        n, vector<int>(W + 1, -1));

    return solveMemo(wt, val,
                     n - 1, W, dp);
}

// ---------------- TABULATION ----------------

int knapsackTab(vector<int> wt,
                vector<int> val,
                int n, int W)
{
    vector<vector<int>> dp(
        n, vector<int>(W + 1, 0));

    for(int w = wt[0]; w <= W; w++)
        dp[0][w] = val[0];

    for(int i = 1; i < n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            int include = 0;

            if(wt[i] <= w)
                include = val[i] +
                          dp[i - 1][w - wt[i]];

            int exclude =
                dp[i - 1][w];

            dp[i][w] =
                max(include, exclude);
        }
    }

    return dp[n - 1][W];
}

// -------- SPACE OPTIMIZATION (2 ARRAYS) --------

int knapsackSO2(vector<int> wt,
                vector<int> val,
                int n, int W)
{
    vector<int> prev(W + 1, 0);
    vector<int> curr(W + 1, 0);

    for(int w = wt[0]; w <= W; w++)
        prev[w] = val[0];

    for(int i = 1; i < n; i++)
    {
        for(int w = 0; w <= W; w++)
        {
            int include = 0;

            if(wt[i] <= w)
                include = val[i] +
                          prev[w - wt[i]];

            int exclude = prev[w];

            curr[w] =
                max(include, exclude);
        }

        prev = curr;
    }

    return prev[W];
}

// -------- SPACE OPTIMIZATION (1 ARRAY) --------

int knapsackSO1(vector<int> wt,
                vector<int> val,
                int n, int W)
{
    vector<int> dp(W + 1, 0);

    for(int w = wt[0]; w <= W; w++)
        dp[w] = val[0];

    for(int i = 1; i < n; i++)
    {
        for(int w = W; w >= wt[i]; w--)
        {
            dp[w] = max(dp[w],
                        val[i] +
                        dp[w - wt[i]]);
        }
    }

    return dp[W];
}

int main()
{
    vector<int> weight = {1, 2, 4, 5};
    vector<int> value  = {5, 4, 8, 6};

    int n = weight.size();
    int W = 5;

    cout << "Recursion: "
         << knapsackRec(weight, value, n, W)
         << endl;

    cout << "Memoization: "
         << knapsackMemo(weight, value, n, W)
         << endl;

    cout << "Tabulation: "
         << knapsackTab(weight, value, n, W)
         << endl;

    cout << "Space Opt (2 arrays): "
         << knapsackSO2(weight, value, n, W)
         << endl;

    cout << "Space Opt (1 array): "
         << knapsackSO1(weight, value, n, W)
         << endl;

    return 0;
}