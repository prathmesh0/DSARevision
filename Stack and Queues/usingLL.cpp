#include <iostream>
using namespace std;

class StackNode
{
public:
    int data;
    StackNode *next;
    int size;
    StackNode(int d)
    {
        data = d;
        next = NULL;
    }
};
class Stack
{
public:
    StackNode *top;
    int size;
    Stack()
    {
        top = NULL;
        size = 0;
    }

    void stackPush(int data)
    {
        StackNode *ele = new StackNode(data);
        ele->next = top;
        top = ele;
        cout << "Element pushed" << "\n";
        size++;
    }

    int stackPop()
    {
        if (top == NULL)
        {
            return -1;
        }
        int topData = top->data;
        StackNode *temp = top;
        top = top->next;
        delete (temp);
        size--;
        return topData;
    }

    int stackSize()
    {
        return size;
    }
    bool stackIsEmpty()
    {
        return top == NULL;
    }

    int stackPeek()
    {
        if (top == NULL)
            return -1;
        return top->data;
    }
};

class QueueNode
{
public:
    int val;
    QueueNode *next;
    QueueNode(int data)
    {
        val = data;
        next = NULL;
    }
};
QueueNode *Front = NULL, *Rare = NULL;

class Queue
{
public:
    int size = 0;
    bool Empty();
    void Enqueue(int value);
    void Dequeue();
    int Peek();
};

bool Queue::Empty()
{
    return Front == nullptr;
}

int Queue::Peek()
{
    if (Empty())
    {
        cout << "Queue is empty" << endl;
        return -1;
    }
    else
        return Front->val;
}

void Queue::Enqueue(int value)
{
    QueueNode *temp;
    temp = new QueueNode(value);
    if (temp == nullptr)
    {
        cout << "Queue is Full" << endl;
    }
    else
    {
        if (Front == nullptr)
        {
            Front = temp;
            Rare = temp;
        }
        else
        {
            Rare->next = temp;
            Rare = temp;
        }
        cout << value << " Inserted into Queue" << endl;
        size++;
    }
}

void Queue ::Dequeue()
{
    if (Front == nullptr)
    {
        cout << "Queue is Empty" << endl;
    }
    else
    {
        cout << Front->val << " Removed from Queue" << endl;
        QueueNode *temp = Front;
        Front = Front->next;
        delete (temp);
        size--;
    }
}

int main()
{
    // Stack s;
    // s.stackPush(10);
    // s.stackPush(12);
    // cout << "Element popped: " << s.stackPop() << "\n";
    // cout << "Stack size: " << s.stackSize() << "\n";
    // cout << "Stack empty or not? " << s.stackIsEmpty() << "\n";
    // cout << "stack's top element: " << s.stackPeek() << "\n";

    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout << "The size of the Queue is " << Q.size << endl;
    cout << "The Peek element of the Queue is " << Q.Peek() << endl;
    return 0;
}