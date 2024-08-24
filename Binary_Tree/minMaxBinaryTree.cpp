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


pair<int, int> getMinAndMax(BinaryTreeNode<int> *root) {
	// Write your code here
	if(root == NULL){
		pair<int, int> p;
		p.first = INT_MAX;
		p.second = INT_MIN; 
		return p;
	}

	pair<int, int> leftAns = getMinAndMax(root->left);
	pair<int, int> rightAns = getMinAndMax(root->right);

	int leftMin = leftAns.first;
	int rightMin = rightAns.first;

	int leftMax = leftAns.second;
	int rightMax = rightAns.second;

	pair<int, int> p;
	p.first = min(root->data, min(leftMin, rightMin));
	p.second = max(root->data, max(leftMax, rightMax));
    return p;
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
            BinaryTreeNode<int>* rightNode = new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }
    return root;
}

int main() {
    BinaryTreeNode<int>* root = takeInput();
    pair<int, int> ans = getMinAndMax(root);
    cout << ans.first << " " << ans.second;
}