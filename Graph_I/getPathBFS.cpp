#include <iostream>
#include <vector>
#include <map> 
#include <queue>
using namespace std;

void pathBFS(vector<vector<bool>> &edges, long long v1, long long v2, vector<bool> visited){
    queue<long long> pendingVertices;
    map<int, int> path;
    pendingVertices.push(v1);
    visited[v1] = true;

    while(!pendingVertices.empty()){
        long long front = pendingVertices.front();
        // if(front == v2){
        //     break;
        // }
        for(long long i = 0; i < edges.size(); i++){
            if(visited[i]){
                continue;
            }
            if(i == front){
                continue;
            }
            if(!visited[i] && edges[front][i]){
                path[i] = front;
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
        pendingVertices.pop();
    }

    if(!visited[v2]){
        return;
    }
    int i = v2;
    cout<<v2<<" ";
    while(i != v1){
        cout<<path[i]<<" ";
        i = path[i];
    }
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

    vector<bool> visited(v, false);
    pathBFS(edges, v1, v2, visited);
    return 0;
}