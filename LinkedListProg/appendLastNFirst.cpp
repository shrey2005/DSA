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

Node *appendLastNToFirst(Node *head, int n)
{
    //Write your code here
	// Node* temp = head;

	Node* temp = head;

	if(temp == NULL || temp -> next == NULL || n == 0) return temp;

    Node* temp1 = head;
    
    int totalNode = 0;
    while(temp1 != NULL){
        temp1 = temp1 -> next;
        totalNode++;
    }
    
    int actualStartPos = totalNode - n;
	Node* initialPointer = head;
	
	int count = 0;
    while(temp != NULL && count < n){
        temp = temp -> next;
        count++;
    }
    
    Node *temp2 = temp;
    while(temp2 -> next != NULL){
        temp2 = temp2 -> next;
    }
    
    int i = 0;

    temp2 -> next = initialPointer;
    while(initialPointer != NULL && i < actualStartPos ){
        temp2 -> next = initialPointer;
        temp2 = temp2 -> next;
        initialPointer = initialPointer -> next;
        i++;
    }
    temp2->next = NULL;
    
    head = initialPointer;
    return head;

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
		int n;
		cin >> n;
		head = appendLastNToFirst(head, n);
		print(head);
	}
	return 0;
}