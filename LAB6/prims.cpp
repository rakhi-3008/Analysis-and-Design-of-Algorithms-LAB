#include <iostream>
using namespace std;

#define INF 9999

void inputGraph(int cost[20][20], int n){
    cout << "Enter cost adjacency matrix:\n";
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            cin >> cost[i][j];
        }
    }
}

void prims(int cost[20][20], int n){
    int near[20], t[20][2];
    int i,j,k,l;
    int min = INF;
    int minCost=0;

    for(i=1;i<=n;i++){
        for(j=1;j<=n;j++){
            if(i!=j && cost[i][j] < min){
                min = cost[i][j];
                k=i;
                l=j;
            }
        }
    }
    t[1][1]=k;
    t[1][2]=l;

    for(i=1;i<=n;i++){
        if(cost[i][k] < cost[i][l])
            near[i]=k;
        else
            near[i]=l;
    }

    near[k]=0;
    near[l]=0;
    minCost+=cost[k][l];

    for(i=2;i<n;i++){
        min=INF;
        int u;

        for(j=1;j<=n;j++){
            if(near[j]!=0 && cost[j][near[j]] < min){
                min = cost[j][near[j]];
                u = j;
            }
        }
        t[i][1] = u;
        t[i][2] = near[u];
        minCost+=cost[u][near[u]];
        near[u] = 0;

        for(k=1;k<=n;k++){
            if(near[k]!=0 && cost[k][u] < cost[k][near[k]])
                near[k] = u;
        }
    }
    cout<<"Edges in MST:"<<endl;
    for(i=1;i<n;i++)
        cout<<t[i][1]<<" - "<<t[i][2]<<endl;

    cout<<"min cost="<<minCost<<endl;
}

int main(){
    int n;
    int cost[20][20];

    cout << "Enter number of vertices: ";
    cin >> n;

    inputGraph(cost,n);
    prims(cost,n);

    return 0;
}