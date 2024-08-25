#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <climits>
#include <queue>
#include<algorithm>
using namespace std;

class BinaryTreeNode
{
public:
    int data;
    BinaryTreeNode *left, *right;
    BinaryTreeNode() : data(0), left(NULL), right(NULL) {}
    BinaryTreeNode(int x) : data(x), left(NULL), right(NULL) {}
    BinaryTreeNode(int x, BinaryTreeNode *left, BinaryTreeNode *right) : data(x), left(left), right(right) {}
};

void inorderArr(BinaryTreeNode *root, vector<int> &arr){
    if(root == NULL){
        return;
    }
    arr.push_back(root->data);
    inorderArr(root->left, arr);
    inorderArr(root->right, arr);
}
bool pairSumBst(BinaryTreeNode *root, int k)
{
    // Write your code here
    if(root == NULL) return false;
    vector<int> arr;
    inorderArr(root, arr);
    sort(arr.begin(), arr.end());
    int i = 0;
    int j = arr.size() - 1;

    bool flagPairSumExist = false;
    while(i < j){
        int calSum = arr[i] + arr[j];
         if(calSum < k){
            i++;
        }
        else if(calSum > k){
            j--;
        }
        else if(calSum == k){
            flagPairSumExist = true;
            i++;
            j--;
        }
    }
    return flagPairSumExist;
}

class Runner
{
    int t;

    vector<BinaryTreeNode *> arr;

    vector<int> k;

public:
    void takeInput()
    {
        t = 1;

        for (int c = 0; c < t; c++)
        {
            int kVal;

            int rootData;
            cin >> rootData;

            if (rootData == -1)
            {
                arr.push_back(NULL);
            }

            BinaryTreeNode *root = new BinaryTreeNode(rootData);

            queue<BinaryTreeNode *> q;

            q.push(root);

            while (!q.empty())
            {
                BinaryTreeNode *currentNode = q.front();
                q.pop();
                int leftChild, rightChild;

                cin >> leftChild;

                if (leftChild != -1)
                {
                    BinaryTreeNode *leftNode = new BinaryTreeNode(leftChild);
                    currentNode->left = leftNode;
                    q.push(leftNode);
                }

                cin >> rightChild;
                if (rightChild != -1)
                {
                    BinaryTreeNode *rightNode = new BinaryTreeNode(rightChild);
                    currentNode->right = rightNode;
                    q.push(rightNode);
                }
            }
            arr.push_back(root);

            cin >> kVal;
            k.push_back(kVal);
        }
    }

    BinaryTreeNode *copyTree(BinaryTreeNode *root)
    {
        if (root == NULL)
        {
            return NULL;
        }
        BinaryTreeNode *copyRoot = new BinaryTreeNode(root->data);
        copyRoot->left = copyTree(root->left);
        copyRoot->right = copyTree(root->right);
        return copyRoot;
    }

    void execute()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode *copy = copyTree(arr[i]);
            int kVal = k[i];

            bool ans = pairSumBst(copy, kVal);

            delete copy;
        }
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {
            BinaryTreeNode *root = arr[i];
            int kVal = k[i];

            bool ans = pairSumBst(root, kVal);

            if (ans == 0)
                cout << "false\n";
            else
                cout << "true\n";
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