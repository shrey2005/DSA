#include <iostream>
#include <queue>
#include<vector>
using namespace std;

bool hasPath(vector<vector<bool>>& edges, long long v1, long long v2, vector<bool> &visited){
    queue<long long> pendingVertices;
    pendingVertices.push(v1);
    visited[v1] = true;

    while(!pendingVertices.empty()){
        long long front = pendingVertices.front();
        pendingVertices.pop();
        if(front == v2){
            return true;
        }
        for(long long i = 0; i < edges.size(); i++){
            if(!visited[i] && edges[front][i]){
                pendingVertices.push(i);
                visited[i] = true;
            }
        }
    }
    return false;
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

    vector<bool> result(v, false);
    bool ans = hasPath(edges, v1, v2, result);
    cout<<(ans ? "true" : "false")<<endl;
    return 0;
}