#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int findMinVertex(int* weight, bool* visited, int n){
    int minVertex = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && (minVertex == -1 || weight[i] < weight[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void prims(vector<vector<int>> &edges, int n){
    int* weight = new int[n];
    bool* visited = new bool[n];
    int* parent = new int[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        weight[i] = INT_MAX;
    }

    parent[0] = -1;
    weight[0] = 0;

    for(int i = 0 ; i < edges.size(); i++){
        int minVertex = findMinVertex(weight, visited, n);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                if(edges[minVertex][j] < weight[j]){
                    weight[j] = edges[minVertex][j];
                    parent[j] = minVertex;
                }
            }
        }
    }

    for(int i = 1; i < edges.size(); i++){
        if(parent[i] < i){
            cout<<parent[i] << " "<<i<<" "<<weight[i]<<endl;
        }
        else{
            cout<<i<<" "<<parent[i]<<" "<<weight[i]<<endl;
        }
    }
}

int main() {
    // Write your code here
    int v, e;
    cin>>v>>e;

    vector<vector<int>> edges(v,vector<int>(v,0));

    for(int i = 0 ; i < e; i++){
        int start, end, weight;
        cin>>start>>end>>weight;
        edges[start][end] = weight;
        edges[end][start] = weight;
    }

    prims(edges, v);
}