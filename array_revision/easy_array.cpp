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
    vector<int> arr = {1, 2, 0, 4, 0, 6};
    // cout << removeDuplicate(arr);
    // leftRotateByOne(arr);
    moveZeros(arr);

    for (auto it : arr)
    {
        cout << it << " ";
    }
    return 0;
}