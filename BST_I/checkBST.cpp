#include <iostream>
#include <queue>
#include <climits>

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

int leftMax(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MIN;
	}

	int	leftMaxVal = leftMax(root->left);

	int	rightMaxVal = leftMax(root->right);

	int maxval = max(root->data, max(leftMaxVal, rightMaxVal));
	return maxval;
}
int rightMin(BinaryTreeNode<int>* root){
	if(root == NULL){
		return INT_MAX;
	}

	int	leftMinVal = rightMin(root->left);

	int	rightMinVal = rightMin(root->right);

	int minval = min(root->data, min(leftMinVal, rightMinVal));
	return minval;

}
bool isBST(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
		return true;
	}

	 int leftMaxValue = leftMax(root->left);

	 int rightMinValue = rightMin(root->right);
    
	if(root->data < leftMaxValue || root->data > rightMinValue){
        return false;
    }
	else if(root->data > leftMaxValue && root->data < rightMinValue){
		// result = true;
		return true;
	}
	// return result;
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
    cout << (isBST(root) ? "true" : "false");
}