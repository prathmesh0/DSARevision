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

void insertion_sort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i <= n - 1; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            int temp = arr[j - 1];
            arr[j - 1] = arr[j];
            arr[j] = temp;
            j--;
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;    // temporary array
    int left = low;      // starting index of left half of arr
    int right = mid + 1; // starting index of right half of arr

    // storing elements in the temporary array in a sorted manner//

    while (left <= mid && right <= high)
    {
        if (arr[left] <= arr[right])
        {
            temp.push_back(arr[left]);
            left++;
        }
        else
        {
            temp.push_back(arr[right]);
            right++;
        }
    }

    // if elements on the left half are still left //

    while (left <= mid)
    {
        temp.push_back(arr[left]);
        left++;
    }

    //  if elements on the right half are still left //
    while (right <= high)
    {
        temp.push_back(arr[right]);
        right++;
    }

    // transfering all elements from temporary to arr //
    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}

void mergeSort(vector<int> &arr, int low, int high)
{
    if (low >= high)
        return;
    int mid = (low + high) / 2;
    mergeSort(arr, low, mid);      // left half
    mergeSort(arr, mid + 1, high); // right half
    merge(arr, low, mid, high);    // merging sorted halves
}

void bubble_sort(int arr[], int n)
{
    // Base Case: range == 1.
    if (n == 1)
        return;

    for (int j = 0; j <= n - 2; j++)
    {
        if (arr[j] > arr[j + 1])
        {
            int temp = arr[j + 1];
            arr[j + 1] = arr[j];
            arr[j] = temp;
        }
    }

    // Range reduced after recursion:
    bubble_sort(arr, n - 1);
}
void insertion_sort(int arr[], int i, int n)
{

    // Base Case: i == n.
    if (i == n)
        return;

    int j = i;
    while (j > 0 && arr[j - 1] > arr[j])
    {
        int temp = arr[j - 1];
        arr[j - 1] = arr[j];
        arr[j] = temp;
        j--;
    }

    insertion_sort(arr, i + 1, n);
}

int main()
{
    vector<int> v = {13, 44, 22, 1, 33, 55};
    int n = v.size();
    // selectionSort(v);
    // bubble_sort(v);
    // insertion_sort(v);
    mergeSort(v, 0, n - 1);
    cout << "Element after sorting" << endl;
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}