#include <iostream>
#include <queue>
#include <climits>
#include <vector>

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
    ~BinaryTreeNode() {
        if (left) delete left;
        if (right) delete right;
    }
};

vector<int> findTreeHeight(BinaryTreeNode<int> *root){
	vector<int> result(3);

	if(root == NULL) return { INT_MAX, INT_MIN, 0};

	vector<int> leftResult = findTreeHeight(root->left);
	vector<int> rightResult = findTreeHeight(root->right);

	if(root->data < rightResult[0] && root->data > leftResult[1]){
		result[0] = min(root->data, min(leftResult[0], rightResult[0]));
		result[1] = max(root->data, max(leftResult[1], rightResult[1]));
		result[2] = max(leftResult[2], rightResult[2]) + 1;
		return result;
	}
	else{
		result[0] = INT_MIN;
		result[1] = INT_MAX;
		result[2] = max(leftResult[2], rightResult[2]);
		return result;
	}
}

int largestBSTSubtree(BinaryTreeNode<int> *root) {
    // Write your code here
	if(root == NULL){
		return 0;
	}
	vector<int> treeHeight = findTreeHeight(root);
	return treeHeight[2];
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
    cout << largestBSTSubtree(root);
    delete root;
}