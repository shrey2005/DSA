#include <iostream>
#include<stdio.h>
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


Node* appendNodeRec(Node *head, Node *temp, int pos, Node* newNode, int count){
    if(pos == 0){
        newNode -> next = head;
        head = newNode;
        return head;
    }
    if(temp != NULL && count == (pos -1)){
        newNode -> next = temp->next;
        temp->next = newNode;
        return head;
    }
    count = count + 1;
    return appendNodeRec(head, temp->next, pos, newNode, count);
}

Node* InsertNode(Node *head, int pos, Node* newNode)
{
    Node *temp = head;
    return appendNodeRec(head, temp, pos, newNode, 0);
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
        int val;
        cin>>val;
        Node* newNode = new Node(val);
		head = InsertNode(head, pos,newNode);
		print(head);
	}

	return 0;
}