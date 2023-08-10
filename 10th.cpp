#include <iostream>
#include <unordered_map>
using namespace std;

char firstNonRepeatedChar(const string &s, char notFoundValue)
{
    unordered_map<char, int> charCount;

    // Count the occurrences of each character in the string
    for (char c : s)
    {
        charCount[c]++;
    }

    // Find the first non-repeated character
    for (char c : s)
    {
        if (charCount[c] == 1)
        {
            return c;
        }
    }

    // If no non-repeated character is found, return the specified value
    return notFoundValue;
}

int main()
{
    string inputString = "racecar";
    char result = firstNonRepeatedChar(inputString, '-'); // Replace '-' with the desired not-found value
    cout << result << endl;                               // Output: 'd'

    return 0;
}
