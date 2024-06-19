#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev;
    Node *next;
    int data;

    // constructor
    Node(int d)
    {
        this->data = d;
        this->next = NULL;
        this->prev = NULL;
    }

    ~Node()
    {
        int val = this->data;
        if (next != NULL)
        {
            delete next;
            next = NULL;
        }
        cout << "Memory free for node with data " << val << endl;
    }
};

Node *convertArraytoDLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
    return head;
}

void traverseDLL(Node *head)
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtHead(Node *&head, int val)
{
    Node *temp = new Node(val);
    temp->next = head;
    head->prev = temp;
    head = temp;
}
void insertAtTail(Node *&head, int val)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *temp = new Node(val);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}
int main()
{
    vector<int> arr = {12, 45, 66, 80};
    Node *head = convertArraytoDLL(arr);
    // cout << head->data << endl;
    traverseDLL(head);
    insertAtHead(head, 40);
    traverseDLL(head);
    insertAtTail(head, 100);
    traverseDLL(head);
    return 0;
}