#include <iostream>
using namespace std;

int main() {
    int n = 4;
    for(int i = 1; i <= n; i++) {
        for(int s =i-1; s >=1; s--)
            cout <<" ";
       for(int j=2*(n-i)+1;j>=1;j--)
           cout<<"*";
        cout << endl;
    }
    return 0;
}
