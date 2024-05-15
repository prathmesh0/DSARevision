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
    // int n = arr.size();
    // int start = 0, end = n - 1;
    // int mid;
    // while (start <= end)
    // {
    //     mid = (start + end) / 2;
    //     if (arr[mid] == key)
    //     {
    //         return mid;
    //     }
    //     else if (arr[mid] < key)
    //     {
    //         start = mid + 1;
    //     }
    //     else
    //     {
    //         end = mid - 1;
    //     }
    // }
    // return -1;

    // Recursive approach
    binarySearch(arr, 0, arr.size() - 1, key);
}
int main()
{
    vector<int> arr = {2, 3, 5, 10, 13, 17};
    int key = 13;
    cout << searchElement(arr, key);
    return 0;
}