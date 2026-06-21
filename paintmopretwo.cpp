#include <bits/stdc++.h>
using namespace std;

#define MOD 1000000007

int add(int a, int b)
{
    return (a % MOD + b % MOD) % MOD;
}

int mul(int a, int b)
{
    return (a % MOD * 1LL * (b % MOD)) % MOD;
}

/////////////////////////////////////////////////
// 1. Recursion
/////////////////////////////////////////////////

int solveRec(int n, int k)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    return add(
        mul(solveRec(n - 1, k), k - 1),
        mul(solveRec(n - 2, k), k - 1)
    );
}

/////////////////////////////////////////////////
// 2. Memoization
/////////////////////////////////////////////////

int solveMem(int n, int k, vector<int>& dp)
{
    if (n == 1)
        return k;

    if (n == 2)
        return add(k, mul(k, k - 1));

    if (dp[n] != -1)
        return dp[n];

    dp[n] = add(
        mul(solveMem(n - 1, k, dp), k - 1),
        mul(solveMem(n - 2, k, dp), k - 1)
    );

    return dp[n];
}

int memoization(int n, int k)
{
    vector<int> dp(n + 1, -1);
    return solveMem(n, k, dp);
}

/////////////////////////////////////////////////
// 3. Tabulation
/////////////////////////////////////////////////

int tabulation(int n, int k)
{
    if (n == 1)
        return k;

    vector<int> dp(n + 1);

    dp[1] = k;
    dp[2] = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        dp[i] = add(
            mul(dp[i - 1], k - 1),
            mul(dp[i - 2], k - 1)
        );
    }

    return dp[n];
}

/////////////////////////////////////////////////
// 4. Space Optimization
/////////////////////////////////////////////////

int spaceOptimized(int n, int k)
{
    if (n == 1)
        return k;

    int prev2 = k;
    int prev1 = add(k, mul(k, k - 1));

    for (int i = 3; i <= n; i++)
    {
        int curr = add(
            mul(prev1, k - 1),
            mul(prev2, k - 1)
        );

        prev2 = prev1;
        prev1 = curr;
    }

    return prev1;
}

/////////////////////////////////////////////////
// Main
/////////////////////////////////////////////////

int main()
{
    int n, k;
    cin >> n >> k;

    cout << "Recursion       : " << solveRec(n, k) << endl;
    cout << "Memoization     : " << memoization(n, k) << endl;
    cout << "Tabulation      : " << tabulation(n, k) << endl;
    cout << "Space Optimized : " << spaceOptimized(n, k) << endl;

    return 0;
}