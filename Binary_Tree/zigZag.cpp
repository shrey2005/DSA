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

#include <stack>
void zigZagOrder(BinaryTreeNode<int> *root) {
	if(root==NULL) return  ; 
	stack<BinaryTreeNode<int>*> s1 ; 
	stack<BinaryTreeNode<int>*> s2l_r ; 
	s1.push(root) ;
        while (!s1.empty() || !s2l_r.empty()) {
          while (!s1.empty()) {
          BinaryTreeNode<int>* cur = s1.top() ; 
		  s1.pop()  ; 
		  cout<<cur->data<<" " ; 
		  if(cur->left!=NULL ) s2l_r.push(cur->left) ; 
		  if(cur->right!=NULL ) s2l_r.push(cur->right) ; 
		  }
		cout<<endl ; 
		  while(!s2l_r.empty()){
			   BinaryTreeNode<int>* cur2 = s2l_r.top() ; 
		  s2l_r.pop()  ; 
		  cout<<cur2->data<<" " ; 
		    if(cur2->right!=NULL ) s1.push(cur2->right) ;
		  if(cur2->left!=NULL ) s1.push(cur2->left) ; 
		  }
		  cout<<endl ; 
                }
				return ; 
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
    zigZagOrder(root);
}