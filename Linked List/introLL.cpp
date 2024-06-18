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

    cout << lengthOfLL(ans) << endl;
    return 0;
}