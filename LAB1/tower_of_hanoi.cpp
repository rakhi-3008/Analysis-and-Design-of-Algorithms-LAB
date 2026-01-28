#include <iostream>
using namespace std;

void moveOneDisk(int n, char source, char destination) {
    if (n == 1) {
        cout << "Move disk " << n << " from " << source << " to " << destination << endl;
    }
}

void towerOfHanoi(int n, char source, char destination, char auxiliary) {
    if (n == 0) return;

    // 1st recursive call: move n-1 disks
    towerOfHanoi(n-1, source, auxiliary, destination);

    // 2nd recursive call: move the nth disk (as recursion with base case)
    moveOneDisk(n, source, destination);

    // 3rd recursive call: move n-1 disks
    towerOfHanoi(n-1, auxiliary, destination, source);
}

int main() {
    int n;
    cout << "Enter number of disks: ";
    cin >> n;
    towerOfHanoi(n, 'A', 'C', 'B');
    return 0;
}
