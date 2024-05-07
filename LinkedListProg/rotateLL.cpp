#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iomanip>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node() : data(0), next(nullptr) {}
    Node(int x) : data(x), next(nullptr) {}
    Node(int x, Node *next) : data(x), next(next) {}
};
Node *rotate(Node *head, int k) {
    // Return head if the list is empty or contains only one node
    if (head == nullptr || head->next == nullptr || k == 0) {
        return head;
    }

    // Calculate the length of the list
    int len = 1;
    Node *tail = head;
    while (tail->next != nullptr) {
        tail = tail->next;
        len++;
    }

    // Adjust k to handle cases where k is larger than or equal to the length of the list
    k = k % len;
    if (k == 0) {
        return head;
    }

    // Find the (len - k)th node from the beginning
    Node *new_tail = head;
    for (int i = 0; i < len - k - 1; i++) {
        new_tail = new_tail->next;
    }

    // Set the next pointer of the current tail node to the head
    tail->next = head;
    // Update head to the next node of the new tail
    head = new_tail->next;
    // Set the next pointer of the new tail to nullptr
    new_tail->next = nullptr;

    return head;
}

class Runner
{
    int k;
    vector<int> list;

public:
    void takeLLInput(int n)
    {
        while (n--)
        {
            int x;
            cin >> x;
            list.push_back(x);
        }
    }

    void printLL(Node *head)
    {

        while (head)
        {
            Node *temp = head;
            cout << head->data << ' ';
            head = head->next;
            delete temp;
        }
    }
    void takeInput()
    {
        int n;
        cin>>n;
        takeLLInput(n);
        cin >> k;
    }

    void execute()
    {
        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        while (head)
        {
            Node *temp = head;
            head = head->next;
            delete temp;
        }
    }

    void executeAndPrintOutput()
    {

        Node *head = nullptr, *cur = nullptr;
        for (auto x : list)
        {
            if (x == -1)
                break;
            Node *temp = new Node(x);
            if (head)
            {
                cur->next = temp;
                cur = cur->next;
            }
            else
            {
                head = temp;
                cur = temp;
            }
        }
        Node *ans = rotate(head, k);
        printLL(ans);
    }
};

int main()
{
    // freopen("testcases/large/in/input11.txt", "r", stdin);
    // freopen("testcases/large/out/output11.txt", "w", stdout);
    Runner runner;
    runner.takeInput();
    runner.executeAndPrintOutput();

    return 0;
}