#include<iostream>
using namespace std;
//time complexity O(n)
int power(int x, int n){
    if(n==0){
        return 1;
    }
    return x*power(x, n-1);
}

//time complexity O(logn)
int pow(int x, int n){
    if(n==0){
        return 1;
    }
    int halfPower=pow(x, n/2);
    int halfPowerSquare=halfPower*halfPower;

    if(n%2!=0){
        return x*halfPowerSquare;
    }
    return halfPowerSquare;
}

int pow2(int x, int n){
    int z=x;
    int m=n;
    int pow=1;
    while(m>0){
        while(m%2==0){
            m=m/2;
            z=z*z;
        }
        m=m-1;
        pow=pow*z;
    }
    return pow;
}

int main(){
    int x, n;
    cout<<"enter value of x: ";
    cin>>x;
    cout<<"enter value of n: ";
    cin>>n;

    cout<<x<<" raised to power "<<n<<" is: "<<pow(x, n)<<endl;
    
    return 0;
}