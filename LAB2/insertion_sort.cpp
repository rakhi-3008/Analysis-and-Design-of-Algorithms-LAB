#include<iostream>
#include<chrono>
#include<random>
using namespace std;
using namespace std::chrono;

int randomNumber(int min, int max){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<>dist(min, max);
    return dist(gen);
}

void insertionSort(int arr[], int n){
    for(int i=0; i<n; i++){
        int key=arr[i];
        int j=i-1;
        while(j>0 && arr[j]>key){
            arr[j+1]=arr[j];
            j=j-1;
        }
        arr[j+1]=key;
    }
}

int main(){

    for(int n=10; n<=1000000; n=n*10){
        long double totalTime=0;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i]=randomNumber(1, n);
        }

        for(int i=1; i<=1000; i++){
            auto start=high_resolution_clock::now();
            insertionSort(arr, n);
            auto stop=high_resolution_clock::now();

            auto duration= duration_cast<microseconds>(stop-start);
            totalTime+=duration.count();
        }
        cout<<"for n= "<<n<<" average time is= "<<(totalTime/1000)<<"microseconds"<<endl;
    }

    return 0;
}