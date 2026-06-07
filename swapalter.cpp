#include <bits/stdc++.h>
using namespace std;

void swapalternate(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while (i < n - 1) {
        swap(arr[i], arr[i + 1]);
        i += 2;
    }
}

void printarray(const vector<int>& arr) {
    for (int x : arr) {
        cout << x << " ";
    }
    cout << endl;
}

int main() {
    // 🔹 Automatic input (hardcoded array)
    vector<int> arr = {1, 2, 3, 4, 5, 6};

    cout << "Before swapping: ";
    printarray(arr);

    swapalternate(arr);

    cout << "After swapping:  ";
    printarray(arr);

    return 0;
}
