#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>
#include <string>
#include <bits/stdc++.h>

using namespace std;

class TreeNode
{
public:
    int data;
    TreeNode *left, *right;
    TreeNode() : data(0), left(NULL), right(NULL) {}
    TreeNode(int x) : data(x), left(NULL), right(NULL) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : data(x), left(left), right(right) {}
};

TreeNode *constructTree(TreeNode *root, vector<int> &preOrder, int &index, int minVal, int maxVal){
    if(index == preOrder.size()) return NULL;

    TreeNode *newNode = NULL;

    if(preOrder[index] > minVal && preOrder[index] < maxVal){
        newNode = new TreeNode(preOrder[index]);

        index = index + 1;
        newNode->left = constructTree(root, preOrder, index, minVal, newNode->data);
        newNode->right = constructTree(root,preOrder, index, newNode->data, maxVal);
    }
   return newNode;
}
TreeNode *preOrderTree(vector<int> &preOrder)
{
    int index = 0;
    TreeNode *root = constructTree(root, preOrder, index, INT_MIN, INT_MAX);

    return root;
}

class Runner
{
    int t;
    vector<vector<int>> arr;

public:
    void takeInput()
    {
        t = 1;
        arr.resize(t);

        for (int i = 0; i < t; i++)
        {
            int n;
            cin >> n;

            arr[i].resize(n);

            for (int j = 0; j < n; j++)
            {
                cin >> arr[i][j];
            }
        }
    }

    void postorder(TreeNode *root)
    {
        if (root == NULL)
        {
            return;
        }

        postorder(root->left);

        postorder(root->right);

        cout << root->data << " ";
    }

    void execute()
    {
        vector<vector<int>> arrCopy = arr;

        for (int i = 0; i < t; i++)
        {
            TreeNode *root = preOrderTree(arrCopy[i]);

            delete root;
        }
        arrCopy.clear();
    }

    void executeAndPrintOutput()
    {
        for (int i = 0; i < t; i++)
        {

            TreeNode *root = preOrderTree(arr[i]);

            postorder(root);
            cout << "\n";
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