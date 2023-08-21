#include <iostream>
#include <stack>
#include <unordered_map>
#include <vector>

using namespace std;

void printNextGreaterElement(const vector<int>& arr) {
    stack<int> st;
    unordered_map<int, int> nextGreater;

    for (int num : arr) {
        while (!st.empty() && num > st.top()) {
            nextGreater[st.top()] = num;
            st.pop();
        }
        st.push(num);
    }

    while (!st.empty()) {
        nextGreater[st.top()] = -1;
        st.pop();
    }

    for (int num : arr) {
        cout << num << " --> " << nextGreater[num] << endl;
    }
}

int main() {
    vector<int> arr = {4, 5, 2, 25};
    printNextGreaterElement(arr);
    return 0;
}
