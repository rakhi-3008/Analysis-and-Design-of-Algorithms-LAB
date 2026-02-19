#include<iostream>
#include<vector>
#include<random>
#include<algorithm>
using namespace std;

// Random Number Generator
int randomNumber(int min, int max){
    static random_device rd;
    static mt19937 gen(rd());
    uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

// Compare function for ratio (descending)
bool compare(pair<double, int> p1, pair<double, int> p2){
    return p1.first > p2.first;
}

// Sort by Profit (Descending)
void sort_profit(vector<int> &val, vector<int> &wt){
    int n = val.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(val[j] < val[j+1]){
                swap(val[j], val[j+1]);
                swap(wt[j], wt[j+1]);
            }
        }
    }
}

// Sort by Weight (Ascending)
void sort_weight(vector<int> &val, vector<int> &wt){
    int n = wt.size();
    for(int i = 0; i < n - 1; i++){
        for(int j = 0; j < n - i - 1; j++){
            if(wt[j] > wt[j+1]){
                swap(val[j], val[j+1]);
                swap(wt[j], wt[j+1]);
            }
        }
    }
}

// Profit Based Method
double knapsack_profit(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    double ans = 0;

    sort_profit(val, wt);

    for(int i = 0; i < n; i++){
        if(wt[i] <= W){
            ans += val[i];
            W -= wt[i];
        }else{
            ans += (double)val[i] / wt[i] * W;
            break;
        }
    }
    return ans;
}

// Weight Based Method
double knapsack_weight(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    double ans = 0;

    sort_weight(val, wt);

    for(int i = 0; i < n; i++){
        if(wt[i] <= W){
            ans += val[i];
            W -= wt[i];
        }else{
            ans += (double)val[i] / wt[i] * W;
            break;
        }
    }
    return ans;
}

// Ratio Based Method
double knapsack_ratio(vector<int> val, vector<int> wt, int W){
    int n = val.size();
    double ans = 0;

    vector<pair<double,int>> ratio(n);

    for(int i = 0; i < n; i++){
        ratio[i] = {(double)val[i]/wt[i], i};
    }

    sort(ratio.begin(), ratio.end(), compare);

    for(int i = 0; i < n; i++){
        int idx = ratio[i].second;

        if(wt[idx] <= W){
            ans += val[idx];
            W -= wt[idx];
        }else{
            ans += ratio[i].first * W;
            break;
        }
    }
    return ans;
}

int main(){

    for(int n=10; n<=100; n=n+10){
    cout<<"for n="<<n<<endl;

    vector<int> val(n), wt(n);

    for(int i = 0; i < n; i++){
        val[i] = randomNumber(1, n*100);
        wt[i]  = randomNumber(1, n*100);
    }

    cout<<"Values: ";
    for(int i=0; i<n; i++)
        cout<<val[i]<<" ";
    cout<<endl;

    cout<<"Weights: ";
    for(int i=0; i<n; i++)
        cout<<wt[i]<<" ";
    cout<<endl;

    int W=randomNumber(1, 1000);

    cout<<"Ratio Method (Correct Greedy): "
        <<knapsack_ratio(val, wt, W)<<endl;

    cout<<"Profit Method: "
        <<knapsack_profit(val, wt, W)<<endl;

    cout<<"Weight Method: "
        <<knapsack_weight(val, wt, W)<<endl;
    }

    return 0;
}
