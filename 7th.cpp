#include <iostream>
using namespace std;

void rotateLeft(int arr[], int size, int rotations)
{
    rotations %= size; // To handle cases where rotations > size

    for (int i = 0; i < rotations; ++i)
    {
        int temp = arr[0];
        for (int j = 0; j < size - 1; ++j)
        {
            arr[j] = arr[j + 1];
        }
        arr[size - 1] = temp;
    }
}

int main()
{
    int size, rotations;

    cout << "Enter the size of the array: ";
    cin >> size;

    int arr[size];

    cout << "Enter the elements of the array:\n";
    for (int i = 0; i < size; ++i)
    {
        cin >> arr[i];
    }

    cout << "Enter the number of rotations: ";
    cin >> rotations;

    rotateLeft(arr, size, rotations);

    cout << "Array after " << rotations << " left rotations:\n";
    for (int i = 0; i < size; ++i)
    {
        cout << arr[i] << " ";
    }

    return 0;
}

// Output:-
// Enter the size of the array: 5
// Enter the elements of the array:
// 10 20 30 40 50
// Enter the number of rotations: 3
// Array after 3 left rotations:
// 40 50 10 20 30