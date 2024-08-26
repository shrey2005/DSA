#include <cstdlib>
#include <fstream>
#include <iostream>
#include <vector>
#include<map>

using namespace std;

//    Solution starts
#include <queue>

//    Defining the node structure
template <typename T>
class HeapNode
{
public:
    
    T frequency;
    int index;
    HeapNode<T> *left;
    HeapNode<T> *right;

    HeapNode(T frequency, int idx)
    {
        this->frequency = frequency;
        this->index = idx;
        left = NULL;
        right = NULL;
    }

    ~HeapNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

//    Defining the class to compare two nodes based on frequency
class cmp
{
public:
    bool operator()(HeapNode<int> *a, HeapNode<int> *b)
    {
        return a->frequency > b->frequency;
    }
};

//     Function to parse the built Huffman Tree to assign Huffman Codes
void assignHuffmanCode(HeapNode<int> *root, string str, vector<string> &ans)
{
    //    Checking if the current node is leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans[root->index] = str;
        return;
    }

    //    Calling for left subtree
    if (root->left)
    {
        assignHuffmanCode(root->left, str + "0", ans);
    }

    //    Calling for right subtree
    if (root->right)
    {
        assignHuffmanCode(root->right, str + "1", ans);
    }
}

vector<string> solve(vector<int> &arr)
{
    //    Finding the number of elements 
    int n = arr.size(); 
    
    if (n==1)
    {
        vector<string> ans(1);
        ans[0] = "1";
        return ans;
    }

    //    Defining the Min Heap
    priority_queue<HeapNode<int> *, vector< HeapNode<int> *>, cmp> heap;

    //    Iterating through the array and adding elements to MinHeap
    for (int i = 0; i < n; i++)
    {
        HeapNode<int> *newNode = new HeapNode<int> (arr[i], i);
        heap.push(newNode);
    }

    while (heap.size() > 1)
    {
        //    Extracting the two nodes having minimum value from the heap
        HeapNode<int> *node1 = heap.top();
        heap.pop();

        HeapNode<int> *node2 = heap.top();
        heap.pop();

        //    Creating a new node combining extracted nodes
        HeapNode<int> *newNode = new HeapNode<int> (node1->frequency + node2->frequency, -1);

        //    Setting its left and right children
        newNode->left = node1;
        newNode->right = node2;

        //    Inserting new node into the Min Heap
        heap.push(newNode);
    }

    //    Finding the root of Huffman string
    HeapNode<int> *root = heap.top();

    //    Defining the output array
    vector<string> ans(n);

    //    Assigning Huffman Code for every character
    assignHuffmanCode(root, "", ans);

    delete root;

    return ans;

}
//    Solution ends

/*
    Time Complexity: O(N*log(N))
    Space Complexity: O(N)

    Where N is the number of elements in the array.
*/
#include <queue>

//    Defining the node class
template <typename T>
class TreeNode
{
public:
    T frequency;
    int index;
    TreeNode<T> *left;
    TreeNode<T> *right;

    TreeNode(T frequency, int idx)
    {
        this->frequency = frequency;
        this->index = idx;
        left = NULL;
        right = NULL;
    }

    ~TreeNode()
    {
        if (left != NULL)
        {
            delete left;
        }
        if (right != NULL)
        {
            delete right;
        }
    }
};

//    Defining the class to compare two nodes based on frequency
class compare
{
public:
    bool operator()(TreeNode<int> *a, TreeNode<int> *b)
    {
        return a->frequency > b->frequency;
    }
};

//     Function to parse the built Huffman Tree to assign Huffman Codes
void assignHuffmanCode(TreeNode<int> *root, string &str, vector<string> &ans)
{
    //    Checking if the current node is leaf node
    if (root->left == NULL && root->right == NULL)
    {
        ans[root->index] = str;
        return;
    }

    //    Calling for left subtree
    if (root->left)
    {
        str.push_back('0');
        assignHuffmanCode(root->left, str, ans);
        str.pop_back();
    }

    //    Calling for right subtree
    if (root->right)
    {
        str.push_back('1');
        assignHuffmanCode(root->right, str, ans);
        str.pop_back();
    }
}

vector<string> huffmanCode(vector<int> &arr)
{
    //    Finding the number of elements
    int n = arr.size();

    //    Handling the case when only one element is in the array
    if (n == 1)
    {
        vector<string> ans(1);
        ans[0] = "1";
        return ans;
    }

    //    Defining the Min Heap
    priority_queue<TreeNode<int> *, vector<TreeNode<int> *>, compare> heap;

    //    Iterating through the array and adding elements to MinHeap
    for (int i = 0; i < n; i++)
    {
        TreeNode<int> *newNode = new TreeNode<int>(arr[i], i);
        heap.push(newNode);
    }

    while (heap.size() > 1)
    {
        //    Extracting the two nodes having minimum value from the heap
        TreeNode<int> *node1 = heap.top();
        heap.pop();

        TreeNode<int> *node2 = heap.top();
        heap.pop();

        //    Creating a new node combining extracted nodes
        TreeNode<int> *newNode = new TreeNode<int>(node1->frequency + node2->frequency, -1);

        //    Setting its left and right children
        newNode->left = node1;
        newNode->right = node2;

        //    Inserting new node into the Min Heap
        heap.push(newNode);
    }

    //    Finding the root of Huffman string
    TreeNode<int> *root = heap.top();

    //    Defining the output array
    vector<string> ans(n);

    string str="";

    //    Assigning Huffman Code for every character
    assignHuffmanCode(root, str, ans);

    delete root;

    return ans;
}

class Runner {
    int t;
    vector<vector<int>> arr;

    public:

        void takeInput() 
        {
            cin >> t;
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

    vector<vector<int>> getCopy() 
    {
        vector<vector<int>> arrCopy;
        arrCopy = arr;
        return arrCopy;
    }

    void execute() 
    {
        vector<vector<int>> arrCopy = arr;

        for (int i = 0; i < t; i++) 
        {
            huffmanCode(arrCopy[i]);
        }

    }

    void executeAndPrintOutput() 
    {
        vector<vector<int>> arrCopy = arr;
        for (int i = 0; i < t; i++)
        {
            vector<string> ans1 = solve(arr[i]);  
            
            vector<string> ans2 = huffmanCode(arrCopy[i]); 
            map<string,int> mp;
            int cost1=0,cost2=0; 
            int flag=1;
            if(ans2.size()!=ans1.size())
            {
                flag=0;goto print ;
            }
            
            for(int ip=0;ip<ans1.size();ip++)
            { 
                cost1+=(ans1[ip].length()*arr[i][ip]);
                cost2+=(ans2[ip].length()*arr[i][ip]);
            } 
            
            
            
            if(cost1!=cost2)
            {
                flag=0; 
                goto print;
            } 
            
            
            for(string ip: ans2)
            { 
                if(mp.find(ip)!=mp.end())
                {
                    flag=0;
                    goto print;
                }
                mp[ip]=1;
            } 
            
            for(string ip: ans2)
            {
                string res;
                for(int j=0;j<ip.length()-1;j++)
                {
                    res.push_back(ip[j]);
                    if(mp.find(res)!=mp.end())
                    {
                        flag=0;
                        goto print ;
                    }
                }
            } 
            
            goto print;
            
            print :
            
            cout<<flag<<'\n';
            
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