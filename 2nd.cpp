// Given a sorted array arr[] and a number x, write a function that counts the occurrences of x in arr[]
#include <iostream>
using namespace std;

int count_occurrences(int arr[], int s, int x)
{
    int result = 0;
    for (int i = 0; i < s; i++)
        if (x == arr[i])
            result++;
    return result;
}

int main()
{
    int nums[] = {5, 7, 8, 8, 5, 8, 7, 7, 7};
    int n = sizeof(nums) / sizeof(nums[0]);
    cout << "Original array: ";
    for (int i = 0; i < n; i++)
        cout << nums[i] << " ";
    int x = 7;
    cout << "\nNumber of occurrences of 7 : " << count_occurrences(nums, n, x);
    return 0;
}
