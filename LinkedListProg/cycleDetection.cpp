#include <cstdlib>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node* next)
    {
        this->data = data;
        this->next = next;
    }
};

bool detectCycle(Node *head)
{
	//	Write your code here
    Node *temp = head;
    if(temp == NULL || temp -> next == NULL){
        return false;
    }

    bool isCycle = true;
    
    Node *slow = head;
    Node *fast = head->next->next;

    while(fast != slow ){
        slow = slow -> next;
        fast = fast -> next -> next;
        //check if our fast nodes reaches to end
        if(fast == NULL || fast -> next == NULL ){
            isCycle = false;
            break;
        }
    }
    return isCycle;
}

class Runner
{
    int t;
    vector<Node *> arr;

public:
    Node *takeInput()
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

        int pos;
        cin >> pos;

        if (pos != -1)
        {

            Node *temp = head;
            //  Connecting last element to "pos"th node
            while (pos--)
            {
                temp = temp->next;
            }
            tail->next = temp;
        }

        return head;
    }

    void execute(Node *head)
    {
        bool ans = detectCycle(head);
    }

    void executeAndPrintOutput(Node *head)
    {
        bool ans = detectCycle(head);
        if (ans)
        {
            cout << "true";
        }
        else
        {
            cout << "false";
        }
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    Runner runner;
    Node *head = runner.takeInput();
    runner.executeAndPrintOutput(head);

    return 0;
}

