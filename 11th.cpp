// You are given a string S, the task is to reverse the string word by word.
#include <iostream>
#include <algorithm> // Required for reverse function

using namespace std;

void reverseWords(string &s)
{
    // Reverse the entire string
    reverse(s.begin(), s.end());

    // Pointers for tracking word boundaries
    int start = 0;
    int end = 0;

    while (end < s.length())
    {
        if (s[end] == ' ')
        {
            // Reverse the word
            reverse(s.begin() + start, s.begin() + end);
            start = end + 1;
        }
        end++;
    }

    // Reverse the last word
    reverse(s.begin() + start, s.end());
}

int main()
{
    string input;
    cout << "Enter a string: ";
    getline(cin, input);

    reverseWords(input);
    cout << "Reversed string: " << input << endl;

    return 0;
}
