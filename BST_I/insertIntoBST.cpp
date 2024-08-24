#include <iostream>
#include <vector>
#include <queue>


using namespace std;



template <typename T>
class TreeNode
{
public:
    T val;
    TreeNode<T> *left, *right;
    TreeNode() : val(0), left(NULL), right(NULL) {}
    TreeNode(T x) : val(x), left(NULL), right(NULL) {}
    TreeNode(T x, TreeNode<T> *left, TreeNode<T> *right) : val(x), left(left), right(right) {}
};

TreeNode<int>* insertionInBST(TreeNode<int>* root, int val)
{
    // Write your code here.
    if(root == NULL){
        return new TreeNode<int>(val);
    }
    if(root->val < val){
        TreeNode<int> *tempRight = insertionInBST(root->right, val);
        root->right = tempRight;
    }
    else{
        TreeNode<int> *tempLeft = insertionInBST(root->left, val);
        root->left = tempLeft;
    }
    return root;
}

// Function to find inorder traversal of binary tree.
void InOrder (TreeNode<int>* root, vector<int> &inOrder)
{
    if (root == NULL)
    {
        return;
    }

    InOrder(root -> left, inOrder);
    inOrder.push_back(root -> val);
    InOrder(root -> right, inOrder);
}

// Checker function to check correctness of the output
bool checker (TreeNode<int>* root, vector<int> &arr, int val, vector<int> &inOrder)
{
    /*
    We will check if inorder traversal of returned bst is sorted or not.
    And all elements of of returned tree should be equal to all elements before
    insertion plus given val
    if both conditon follow print 1 else 0
    */

    inOrder.clear();
    InOrder(root, inOrder);

    for (int i = 1; i < inOrder.size(); i++)
    {
        if (inOrder[i] <= inOrder[i - 1])
        {
            return false;
        }
    }

    if (inOrder.size() != arr.size() + 1)
    {
        return false;
    }

    int p1 = 0, p2 = 0;

    while (p1 < inOrder.size())
    {
        if ( p2 < arr.size() && inOrder[p1] == arr[p2])
        {
            p2 ++;
        }

        else
        {
            if ( inOrder[p1] != val)
            {
                return false;
            }
        }

        p1 ++;

    }

    if (p2 != arr.size())
    {
        return false;
    }

    return true;
}



class Runner
{
    int t = 1;
    vector<TreeNode<int>*> allTree;
    vector<int> allVal;
    vector<int> inOrder;


    TreeNode<int> *takeTreeInput()
    {

        int rootData;
        cin >> rootData;


        if (rootData == -1)
        {
            return NULL;
        }

        TreeNode<int> *root = new TreeNode<int>(rootData);

        queue<TreeNode<int> *> q;
        q.push(root);

        while (q.empty() == false)
        {
            TreeNode<int> *currentNode = q.front();
            q.pop();
            int leftChild, rightChild;

            cin >> leftChild;

            if (leftChild != -1)
            {
                TreeNode<int> *leftNode = new TreeNode<int>(leftChild);

                currentNode->left = leftNode;
                q.push(leftNode);
            }

            cin >> rightChild;

            if (rightChild != -1)
            {
                TreeNode<int> *rightNode = new TreeNode<int>(rightChild);

                currentNode->right = rightNode;
                q.push(rightNode);
            }
        }

        return root;
    }

    TreeNode<int> *copyTree(TreeNode<int> *root)
    {
        if (root == NULL)
        {
            return NULL;
        }

        TreeNode<int> *copyRoot = new TreeNode<int>(root->val);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

public:
    void takeInput()
    {
        // cin >> t;
        allTree.resize(t);
        allVal.resize(t);

        for (int i = 0; i < t; i++)
        {
            allTree[i] = takeTreeInput();
            cin >> allVal[i];
        }
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            TreeNode<int> *copyRoot = copyTree(allTree[i]);

            // Get the answer from scaffold/solution
            insertionInBST(copyRoot, allVal[i]);

            // We are done with current copy root so we can delete it.
            delete copyRoot;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {

            inOrder.clear();
            InOrder(allTree[i], inOrder);

            vector<int> beforeInsert = inOrder;
            inOrder.clear();

            TreeNode<int>* ansRoot = insertionInBST(allTree[i], allVal[i]);

            bool check = checker(ansRoot, beforeInsert, allVal[i], inOrder);

            inOrder.clear();

            if (check == true)
            {
                cout << "1\n";
            }
            else
            {
                cout << "0\n";
            }
        }
    }
};

int main()
{
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}