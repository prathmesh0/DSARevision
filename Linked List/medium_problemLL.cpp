#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
    Node(int data1)
    {
        data = data1;
        next = nullptr;
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
Node *findMiddle(Node *head)
{
    // Brute force approach
    //  if (head == NULL || head->next == NULL)
    //  {
    //      return head;
    //  }
    //  Node *temp = head;
    //  int count = 0;

    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }
    // int mid = (count / 2) + 1;
    // temp = head;
    // while (temp != NULL)
    // {
    //     mid = mid - 1;
    //     if (mid == 0)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // return temp;

    // optimal approach
    Node *slow = head;
    Node *fast = head;
    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node *reverseLinkedList(Node *&head)
{
    // Bruteforce
    // Node *temp = head;
    // stack<int> st;
    // while (temp != NULL)
    // {
    //     st.push(temp->data);
    //     temp = temp->next;
    // }

    // temp = head;
    // while (!st.empty())
    // {
    //     temp->data = st.top();
    //     st.pop();
    //     temp = temp->next;
    // }
    // return temp;

    // optimal approch
    Node *prev = NULL;
    while (head != NULL)
    {
        Node *next = head->next;
        head->next = prev;
        prev = head;
        head = next;
    }
    return prev;
}

bool detectLoop(Node *head)
{

    // Node *temp = head;

    // unordered_map<Node *, int> nodeMap;

    // while (temp != nullptr)
    // {

    //     if (nodeMap.find(temp) != nodeMap.end())
    //     {
    //         return true;
    //     }

    //     nodeMap[temp] = 1;

    //     temp = temp->next;
    // }

    // return false;

    Node *slow = head;
    Node *fast = head;

    while (fast != nullptr && fast->next != nullptr)
    {

        slow = slow->next;

        fast = fast->next->next;

        if (slow == fast)
        {
            return true; // Loop detected
        }
    }

    return false;
}
bool isPalindrome(Node *head)
{

    // stack<int> st;

    // Node *temp = head;

    // while (temp != NULL)
    // {

    //     st.push(temp->data);

    //     temp = temp->next;
    // }

    // temp = head;

    // while (temp != NULL)
    // {
    //     if (temp->data != st.top())
    //     {

    //         // it's not a palindrome
    //         return false;
    //     }

    //     st.pop();

    //     temp = temp->next;
    // }

    // return true;

    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node *newHead = reverseLinkedList(head->next);

    Node *front = head->next;

    front->next = head;

    head->next = NULL;
    return newHead;
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6};
    Node *head = convertArraytoLL(num);

    // Node *middle = findMiddle(head);
    // cout << "The middle value " << middle->data << endl;

    // Node *temp = reverseLinkedList(head);
    // traverseLL(temp);

    // if (detectLoop(head))
    // {
    //     cout << "Loop detected in the linked list." << endl;
    // }
    // else
    // {
    //     cout << "No loop detected in the linked list." << endl;
    // }

    cout << isPalindrome(head);
    return 0;
}