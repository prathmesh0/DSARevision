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
int main()
{
    // vector<int> v = {12, 4, 5, 66, 77, 8, 77};
    // // cout << largest(v) << endl;
    // vector<int> ans = secondlargestandSmallest(v);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    vector<int> v1 = {11, 2, 4, 5, 6, 7, 9};
    cout << isSorted(v1);
    return 0;
}