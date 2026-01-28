#include <iostream>
using namespace std;

// Recursive function for Horner's Rule
double hornerRecursive(double A[], int n, double a, int index = 0) {
    if (index == n)          // Base case: last coefficient A_0
        return A[index];

    return A[index] + a * hornerRecursive(A, n, a, index + 1);
}

int main() {
    int n;
    double a;

    cout << "Enter degree of polynomial: ";
    cin >> n;

    double A[n + 1];
    cout << "Enter coefficients (from A_n to A_0):\n";
    for (int i = 0; i <= n; i++) {
        cin >> A[i];
    }

    cout << "Enter value of a: ";
    cin >> a;

    double value = hornerRecursive(A, n, a);

    cout << "Value of polynomial at x = " << a << " is: " << value << endl;

    return 0;
}
