#include <iostream>
#include <vector>
#include <chrono>
#include <random>

using namespace std;
using namespace std::chrono;

int partition(int arr[], int s, int e) {

    int pivot = arr[s];

    int count = 0;
    for (int i = s + 1; i <= e; i++) {
        if (arr[i] <= pivot)
            count++;
    }

    int pivotIndex = s + count;
    swap(arr[s], arr[pivotIndex]);

    int i = s;
    int j = e;

    while (i < pivotIndex && j > pivotIndex) {

        while (arr[i] <= pivot)
            i++;

        while (arr[j] > pivot)
            j--;

        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    return pivotIndex;
}

void quickSort(int arr[], int s, int e) {
    if (s >= e) return;

    int p = partition(arr, s, e);

    quickSort(arr, s, p - 1);
    quickSort(arr, p + 1, e);
}

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

        for (int i = 0; i < n; i++) {
            arr[i] = randomNumber(1, n);
        }

        for (int i = 1; i <= 100; i++) {

            int tempArr[n];
            for (int j = 0; j < n; j++) {
                tempArr[j] = arr[j];
            }

            auto start = high_resolution_clock::now();
            quickSort(tempArr, 0, n - 1);
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
