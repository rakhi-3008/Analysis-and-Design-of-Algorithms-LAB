#include <iostream>
#include <string>
using namespace std;

void lcs(string s1, string s2) {
    int m = s1.length();
    int n = s2.length();

    int dp[100][100];

    // Initialize first row and column as 0
    for(int i = 0; i <= m; i++)
        dp[i][0] = 0;

    for(int j = 0; j <= n; j++)
        dp[0][j] = 0;

    // Fill DP table
    for(int i = 1; i <= m; i++) {
        for(int j = 1; j <= n; j++) {
            if(s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    cout << "\nLength of Longest Common Subsequence = " << dp[m][n];
}

int main() {
    string s1, s2;

    cout << "Enter first string: ";
    cin >> s1;

    cout << "Enter second string: ";
    cin >> s2;

    lcs(s1, s2);

    return 0;
}