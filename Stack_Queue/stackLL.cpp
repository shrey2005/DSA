#include <iostream>
using namespace std;


class Node {
   public:
    int data;
    Node *next;

    Node(int data) {
        this->data = data;
        next = NULL;
    }
};



class Stack {
    Node *head;
    int count;
	// Define the data members
     
   public:
    Stack() {
        // Implement the Constructor
        head = NULL;
        count = 0;
    }

	/*----------------- Public Functions of Stack -----------------*/

    int getSize() {
        // Implement the getSize() function
        return count;
    }

    bool isEmpty() {
        // Implement the isEmpty() function
        if(head == NULL){
            return true;
        }
        return false;
    }

    void push(int element) {
        // Implement the push() function
        Node *newNode = new Node(element);
        if(head == NULL){
            head = newNode;
        }
        else{
            newNode -> next = head;
            head = newNode;
        }
        count = count + 1;
    }

    int pop() {
        // Implement the pop() function
        if(head == NULL){
            return -1;
        }

        int lastElement = head->data;
        Node *temp = head;
        head = head -> next;
        delete[] temp;
        count = count - 1;
        return lastElement;
    }

    int top() {
        // Implement the top() function
        if(head == NULL){
            return -1;
        }
        return head->data;
    }
};

int main() {
    Stack st;

    int q;
    cin >> q;

    while (q--) {
        int choice, input;
        cin >> choice;
        switch (choice) {
            case 1:
                cin >> input;
                st.push(input);
                break;
            case 2:
                cout << st.pop() << "\n";
                break;
            case 3:
                cout << st.top() << "\n";
                break;
            case 4:
                cout << st.getSize() << "\n";
                break;
            default:
                cout << ((st.isEmpty()) ? "true\n" : "false\n");
                break;
        }
    }
}