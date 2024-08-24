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

void printLevelWise(BinaryTreeNode<int> *root) {
	// Write your code here
	// BinaryTreeNode<int>* rootNode = new BinaryTreeNode<int>(root);
	queue<BinaryTreeNode<int>*> q;
	q.push(root);

	while(!q.empty()){
		BinaryTreeNode<int>* currentNode = q.front();
		q.pop();

		cout<<currentNode->data<<":";
		if(currentNode->left){
			cout<<"L:"<<currentNode->left->data;
			q.push(currentNode->left);	
		}
		else{
		    cout<<"L:-1";
		}

		if(currentNode->right){
			cout<<",R:"<<currentNode->right->data;
			q.push(currentNode->right);
		}
		else{
		    cout<<",R:-1";
		}
		cout<<endl;
	}
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
    printLevelWise(root);
}