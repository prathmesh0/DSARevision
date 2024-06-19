#include <bits/stdc++.h>
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

    ~Node()
    {
        int value = this->data;
        // memory free
        if (this->next != NULL)
        {
            delete next;
            this->next = NULL;
        }
        cout << " memory is free for node with data " << value << endl;
    }
};

Node *convertArraytoLL(vector<int> &arr)
{
    Node *head = new Node(arr[0]);
    Node *tail = head;
    for (int i = 1; i < arr.size(); i++)
    {
        Node *temp = new Node(arr[i]);
        tail->next = temp;
        tail = temp;
    }
    return head;
}
void traverseLL(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
bool searchAnElement(Node *head, int key)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->data == key)
        {
            return true;
        }
        temp = temp->next;
    }
    return false;
}
int lengthOfLL(Node *head)
{
    int count = 0;
    Node *temp = head;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertAtHead(Node *&head, int data)
{
    Node *temp = new Node(data);
    temp->next = head;
    head = temp;
}

void insertAtTail(Node *&head, int data)
{
    Node *tail = head;
    while (tail->next != NULL)
    {
        tail = tail->next;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = tail->next;
    // cout << tail->data << endl;
}

void insertAtnthPos(Node *&head, int data, int pos) // pos= 5
{
    if (pos == 1)
    {
        insertAtHead(head, data);
        return;
    }
    Node *temp = head;
    int count = 1;
    while (count < pos)
    {
        temp = temp->next;
        count++;
    }

    if (temp->next == NULL)
    {
        insertAtTail(temp, data);
        return;
    }

    Node *nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}
void deleteNode(int position, Node *&head)
{
    if (position == 1)
    {
        Node *temp = head;
        head = temp->next;
        temp->next = NULL;
        delete (temp);
    }
    else
    {
        Node *curr = head;
        Node *prev = nullptr;
        int count = 1;
        while (count < position)
        {
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete (curr);
    }
}
int main()
{
    // Node *node = new Node(4);
    // cout << node->data << endl;
    // cout << node->next << endl;
    // delete (node);

    vector<int> arr = {4, 6, 23, 55, 66, 99, 1};
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    Node *ans = convertArraytoLL(arr);
    // cout << ans->data << endl;
    // traverseLL(ans);

    // if (searchAnElement(ans, 553))
    // {
    //     cout << "Element is present." << endl;
    // }
    // else
    // {
    //     cout << "Element is not present." << endl;
    // }

    // cout << lengthOfLL(ans) << endl;

    // creating LL from an array
    vector<int> num = {12, 44, 55, 6};
    Node *head = convertArraytoLL(num);
    traverseLL(head);

    // insert at head
    insertAtHead(head, 9);
    traverseLL(head);
    insertAtTail(head, 40);
    traverseLL(head);
    insertAtnthPos(head, 15, 2);
    traverseLL(head);
    deleteNode(7, head);
    traverseLL(head);
    return 0;
}