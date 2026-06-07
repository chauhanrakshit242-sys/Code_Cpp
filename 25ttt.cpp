#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int t;
    cin >> t;

    while(t--) {
        string x;
        cin >> x;

        vector<int> digits;
        int sum = 0;

        for(char c : x) {
            int val = c - '0';
            digits.push_back(val);
            sum += val;
        }

        if(sum <= 9) {
            cout << 0 << endl;
            continue;
        }

        sort(digits.begin(), digits.end(), greater<int>());

        int moves = 0;

        for(int d : digits) {
            if(sum <= 9) break;
            sum -= d;
            moves++;
        }

        cout << moves << endl;
    }

    return 0;
}