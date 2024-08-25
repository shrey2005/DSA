#include <iostream>
#include <queue>
#include <vector>

using namespace std;
template <typename T>
class BinaryTreeNode {
   public:
    T data;
    BinaryTreeNode<T> *left;
    BinaryTreeNode<T> *right;

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


bool findNode(BinaryTreeNode<int> *root , int data, vector<int>& result){
	if(root == NULL){
		return false;
	}

	if(root->data == data){
		result.push_back(root->data);
		return true;
	}
	if(data < root->data){
		bool temp = findNode(root->left, data, result);
		if(temp){
			result.push_back(root->data);
		}
		return temp;
	}
	else{
		bool temp = findNode(root->right, data, result);
		if(temp){
			result.push_back(root->data);
		}
		return temp;
	}
}

vector<int>* getPath(BinaryTreeNode<int> *root , int data) {
	// Write your code here
	vector<int>* result = new vector<int>();
	if(root == NULL){
		return result;
	}
	bool isPathExists = findNode(root, data, *result);
	return result;
}

BinaryTreeNode<int> *takeInput() {
    int rootData;
    cin >> rootData;
    if (rootData == -1) {
        return NULL;
    }

    BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    while (!q.empty()) {
        BinaryTreeNode<int> *currentNode = q.front();
        q.pop();
        int leftChild, rightChild;
        cin >> leftChild;
        if (leftChild != -1) {
            BinaryTreeNode<int> *leftNode = new BinaryTreeNode<int>(leftChild);
            currentNode->left = leftNode;
            q.push(leftNode);
        }
        cin >> rightChild;
        if (rightChild != -1) {
            BinaryTreeNode<int> *rightNode =
                new BinaryTreeNode<int>(rightChild);
            currentNode->right = rightNode;
            q.push(rightNode);
        }
    }

    return root;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    int k;
    cin >> k;
    vector<int> *output = getPath(root, k);

    if (output != NULL) {
        for (int i = 0; i < output->size(); i++) {
            cout << output->at(i) << " ";
        }
    }

    delete root;
}