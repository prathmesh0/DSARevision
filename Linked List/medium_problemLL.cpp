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

Node *detectCycle(Node *head)
{
    // if (head == NULL || head->next == NULL)
    //     return NULL;
    // Node *temp = head;
    // unordered_map<Node *, int> mpp;
    // while (temp != NULL)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //     {
    //         return temp;
    //     }
    //     mpp[temp] = 1;
    //     temp = temp->next;
    // }
    // return NULL;

    // Optimal
    if (head == NULL || head->next == NULL)
        return NULL;
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            while (temp != slow)
            {
                temp = temp->next;
                slow = slow->next;
            }
            return slow;
        }
    }
    return NULL;
}

int lengthOfLoop(Node *slow, Node *fast)
{
    int count = 1;
    fast = fast->next;
    while (slow != fast)
    {
        count++;
        fast = fast->next;
    }
    return count;
}
int countNodesinLoop(struct Node *head)
{
    // if (head == NULL || head->next == NULL)
    //     return 0;
    // unordered_map<Node *, int> mpp;
    // int length = 1;
    // Node *temp = head;

    // while (temp != NULL)
    // {
    //     if (mpp.find(temp) != mpp.end())
    //     {
    //         return (length - mpp[temp]);
    //     }
    //     mpp[temp] = length;
    //     length += 1;
    //     temp = temp->next;
    // }

    if (head == NULL || head->next == NULL)
        return 0;
    Node *slow = head;
    Node *fast = head;

    while (fast->next != NULL && fast->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return lengthOfLoop(slow, fast);
        }
    }

    return 0;
}
bool isPalindrome(Node *head)
{

    stack<int> st;

    Node *temp = head;

    while (temp != NULL)
    {

        st.push(temp->data);

        temp = temp->next;
    }

    temp = head;

    while (temp != NULL)
    {
        if (temp->data != st.top())
        {

            // it's not a palindrome
            return false;
        }

        st.pop();

        temp = temp->next;
    }

    return true;

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

Node *oddEvenList(Node *head)
{
    // if (head == NULL || head->next == NULL)
    //     return head;
    // Node *odd = head;
    // Node *even = head->next;
    // vector<int> ans;
    // // odd index node
    // while (odd != NULL && odd->next != NULL)
    // {
    //     ans.push_back(odd->data);
    //     odd = odd->next->next;
    // }
    // if (odd != NULL)
    // {
    //     ans.push_back(odd->data);
    // }
    // // even index node
    // while (even != NULL && even->next != NULL)
    // {
    //     ans.push_back(even->data);
    //     even = even->next->next;
    // }
    // if (even != NULL)
    // {
    //     ans.push_back(even->data);
    // }

    // Node *temp = head;
    // int i = 0;
    // while (temp != NULL)
    // {
    //     temp->data = ans[i];
    //     i++;
    //     temp = temp->next;
    // }
    // return head;

    // optimal
    if (head == NULL || head->next == NULL)
        return head;

    Node *even = head->next;
    Node *evenHead = head->next;
    Node *odd = head;

    while (even != NULL && even->next != NULL)
    {
        odd->next = odd->next->next;
        even->next = even->next->next;

        odd = odd->next;
        even = even->next;
    }
    odd->next = evenHead;
    return head;
}

Node *removeNthFromEnd(Node *head, int n)
{
    // Node *temp = head;
    // int len = 0;
    // while (temp != NULL)
    // {
    //     len++;
    //     temp = temp->next;
    // }

    // if (n == len)
    // {
    //     head = head->next;
    //     delete (temp);
    //     return head;
    // }
    // int nodetoDelete = len - n;
    // temp = head;
    // while (temp != NULL)
    // {
    //     nodetoDelete--;
    //     if (nodetoDelete == 0)
    //     {
    //         break;
    //     }
    //     temp = temp->next;
    // }
    // Node *temp2 = temp->next;
    // temp->next = temp2->next;
    // delete (temp2);

    // return head;

    // Optimal approach
    Node *fast = head;
    for (int i = 0; i < n; i++)
    {
        fast = fast->next;
    }

    if (fast == NULL)
    {
        Node *temp = head;
        head = head->next;
        delete (temp);
        return head;
    }
    Node *slow = head;
    while (fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next;
    }
    Node *nodeToDelete = slow->next;
    slow->next = slow->next->next;
    delete (nodeToDelete);
    return head;
}

Node *deleteMiddle(Node *head)
{
    // if (head == NULL || head->next == NULL)
    // {
    //     return NULL;
    // }
    // Node *temp = head;
    // int count = 0;
    // while (temp != NULL)
    // {
    //     count++;
    //     temp = temp->next;
    // }

    // temp = head;
    // Node *prev = NULL;

    // for (int i = 0; i < (count / 2); i++)
    // {
    //     prev = temp;
    //     temp = temp->next;
    // }
    // prev->next = temp->next;
    // delete (temp);
    // return head;

    // Optimal
    if (head == NULL || head->next == NULL)
    {
        return NULL;
    }
    Node *slow = head;
    Node *fast = head;
    Node *prev = head;
    while (fast != NULL && fast->next != NULL)
    {
        if (slow != head)
        {
            prev = prev->next;
        }

        slow = slow->next;
        fast = fast->next->next;
    }
    prev->next = slow->next;
    delete (slow);
    return head;
}
// Node *sortList(Node *head)
// {

//     if (head == NULL || head->next == NULL)
//         return head;
//     Node *temp = head;
//     vector<int> arr;
//     while (temp != NULL)
//     {
//         arr.push_back(temp->data);
//         temp = temp->next;
//     }
//     sort(arr.begin(), arr.end());
//     temp = head;
//     int i = 0;
//     while (temp != NULL)
//     {
//         temp->data = arr[i];
//         temp = temp->next;
//         i++;
//     }
//     return head;
// }
Node *mergeList(Node *l1, Node *l2)
{
    if (l1 == NULL)
        return l2;
    if (l2 == NULL)
        return l1;
    if (l1->data > l2->data)
    {
        swap(l1, l2);
    }
    Node *res = l1;
    while (l1 != NULL && l2 != NULL)
    {
        Node *temp = NULL;
        while (l1 != NULL && l1->data <= l2->data)
        {
            temp = l1;
            l1 = l1->next;
        }
        temp->next = l2;
        swap(l1, l2);
    }
    return res;
}

Node *sortList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;

    // middle
    Node *slow = head;
    Node *fast = head;
    Node *temp = head;

    while (fast != NULL && fast->next != NULL)
    {
        temp = slow;
        slow = slow->next;
        fast = fast->next->next;
    }
    temp->next = NULL;

    Node *l = sortList(head);
    Node *r = sortList(slow);
    return mergeList(l, r);
}
int main()
{
    vector<int> num = {1, 2, 3, 4, 5, 6};
    Node *head = convertArraytoLL(num);

    // Node *middle = findMiddle(head);
    // cout << "The middle dataue " << middle->data << endl;

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

    // cout << isPalindrome(head);

    // Node *node1 = new Node(1);
    // Node *node2 = new Node(2);
    // node1->next = node2;
    // Node *node3 = new Node(3);
    // node2->next = node3;
    // Node *node4 = new Node(4);
    // node3->next = node4;
    // Node *node5 = new Node(5);
    // node4->next = node5;

    // // Make a loop from node5 to node2
    // node5->next = node2;

    // // Set the head of the linked list
    // Node *head = node1;

    // // Detect the loop in the linked list
    // // Node *loopStartNode = detectCycle(head);

    // // if (loopStartNode)
    // // {
    // //     cout << "Loop detected. Starting node of the loop is: " << loopStartNode->data << endl;
    // // }
    // // else
    // // {
    // //     cout << "No loop detected in the linked list." << endl;
    // // }

    // cout << countNodesinLoop(head) << endl;

    // Node *ans = oddEvenList(head);
    // traverseLL(ans);

    // Node *ans = removeNthFromEnd(head, 2);
    // traverseLL(ans);

    // Node *ans = deleteMiddle(head);
    // traverseLL(ans);

    Node *ans = sortList(head);
    traverseLL(ans);

    return 0;
}