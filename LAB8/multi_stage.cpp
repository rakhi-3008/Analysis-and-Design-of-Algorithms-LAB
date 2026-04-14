#include <iostream>
#include <vector>
#include <climits>
using namespace std;

void multiStage(int n, int k, vector<vector<int>> &c) {
    vector<int> cost(n+1, INT_MAX);
    vector<int> d(n+1);
    vector<int> p(k+1);

    cost[n] = 0;

    for(int j = n-1; j >= 1; j--) {
        int minCost = INT_MAX;

        for(int r = j+1; r <= n; r++) {
            if(c[j][r] != 0 && cost[r] != INT_MAX) {
                if(c[j][r] + cost[r] < minCost) {
                    minCost = c[j][r] + cost[r];
                    d[j] = r;
                }
            }
        }
        cost[j] = minCost;
    }

    p[1] = 1;
    p[k] = n;

    for(int j = 2; j <= k-1; j++) {
        p[j] = d[p[j-1]];
    }

    cout << "\nMinimum Cost: " << cost[1];

    cout << "\nPath: ";
    for(int i = 1; i <= k; i++) {
        cout << p[i];
        if(i != k) cout << " -> ";
    }
    cout << endl;
}

int main() {
    int n, k;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter number of stages: ";
    cin >> k;

    vector<vector<int>> c(n+1, vector<int>(n+1));

    cout << "Enter cost adjacency matrix (0 if no edge): ";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> c[i][j];
        }
    }

    multiStage(n, k, c);

    return 0;
}