#include <iostream>
using namespace std;

int x[20], n;

bool place(int k, int i){
    for (int j = 1; j < k; j++){
        if (x[j] == i || abs(x[j] - i) == abs(j - k))
            return false;
    }
    return true;
}

void nQueens(int k){
    for (int i = 1; i <= n; i++){
        if (place(k, i)){
            x[k] = i;
            if (k == n){
                cout << "Solution:\n";
                for (int r = 1; r <= n; r++){
                    for (int c = 1; c <= n; c++){
                        if (x[r] == c)
                            cout << "Q ";
                        else
                            cout << ". ";
                    }
                    cout << endl;
                }
                cout << endl;
            }
            else{
                nQueens(k + 1);
            }
        }
    }
}

int main(){
    cout << "Enter number of queens: ";
    cin >> n;

    nQueens(1);

    return 0;
}