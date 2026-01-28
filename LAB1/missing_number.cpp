#include <iostream>
using namespace std;

int findMissing(int arr[], int n) {
    int xor1 = 0;
    int xor2 = 0;

    // XOR of 1 to n
    for(int i = 1; i <= n; i++)
        xor1 ^= i;

    // XOR of array elements
    for(int i = 0; i < n-1; i++)
        xor2 ^= arr[i];

    return xor1 ^ xor2;
}

int main() {
    int arr[] = {1, 2, 4, 5};
    int n = 5;

    cout << "Missing number: " << findMissing(arr, n);
    return 0;
}
