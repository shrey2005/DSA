#include <iostream>
#include <queue>
#include <vector>

using namespace std;
template <typename T>
class Node {
   public:
    T data;
    Node<T> *next;
    Node(T data) {
        this->data = data;
        this->next = NULL;
    }
};

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
};

vector<Node<int>*> constructLinkedListForEachLevel(BinaryTreeNode<int> *root) {
    // Write your code here
	vector<Node<int>*> updatedRoot;
	if(root == NULL){
		return updatedRoot;
	}

	queue<BinaryTreeNode<int>*> q;
	q.push(root);
	q.push(NULL);

	Node<int> *head = NULL, *tail = NULL;
	
	while(!q.empty()){
		BinaryTreeNode<int>* current = q.front();
		q.pop();

		if(current == NULL){
			if(head != NULL){
				updatedRoot.push_back(head);
				head = tail = NULL;
			}

			if(!q.empty()){
				q.push(NULL);
			}
		}
		else{
			Node<int> *llNode = new Node<int>(current->data);
			if(head == NULL){
				head = llNode;
				tail = llNode;
			}
			else{
				tail-> next = llNode;
				tail = llNode;
			}

			if(current->left){
				q.push(current->left);
			}

			if(current->right){
				q.push(current->right);
			}
		}
	}
	return updatedRoot;
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

void print(Node<int> *head) {
    Node<int> *temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    vector<Node<int> *> ans = constructLinkedListForEachLevel(root);

    for (int i = 0; i < ans.size(); i++) {
        print(ans[i]);
    }
}