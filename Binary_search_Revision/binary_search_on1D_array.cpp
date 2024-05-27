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

int count(vector<int> &arr, int n, int x)
{
    // Linear approach
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == x)
    //     {
    //         count++;
    //     }
    // }
    // return count;

    // Binary Search Approach
    int ans = lastOccurence(n, x, arr) - firstOccurence(n, x, arr) + 1;
    return ans;
}

int sortedRotatedone(vector<int> &arr, int n, int k)
{

    // Linear Search
    //  for (int i = 0; i < n; i++)
    //  {
    //      if (arr[i] == k)
    //      {
    //          return i;
    //      }
    //  }
    //  return -1;

    // Binary Search
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return mid;
        }

        // check which part is sorted
        // left
        if (arr[s] <= arr[mid])
        {
            // if element exist
            if (arr[s] <= k && arr[mid] >= k)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        // right
        else
        {
            // if element exist
            if (arr[mid] <= k && arr[e] >= k)
            {
                s = mid + 1;
            }
            else
            {
                e = mid - 1;
            }
        }
    }
    return -1;
}

bool searchInARotatedSortedArrayII(vector<int> &arr, int k)
{
    int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == k)
    //     {
    //         return true;
    //     }
    // }
    // return false;

    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == k)
        {
            return true;
        }

        if (arr[mid] == arr[s] && arr[mid] == arr[e])
        {
            s = s + 1;
            e = e - 1;
            continue;
        }

        // left
        if (arr[s] <= arr[mid])
        {
            // if element is exist
            if (arr[s] >= k && arr[mid] <= k)
            {
                e = mid - 1;
            }
            // not exist
            else
            {
                s = mid + 1;
            }
        }
        else
        {
            // if element is exist
            if (arr[mid] >= k && arr[e] <= k)
            {
                s = mid + 1;
            }
            // not exist
            else
            {
                e = mid - 1;
            }
        }
    }
    return false;
}

int findMin(vector<int> &arr)
{
    int n = arr.size();
    int mini = INT_MAX;
    // Linear approach
    // for (int i = 0; i < n; i++)
    // {
    //     mini = min(arr[i], mini);
    // }
    // return mini;

    // BS
    // int s = 0, e = n - 1;
    // while (s <= e)
    // {
    //     int mid = s + (e - s) / 2;
    //     // if left part is sorted
    //     if (arr[s] <= arr[mid])
    //     {
    //         mini = min(mini, arr[s]);
    //         s = mid + 1;
    //     }
    //     else
    //     {
    //         mini = min(mini, arr[mid]);
    //         e = mid - 1;
    //     }
    // }
    // return mini;

    // Optimize BS
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        // search space is already sorted
        // then arr[low] will always be
        // the minimum in that search space:

        if (arr[s] <= arr[e])
        {
            mini = min(mini, arr[s]);
            break;
        }
        // if left part is sorted
        if (arr[s] <= arr[mid])
        {
            mini = min(mini, arr[s]);
            s = mid + 1;
        }
        // if right part is sorted
        else
        {
            mini = min(mini, arr[mid]);
            e = mid - 1;
        }
    }
    return mini;
}

int singleNonDuplicate(vector<int> &arr)
{

    // int n = arr.size();
    // unordered_map<int, int> mpp;
    // for(auto it : arr)
    // {
    //     mpp[it]++;
    // }

    // for (auto it : mpp)
    // {
    //     if (it.second == 1)
    //     {
    //         return it.first;
    //     }
    // }
    // return -1;

    // int n = arr.size();
    // int xorr = 0;
    // for (auto it : arr)
    // {
    //     xorr = xorr ^ it;
    // }
    // return xorr;

    int n = arr.size();
    if (n == 1)
        return arr[0];

    if (arr[0] != arr[1])
        return arr[0];

    if (arr[n - 1] != arr[n - 2])
        return arr[n - 1];

    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] != arr[mid + 1] && arr[mid] != arr[mid - 1])
        {
            return arr[mid];
        }
        // standing at  odd  index and prev element is equal or standing at even index and next element is equal

        else if ((mid % 2 == 1 && arr[mid] == arr[mid - 1]) || (mid % 2 == 0 && arr[mid] == arr[mid + 1]))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int findPeakElement(vector<int> &arr)
{
    // int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     if ((i == 0 || arr[i] > arr[i - 1]) && (i == (n - 1) || arr[i] > arr[i + 1]))
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    int n = arr.size();
    if (arr[0] > arr[1])
        return arr[0];
    if (arr[n - 1] > arr[n - 2])
        return arr[n - 1];

    int s = 1, e = n - 2;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] > arr[mid + 1] && arr[mid] > arr[mid - 1])
        {
            return mid;
        }
        else if (arr[mid] > arr[mid - 1])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return -1;
}

int floorSqrt(int n)
{

    // Brute force approach
    //  int ans;
    //  for (long long i = 1; i <= n; i++)
    //  {
    //      long long val = i * i;
    //      if (val <= n * 1ll)
    //      {
    //          ans = i;
    //      }
    //      else
    //      {
    //          break;
    //      }
    //  }
    //  return ans;

    // return sqrt(n);

    int s = 1, e = n;

    while (s <= e)
    {
        long long mid = s + (e - s) / 2;
        long long val = mid * mid;
        if (val <= (long long)(n))
        {

            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

int findDays(vector<int> &arr, int cap)
{
    int days = 1;
    int load = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        if (load + arr[i] > cap)
        {
            days += 1;
            load = arr[i];
        }
        else
        {
            load += arr[i];
        }
    }
    return days;
}
int leastWeightCapacity(vector<int> &arr, int d)
{
    int n = arr.size();
    int maxi = INT_MIN;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }

    // linear approach
    //  for (int i = maxi; i <= sum; i++)
    //  {
    //      if (findDays(arr, i) <= d)
    //      {
    //          return i;
    //      }
    //  }
    //  return -1;

    // Binary Search approach
    int s = maxi, e = sum;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (findDays(arr, mid) <= d)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int missingK(vector<int> &arr, int n, int k)
{
    // Linear Approach
    //  for (int i = 0; i < n; i++)
    //  {
    //      if (arr[i] <= k)
    //      {
    //          k++;
    //      }
    //      else
    //      {
    //          break;
    //      }
    //  }
    //  return k;

    // Binary Search Approach
    int s = 0, e = n - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int missing = arr[mid] - (mid + 1);
        if (missing < k)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return k + e + 1; //  or s+k
}

int lowerBoundb(vector<int> arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // maybe an answer
        if (arr[mid] >= x)
        {
            ans = mid;
            // look for smaller index on the left
            high = mid - 1;
        }
        else
        {
            low = mid + 1; // look on the right
        }
    }
    return ans;
}
int rowWithMax1s(vector<vector<int>> &matrix, int n, int m)
{

    // Brute force
    //  int cnt_max = 0;
    //  int index = -1;

    // //traverse the matrix:
    // for (int i = 0; i < n; i++) {
    //     int cnt_ones = 0;
    //     for (int j = 0; j < m; j++) {
    //         cnt_ones += matrix[i][j];
    //     }
    //     if (cnt_ones > cnt_max) {
    //         cnt_max = cnt_ones;
    //         index = i;
    //     }
    // }
    // return index;

    // BS
    int cnt_max = 0;
    int index = -1;

    // traverse the rows:
    for (int i = 0; i < n; i++)
    {
        // get the number of 1's:
        int cnt_ones = m - lowerBoundb(matrix[i], m, 1);
        if (cnt_ones > cnt_max)
        {
            cnt_max = cnt_ones;
            index = i;
        }
    }
    return index;
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

    // int n = 7;
    // int key = 13;
    // vector<int> v = {3, 4, 13, 13, 13, 20, 40};

    // // returning the first occurrence index if the element is present otherwise -1
    // cout << firstOccurence(n, key, v) << "\n";
    // cout << lastOccurence(n, key, v) << endl;

    // vector<int> arr5 = {2, 4, 6, 8, 8, 8, 11, 13};
    // int n = 8, x = 8;
    // int ans = count(arr5, n, x);
    // cout << "The number of occurrences is: "
    //      << ans << "\n";

    // vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    // int n = 9, k = 1;
    // int ans = sortedRotatedone(arr, n, k);
    // if (ans == -1)
    //     cout << "Target is not present.\n";
    // else
    //     cout << "The index is: " << ans << "\n";

    // vector<int> arr = {7, 8, 1, 2, 3, 3, 3, 4, 5, 6};
    // int k = 3;
    // bool ans = searchInARotatedSortedArrayII(arr, k);
    // if (!ans)
    //     cout << "Target is not present.\n";
    // else
    //     cout << "Target is present in the array.\n";

    // vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3};
    // int ans = findMin(arr);
    // cout << "The minimum element is: " << ans << "\n";

    // vector<int> arr = {1, 1, 2, 2, 3, 3, 4, 5, 5, 6, 6};
    // int ans = singleNonDuplicate(arr);
    // cout << "The single element is: " << ans << "\n";

    // vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 5, 1};
    // int ans = findPeakElement(arr);
    // cout << "The peak is at index: " << ans << "\n";

    // int n = 227;
    // int ans = floorSqrt(n);
    // cout << "The floor of square root of " << n
    //      << " is: " << ans;

    // vector<int> weights = {5, 4, 5, 2, 3, 4, 5, 6};
    // int d = 5;
    // int ans = leastWeightCapacity(weights, d);
    // cout << "The minimum capacity should be: " << ans << "\n";

    // vector<int> vec = {4, 7, 9, 10};
    // int n = 4, k = 4;
    // int ans = missingK(vec, n, k);
    // cout << "The missing number is: " << ans << "\n";

    vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    int n = 3, m = 3;
    cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';
    return 0;
}