#include <iostream>
#include <queue>
#include <vector>

#include <cmath>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};


void nextLargest(TreeNode<int>* root, TreeNode<int>* &nextLargeEle, int x){
    if(root == NULL){
        return;
    }
    
    int calDiff = abs(root->data - x);
    int calDiff1 = abs(nextLargeEle->data - root->data);
    
    if(calDiff <= calDiff1){
        nextLargeEle = root;
    }
    
    for(int i = 0; i < root->children.size(); i++){
        nextLargest(root->children[i], nextLargeEle, x);
    }
}

TreeNode<int>* getNextLargerElement(TreeNode<int>* root, int x) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* nextLargestEle = root;
    nextLargest(root, nextLargestEle, x);

    if(nextLargestEle->data > x){
        return nextLargestEle;
    }

    return NULL;
}

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();
    int x;
    cin >> x;
    TreeNode<int>* ans = getNextLargerElement(root, x);

    if (ans != NULL) {
        cout << ans->data;
    }
}