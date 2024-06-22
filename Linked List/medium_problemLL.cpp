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

    // Initialize a pointer 'temp'
    // at the head of the linked list
    Node *temp = head;

    // Create a map to keep track of
    // encountered nodes
    std::unordered_map<Node *, int> nodeMap;

    // Step 2: Traverse the linked list
    while (temp != nullptr)
    {
        // If the node is already in the
        // map, there is a loop
        if (nodeMap.find(temp) != nodeMap.end())
        {
            return true;
        }
        // Store the current node
        // in the map
        nodeMap[temp] = 1;

        // Move to the next node
        temp = temp->next;
    }

    // Step 3: If the list is successfully traversed
    // without a loop, return false
    return false;
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6};
    Node *head = convertArraytoLL(num);

    // Node *middle = findMiddle(head);
    // cout << "The middle value " << middle->data << endl;

    Node *temp = reverseLinkedList(head);
    traverseLL(temp);

    if (detectLoop(head))
    {
        cout << "Loop detected in the linked list." << endl;
    }
    else
    {
        cout << "No loop detected in the linked list." << endl;
    }
    return 0;
}