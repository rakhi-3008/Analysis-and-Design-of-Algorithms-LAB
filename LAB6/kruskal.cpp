#include <iostream>
using namespace std;

#define MAX 20
#define INF 999

int parent[MAX];

struct Edge {
    int u, v, w;
};

int find(int i){
    while(parent[i] != -1)
        i = parent[i];
    return i;
}

void Union(int x, int y){
    parent[x] = y;
}

void kruskal(Edge e[], int n, int m){
    int i, j, min, a, b, k;
    int mincost = 0;

    for(i = 1; i <= n; i++)
        parent[i] = -1;

    cout << "Edges in Minimum Spanning Tree:\n";

    for(i = 1; i <= m; i++){
        min = INF;

        for(j = 1; j <= m; j++){
            if(e[j].w < min){
                min = e[j].w;
                a = e[j].u;
                b = e[j].v;
                k = j;   // store index
            }
        }

        int x = find(a);
        int y = find(b);

        if(x != y){
            cout << a << " - " << b << endl;
            mincost += min;
            Union(x, y);
        }
        e[k].w = INF;   // mark edge as used
    }

    cout << "Minimum Cost = " << mincost;
}

int main(){
    int n, m, i;
    Edge e[MAX];

    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter edges (u v weight):\n";

    for(i = 1; i <= m; i++)
        cin >> e[i].u >> e[i].v >> e[i].w;

    kruskal(e, n, m);

    return 0;
}