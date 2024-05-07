#include <iostream>
#include <queue>
#include <vector>
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

int ansResult = 0;
int maxSumLevelWise(TreeNode<int>* root, TreeNode<int>* &ans, int sum){
    if(root == NULL){
        return 0;
    }
    
    int calSum = root->data;
    for(int i = 0; i < root->children.size(); i++){
        calSum += + root->children[i]->data;
    }
    
    for(int i = 0; i < root->children.size(); i++){
        ansResult = maxSumLevelWise(root->children[i], ans, sum);
    }
    
    if(calSum > ansResult){
        ans = root;
        ansResult = calSum;
    }
    return ansResult;
}

TreeNode<int>* maxSumNode(TreeNode<int>* root) {
    // Write your code here
    if(root == NULL){
        return NULL;
    }
    
    TreeNode<int>* ans = root;
    int childSum = 0;
    for(int i = 0; i < root->children.size(); i++){
        childSum = childSum + root->children[i]->data;
    }
    
    int result = maxSumLevelWise(root, ans, childSum);
    return ans;
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

    TreeNode<int>* ans = maxSumNode(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}