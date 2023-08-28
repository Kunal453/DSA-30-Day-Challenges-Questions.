

#include <iostream>
#include <vector>

using namespace std;

int main()
{

    vector<int> numbers = {1, -2, 3, -4, 5};
    int k = 3;

    for (int i = 0; i < numbers.size() - k + 1; i++)
    {
        bool foundNegative = false;
        for (int j = i; j < i + k; j++)
        {
            if (numbers[j] < 0)
            {
                cout << numbers[j] << " ";
                foundNegative = true;
                break;
            }
        }
        if (!foundNegative)
        {
            cout << 0 << " ";
        }
    }

    cout << endl;

    return 0;
}