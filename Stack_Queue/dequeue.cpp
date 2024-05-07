// C++ implementation of De-queue using circular
// array
#include<iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    ~Node() {
        if (next) {
            delete next;
        }
    }
};

class Deque {
    Node* head;
    Node* tail;
    int size;
    int totalSize;

public:
    Deque(int queueSize) {
        head = NULL;
        tail = NULL;
        size = 0;
        totalSize = queueSize;
    }

    void insertFront(int data) {
        if (size == totalSize) {
            cout << "-1" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
        size++;
    }

    void insertRear(int data) {
        if (size == totalSize) {
            cout << "-1" << endl;
            return;
        }
        Node* newNode = new Node(data);
        if (head == NULL) {
            head = newNode;
            tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
        size++;
    }

    void deleteFront() {
        if (size == 0) {
            cout << "-1" << endl;
            return;
        }
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
        size--;
    }

    void deleteRear() {
        if (size == 0) {
            cout << "-1" << endl;
            return;
        }
        if (head == tail) {
            delete head;
            head = tail = NULL;
            size--;
            return;
        }
        Node* temp = head;
        while (temp->next != tail) {
            temp = temp->next;
        }
        temp->next = NULL;
        //here u have to update ur code
        
        delete tail;
        tail = temp;
        size--;
    }

    int getFront() {
        if (size == 0) {
            return -1;
        }
        return head->data;
    }

    int getRear() {
        if (size == 0) {
            return -1;
        }
        return tail->data;
    }
};


// Driver program to test above function
int main()
{
    Deque dq(10);
    int choice,input;
    while(true) {
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                dq.insertFront(input);
                break;
            case 2:
                cin >> input;
                dq.insertRear(input);
                break;
            case 3:
                dq.deleteFront();
                break;
            case 4:
                dq.deleteRear();
                break;
            case 5:
                cout << dq.getFront() << "\n";
                break;
            case 6:
                cout << dq.getRear() << "\n";
                break;
            default:
                return 0;
        }
    }
    
    return 0;
}
