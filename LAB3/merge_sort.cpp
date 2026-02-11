#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

// Merge Function
void merge(int arr[], int st, int end, int mid) {
    vector<int> temp;
    int i = st;
    int j = mid + 1;

    while (i <= mid && j <= end) {
        if (arr[i] <= arr[j]) {
            temp.push_back(arr[i++]);
        } else {
            temp.push_back(arr[j++]);
        }
    }

    while (i <= mid) {
        temp.push_back(arr[i++]);
    }

    while (j <= end) {
        temp.push_back(arr[j++]);
    }

    for (int idx = st, x = 0; idx <= end; idx++, x++) {
        arr[idx] = temp[x];
    }
}

// Merge Sort Function
void mergeSort(int arr[], int st, int end) {
    if (st >= end) return;

    int mid = st + (end - st) / 2;

    mergeSort(arr, st, mid);
    mergeSort(arr, mid + 1, end);

    merge(arr, st, end, mid);
}

// Random Number Generator
int randomNumber(int min, int max) {
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

int main() {

    for (int n = 10; n <= 100000; n = n * 10) {

        long double totalTime = 0;
        int arr[n];

        // Generate random array
        for (int i = 0; i < n; i++) {
            arr[i] = randomNumber(1, n);
        }

        // Repeat 100 times for average
        for (int i = 1; i <= 100; i++) {

            int tempArr[n];
            for (int j = 0; j < n; j++) {
                tempArr[j] = arr[j];
            }

            auto start = high_resolution_clock::now();
            mergeSort(tempArr, 0, n - 1);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            totalTime += duration.count();
        }

        cout << "for n = " << n
             << " average time = "
             << (totalTime / 100)
             << " microseconds" << endl;
    }

    return 0;
}
