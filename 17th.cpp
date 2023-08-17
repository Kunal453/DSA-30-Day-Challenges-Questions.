// Given a number N, figure out if it is a member of the fibonacci series or not. Return true if the number of members of the fibonacci series else false.

#include <iostream>

using namespace std;

bool isFibonacci(int n)
{

    if (n == 0 || n == 1)
    {
        return true;
    }

    int a = 0;
    int b = 1;

    for (int i = 2; i <= n; i++)
    {

        int c = a + b;

        if (c == n)
        {
            return true;
        }

        a = b;
        b = c;
    }

    return false;
}

int main()
{

    int n;
    cout << "Enter a number: ";
    cin >> n;

    // Check if the number is a member of the Fibonacci sequence.
    bool isMember = isFibonacci(n);

    // Print the result.
    if (isMember)
    {
        cout << "The number " << n << " is a member of the Fibonacci sequence." << endl;
    }
    else
    {
        cout << "The number " << n << " is not a member of the Fibonacci sequence." << endl;
    }

    return 0;
}
