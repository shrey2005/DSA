#include <vector>
#include <iostream>
using namespace std;

void DFS(vector<vector<bool>> &edges, long long sv, vector<bool> &visited){
    visited[sv] = true;

    for(long long i = 0; i < edges.size(); i++){
        if(!visited[i] && edges[sv][i]){
            DFS(edges, i, visited);
        }
    }
}
void connectedPath(vector<vector<bool>> edges, long long v, int &count){
    
    vector<bool> visited(edges.size(), false);

    count = 0;
    for(int i = 0; i < visited.size(); i++){
        if(!visited[i]){
            DFS(edges, i, visited);
            count++;
        }
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

    int count = 0;
    connectedPath(edges, v, count);
    cout<<count<<endl;
    return 0;
}

