#include <iostream>
#include <unordered_map>
using namespace std;

int countPairsWithSum(int arr[], int N, int K)
{
    int count = 0;
    unordered_map<int, int> num_count; // Hashmap to store the count of each number

    for (int i = 0; i < N; i++)
    {
        int diff = K - arr[i];
        if (num_count.find(diff) != num_count.end())
        {
            count += num_count[diff];
        }
        num_count[arr[i]]++;
    }

    return count;
}

int main()
{
    int arr[] = {3, 1, 2, 4, 5};
    int N = sizeof(arr) / sizeof(arr[0]);
    int K = 5;
    int result = countPairsWithSum(arr, N, K);
    cout << "Number of pairs with sum equal to " << K << " is: " << result << endl;

    return 0;
}
