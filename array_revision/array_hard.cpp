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

vector<vector<int>> triplet(int n, vector<int> &arr)
{

    // Brute force approach

    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {

    //             if (arr[i] + arr[j] + arr[k] == 0)
    //             {
    //                 vector<int> temp = {arr[i], arr[j], arr[k]};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // better Approach
    // set<vector<int>> st;
    // for (int i = 0; i < n; i++)
    // {
    //     set<int> hashst;
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         int rem = -(arr[j] + arr[i]);
    //         if (hashst.find(rem) != hashst.end())
    //         {
    //             vector<int> temp = {arr[i], arr[j], rem};
    //             sort(temp.begin(), temp.end());
    //             st.insert(temp);
    //         }

    //         hashst.insert(arr[j]);
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // Optimal Approach
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {

        if (i != 0 && arr[i] == arr[i - 1])
            continue;

        int j = i + 1;
        int k = n - 1;
        while (j < k)
        {
            int sum = arr[i] + arr[j] + arr[k];
            if (sum < 0)
            {
                j++;
            }
            else if (sum > 0)
            {
                k--;
            }
            else
            {
                vector<int> temp = {arr[i], arr[j], arr[k]};
                ans.push_back(temp);
                j++;
                k--;
                // skip the duplicates:
                while (j < k && arr[j] == arr[j - 1])
                    j++;
                while (j < k && arr[k] == arr[k + 1])
                    k--;
            }
        }
    }
    return ans;
}

int solve(vector<int> &arr)
{
    int n = arr.size();
    // int maxLength = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == 0)
    //         {
    //             maxLength = max(maxLength, j - i + 1);
    //         }
    //     }
    // }
    // return maxLength;

    int maxLen = 0;
    unordered_map<int, int> mpp;
    int sum = 0;

    for (int i = 0; i < n; i++)
    {
        sum += arr[i];

        if (sum == 0)
        {
            maxLen = i + 1;
        }
        else if (mpp.find(sum) != mpp.end())
        {
            maxLen = max(maxLen, i - mpp[sum]);
        }
        else
        {
            mpp[sum] = i;
        }
    }
    return maxLen;
}

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    // Brute force approach
    //  int n = nums.size();
    //  set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             for (int l = k + 1; l < n; l++)
    //             {
    //                 long long sum = nums[i] + nums[j];
    //                 sum += nums[k];
    //                 sum += nums[l];

    //                 if (sum == target)
    //                 {
    //                     vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
    //                     sort(temp.begin(), temp.end());
    //                     st.insert(temp);
    //                 }
    //             }
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // Better Approach
    // int n = nums.size();
    // set<vector<int>> st;

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         set<long long> hashSet;
    //         for (int k = j + 1; k < n; k++)
    //         {
    //             long long sum = nums[i] + nums[j];
    //             sum += nums[k];

    //             long long rem = target - sum;
    //             if (hashSet.find(rem) != hashSet.end())
    //             {
    //                 vector<int> temp = {nums[i], nums[j], nums[k], (int)rem};
    //                 sort(temp.begin(), temp.end());
    //                 st.insert(temp);
    //             }
    //             hashSet.insert(nums[k]);
    //         }
    //     }
    // }
    // vector<vector<int>> ans(st.begin(), st.end());
    // return ans;

    // Optimal Approach
    int n = nums.size(); // size of the array
    vector<vector<int>> ans;

    // sort the given array:
    sort(nums.begin(), nums.end());

    // calculating the quadruplets:
    for (int i = 0; i < n; i++)
    {
        // avoid the duplicates while moving i:
        if (i > 0 && nums[i] == nums[i - 1])
            continue;
        for (int j = i + 1; j < n; j++)
        {
            // avoid the duplicates while moving j:
            if (j > i + 1 && nums[j] == nums[j - 1])
                continue;

            // 2 pointers:
            int k = j + 1;
            int l = n - 1;
            while (k < l)
            {
                long long sum = nums[i];
                sum += nums[j];
                sum += nums[k];
                sum += nums[l];
                if (sum == target)
                {
                    vector<int> temp = {nums[i], nums[j], nums[k], nums[l]};
                    ans.push_back(temp);
                    k++;
                    l--;

                    // skip the duplicates:
                    while (k < l && nums[k] == nums[k - 1])
                        k++;
                    while (k < l && nums[l] == nums[l + 1])
                        l--;
                }
                else if (sum < target)
                    k++;
                else
                    l--;
            }
        }
    }

    return ans;
}

int subarraysWithXorK(vector<int> &arr, int k)
{
    // Brute force
    // int n = arr.size();
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int xorr = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             xorr = xorr ^ arr[k];
    //             if (xorr == k)
    //             {
    //                 count++;
    //             }
    //         }
    //     }
    // }
    // return count;

    // better approach
    //

    // Optimal Approach
    int n = arr.size();
    unordered_map<int, int> mpp;
    int count = 0;
    int xorr = 0;
    mpp[xorr]++;

    for (int i = 0; i < n; i++)
    {
        // xor till i
        xorr ^= arr[i];
        // formula
        int x = xorr ^ k;
        if (mpp.find(x) != mpp.end())
        {
            count += mpp[x];
        }

        // update the value and its frequecy in the map
        mpp[xorr]++;
    }
    return count;
}

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr)
{
    // Brute force appraoch

    // int n = arr.size();
    // vector<vector<int>> ans;
    // sort(arr.begin(), arr.end());

    // for (int i = 0; i < n; i++)
    // {
    //     int start = arr[i][0];
    //     int end = arr[i][1];

    //     // check to skip the already overlapping interval
    //     if (!ans.empty() && end <= ans.back()[1])
    //     {
    //         continue;
    //     }

    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j][0] <= end)
    //         {
    //             end = max(end, arr[j][1]);
    //         }
    //         else
    //         {
    //             break;
    //         }
    //     }
    //     ans.push_back({start, end});
    // }
    // return ans;

    // Optimal approach
    int n = arr.size();
    vector<vector<int>> ans;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        // creating new intervals
        if (ans.empty() || arr[i][0] > ans.back()[1])
        {
            ans.push_back(arr[i]);
        }
        // merge overlapping intervals
        else
        {
            ans.back()[1] = max(ans.back()[1], arr[i][1]);
        }
    }
    return ans;
}
int main()
{
    // {
    //     vector<int> arr = {11, 33, 33, 11, 33, 11};
    //     vector<int> ans = majorityElement(arr);
    //     cout << "The majority elements are: ";
    //     for (auto it : ans)
    //         cout << it << " ";
    //     cout << "\n";

    // vector<int> arr1 = {-1,
    //                     0,
    //                     1,
    //                     2,
    //                     -1,
    //                     -4};
    // int n = arr1.size();
    // vector<vector<int>> ans = triplet(n, arr1);
    // for (auto it : ans)
    // {
    //     cout << "[";
    //     for (auto i : it)
    //     {
    //         cout << i << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << "\n";
    // vector<int> a = {9, -3, 3, -1, 6, -5};
    // cout << solve(a) << endl;

    // vector<int> nums = {4, 3, 3, 4, 4, 2, 1, 2, 1, 1};
    // int target = 9;
    // vector<vector<int>> ans = fourSum(nums, target);
    // cout << "The quadruplets are: \n";
    // for (auto it : ans)
    // {
    //     cout << "[";
    //     for (auto ele : it)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << "] ";
    // }
    // cout << "\n";

    // vector<int> a1 = {4, 2, 2, 6, 4};
    // int k = 6;
    // int ans = subarraysWithXorK(a1, k);
    // cout << "The number of subarrays with XOR k is: "
    //      << ans << "\n";

    vector<vector<int>> arr1 = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    vector<vector<int>> ans = mergeOverlappingIntervals(arr1);
    cout << "The merged intervals are: " << "\n";
    for (auto it : ans)
    {
        cout << "[" << it[0] << ", " << it[1] << "] ";
    }
    cout << endl;

    return 0;
}