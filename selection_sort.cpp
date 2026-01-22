#include<iostream>
#include<random>
using namespace std;

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
    cout<<"sorted array"<<endl;
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
}

int main(){
    int n;
    cout<<"enter number of elements in array: ";
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++){
        arr[i]=randomNumber(1, 100000);
    }

    selectionSort(arr, n);
    return 0;

}