#include<iostream>
using namespace std;

bool isprime(int n)
{
    if(n < 2)
        return false;

    for(int i = 2; i * i <= n; i++)
    {
        if(n % i == 0)
            return false;
    }
    return true;
}

int main()
{
    int n;
    int count = 0;

    cout << "Enter the Number: ";
    cin >> n;

    for(int i = 2; i <=n; i++)
    {
        if(isprime(i))
        {
            cout << i << endl;
            count++;
        }
    }

    cout << "Total Prime Numbers = " << count << endl;
    return 0;
}
