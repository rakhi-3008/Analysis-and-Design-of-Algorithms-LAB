#include <iostream>
using namespace std;

int n, m;                
int G[20][20];           
int x[20]; 

void nextValue(int k){
    while (true){
        x[k] = (x[k] + 1) % (m + 1);
        if (x[k] == 0){
            return;
        }

        int j;
        for (j = 1; j <= n; j++)
        {
            if (G[k][j] != 0 && x[k] == x[j])
                break;
        }

        if (j == n + 1)
            return;
    }
}

void mColoring(int k){
    while (true){
        nextValue(k);

        if (x[k] == 0)
            return;

        if (k == n){
            cout << "Solution: ";
            for (int i = 1; i <= n; i++)
                cout << x[i] << " ";
            cout << endl;
        }
        else{
            mColoring(k + 1);
        }
    }
}

int main(){
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cin >> G[i][j];
    }

    cout << "Enter number of colors: ";
    cin >> m;

    for (int i = 1; i <= n; i++)
        x[i] = 0;

    cout << "\nPossible colorings are:\n";
    mColoring(1);

    return 0;
}

