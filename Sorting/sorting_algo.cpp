#include <bits/stdc++.h>
using namespace std;

void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n - 2; i++)
    {
        int mini = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[mini])
            {
                mini = j;
            }
        }
        swap(arr[i], arr[mini]);
    }
}

void bubble_sort(vector<int> &arr)
{
    int n = arr.size();
    // bubble sort
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j <= i - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j + 1];
                arr[j + 1] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main()
{
    vector<int> v = {13, 44, 22, 1, 33, 55};
    // selectionSort(v);
    bubble_sort(v);
    cout << "Element after sorting" << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}