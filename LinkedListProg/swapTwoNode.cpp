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

Node *swapNodes(Node *head, int i, int j)
{
	//Write your code here
    //edge case handling
    if(head == NULL || i == j || (i < 0 || j < 0)){
        return head;
    }

    int totalEle = 0;
	Node *temp = head;
	while(temp != NULL){
	    temp = temp -> next;
	    totalEle = totalEle + 1;
	}

    //If i or j exceed then total element
    if(i >= totalEle || j >= totalEle){
        return head;
    }

    Node *firstCur = head, *firstPrev = NULL;
    Node *secondCur = head, *secondPrev = NULL;
	
    int firstIndex = 0;
    while(firstCur != NULL && firstIndex < i){
        firstPrev = firstCur;
        firstCur = firstCur -> next;
        firstIndex++;
    }

    int secondIndex = 0;
    while(secondCur != NULL && secondIndex < j){
        secondPrev = secondCur;
        secondCur = secondPrev -> next;
        secondIndex++;
    }

    if(firstPrev != NULL){
        firstPrev -> next = secondCur;
    }
    else{
        head = secondCur;
    }

    if(secondPrev != NULL){
        secondPrev -> next = firstCur;
    }
    else{
        head = firstCur;
    }

    Node *tempNext = secondCur -> next;
    secondCur -> next = firstCur -> next;
    firstCur -> next = tempNext;
    
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
		int i, j;
		Node *head = takeinput();
		cin >> i;
		cin >> j;
		head = swapNodes(head, i, j);
		print(head);
	}
	return 0;
}