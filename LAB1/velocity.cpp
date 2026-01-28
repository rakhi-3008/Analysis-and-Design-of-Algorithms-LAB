#include<iostream>
using namespace std;

int tip(double v){
    if(v <= 1)
        return 0;

    return 1 + tip(v * 0.575);
}

int main(){
    cout << "number of tips: " << tip(200) << endl;
    return 0;
}
