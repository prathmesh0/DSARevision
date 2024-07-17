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
        (*this).maxSize = maxSize;
        arr = new int[maxSize];
        start = -1;
        end = -1;
        currSize = 0;
    }
    void push(int newElement)
    {
        if (currSize == maxSize)
        {
            cout << "Queue is full\nExiting..." << endl;
            exit(1);
        }
        if (end == -1)
        {
            start = 0;
            end = 0;
        }
        else
            end = (end + 1) % maxSize;
        arr[end] = newElement;
        cout << "The element pushed is " << newElement << endl;
        currSize++;
    }
    int pop()
    {
        if (start == -1)
        {
            cout << "Queue Empty\nExiting..." << endl;
        }
        int popped = arr[start];
        if (currSize == 1)
        {
            start = -1;
            end = -1;
        }
        else
            start = (start + 1) % maxSize;
        currSize--;
        return popped;
    }
    int top()
    {
        if (start == -1)
        {
            cout << "Queue is Empty" << endl;
            exit(1);
        }
        return arr[start];
    }
    int size()
    {
        return currSize;
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

    return 0;
}