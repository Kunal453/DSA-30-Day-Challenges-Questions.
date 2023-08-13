#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isBalanced(const string &s) {
    stack<char> brackets;

    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            brackets.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (brackets.empty()) {
                return false; // No corresponding opening bracket found
            }

            char top = brackets.top();
            brackets.pop();

            if ((c == ')' && top != '(') || (c == '}' && top != '{') || (c == ']' && top != '[')) {
                return false; // Mismatched brackets
            }
        }
    }

    return brackets.empty(); // If the stack is empty, all brackets are balanced
}

int main() {
    string input;
    cout << "Enter a string with brackets: ";
    cin >> input;

    if (isBalanced(input)) {
        cout << "The string is balanced." << endl;
    } else {
        cout << "The string is not balanced." << endl;
    }

    return 0;
}

