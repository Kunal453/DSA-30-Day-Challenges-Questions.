//Given an unsorted array of N integers, find smallest and largest element in optimal way.
//Time complexity should be O(n).


#include <iostream>
using namespace std;

int main()
{
    int arr[] = {2, 6, 3, 9, 1, 8, 5};
    int min = arr[0];
    int max = arr[0];
    for (int i = 1; i < sizeof(arr) / sizeof(arr[0]); i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
        if (arr[i] < min)
        {
            min = arr[i];
        }
    }
    cout << "Smallest value is: " << min << endl;
    cout << "Largest value is: " << max << endl;
    return 0;
}
