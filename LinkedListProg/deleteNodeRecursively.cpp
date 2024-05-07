using namespace std;
#include <iostream>

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

Node* deleteElement(Node *head, Node *temp, int pos, int i){
	if(pos == 0){
		if(head == NULL){
			return head;
		}
		temp = temp -> next;
		return temp;
	}

	if(temp != NULL && pos == i){
		Node *a = temp -> next;
		Node *b = a -> next;
		temp -> next = b;
		delete[] a;
		return head;
	}

	temp = temp -> next;
	i = i + 1;
	return deleteElement(head, temp, pos, i);
}

Node *deleteNodeRec(Node *head, int pos) {
	//Write your code here
	Node* temp = head;
	return deleteElement(head, temp, pos, 1);
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

void print(Node *head)
{
	Node *temp = head;
	while (temp != NULL)
	{
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		Node *head = takeinput();
		int pos;
		cin >> pos;
		head = deleteNodeRec(head, pos);
		print(head);
	}

	return 0;
}