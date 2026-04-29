#include <iostream>
#include <climits>
using namespace std;

int m[100][100];
int s[100][100];

void printOptimalParens(int i, int j) {
    if (i == j)
        cout << "A" << i;
    else {
        cout << "(";
        printOptimalParens(i, s[i][j]);
        printOptimalParens(s[i][j] + 1, j);
        cout << ")";
    }
}

void matrixChainOrder(int p[], int n) {
    for (int i = 1; i < n; i++)
        m[i][i] = 0;

    for (int L = 2; L < n; L++) {
        for (int i = 1; i < n - L + 1; i++) {
            int j = i + L - 1;
            m[i][j] = INT_MAX;

            for (int k = i; k <= j - 1; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];

                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    cout << "Minimum number of multiplications = " << m[1][n - 1] << endl;

    cout << "Optimal Parenthesization = ";
    printOptimalParens(1, n - 1);
}

int main() {
    int n;

    cout << "Enter number of matrices: ";
    cin >> n;

    int p[n + 1];

    cout << "Enter dimensions array:\n";
    for (int i = 0; i <= n; i++)
        cin >> p[i];

    matrixChainOrder(p, n + 1);

    return 0;
}