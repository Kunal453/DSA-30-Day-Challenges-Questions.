// // How do you check if two strings are anagrams of each other?
#include <iostream>
#include <unordered_map>

using namespace std;

bool areAnagrams(string str1, string str2)
{
    unordered_map<char, int> freq;

    // count the frequency of each character in str1
    for (char c : str1)
    {
        freq[c]++;
    }

    // decrement the frequency of each character in str2
    for (char c : str2)
    {
        freq[c]--;
    }

    // check if the frequency of each character is the same
    for (auto it : freq)
    {
        if (it.second != 0)
        {
            return false;
        }
    }

    return true;
}

int main()
{
    string str1 = "listen";
    string str2 = "silent";

    if (areAnagrams(str1, str2))
    {
        cout << str1 << " and " << str2 << " are anagrams of each other." << endl;
    }
    else
    {
        cout << str1 << " and " << str2 << " are not anagrams of each other." << endl;
    }

    return 0;
}
