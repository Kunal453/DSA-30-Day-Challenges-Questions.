#include <bits/stdc++.h>
using namespace std;

void reverseKElements(queue<int> &queue, int k)
{
    if (k < 0 || k >= queue.size() || queue.empty())
    {
        cout << "Invalid Input" << endl;
        return;
    }

    stack<int> st;

    // Push the first K elements in stack
    for (int i = 0; i < k; i++)
    {
        int curr = queue.front();
        queue.pop();
        st.push(curr);
    }

    // Pop elements from the stack and push them back into the queue
    while (!st.empty())
    {
        int curr = st.top();
        st.pop();
        queue.push(curr);
    }

    // Move the remaining (n - k) elements to the end of the queue
    for (int i = 0; i < queue.size() - k; i++)
    {
        int curr = queue.front();
        queue.pop();
        queue.push(curr);
    }

    // Print the elements of the queue
    while (!queue.empty())
    {
        int curr = queue.front();
        queue.pop();
        cout << curr << " ";
    }
    cout << endl;
}

int main()
{
    // Example 1
    queue<int> q1;
    int k1 = 3;
    q1.push(1);
    q1.push(2);
    q1.push(3);
    q1.push(4);
    q1.push(5);
    reverseKElements(q1, k1);

    // // Example 2
    // queue<int> q2;
    // int k2 = 2;
    // q2.push(12);
    // q2.push(14);
    // q2.push(16);
    // q2.push(7);
    // q2.push(9);
    // reverseKElements(q2, k2);

    return 0;
}

