#include <iostream>
#include <queue>
#include <vector>
#include <climits>
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

void largestNode(TreeNode<int>* root, TreeNode<int>* &copyRoot){
    if(root == NULL){
        return;
    }

    if(copyRoot == NULL || root->data > copyRoot->data){
        copyRoot = root;
    }

    for(int i = 0; i < root->children.size(); i++){
        largestNode(root->children[i], copyRoot);
    }
}

void secondLargest(TreeNode<int>* root, TreeNode<int>* &secondNode, TreeNode<int>* maxNode){
    
    if(root == NULL){
        return;
    }
    
    if((secondNode == NULL || root->data > secondNode->data) && root->data != maxNode->data){
        secondNode = root;
    }

    // if ((secondNode == NULL || root->data > secondNode->data) && root->data != maxNode->data) {
    //     secondNode = root;
    // }
    
    for(int i = 0; i < root->children.size(); i++){
        secondLargest(root->children[i], secondNode, maxNode);
    }

}

TreeNode<int>* getSecondLargestNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* maxRoot = root;
    TreeNode<int>* secondMaxRoot = NULL;
    largestNode(root, maxRoot);
    secondLargest(root, secondMaxRoot, maxRoot);
    return secondMaxRoot;
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

    TreeNode<int>* ans = getSecondLargestNode(root);

    if (ans != NULL) {
        cout << ans->data;
    } else {
        cout << INT_MIN;
    }

}