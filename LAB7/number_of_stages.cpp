#include <iostream>
using namespace std;

void inputGraph(int cost[][10], int n) {
    cout << "Enter adjacency matrix (0 if no edge):\n";
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> cost[i][j];
        }
    }
}

void findStages(int cost[][10], int stage[], int n) {
    stage[n] = 1;

    for(int i = n - 1; i >= 1; i--) {
        int maxStage = 0;

        for(int j = i + 1; j <= n; j++) {
            if(cost[i][j] != 0) {
                if(stage[j] > maxStage)
                    maxStage = stage[j];
            }
        }

        stage[i] = maxStage + 1;
    }

    int totalStages = stage[1];

    for(int i = 1; i <= n; i++) {
        stage[i] = totalStages - stage[i] + 1;
    }
}

void displayStages(int stage[], int n) {
    cout << "\nNumber of stages = " << stage[n] << endl;

    cout << "\nStage of each vertex:\n";
    for(int i = 1; i <= n; i++) {
        cout << "Vertex " << i << " -> Stage " << stage[i] << endl;
    }
}

int main() {
    int n, cost[10][10], stage[10];

    cout << "Enter number of vertices: ";
    cin >> n;

    inputGraph(cost, n);
    findStages(cost, stage, n);
    displayStages(stage, n);

    return 0;
}