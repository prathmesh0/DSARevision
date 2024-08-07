#include <bits/stdc++.h>
using namespace std;

class StackImplementation
{

    int size;
    int *arr;
    int top;

public:
    StackImplementation()
    {
        size = 1000;
        top = -1;
        arr = new int[size];
    }

    void push(int x)
    {
        top++;
        arr[top] = x;
    }

    int pop()
    {
        if (top == -1)
        {
            return -1;
        }
        int ele = arr[top];
        top--;
        return ele;
    }

    int Top()
    {
        return arr[top];
    }

    int Size()
    {
        return (top + 1);
    }
};

class Queue
{
    int *arr;
    int start, end, currSize, maxSize;

public:
    Queue()
    {
        arr = new int[16];
        start = -1;
        end = -1;
        currSize = 0;
    }

    Queue(int maxSize)
    {
        this->maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int d)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full " << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
        {
            end = (end + 1) % maxSize;
        }
        arr[end] = d;
        cout << "The element pushed is " << d << endl;
        currSize++;
    }

    void pop()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
        {
            start = (start + 1) % maxSize;
        }
        currSize--;
        return popped;
    }

    int top()
    {
        if (start == -1)
        {
            cout << "Queue is empty" << endl;
            exit(1);
        }
        return arr[start];
    }

    int size()
    {
        return currSize;
    }
};

class Stack
{
    queue<int> q;

public:
    void Push(int x)
    {
        int s = q.size();
        q.push(x);
        for (int i = 0; i < s; i++)
        {

            q.push(q.front());
            q.pop();
        }
    }
    int Pop()
    {
        int n = q.front();
        q.pop();
        return n;
    }
    int Top()
    {
        return q.front();
    }
    int Size()
    {
        return q.size();
    }
};

// Queue using stack
struct Queue1
{
    stack<int> input, output;

    void Push(int data)
    {

        while (!input.empty())
        {
            output.push(input.top());
            input.pop();
        }

        cout << "The element pushed is " << data << endl;
        input.push(data);

        while (!output.empty())
        {
            input.push(output.top());
            output.pop();
        }
    }

    int Pop()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        int val = input.top();
        input.pop();
        return val;
    }
    // Return the Topmost element from the Queue
    int Top()
    {
        if (input.empty())
        {
            cout << "Stack is empty";
            exit(0);
        }
        return input.top();
    }
    // Return the size of the Queue
    int size()
    {
        return input.size();
    }
};

class MyQueue
{
public:
    stack<int> input, output;
    /** Initialize your data structure here. */
    MyQueue()
    {
    }

    /** Push element x to the back of queue. */
    void push(int x)
    {
        cout << "The element pushed is " << x << endl;
        input.push(x);
    }

    /** Removes the element from in front of queue and returns that element. */
    int pop()
    {
        // shift input to output
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();

        int x = output.top();
        output.pop();
        return x;
    }

    /** Get the front element. */
    int top()
    {
        // shift input to output
        if (output.empty())
            while (input.size())
                output.push(input.top()), input.pop();
        return output.top();
    }

    int size()
    {
        return (output.size() + input.size());
    }
};

bool isValid(string s)
{
    stack<char> st;
    for (auto it : s) // traverse string
    {
        if (it == '(' || it == '{' || it == '[')
            st.push(it);
        else
        {
            if (st.size() == 0)
                return false;
            char ch = st.top();
            st.pop();
            if ((it == ')' and ch == '(') or (it == ']' and ch == '[') or (it == '}' and ch == '{'))
                continue;
            else
                return false;
        }
    }
    return st.empty();
}

struct stackNode
{
    int data;
    stackNode *next;
    int size;
    stackNode(int d)
    {
        data = d;
        next = NULL;
    }
};
struct stack
{
    stackNode *top;
    int size;
    stack()
    {
        top = NULL;
        size = 0;
    }
    void stackPush(int x)
    {
        stackNode *element = new stackNode(x);
        element->next = top;
        top = element;
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
        stackNode *temp = top;
        top = top->next;
        delete temp;
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
    void printStack()
    {
        stackNode *current = top;
        while (current != NULL)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
};
int main()
{
    // StackImplementation s;
    // s.push(6);
    // s.push(3);
    // s.push(7);
    // cout << "Top of stack is before deleting any element " << s.Top() << endl;
    // cout << "Size of stack before deleting any element " << s.Size() << endl;
    // cout << "The element deleted is " << s.pop() << endl;
    // cout << "Size of stack after deleting an element " << s.Size() << endl;
    // cout << "Top of stack after deleting an element " << s.Top() << endl;

    Queue q(6);
    q.push(4);
    q.push(14);
    q.push(24);
    q.push(34);
    cout << "The peek of the queue before deleting any element " << q.top() << endl;
    cout << "The size of the queue before deletion " << q.size() << endl;
    cout << "The first element to be deleted " << q.pop() << endl;
    cout << "The peek of the queue after deleting an element " << q.top() << endl;
    cout << "The size of the queue after deleting an element " << q.size() << endl;

    string s = "()[{}()]";
    if (isValid(s))
        cout << "True" << endl;
    else
        cout << "False" << endl;

    return 0;
}