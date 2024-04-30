#include <bits/stdc++.h>
using namespace std;

vector<int> twoSum(vector<int> &arr, int target)
{
    // Brute Force
    int n = arr.size();
    // vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] + arr[j] == target)
    //         {
    //             ans.push_back(i);
    //             ans.push_back(j);
    //             return ans;
    //         }
    //     }
    // }
    // return {-1, -1};

    // Better Approach
    unordered_map<int, int> mpp;
    for (int i = 0; i < n; i++)
    {
        int num = arr[i];
        int moreNeeded = target - num;

        if (mpp.find(moreNeeded) != mpp.end())
        {
            return {mpp[moreNeeded], i};
        }
        mpp[num] = i;
    }
    return {-1, -1};

    // Better Approach->this approach will bw work when we need to check whether the element give sum equal to target
    // sort(arr.begin(), arr.end());
    // int s = 0, e = n - 1;
    // while (s <= e)
    // {
    //     if (arr[s] + arr[e] == target)
    //     {
    //         return true;
    //     }
    //     else if (arr[s] + arr[e] > target)
    //     {
    //         e--;
    //     }
    //     else
    //     {
    //         s++;
    //     }
    // }
    // return false;
}

void sortArray(vector<int> &arr)
{
    int n = arr.size();
    // Extreme Brute force
    // sort(arr.begin(), arr.end());

    // Better Appraoch
    // int count_zero = 0, count_one = 0, count_two = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] == 0)
    //     {
    //         count_zero++;
    //     }
    //     else if (arr[i] == 1)
    //     {
    //         count_one++;
    //     }
    //     else
    //     {
    //         count_two++;
    //     }
    // }

    // int i = 0;

    // // Fill the array with 0s
    // while (count_zero > 0)
    // {
    //     arr[i] = 0;
    //     i++;
    //     count_zero--;
    // }

    // // Fill the array with 1s
    // while (count_one > 0)
    // {
    //     arr[i] = 1;
    //     i++;
    //     count_one--;
    // }

    // // Fill the array with 2s
    // while (count_two > 0)
    // {
    //     arr[i] = 2;
    //     i++;
    //     count_two--;
    // }

    // Optimal Approach
    int low = 0, high = n - 1, mid = 0;
    while (mid <= high)
    {
        if (arr[mid] == 0)
        {
            swap(arr[low], arr[mid]);
            low++;
            mid++;
        }
        else if (arr[mid] == 1)
        {
            mid++;
        }
        else
        {
            swap(arr[mid], arr[high]);
            high--;
        }
    }
}

int majorityElement(vector<int> &arr)
{
    // Brute Force
    int n = arr.size();
    // for (int i = 0; i < n; i++)
    // {
    //     int count = 1;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] == arr[j])
    //         {
    //             count++;
    //         }
    //     }
    //     if (count > (n / 2))
    //     {
    //         return arr[i];
    //     }
    // }
    // return -1;

    // Better Approach
    // unordered_map<int, int> mpp;
    // for (auto it : arr)
    // {
    //     mpp[it]++;
    // }

    // for (auto it : mpp)
    // {
    //     if (it.second > (n / 2))
    //     {
    //         return it.first;
    //     }
    // }
    // return -1;
    int cnt = 0;
    int ele;
    for (int i = 0; i < n; i++)
    {
        if (cnt == 0)
        {
            cnt++;
            ele = arr[i];
        }
        else if (arr[i] == ele)
        {
            cnt++;
        }
        else
        {
            cnt--;
        }
    }
    cnt = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == ele)
        {
            cnt++;
        }
    }
    if (cnt > (n / 2))
    {
        return ele;
    }
    return -1;
}

int maxSubarraySum(vector<int> &arr)
{
    int n = arr.size();
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {

        int sum = 0;
        for (int j = i; j < n; j++)
        {
            sum += arr[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

int main()
{
    // vector<int> arr1 = {2, 6, 5, 8, 11};
    // int target = 14;
    // vector<int> ans = twoSum(arr1, target);
    // cout << "This is the answer for variant 2: [" << ans[0] << ", "
    //      << ans[1] << "]" << endl;
    // vector<int> arr2 = {0, 2, 1, 2, 0, 1};
    // sortArray(arr2);
    // cout << "After sorting:" << endl;
    // for (int i = 0; i < arr2.size(); i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    vector<int> arr = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    // int ans = majorityElement(arr);
    // cout << "The majority element is: " << ans << endl;
    cout << maxSubarraySum(arr);

    return 0;
}