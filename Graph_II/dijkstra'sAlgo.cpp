#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int findMinVertex(int* distance, bool* visited, int n){
    int minVertex = -1;
    for(int i = 0; i < n; i++){
        if(!visited[i] && (minVertex == -1 || distance[i] < distance[minVertex])){
            minVertex = i;
        }
    }
    return minVertex;
}

void dijkstra(vector<vector<int>> edges, int n){
    bool *visited = new bool[n];
    int *distance = new int[n];

    for(int i = 0; i < n; i++){
        visited[i] = false;
        distance[i] = INT_MAX;
    }

    distance[0] = 0;

    for(int i = 0; i < n - 1; i++){
        int minVertex = findMinVertex(distance, visited, n);
        visited[minVertex] = true;
        for(int j = 0; j < n; j++){
            if(edges[minVertex][j] != 0 && !visited[j]){
                int dist = distance[minVertex] + edges[minVertex][j];
                if(dist < distance[j]){
                    distance[j] = dist;
                }
            }
        }
    }

    for(int i = 0; i < n; i++){
        cout<<i<<" "<<distance[i]<<endl;
    }
}
int main() {
    // Write your code here
    int n, e;
    cin>>n>>e;

    vector<vector<int>> edges(n, vector<int>(n, 0));

    for(int i = 0; i < e; i++){
        int s, e, w;
        cin>>s>>e>>w;
        edges[s][e] = w;
        edges[e][s] = w;
    }

    dijkstra(edges, n);
}