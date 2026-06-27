#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxi;

    //------------------ Recursion ------------------//
    int solveRec(vector<vector<int>>& mat, int i, int j) {
        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        int right = solveRec(mat, i, j + 1);
        int down = solveRec(mat, i + 1, j);
        int diagonal = solveRec(mat, i + 1, j + 1);

        if (mat[i][j] == 1) {
            int ans = 1 + min({right, down, diagonal});
            maxi = max(maxi, ans);
            return ans;
        }
        return 0;
    }

    //------------------ Memoization ------------------//
    int solveMemo(vector<vector<int>>& mat, int i, int j,
                  vector<vector<int>>& dp) {

        if (i >= mat.size() || j >= mat[0].size())
            return 0;

        if (dp[i][j] != -1)
            return dp[i][j];

        int right = solveMemo(mat, i, j + 1, dp);
        int down = solveMemo(mat, i + 1, j, dp);
        int diagonal = solveMemo(mat, i + 1, j + 1, dp);

        if (mat[i][j] == 1) {
            dp[i][j] = 1 + min({right, down, diagonal});
            maxi = max(maxi, dp[i][j]);
        } else {
            dp[i][j] = 0;
        }

        return dp[i][j];
    }

    //------------------ Tabulation ------------------//
    int solveTab(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

        int ans = 0;

        for (int i = m - 1; i >= 0; i--) {
            for (int j = n - 1; j >= 0; j--) {

                if (mat[i][j] == 1) {
                    dp[i][j] = 1 + min({
                        dp[i + 1][j],
                        dp[i][j + 1],
                        dp[i + 1][j + 1]
                    });

                    ans = max(ans, dp[i][j]);
                }
            }
        }

        return ans;
    }

    //------------------ Space Optimization ------------------//
    int solveSpace(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<int> curr(n + 1, 0);
        vector<int> next(n + 1, 0);

        int ans = 0;

        for (int i = m - 1; i >= 0; i--) {

            for (int j = n - 1; j >= 0; j--) {

                if (mat[i][j] == 1) {

                    curr[j] = 1 + min({
                        curr[j + 1],
                        next[j],
                        next[j + 1]
                    });

                    ans = max(ans, curr[j]);
                }
                else
                    curr[j] = 0;
            }

            next = curr;
        }

        return ans;
    }

    //------------------ O(1) Space ------------------//
    int solveConstant(vector<vector<int>> mat) {

        int m = mat.size();
        int n = mat[0].size();

        int ans = 0;

        for (int j = 0; j < n; j++)
            ans = max(ans, mat[0][j]);

        for (int i = 0; i < m; i++)
            ans = max(ans, mat[i][0]);

        for (int i = 1; i < m; i++) {

            for (int j = 1; j < n; j++) {

                if (mat[i][j] == 1) {

                    mat[i][j] = 1 + min({
                        mat[i - 1][j],
                        mat[i][j - 1],
                        mat[i - 1][j - 1]
                    });

                    ans = max(ans, mat[i][j]);
                }
            }
        }

        return ans;
    }

    //---------------- Driver Function ----------------//
    int maxSquare(vector<vector<int>>& mat) {

        //---------- Recursion ----------
        //maxi = 0;
        //solveRec(mat,0,0);
        //return maxi;

        //---------- Memoization ----------
        //maxi = 0;
        //vector<vector<int>> dp(mat.size(), vector<int>(mat[0].size(), -1));
        //solveMemo(mat,0,0,dp);
        //return maxi;

        //---------- Tabulation ----------
        //return solveTab(mat);

        //---------- Space Optimization ----------
        //return solveSpace(mat);

        //---------- O(1) Space ----------
        return solveConstant(mat);
    }
};

int main() {

    vector<vector<int>> mat = {
        {1,0,1,0,0},
        {1,0,1,1,1},
        {1,1,1,1,1},
        {1,0,0,1,0}
    };

    Solution obj;

    cout << obj.maxSquare(mat);

    return 0;
}