#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int> &arr, int start, int end, int key)
{
    // Base case
    if (start > end)
        return -1;
    int mid = (start + end) / 2;
    if (arr[mid] == key)
    {
        return mid;
    }

    else if (arr[mid] > key)
        return binarySearch(arr, start, mid - 1, key);

    return binarySearch(arr, mid + 1, end, key);
}
int searchElement(vector<int> &arr, int key)
{
    // Iterative approach
    int n = arr.size();
    int start = 0, end = n - 1;
    int mid;
    while (start <= end)
    {
        mid = (start + end) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        else if (arr[mid] < key)
        {
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return -1;

    // Recursive approach
    // binarySearch(arr, 0, arr.size() - 1, key);
}

int lowerBound(vector<int> &arr, int n, int key)
{
    for (int i = 0; i < n; i++)
    {
    }
}

int searchInsert(vector<int> &arr, int x)
{
    int n = arr.size(); // size of the array
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] >= x)
        {
            ans = mid;

            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    return ans;
}

int main()
{
    // vector<int> arr = {2, 3, 5, 10, 13, 17};
    // int key = 13;
    // cout << searchElement(arr, key);

    // vector<int> arr1 = {3, 5, 8, 15, 19};
    // int n = 5, x = 9;
    // int ind = lowerBound(arr, n, x);
    // cout << "The lower bound is the index: " << ind << "\n";

    vector<int> arr = {1, 2, 4, 7};
    int x = 6;
    int ind = searchInsert(arr, x);
    cout << "The index is: " << ind << "\n";
    return 0;
}