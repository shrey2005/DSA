#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>

using namespace std;

template <typename T>
class BinaryTreeNode
{
public:
    T data;
    BinaryTreeNode<T> *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(T x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(T x, BinaryTreeNode<T> *left, BinaryTreeNode<T> *right) : data(x), left(left), right(right) {}
};

BinaryTreeNode<int>* deleteNode(BinaryTreeNode<int>* root, int key) {
    // Write your code here.
    if(root == NULL){
        return root;//1
    }
    
    if(root->data < key){
        root->right = deleteNode(root->right, key);
        return root;
    }
    else if(root->data > key){
        root->left = deleteNode(root->left, key);
        return root;
    }

    if(root->left == NULL){
        BinaryTreeNode<int>* temp = root->right;
        delete root;
        return temp;
    }
    else if(root->right == NULL){
        BinaryTreeNode<int>* temp = root->left;
        delete root;
        return temp;
    }
    else{
        BinaryTreeNode<int>* s = root->right;
        BinaryTreeNode<int>* sp = root;
        while(s->left != NULL){
            sp = s;
            s = s->left;
        }

        if(sp == root){
            sp->right = s->right;
        }
        else{
            sp->left = s->right;
        }
        root->data = s->data;
        delete s;
        return root;
    }
}



class Runner
{
    int t = 1;

    vector<BinaryTreeNode<int>* > arr;
    vector<int> keys;

public:

    void takeInput()
    {

        // cin >> t;

        for (int c = 0; c < t; c++)
        {
            int rootData;
            cin >> rootData;

            if (rootData == -1)
            {
                arr.push_back(NULL);
                continue;
            }

            BinaryTreeNode<int> *root = new BinaryTreeNode<int>(rootData);

            queue<BinaryTreeNode<int> *> q;

            q.push(root);

            while (!q.empty())
            {
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
                    BinaryTreeNode<int> *rightNode = new BinaryTreeNode<int>(rightChild);
                    currentNode->right = rightNode;
                    q.push(rightNode);
                }
            }
            arr.push_back(root);

            int key;

            cin >> key;

            keys.push_back(key);
        }

    }

    void printInorder(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return;
        }

        printInorder(root -> left);

        cout << root -> data << " ";

        printInorder(root -> right);
    }

    BinaryTreeNode<int> *copyTree(BinaryTreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BinaryTreeNode<int> *copyRoot = new BinaryTreeNode<int>(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode<int> *copy = copyTree(arr[i]);

            copy = deleteNode(copy, keys[i]);

            delete copy;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode<int> *root = arr[i];
            root = deleteNode(root, keys[i]);

            if (root == NULL)
            {
                cout << -1;
            }
            else
            {
                printInorder(root);
            }

            cout << "\n";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    Runner runner;

    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}
