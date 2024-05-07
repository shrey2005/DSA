#include <iostream>
using namespace std;
class Node
{
public:
	int data;
	Node *next;
	Node* prev;
	Node(int data)
	{
		
		this->data = data;
		this->next = NULL;
		this->prev = NULL;
	}
};


bool palindromeDLL(Node* head){
    Node *head1 = head;
	Node *head2 = head;

	if(head == NULL || head -> next == NULL){
		return true;
	}

	while(head2 -> next != NULL){
		head2 = head2 -> next;
	}

	bool flag = true;
	while(head1 != NULL){
		if(head1->data == head2->data){
			head1 = head1 -> next;
			head2 = head2 -> prev;
		}
		else if(head1->data != head2->data){
		       flag = false;
		       break;
		}
	}
	return flag;
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
			newNode->prev = tail;
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
		bool ans = palindromeDLL(head);
		
		if (ans) cout << "true";
		else cout << "false";

		cout << endl;
	}
	return 0;
}