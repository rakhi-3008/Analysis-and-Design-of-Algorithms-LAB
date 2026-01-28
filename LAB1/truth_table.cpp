#include<iostream>
using namespace std;

void truthTable(char arr[], int n, int k){
    if(k==n){
        for(int i=0; i<n; i++){
            cout<<arr[i];
        }
        cout<<endl;
        return;
    }
    arr[k]='T';
    truthTable(arr, n, k+1);

    arr[k]='F';
    truthTable(arr, n, k+1);

}

int main(){
    int n;
    cout<<"enter number of character: ";
    cin>>n;
    char arr[n];

    truthTable(arr, n, 0);

    return 0;
}