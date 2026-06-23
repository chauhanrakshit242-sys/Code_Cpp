#include<bits/stdc++.h>
using namespace std;

enum method
{
    Recusrion = 1,
    Memoiation = 2,
    Tabulation = 3
};

int solver(vector<int>& num, int target)
{
    if(target < 0)
        return 0;

    if(target == 0)
        return 1;

    int ans = 0;

    for(int i = 0; i < num.size(); i++)
    {
        ans += solver(num, target - num[i]);
    }

    return ans;
}

int solvem(vector<int>& num, int target, vector<int>& dp)
{
    if(target < 0)
        return 0;

    if(target == 0)
        return 1;

    if(dp[target] != -1)
        return dp[target];

    int ans = 0;

    for(int i = 0; i < num.size(); i++)
    {
        ans += solvem(num, target - num[i], dp);
    }

    return dp[target] = ans;
}

int solveT(vector<int>& num, int target)
{
    vector<int> dp(target + 1, 0);

    dp[0] = 1;

    for(int i = 1; i <= target; i++)
    {
        for(int j = 0; j < num.size(); j++)
        {
            if(i - num[j] >= 0)
            {
                dp[i] += dp[i - num[j]];
            }
        }
    }

    return dp[target];
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);

    for(int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int target;
    cin >> target;

    string str;
    cin >> str;

    int choice = -1;

    if(str == "Recursion")
        choice = Recusrion;
    else if(str == "Memoization")
        choice = Memoiation;
    else if(str == "Tabulation")
        choice = Tabulation;

    switch(choice)
    {
        case Recusrion:
        {
            int ans = solver(arr, target);
            cout << "Output is Solve by Recursion: " << ans;
            break;
        }

        case Memoiation:
        {
            vector<int> dp(target + 1, -1);

            int ans = solvem(arr, target, dp);

            cout << "Output is Solve by Memoization: " << ans;
            break;
        }

        case Tabulation:
        {
            int ans = solveT(arr, target);

            cout << "Output is Solve by Tabulation: " << ans;
            break;
        }

        default:
        {
            cout << "Invalid Method";
            break;
        }
    }

    return 0;
}