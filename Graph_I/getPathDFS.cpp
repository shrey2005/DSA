#include <iostream>
#include <vector>
using namespace std;

vector<long long> pathDFS(vector<vector<bool>> &edges, long long v1, long long v2, vector<bool> &visited){
    vector<long long> path;
    if(v1 == v2){
        path.push_back(v1);
        return path;
    }
    for(long long i = 0; i < edges.size(); i++){
        if(i == v1){
            continue;
        }
        if(visited[i]){
            continue;
        }
        if(edges[v1][i]){
            visited[i] = true;
            path = pathDFS(edges, i, v2, visited); 
            if(path.size()){
                path.push_back(v1);
                return path;
            }
        }
    }
    return path;
}

int main() {
    // Write your code here;

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

    vector<bool> visited(v, false);

    visited[v1] = true;
    vector<long long> path = pathDFS(edges, v1, v2, visited);
    if(path.size()){
        for(long long i = 0; i < path.size(); i++){
            cout<<path[i]<<" ";
        }
    }
        
    return 0;
}