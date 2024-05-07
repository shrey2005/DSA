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

Node * mergeLinkedList(Node * head1, Node * head2) {
    if (head1 == NULL) {
        return head2;
    }
    if (head2 == NULL) {
        return head1;
    }
    Node * head = NULL, * tail = NULL;
    if (head1 -> data < head2 -> data) {
        head = head1;
        tail = head1;
        head1 = head1 -> next;
    } else {
        head = head2;
        tail = head2;
        head2 = head2 -> next;
    }
    while (head1 != NULL && head2 != NULL) {
        if (head1 -> data < head2 -> data) {
            tail -> next = head1;
            tail = head1;
            head1 = head1 -> next;
        } else {
            tail -> next = head2;
            tail = head2;
            head2 = head2 -> next;
        }
    }
    if (head1 != NULL) {
        tail -> next = head1;
    }
    if (head2 != NULL) {
        tail -> next = head2;
    }
    return head;
}

Node * midPoint(Node * head) {
    if (head == NULL) return head;

    Node * slow = head;
    Node * fast = head;

    while (fast -> next != NULL && fast -> next -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    return slow;
}

Node * mergeSort(Node * head) {
    if (head == NULL || head -> next == NULL) return head;

    Node * midVal = midPoint(head);
    Node * head1 = head;
    Node * head2 = midVal -> next;
    midVal -> next = NULL;

    head1 = mergeSort(head1);
    head2 = mergeSort(head2);
    Node * ans = mergeLinkedList(head1, head2);
    return ans;
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
		head = mergeSort(head);
		print(head);
	}

	return 0;
}