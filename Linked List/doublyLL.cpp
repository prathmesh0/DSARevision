#include <bits/stdc++.h>
using namespace std;

// Define the Node structure
struct Node
{
    int data;
    Node *next;
    Node *prev;
};

// Function to delete all occurrences of a given value in the linked list
void deleteAllOccurOfX(Node **head_ref, int x)
{
    Node *curr = *head_ref; // start from the head of the list
    Node *prev = NULL;      // initialize prev pointer to NULL

    // Traverse the list
    while (curr != NULL)
    {
        if (curr->data == x)
        { // if current node contains key
            if (curr == *head_ref)
            {                                 // if key is in head
                *head_ref = curr->next;       // move head to next node
                if (*head_ref != NULL)        // if head is not NULL
                    (*head_ref)->prev = NULL; // make prev of new head NULL
            }
            else
            {
                prev->next = curr->next;     // skip current node
                if (curr->next != NULL)      // if not end node
                    curr->next->prev = prev; // change prev of next node
            }
            Node *temp = curr; // free memory of current node
            curr = curr->next;
            delete temp;
        }
        else
        {                      // if current node doesn't contain key
            prev = curr;       // update prev pointer
            curr = curr->next; // move to next node
        }
    }
}

// Function to push a new node at the beginning of the list
void push(Node **head_ref, int new_data)
{
    Node *new_node = new Node();
    new_node->data = new_data;
    new_node->next = (*head_ref);
    new_node->prev = NULL;
    if ((*head_ref) != NULL)
        (*head_ref)->prev = new_node;
    (*head_ref) = new_node;
}

// Function to print the linked list
void printList(Node *node)
{
    while (node != NULL)
    {
        std::cout << node->data << " ";
        node = node->next;
    }
    std::cout << std::endl;
}

int main()
{
    /* Start with the empty list */
    Node *head = NULL;

    /* Let us create the doubly linked list 10<->8<->4<->10<->2<->10 */
    push(&head, 10);
    push(&head, 2);
    push(&head, 10);
    push(&head, 4);
    push(&head, 8);
    push(&head, 10);

    std::cout << "Created Linked list: ";
    printList(head);

    // Delete all occurrences of 10
    deleteAllOccurOfX(&head, 10);

    std::cout << "List after deleting all occurrences of 10: ";
    printList(head);

    return 0;
}
