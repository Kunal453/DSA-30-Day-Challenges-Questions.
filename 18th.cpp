#include <iostream>
#include <cmath>

using namespace std;

int calculateNthRoot(int N, int M) {
    double nthRoot = pow(M, 1.0 / N);

    // Check if the Nth root is very close to an integer
    if (abs(nthRoot - round(nthRoot)) < 1e-9) {
        return static_cast<int>(round(nthRoot));
    } else {
        return -1;
    }
}

int main() {
    int N = 3;
    int M = 27;
    int result = calculateNthRoot(N, M);
    cout << result << endl;  // Output: 3

    N = 2;
    M = 10;
    result = calculateNthRoot(N, M);
    cout << result << endl;  // Output: -1

    return 0;
}
