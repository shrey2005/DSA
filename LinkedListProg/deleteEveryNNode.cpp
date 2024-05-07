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

Node *skipMdeleteN(Node *head, int M, int N)
{
	// Write your code here
	if(head==NULL ){
		return head;
	}
	if(M==0){
		return NULL;
	}
	int count1=1;
	int  count2=1;
	Node *t1=head;
	Node *t2=NULL;
	while(count1<M&&t1!=NULL){
		t1=t1->next;
		count1++;
	}
	if (t1 == NULL || t1->next == NULL) {
        return head;
    }
	t2=t1->next;
	while(count2<=N&&t2!=NULL){
		Node *temp=t2;
		t2=t2->next;
		delete temp;
		count2++;
	}
	t1->next=t2;
	
	// recursion call
	Node *ans=skipMdeleteN(t2,M,N);
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
		int m, n;
		cin >> m >> n;
		head = skipMdeleteN(head, m, n);
		print(head);
	}
	return 0;
}