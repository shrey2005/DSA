#include <iostream>
#include <queue>
#include<algorithm>
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


void inorderArr(BinaryTreeNode<int> *root, vector<int> &arr){
	if(root == NULL){
		return;
	}
	arr.push_back(root->data);
	inorderArr(root->left, arr);
	inorderArr(root->right, arr);
}
void pairSum(BinaryTreeNode<int> *root, int sum) {
    // Write your code here
	vector<int> rootNode;
	inorderArr(root, rootNode);
	sort(rootNode.begin(), rootNode.end());
	int i = 0;
	int j = rootNode.size() - 1;

	while(i < j){
		if(rootNode[i] + rootNode[j] < sum){
			i++;
		}
		else if(rootNode[i] + rootNode[j] > sum){
			j--;
		}
		else if(rootNode[i] + rootNode[j] == sum){
			cout<<rootNode[i]<<" "<<rootNode[j]<<endl;
			i++;
			j--;
		}
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
    int sum;
    cin >> sum;
    pairSum(root, sum);
    delete root;
}