#include <iostream>
#include <queue>
using namespace std;

class Node{
    public:
        char data;
        int freq;
        Node *L;
        Node *R;
        
    Node(char data, int freq){
        this->data = data;
        this->freq = freq;
        L = R = NULL;
    }
};

struct comp{
    bool operator()(Node *a, Node *b){
        return a->freq > b->freq;
    }
};

void dfs(Node *root, string word){
    if(root == NULL) return;
    if(root->data != '$') cout<<root->data<<" "<<word<<endl;
    
    dfs(root->L, word + "0");
    dfs(root->R, word + "1");
}

int main() {
    char data;
    int frq, n;
    
    priority_queue<Node*, vector<Node*>, comp> min_queue; 
    
    cin>>n;
    
    while(n--){
        cin>>data>>frq;
        min_queue.push(new Node(data, frq));
    }
    
    while(min_queue.size() > 1){
        Node *l = min_queue.top();
        min_queue.pop();
        
        Node *r = min_queue.top();
        min_queue.pop();
        
        // cout<<l->data<<" "<<r->data<<endl;
        Node *newNode = new Node('$', l->freq + r->freq);
        newNode -> L = l;
        newNode -> R = r;
        
        min_queue.push(newNode);
    }
    
    Node *root = min_queue.top();
    
    dfs(root, "");
}