Given an undirected and disconnected graph G(V, E), print its BFS traversal.

Note:

1. Here you need to consider that you need to print BFS path starting from vertex 0 only. 
2. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
3. E is the number of edges present in graph G.
4. Take graph input in the adjacency matrix.
5. Handle for Disconnected Graphs as well
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
0 <= V <= 1000
0 <= E <= (V * (V - 1)) / 2
0 <= a <= V - 1
0 <= b <= V - 1
Time Limit: 1 second
Sample Input 1:
4 4
0 1
0 3
1 2
2 3
Sample Output 1:
0 1 3 2
//     }
// }


#include <iostream>
#include <queue>
using namespace std;

void print(bool **edges, long long v, long long sv, bool *visited)
{
…        if (!visited[i])
            print(edges, v, i, visited);
    }
    delete[] visited;
    for (long long i = 0; i < v; i++)
        delete edges[i];
    delete[] edges;
    return 0;
}
