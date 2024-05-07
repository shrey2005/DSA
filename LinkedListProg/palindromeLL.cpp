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

Node *reverseLL(Node* head){
	
	Node *currPtr = NULL;
	Node *prevPtr = NULL;

	while(head != NULL){
		currPtr = new Node(head->data);
		currPtr -> next = prevPtr;
		prevPtr = currPtr;
		head = head -> next;
	}
	
	return currPtr;
}

bool isPalindrome(Node *head)
{
    //Write your code here
	Node *reversedLL = reverseLL(head);

	bool isPal = true;
	while(head != NULL){
		if(reversedLL->data != head->data){
			isPal = false;
			break;
		}
		reversedLL = reversedLL -> next;
		head = head -> next;
	}

	return isPal;
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
		bool ans = isPalindrome(head);

		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}

	return 0;
}