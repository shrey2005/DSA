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

void printReverse(Node *head)
{
    //Write your code here
	// Node *currPtr = head;
	// Node *nextPtr = NULL;
	// Node *prevPtr = NULL;

	// while(currPtr != NULL){
	// 	nextPtr = currPtr -> next;
	// 	currPtr -> next = prevPtr;
	// 	prevPtr = currPtr ;
	// 	currPtr = nextPtr;
	// }

	// while(prevPtr != NULL){
	// 	cout<<prevPtr->data<<" ";
	// 	prevPtr = prevPtr -> next;
	// }
	if(head == NULL){
		return;
	}
	printReverse(head->next);
	cout<<head->data<<" ";
}

Node *takeinput()
{
	int data;
	cin >> data;
	Node *head = NULL, *tail = NULL;
	while (data != -1)
	{
		Node *newnode = new Node(data);
		if (head == NULL)
		{
			head = newnode;
			tail = newnode;
		}
		else
		{
			tail->next = newnode;
			tail = newnode;
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
		printReverse(head);
		cout << endl;
	}
	return 0;
}