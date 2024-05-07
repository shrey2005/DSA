#include <iostream>
using namespace std;

class Node
{
public:
	int data;
	Node *next;
	Node(int data)
	{
		this->data = data;
		this->next = NULL;
	}
};

int findNodeRec(Node *head, int n)
{
	//Write your code here
	if(head == NULL || head -> next == NULL){
		return -1;
	}

	if(head -> data == n){
		return 0;
	}
	int smallAns = findNodeRec(head->next, n);
	if(smallAns == -1){
		return -1;
	}
	else{
		return smallAns + 1;
	}
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newNode = new Node(data);
		if (head == NULL)
		{
			head = newNode;
			tail = newNode;
		}
		else
		{
			tail->next = newNode;
			tail = newNode;
		}
		cin >> data;
	}
	return head;
}

int main()
{
	int t;
	cin >> t;
	while (t--)
	{
		Node *head = takeinput();
		int val;
		cin >> val;
		cout << findNodeRec(head, val) << endl;
	}
}