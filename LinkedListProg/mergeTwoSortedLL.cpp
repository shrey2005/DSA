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

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    //Write your code here
	Node *ll1 = head1;
    Node *ll2 = head2;
    
    Node *mergeLL = NULL;
    Node *newLL = NULL;
    
    Node *newNode = NULL;

	while(ll1 != NULL && ll2 == NULL){
        newNode = new Node(ll1->data);
         if(mergeLL == NULL){
                newLL = newNode;
                mergeLL = newNode;
         }
         else{
                newLL -> next = newNode;
                newLL = newNode;
         }
         ll1 = ll1 ->next;
    }
    
    while(ll1 == NULL && ll2 != NULL){
        newNode = new Node(ll2->data);
         if(mergeLL == NULL){
                newLL = newNode;
                mergeLL = newNode;
         }
         else{
                newLL -> next = newNode;
                newLL = newNode;
         }
         ll2 = ll2 ->next;
    }

	if(ll1 == NULL && ll2 == NULL){
        return mergeLL;
    }
    
	Node *newNode1 = NULL;
	Node *newNode2 = NULL;

    if(ll1 ->data <= ll2 -> data){
        newNode1 = new Node(ll1->data);
        newLL = newNode1;
        mergeLL = newNode1;
        ll1 = ll1 -> next;
    }
    else{
        newNode2 = new Node(ll2->data);
        newLL = newNode2;
        mergeLL = newNode2;
        ll2 = ll2 -> next;
    }

    while(ll1 != NULL && ll2 != NULL){
        if(ll1 -> data <= ll2 -> data){
            newNode1 = new Node(ll1->data);
            newLL -> next = newNode1;
            newLL = newNode1;
            ll1 = ll1 ->next;
        }
        else if(ll1 -> data >= ll2 -> data){
            newNode2 = new Node(ll2->data);
            newLL -> next = newNode2;
            newLL = newNode2;
            ll2 = ll2 ->next;
        }
    }
    
    while(ll1 != NULL){
        newNode1 = new Node(ll1->data);
        newLL -> next = newNode1;
        newLL = newNode1;
        ll1 = ll1 ->next;
    }
    
     while(ll2 != NULL){
        newNode2 = new Node(ll2->data);
        newLL -> next = newNode2;
        newLL = newNode2;
        ll2 = ll2 ->next;
    }
    return mergeLL;
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
		Node *head1 = takeinput();
		Node *head2 = takeinput();
		Node *head3 = mergeTwoSortedLinkedLists(head1, head2);
		print(head3);
	}
	return 0;
}