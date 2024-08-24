#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
#include <sstream>
#include <queue>
#include <climits>
using namespace std;
class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node() : data(0), left(nullptr), right(nullptr){};
    Node(int x) : data(x), left(nullptr), right(nullptr) {}
    Node(int x, Node *left, Node *right) : data(x), left(left), right(right) {}
};

int minVal(Node* root){
	// Write your code here.	

	if(root == NULL){
		return -1;
	}

	Node* rootNode = root;

	while(rootNode->left != NULL){
		rootNode = rootNode->left;
	}
	return rootNode->data;
}

class Runner
{
    string s;

    Node *buildTree(string s)
    {
        if (s.length() == 0 || s[0] == 'N')
            return NULL;

        vector<string> inp;
        istringstream STR(s);
        string cur;
        while (STR >> cur)
        {
            inp.push_back(cur);
        }
        Node *root = new Node(stoi(inp[0]));
        queue<Node *> q;
        q.push(root);
        int i = 1;
        while (!q.empty() && i < inp.size())
        {
            Node *temp = q.front();
            q.pop();
            string val = inp[i];
            // left
            if (val != "N")
            {
                temp->left = new Node(stoi(val));
                q.push(temp->left);
            }
            i++;
            if (i >= inp.size())
                break;
            val = inp[i];
            // right
            if (val != "N")
            {
                temp->right = new Node(stoi(val));
                q.push(temp->right);
            }
            i++;
        }
        return root;
    }

public:
    void takeInput()
    {
        getline(cin, s);
    }

    void execute()
    {

        Node *tree = buildTree(s);
        int ans = minVal(tree);
    }

    void executeAndPrintOutput()
    {

        Node *tree = buildTree(s);
        int ans = minVal(tree);
        cout << ans << endl;
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}