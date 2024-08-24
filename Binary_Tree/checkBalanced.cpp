#include <iostream>
#include <queue>

using namespace std;
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T>* left;
    BinaryTreeNode<T>* right;

    BinaryTreeNode(T data) {
        this->data = data;
        left = NULL;
        right = NULL;
    }
};

int calHeight(BinaryTreeNode<int> *root){
    
    int left = 0;
    if(root->left){
        left = calHeight(root->left);
    }
    
    int right = 0;
    if(root->right){
        right = calHeight(root->right);
    }
    return 1 + left + right;
}

bool isBalanced(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
        return true;
    }

    int leftTreeHeight = 0;
    if (root->left) {
         leftTreeHeight = calHeight(root->left);
    }
    int rightTreeHeight = 0;
	if(root->right){
		rightTreeHeight =calHeight(root->right);
	}

    bool balanced = false;
    int findDiff = abs(leftTreeHeight - rightTreeHeight);
    if(findDiff <= 1){
        balanced = true;
    }
    return balanced;
}

BinaryTreeNode<int>* takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int>* currentNode = q.front();
        q.pop();
        int leftChild, rightChild;

        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int>* leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }

        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int>* rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << (isBalanced(root) ? "true" : "false");
}