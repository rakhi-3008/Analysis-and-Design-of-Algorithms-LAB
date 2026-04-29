#include<iostream>
#include<random>
#include<chrono>
using namespace std;
using namespace std::chrono;

int randomNumber(int min, int max){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<>dist(min, max);
    return dist(gen);
}

void selectionSort(int arr[], int n){

    if(n==1) {
        cout<<arr[n];
    }

    for(int i=0; i<n-1; i++){
        int smallestIdx=i;
        for(int j=i+1; j<n; j++){
            if(arr[j]<arr[smallestIdx]){
                smallestIdx=j;
            }
        }
        swap(arr[i], arr[smallestIdx]);
    }
}

int main(){
   for(int n = 10; n <= 100000; n = n * 10){ // keep n reasonable for bubble sort
        long double totalTime = 0;
        int arr[n];

        // Generate random array
        for(int i = 0; i < n; i++){
            arr[i] = randomNumber(1, n);
        }

        // Repeat sorting 100 times to get average time
        for(int i = 1; i <= 100; i++){ // reduced repetition for big arrays
            // Copy array so that each sort works on the same unsorted array
            int tempArr[n];
            for(int j = 0; j < n; j++){
                tempArr[j] = arr[j];
            }

            auto start = high_resolution_clock::now();
            selectionSort(tempArr, n);
            auto stop = high_resolution_clock::now();

            auto duration = duration_cast<microseconds>(stop - start);
            totalTime += duration.count();
        }

        cout << "for n = " << n << " average time = " << (totalTime / 100) << " microseconds" << endl;
    }

    return 0;
}