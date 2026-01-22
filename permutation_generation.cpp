#include<iostream>
using namespace std;

void permutations(char arr[], int n, int k){
    if(k==n){
        for(int i=0; i<n; i++){
            cout<<arr[i];
        }
        cout<<endl;
        return;
    }else{
        for(int i=k; i<n; i++){
            swap(arr[i], arr[k]);
            permutations(arr, n, k+1);
            swap(arr[i], arr[k]);
        }
    }
}

int main(){
    int n;
    cout<<"enter value of n: ";
    cin>>n;
    char arr[n];
    cout<<"enter values inside array: "<<endl;
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }
    cout<<"possible permuations are: "<<endl;
    permutations(arr, n, 0);
    return 0;
}