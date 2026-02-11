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

int binarySearch(int arr[], int st, int end, int target){
    if(st==end){
        if(arr[st]==target){
            cout<<"element found..."<<endl;
            return st;
        }else{
        cout<<"no element found..."<<endl;
        return -1;
        }
    }

    int mid= st+((end-st)/2);

    if(arr[mid]==target){
        return mid;
    }else if(target<arr[mid]){
        return binarySearch(arr, st, mid-1, target);
    }else{
        return binarySearch(arr, mid+1, end, target);
    }
}

int main(){

    for(int n=10; n<=100000; n=n*10){
        long double totalTime=0;
        int arr[n];
        for(int i=0; i<n; i++){
            arr[i]=i;
        }

        int target=randomNumber(1, n*10);
        cout<<"element to be searched is: "<<target<<endl;

        for(int i=1; i<=10; i++){
            auto start=high_resolution_clock::now();
            int idx= binarySearch(arr, 0, n-1, target);
            auto stop=high_resolution_clock::now();
            cout<<"found at the index: "<<idx<<endl;

            auto duration= duration_cast<microseconds>(stop-start);
            totalTime+=duration.count();
        }
        cout<<"for n= "<<n<<" average time is= "<<(totalTime/10)<<"microseconds"<<endl;
    
    }

    return 0;
}