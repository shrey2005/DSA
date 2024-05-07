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


Node *evenAfterOdd(Node *head)
{
	//write your code here
	Node *temp1 = head;
	
	if(temp1 == NULL || temp1 -> next == NULL){
	    return temp1;
	}

	Node *travserOdd = head;
    bool isAllOdd = true;
    while(travserOdd != NULL){
        if(travserOdd -> data % 2!= 0){
            isAllOdd = false;
            break;
        }
        travserOdd = travserOdd -> next;
    }
    
    if(isAllOdd && travserOdd == NULL){
        return head;
    }
    
    Node *travserEven = head;
    bool isAllEven = true;
    while(travserEven != NULL){
        if(travserEven -> data % 2 == 0){
            isAllEven = false;
            break;
        }
        travserEven = travserEven -> next;
    }
    
    if(isAllEven && travserEven == NULL){
        return head;
    }
	
	Node *evenLL = NULL;
	Node *oddLL = NULL;
	
	Node *newNode = NULL;
	Node *evenPtr = NULL;
	Node *oddPtr = NULL;
	if(temp1 -> data % 2 != 0){
	    newNode = new Node(temp1->data);
	    evenPtr = newNode;
	    evenLL = newNode;
	}
	else{
	    newNode = new Node(temp1->data);
	    oddPtr = newNode;
	    oddLL = newNode;
	}
	
    temp1 = temp1 -> next;
	
	Node *newNode1 = NULL;
	while(temp1 != NULL){
	    int data = temp1->data;
	    if(data % 2 != 0){
	        newNode1 = new Node(data);
	        if(evenLL == NULL){
	            evenLL = newNode1;
	            evenPtr = newNode1;
	        }
	        else{
	            evenLL -> next = newNode1;
	            evenLL = newNode1;
	        }
	    }
	    else{
	        newNode1 = new Node(data);
	        if(oddLL == NULL){
	            oddLL = newNode1;
	            oddPtr = newNode1;
	        }
	        else{
	            oddLL -> next = newNode1;
	            oddLL = newNode1;
	        }
	    }
	    temp1 = temp1 -> next;
	}
	
	while(oddPtr != NULL){
	    evenLL -> next = oddPtr;
	    evenLL = oddPtr;
	    oddPtr = oddPtr -> next;
	}
	
	return evenPtr;
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
		head = evenAfterOdd(head);
		print(head);
	}
	return 0;
}