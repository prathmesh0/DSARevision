

#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};

// } Driver Code Ends
// User function Template for C++

/* Doubly linked list node class
class Node
{
public:
    int data;
    Node *next, *prev;
    Node(int val) : data(val), next(NULL), prev(NULL)
    {
    }
};
*/

class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // Node* temp1 = head;
        // vector<pair<int, int>>ans;
        // while(temp1 != NULL){
        //     Node* temp2  = temp1->next;
        //     while(temp2 != NULL && temp1->data + temp2->data <= target){
        //         if(temp1->data + temp2->data == target){
        //             ans.push_back({temp1->data, temp2->data});
        //         }
        //         temp2 = temp2->next;
        //     }
        //         temp1 = temp1->next;
        // }
        // return ans;

        // Optimal Approach
        Node *left = head;
        Node *right = head;
        while (right->next != NULL)
        {
            right = right->next;
        }
        vector<pair<int, int>> ans;
        while (left->data < right->data)
        {
            if (left->data + right->data == target)
            {
                ans.push_back({left->data, right->data});
                left = left->next;
                right = right->prev;
            }
            else if (left->data + right->data < target)
            {
                left = left->next;
            }
            else
            {
                right = right->prev;
            }
        }
        return ans;
    }
};

Node *removeDuplicates(struct Node *head)
{
    Node *temp = head;
    while (temp != NULL && temp->next != NULL)
    {
        Node *nextNode = temp->next;
        while (nextNode != NULL && nextNode->data == temp->data)
        {
            Node *duplicate = nextNode;
            nextNode = nextNode->next;
            free(duplicate);
        }
        temp->next = nextNode;
        if (nextNode)
            nextNode->prev = temp;
        temp = temp->next;
    }

    return head;
}

struct Node *head = *head_ref;
struct Node *temp = head;

while (temp != NULL)
{
    if (temp->data == x)
    {
        // If temp is the head node
        if (temp == head)
        {
            head = head->next;
            if (head != NULL)
            {
                head->prev = NULL;
            }
            *head_ref = head; // Update the head reference
        }
        else
        {
            struct Node *nextNode = temp->next;
            struct Node *prevNode = temp->prev;

            if (nextNode)
                nextNode->prev = prevNode;
            if (prevNode)
                prevNode->next = nextNode;
        }
        struct Node *nodeToDelete = temp;
        temp = temp->next;
        free(nodeToDelete);
    }
    else
    {
        temp = temp->next;
    }
}



//{ Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, target;
        cin >> target >> n;
        int a;
        cin >> a;
        Node *head = new Node(a);
        Node *tail = head;
        for (int i = 0; i < n - 1; i++)
        {
            cin >> a;
            tail->next = new Node(a);
            tail->next->prev = tail;
            tail = tail->next;
        }
        Solution ob;
        auto ans = ob.findPairsWithGivenSum(head, target);
        if (ans.size() == 0)
            cout << "-1";
        else
        {
            for (int i = 0; i < ans.size(); i++)
            {
                cout << "(" << ans[i].first << "," << ans[i].second << ")"
                     << " ";
            }
        }
        cout << "\n";
    }
    return 0;
}

// } Driver Code Ends