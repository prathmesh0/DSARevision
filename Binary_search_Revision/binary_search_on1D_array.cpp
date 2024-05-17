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
    // Linear force
    //  for (int i = 0; i < n; i++)
    //  {
    //      if (arr[i] >= key)
    //      {
    //          return i;
    //      }
    //  }
    //  return n;

    // BS
    // Lower Bound = index near to key element which gives me arr[i] >= key

    int start = 0, end = n - 1;
    int ans = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= key)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int upperBound(vector<int> &arr, int key, int n)
{
    // Lower Bound = index near to key element which gives me arr[i] > key

    // Linear approach
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] > key)
    //     {
    //         return i;
    //     }
    // }
    // return n;

    // BS
    int start = 0, end = n - 1;
    int ans = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] > key)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}

int searchInsert(vector<int> &arr, int key)
{
    // Linear Search
    // int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] >= key)
    //     {
    //         return i;
    //     }
    // }
    // return n;

    // BS
    int n = arr.size();
    int start = 0, end = n - 1;
    int ans = n;

    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= key)
        {
            ans = mid;
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
int floorOfx(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1;
    int ans = -1;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] <= key)
        {
            ans = arr[mid];
            start = mid + 1;
        }
        else
        {
            end = mid - 1;
        }
    }
    return ans;
}
int ceilOfx(vector<int> &arr, int n, int key)
{
    int start = 0, end = n - 1;
    int ans = n;
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (arr[mid] >= key)
        {
            ans = arr[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return ans;
}
pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{

    // The floor of x is the largest element in the array which is smaller than or equal to x.
    // The ceiling of x is the smallest element in the array greater than or equal to x.
    int f = floorOfx(arr, n, x);
    int c = ceilOfx(arr, n, x);
    return make_pair(f, c);
}

int firstOccurence(int n, int key, vector<int> &arr)
{
    // first occurrence
    // Linear approach
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == key)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Bs
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            e = mid - 1;
        }
        else if (arr[mid] < key)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return ans;
}

int lastOccurence(int n, int key, vector<int> &arr)
{
    // last occurrence
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     if (arr[i] == key)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Bs
    int s = 0, e = n - 1;
    int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == key)
        {
            ans = mid;
            s = mid + 1;
        }
        else if (arr[mid] > key)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
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
    // int ind = lowerBound(arr1, n, x);
    // cout << "The lower bound is the index: " << ind << "\n";

    //  For the lower bound the condition was arr[ind] >= x and here, in the case of the upper bound, it is arr[ind] > x.

    // vector<int> arr2 = {3, 5, 8, 9, 15, 19};
    // int n = 6, x = 9;
    // int ind1 = upperBound(arr2, x, n);
    // cout << "The upper bound is the index: " << ind1 << "\n";

    // vector<int> arr3 = {1, 2, 4, 7};
    // int x = 6;
    // int ind3 = searchInsert(arr3, x);
    // cout << "The index is: " << ind3 << "\n";

    // vector<int> arr4 = {3, 4, 4, 7, 8, 10};
    // int n = 6, x = 5;
    // pair<int, int> ans = getFloorAndCeil(arr4, n, x);
    // cout << "The floor and ceil are: " << ans.first << " " << ans.second << endl;

    int n = 7;
    int key = 13;
    vector<int> v = {3, 4, 13, 13, 13, 20, 40};

    // returning the first occurrence index if the element is present otherwise -1
    cout << firstOccurence(n, key, v) << "\n";
    cout << lastOccurence(n, key, v) << endl;

    return 0;
}