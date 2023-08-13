#include <iostream>
#include <unordered_map>
using namespace std;

int romanToInt(string s) {
    unordered_map<char, int> romanValues = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
        {'C', 100}, {'D', 500}, {'M', 1000}
    };

    int result = 0, prevValue = 0;

    for (char c : s) {
        int currentValue = romanValues[c];
        result += (currentValue > prevValue) ? (currentValue - 2 * prevValue) : currentValue;
        prevValue = currentValue;
    }

    return result;
}

int main() {
    string romanNumeral;
    cout << "Enter a Roman numeral: ";
    cin >> romanNumeral;

    int decimalValue = romanToInt(romanNumeral);
    cout << "Decimal value: " << decimalValue << endl;

    return 0;
}


// Explanation:

// The romanToInt function takes a string s representing a Roman numeral and returns its decimal value.

// The unordered_map romanValues stores the decimal values for each Roman numeral character.

// The result variable stores the cumulative decimal value as we iterate through the string.

// The prevValue variable is used to keep track of the previous Roman numeral value for handling subtractive notation.

// The loop iterates through each character in the input string s.

// For each character, we retrieve its decimal value from the romanValues map.

// If the current value is greater than the previous value (indicating subtractive notation like IV, IX, XL, etc.), we subtract twice the previous value from the result before adding the current value.

// Otherwise, we simply add the current value to the result.

// Finally, we update prevValue and return the computed result.

// In the main function, we input a Roman numeral, call romanToInt, and output the corresponding decimal value.