#include <iostream>
using namespace std;

int w[20], x[20];
int n, k;

void printSubset(){
    cout << "{ ";
    for (int i = 1; i <= n; i++){
        if (x[i] == 1)
            cout << w[i] << " ";
    }
    cout << "}" << endl;
}

void sumOfSubsets(int s, int idx){
    if (s == k){
        printSubset();
        return;
    }

    if (idx > n || s > k){
        return;
    }

    x[idx] = 1;
    sumOfSubsets(s + w[idx], idx + 1);

    x[idx] = 0;
    sumOfSubsets(s, idx + 1);
}

int main(){
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements:\n";
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    cout << "Enter required sum: ";
    cin >> k;

    for (int i = 1; i <= n; i++)
        x[i] = 0;

    cout << "\nSubsets with sum = " << k << " are:\n";
    sumOfSubsets(0, 1);

    return 0;
}