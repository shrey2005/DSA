#include<iostream>
#include<fstream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<bits/stdc++.h>
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

Node *deleteNode(Node *head, int pos)
{
    // Write your code here.
	int count = 1;
    Node *temp = head;
    
    if(pos == 0){
		if(head == NULL){
			return head;
		}
        head = head -> next;
        return head;
    }

    int totalNode = 0;
    Node *nodeCpy = head;
    while(nodeCpy != NULL){
        nodeCpy = nodeCpy -> next;
        totalNode++;
    }

    if(totalNode == pos){
        return head;
    }
    
    while(temp != NULL && count < pos){
        temp = temp -> next;
        count++;
    }

    if(temp != NULL && pos >= count){
        Node *a = temp -> next;
        Node *b = a -> next;
        temp -> next = b;
        delete[] a;
    }
    
    return head;
}


class Runner
{
    int pos;
    Node *head = NULL;
public:
    
    void takeInput()
    {
        int data;
        cin >> data;
        Node *tail = NULL;
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
		cin >> pos;
    }
    Node * copyll(Node *chead)
    {
        if(chead == NULL)return NULL;
        Node *nhead= NULL;

        Node *tail = NULL;
        while (chead != NULL)
        {
            Node *newNode = new Node(chead->data);
            if (nhead == NULL)
            {
                nhead = newNode;
                tail = newNode;
            }
            else
            {
                tail->next = newNode;
                tail = newNode;
            }
            chead=chead->next;
        }
        return nhead;
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
    void execute()
    {
        Node *copyhead = copyll(head);
        copyhead = deleteNode(copyhead, pos);
        while(copyhead!=NULL)
        {
            Node* temp=copyhead;
            copyhead=copyhead->next;
            delete temp;
        }
    }
    void executeAndPrintOutput()
    {
        Node *copyhead = copyll(head);
        copyhead = deleteNode(copyhead, pos);
		print(copyhead);
        while(copyhead!=NULL)
        {
            Node* temp=copyhead;
            copyhead=copyhead->next;
            delete temp;
        }
    }
};


int main()
{   
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();   
    return 0;
}