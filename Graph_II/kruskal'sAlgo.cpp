#include <iostream>
#include <vector>
#include <bits/stdc++.h> 
using namespace std;

class Edge{
    public:
        int source;
        int destination;
        int weight;
};

bool compare(Edge e1, Edge e2){
    return e1.weight < e2.weight;
}

int findParent(int i, int *parent){
    if(parent[i] == i){
        return i;
    }
    return findParent(parent[i], parent);
}

void krushkal(Edge *input,int v, int e){
    //sort the input array - ascending order based on weight
    sort(input, input + e, compare);

    Edge *output = new Edge[v-1];

    int *parent = new int[v];
    for(int i = 0; i < v; i++){
        parent[i] = i;
    }

    int count = 0;
    int i = 0;
    while(count != v-1){
        Edge currentEdge = input[i];

        //Check if we can add the currentEdge in MST or not
        int sourceParent = findParent(currentEdge.source, parent);
        int destinationParent = findParent(currentEdge.destination, parent );
        if(sourceParent != destinationParent){
            output[count] = currentEdge;
            parent[sourceParent] = destinationParent;
            count++;
        }
        i++;
    }

    for(int i = 0; i < v-1; i++){
        if(output[i].source < output[i].destination){
            cout<<output[i].source<<" "<<output[i].destination<<" "<<output[i].weight<<endl;
        }
        else{
            cout<<output[i].destination<<" "<<output[i].source<<" "<<output[i].weight<<endl;
        }
    }
}
int main() {
    // Write your code here

    int v, e;
    cin>>v>>e;

    Edge *input = new Edge[e];
    for(int i = 0; i < e; i++){
        int s, d, w;
        cin>>s>>d>>w;
        input[i].source = s;
        input[i].destination = d;
        input[i].weight = w;
    }

    krushkal(input, v, e);
}