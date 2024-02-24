#include <bits/stdc++.h>
using namespace std;

int largest(vector<int> &arr)
{
    // brute force
    // sort(arr.begin(), arr.end());
    // return arr[arr.size() - 1];

    // optimal
    int maxi = INT_MIN;
    for (int i = 0; i < arr.size(); i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

vector<int> secondlargestandSmallest(vector<int> &v)
{
    // vector<int> ans;
    // sort(v.begin(), v.end());
    // int s_large = v[v.size() - 2];
    // int s_small = v[1];
    // ans.push_back(s_large);
    // ans.push_back(s_small);
    // return ans;

    vector<int> ans;
    // int maxi = INT_MIN, mini = INT_MAX;
    // for (int i = 0; i < v.size(); i++)
    // {
    //     maxi = max(maxi, v[i]);
    //     mini = min(mini, v[i]);
    // }
    // int s_maxi = INT_MIN, s_mini = INT_MAX;

    // for (int i = 0; i < v.size(); i++)
    // {
    //     if (v[i] > s_maxi && v[i] != maxi)
    //     {
    //         s_maxi = v[i];
    //     }
    //     if (v[i] < s_mini && v[i] != mini)
    //     {
    //         s_mini = v[i];
    //     }
    // }
    // ans.push_back(s_maxi);
    // ans.push_back(s_mini);
    // return ans;

    int largest = INT_MIN, s_largest = INT_MIN;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > largest)
        {
            s_largest = largest;
            largest = v[i];
        }
        else if (v[i] > s_largest && v[i] != largest)
        {
            s_largest = v[i];
        }
    }
    ans.push_back(s_largest);

    int smallest = INT_MAX, s_smallest = INT_MAX;
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] < smallest)
        {
            s_smallest = smallest;
            smallest = v[i];
        }
        else if (v[i] < s_smallest && v[i] != smallest)
        {
            s_smallest = v[i];
        }
    }
    ans.push_back(s_smallest);
    return ans;
}
bool isSorted(vector<int> &arr)
{
    int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             return false;
    //         }
    //     }
    // }
    // return true;

    for (int i = 1; i < n; i++)
    {
        if (arr[i - 1] > arr[i])
        {
            return false;
        }
    }
    return true;
}
int removeDuplicate(vector<int> &arr)
{
    // brute force
    //  set<int> st;
    //  for (auto it : arr)
    //  {
    //      st.insert(it);
    //  }
    //  int siz = st.size();
    //  int j = 0;
    //  for (auto it : st)
    //  {
    //      arr[j] = it;
    //      j++;
    //  }
    //  return siz;
    int i = 0;
    for (int j = 1; j < arr.size(); j++)
    {
        if (arr[i] != arr[j])
        {
            i++;
            arr[i] = arr[j];
        }
    }
    return (i + 1);
}

void leftRotateByOne(vector<int> &arr)
{
    // Brute
    // vector<int> ans(arr.size());
    // int temp = arr[0];
    // for (int i = 1; i < arr.size(); i++)
    // {
    //     ans[i - 1] = arr[i];
    // }
    // ans[ans.size() - 1] = temp;
    // int j = 0;
    // for (auto it : ans)
    // {
    //     arr[j] = it;
    //     j++;
    // }

    // optimal
    int n = arr.size();
    int tem = arr[0];
    for (int i = 1; i < n; i++)
    {
        arr[i - 1] = arr[i];
    }
    arr[n - 1] = tem;
}

void moveZeros(vector<int> &arr)
{
    // brute
    // int n = arr.size();
    // vector<int> ans(n, 0);
    // int j = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] != 0)
    //     {
    //         ans[j] = arr[i];
    //         j++;
    //     }
    // }
    // j = 0;
    // for (auto it : ans)
    // {
    //     arr[j] = it;
    //     j++;
    // }
    int n = arr.size();
    int k = 0;
    while (k < n)
    {
        if (arr[k] == 0)
        {
            break;
        }
        else
        {
            k++;
        }
    }
    int i = k;
    int j = k + 1;

    while (i < n && j < n)
    {
        if (arr[j] != 0)
        {
            swap(arr[i], arr[j]);
            i++;
        }
        j++;
    }
}

int linearSearch(vector<int> &arr, int key)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            return i;
        }
    }
    return -1;
}

vector<int> unionOfTwosortedArray(vector<int> &arr1, vector<int> &arr2)
{
    set<int> st;
    map<int, int> mpp;
    vector<int> ans;
    // brute force
    //  for (int i = 0; i < arr1.size(); i++)
    //  {
    //      st.insert(arr1[i]);
    //  }
    //  for (int i = 0; i < arr2.size(); i++)
    //  {
    //      st.insert(arr2[i]);
    //  }
    //  for (auto it : st)
    //  {
    //      ans.push_back(it);
    //  }

    // brute force
    // for (int i = 0; i < arr1.size(); i++)
    // {
    //     mpp[arr1[i]]++;
    // }
    // for (int i = 0; i < arr2.size(); i++)
    // {
    //     mpp[arr2[i]]++;
    // }
    // for (auto it : mpp)
    // {
    //     ans.push_back(it.first);
    // }
    // return ans;

    // optimal approach
    int i = 0;
    int j = 0;
    int n = arr1.size();
    int m = arr2.size();
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j])
        {
            if (ans.size() == 0 || ans.back() != arr1[i])
            {
                ans.push_back(arr1[i]);
            }
            i++;
        }
        else
        {
            if (ans.size() == 0 || ans.back() != arr2[j])
            {
                ans.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n)
    {
        if (ans.size() == 0 || ans.back() != arr1[i])
        {
            ans.push_back(arr1[i]);
        }
        i++;
    }

    while (j < m)
    {
        if (ans.size() == 0 || ans.back() != arr2[j])
        {
            ans.push_back(arr2[j]);
        }
        j++;
    }
    return ans;
}
int missingNumber(vector<int> arr1)
{
    // Brute force approach
    //  int n = arr1.size();
    //  sort(arr1.begin(), arr1.end());
    //  for (int i = 0; i <= n; i++)
    //  {
    //      if (arr1[i] != i)
    //      {
    //          return i;
    //      }
    //  }
    //  return -1;
    // Better approach
    //  int n = arr1.size();
    //  int arr[n + 1] = {0};

    // for (int i = 0; i < n; i++)
    // {
    //     arr[arr1[i]]++;
    // }

    // for (int i = 0; i <= n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Optimal Approach

    // int n = arr1.size();
    // int sumOfn = (n * (n + 1)) / 2;
    // int sumOfA = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sumOfA = sumOfA + arr1[i];
    // }

    // return (sumOfn - sumOfA);

    // optimal Approach
    int xor1 = 0, xor2 = 0;
    int n = arr1.size();
    for (int i = 0; i < n; i++)
    {
        xor1 = xor1 ^ arr1[i];
        xor2 = xor2 ^ (i);
    }
    xor2 = xor2 ^ (n);
    return xor1 ^ xor2;
}
int main()
{
    // vector<int> v = {12, 4, 5, 66, 77, 8, 77};
    // // cout << largest(v) << endl;
    // vector<int> ans = secondlargestandSmallest(v);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // vector<int> v1 = {11, 2, 4, 5, 6, 7, 9};
    // cout << isSorted(v1);
    // vector<int> arr = {1, 2, 0, 4, 0, 6};
    // cout << removeDuplicate(arr);
    // leftRotateByOne(arr);
    // moveZeros(arr);

    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    // int key = 6;
    // cout << linearSearch(arr, key) << endl;
    vector<int> arr1 = {2, 0, 1};
    // vector<int> arr2 = {2, 4, 7, 8};
    // vector<int> ans = unionOfTwosortedArray(arr1, arr2);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    cout << missingNumber(arr1) << endl;

    return 0;
}