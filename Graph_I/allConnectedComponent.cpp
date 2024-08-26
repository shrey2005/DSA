#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

vector<long long> getConnectedComponent(const vector<vector<long long>> &edges, long long v, vector<bool> &visited) {
    queue<long long> vertices;
    vector<long long> ans;
    vertices.push(v);
    visited[v] = true;

    while (!vertices.empty()) {
        long long front = vertices.front();
        ans.push_back(front);
        vertices.pop();

        for (long long i = 0; i < edges.size(); i++) {
            if (!visited[i] && edges[front][i] == 1) {
                vertices.push(i);
                visited[i] = true;
            }
        }
    }

    return ans;
}

vector<vector<long long>> getans(const vector<vector<long long>> &edges, long long v) {
    vector<bool> visited(v, false);
    vector<vector<long long>> component;
    for (long long i = 0; i < edges.size(); i++) {
        if (!visited[i]) {
            vector<long long> ans = getConnectedComponent(edges, i, visited);
            component.push_back(ans);
        }
    }
    return component;
}

int main() {
    long long v, e;
    cin >> v >> e;

    vector<vector<long long>> edges(v, vector<long long>(v, 0));
    for (long long i = 0; i < e; i++) {
        long long start, end;
        cin >> start >> end;
        edges[start][end] = 1;
        edges[end][start] = 1;
    }

    vector<vector<long long>> connectedPath = getans(edges, v);

    for (long long i = 0; i < connectedPath.size(); i++) {
        sort(connectedPath[i].begin(), connectedPath[i].end());
        for (long long j = 0; j < connectedPath[i].size(); j++) {
            cout << connectedPath[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}
