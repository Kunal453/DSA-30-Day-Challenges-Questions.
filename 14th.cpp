// Given a string of lowercase alphabets, count all possible substrings (not necessarily distinct) that has exactly k distinct characters?
#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

int countSubstringsWithKDistinct(string s, int k)
{
    int n = s.length();
    int count = 0;

    for (int i = 0; i < n; ++i)
    {
        unordered_map<char, int> charFreq;
        int distinctCount = 0;

        for (int j = i; j < n; ++j)
        {
            if (charFreq[s[j]] == 0)
            {
                distinctCount++;
            }
            charFreq[s[j]]++;

            if (distinctCount == k)
            {
                count++;
            }
            if (distinctCount > k)
            {
                break;
            }
        }
    }

    return count;
}

int main()
{
    string s = "abc";
    int k = 2;

    int result = countSubstringsWithKDistinct(s, k);
    cout << "Number of substrings with exactly " << k << " distinct characters: " << result << endl;

    return 0;
}
