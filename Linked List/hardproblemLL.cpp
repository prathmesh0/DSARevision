#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int num;
    Node *next;
    Node(int a)
    {
        num = a;
        next = NULL;
    }
};
// utility function to insert node at the end of the list
void insertNode(Node *&head, int val)
{
    Node *newNode = new Node(val);
    if (head == NULL)
    {
        head = newNode;
        return;
    }
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return;
}
Node *findNthNode(Node *head, int n)
{
    int cnt = 1;
    while (head != NULL)
    {
        if (cnt == n)
            return head;
        head = head->next;
        cnt++;
    }
    return head;
}

Node *rotateRight(Node *head, int k)
{
    if (head == NULL || head->next == NULL)
    {
        return head;
    }
    Node *temp = head;
    int len = 1;
    while (temp->next != NULL)
    {
        temp = temp->next;
        len += 1;
    }
    if (k % len == 0)
        return head;
    k = k % len;
    temp->next = head;
    Node *newLastNode = findNthNode(head, len - k);
    head = newLastNode->next;
    newLastNode->next = NULL;
    return head;
}

Node *getKthNode(Node *temp, int k)
{
    k -= 1;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}

void reverseLL(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    while (curr != NULL)
    {
        Node *next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
}

Node *reverseKGroup(Node *head, int k)
{
    Node *temp = head;
    Node *prevLast = NULL;
    while (temp != NULL)
    {
        Node *kthNode = getKthNode(temp, k);
        if (kthNode == NULL)
        {
            if (prevLast)
                prevLast->next = temp;
            break;
        }
        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (temp == head)
        {
            head = kthNode;
        }

        else
        {
            prevLast->next = kthNode;
        }
        prevLast = temp;
        temp = nextNode;
    }
    return head;
}

// utility function to print list
void printList(Node *head)
{
    while (head->next != NULL)
    {
        cout << head->num << "->";
        head = head->next;
    }
    cout << head->num << endl;
    return;
}

int main()
{
    // Node *head = NULL;
    // // inserting Node
    // insertNode(head, 1);
    // insertNode(head, 2);
    // insertNode(head, 3);
    // insertNode(head, 4);
    // insertNode(head, 5);

    // cout << "Original list: ";
    // printList(head);

    // int k = 2;
    // Node *newHead = rotateRight(head, k); // calling function for rotating right of the nodes by k times

    // cout << "After " << k << " iterations: ";
    // printList(newHead); // list after rotating nodes

    Node *head = new Node(5);
    head->next = new Node(4);
    head->next->next = new Node(3);
    head->next->next->next = new Node(7);
    head->next->next->next->next = new Node(9);
    head->next->next->next->next->next = new Node(2);

    // Print the original linked list
    cout << "Original Linked List: ";
    printList(head);

    // Reverse the linked list
    head = reverseKGroup(head, 4);

    // Print the reversed linked list
    cout << "Reversed Linked List: ";
    printList(head);
    return 0;
}