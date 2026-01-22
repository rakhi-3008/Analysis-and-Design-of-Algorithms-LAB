#include<iostream>
#include<chrono>
#include<random>
using namespace std;
using namespace std::chrono;

int linearSearch(int arr[], int n, int target){
    for(int i=0; i<n; i++){
        if(arr[i]==target){
            return i;
        }
    }
    return -1;
}

int randomNumber(int min, int max){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<>dist(min, max);
    return dist(gen);
}

int main(){

    for(int n=10; n<=1000000; n=n*10){
        long double totalTime=0;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i]=randomNumber(1, n);
        }
        int target=randomNumber(1, n);
        cout<<"element to be searched is: "<<target<<endl;

        for(int i=1; i<=1000; i++){
            auto start=high_resolution_clock::now();
            int idx=linearSearch(arr, n, target);
            auto stop=high_resolution_clock::now();

            auto duration= duration_cast<nanoseconds>(stop-start);
            totalTime+=duration.count();
        }
        cout<<"for n= "<<n<<" average time is= "<<(totalTime/1000)<<"nanoseconds"<<endl;
    }

    return 0;
}