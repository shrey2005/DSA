#include <iostream>
#include <vector>
using namespace std;

void DFS(vector<vector<bool>> &edges, long long v, vector<bool> &visited){
    visited[v] = true;

    for(long long i = 0; i < edges.size(); i++){
        if(!visited[i] && edges[v][i]){
            DFS(edges, i, visited);
        }
    }
}

bool isConnected(vector<vector<bool>> &edges, long long v, long long e){
    vector<bool> visited(edges.size(), false);

    DFS(edges, 0, visited);
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            return false;
        }
    }
    return true;
}

int main() {
    // Write your code here
    long long v, e;
    cin>>v>>e;

    vector<vector<bool>> edges(v, vector<bool>(v, false)); 
    for(long long i = 0; i < e; i++){
        long long start, end;
        cin>>start>>end;
        edges[start][end] = true;
        edges[end][start] = true;
    }

    long long v1, v2;
    cin>>v1>>v2;

    bool flag = isConnected(edges, 0, e);

    cout<<(flag ? "true" : "false");
    return 0;
}