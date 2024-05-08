#include <bits/stdc++.h>
using namespace std;

vector<int> majorityElement(vector<int> &arr)
{
    // Brute Force Approach
    int n = arr.size();
    vector<int> ans;

    // for (int i = 0; i < n; i++)
    // {
    //     if (ans.size() == 0 || ans[0] != arr[i])
    //     {
    //         int count = 0;
    //         for (int j = 0; j < n; j++)
    //         {
    //             if (arr[i] == arr[j])
    //             {
    //                 count++;
    //             }
    //         }

    //         if (count > (n / 3))
    //         {
    //             ans.push_back(arr[i]);
    //         }
    //         if (ans.size() == 2)
    //         {
    //             break;
    //         }
    //     }
    // }
    // return ans;

    // Better Appraoch

    // unordered_map<int, int> mpp;
    // for (auto it : arr)
    // {
    //     mpp[it]++;
    // }

    // for (auto it : mpp)
    // {
    //     if (it.second > (n / 3))
    //     {
    //         ans.push_back(it.first);
    //     }
    //      if (ls.size() == 2) break; // In any array there can be 2 elements which appears more than n/3

    // }
    // return ans;

    // Optimal appraoch
    int count1 = 0, count2 = 0;
    int ele1 = INT_MIN, ele2 = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (count1 == 0 && arr[i] != ele2)
        {
            count1++;
            ele1 = arr[i];
        }
        else if (count2 == 0 && arr[i] != ele1)
        {
            count2++;
            ele2 = arr[i];
        }
        else if (arr[i] == ele1)
            count1++;
        else if (arr[i] == ele2)
            count2++;
        else
        {
            count1--;
            count2--;
        }
    }
    count1 = 0;
    count2 = 0;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele1)
            count1++;
        if (arr[i] == ele2)
            count2++;
    }
    if (count1 > (n / 3))
    {
        ans.push_back(ele1);
    }
    if (count2 > (n / 3))
    {
        ans.push_back(ele2);
    }
    return ans;
}


int main()
{
    vector<int> arr = {11, 33, 33, 11, 33, 11};
    vector<int> ans = majorityElement(arr);
    cout << "The majority elements are: ";
    for (auto it : ans)
        cout << it << " ";
    cout << "\n";
    return 0;
}