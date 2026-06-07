
/*Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void solve(vector<int> nums, vector<int> output, int index, vector<vector<int>>& ans)
{
    if (index >= nums.size())
    {
        sort(output.begin(), output.end()); // optional if you want sorted inside each subset
        ans.push_back(output);
        return;
    }

    // Exclude current element
    solve(nums, output, index + 1, ans);

    // Include current element
    output.push_back(nums[index]);
    solve(nums, output, index + 1, ans);
}

int main()
{
    vector<int> nums = {1, 2, 3};
    vector<int> output;
    vector<vector<int>> ans;
    int index = 0;

    sort(nums.begin(), nums.end()); // ensure input is sorted

    solve(nums, output, index, ans);

    sort(ans.begin(), ans.end()); // sort all subsets lexicographically

    // Print all subsets
    cout << "Power Set in Lexicographic Order:\n";
    for (auto subset : ans)
    {
        cout << "{ ";
        for (int num : subset)
            cout << num << " ";
        cout << "}" << endl;
    }

    return 0;
}
