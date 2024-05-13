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

void merge(long long arr1[], long long arr2[], int n, int m)
{
    // Brute force Approch

    // long long ans[m + n];
    // int left = 0, right = 0;
    // int index = 0;

    // while (left < n && right < m)
    // {
    //     if (arr1[left] <= arr2[right])
    //     {
    //         ans[index] = arr1[left];
    //         index++;
    //         left++;
    //     }
    //     else
    //     {
    //         ans[index] = arr2[right];
    //         index++;
    //         right++;
    //     }
    // }

    // while (left < n)
    // {
    //     ans[index] = arr1[left];
    //     left++;
    //     index++;
    // }
    // while (right < m)
    // {
    //     ans[index] = arr2[right];
    //     index++;
    //     right++;
    // }

    // for (int i = 0; i < n + m; i++)
    // {
    //     if (i < n)
    //     {
    //         arr1[i] = ans[i];
    //     }
    //     else
    //     {
    //         arr2[i-n] = ans[i];
    //     }
    // }

    // Optimal Approach-1
    int left = n - 1;
    int right = 0;

    while (left >= 0 && right < m)
    {
        if (arr2[right] < arr1[left])
        {
            swap(arr2[right], arr1[left]);
            left--;
            right++;
        }
        else
        {
            break;
        }
    }
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
}

int maxProductSubArray(vector<int> &arr)
{
    // Brute force approach
    //  int n = arr.size();
    //  int max_prod = INT_MIN;
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = i + 1; j < n; j++)
    //      {
    //          int prod = 1;

    //         for (int k = i; k <= j; k++)
    //         {
    //             prod = prod * arr[k];
    //             max_prod = max(max_prod, prod);
    //         }
    //     }
    // }
    // return max_prod;

    // Better Approach
    // int n = arr.size();
    // int max_prod = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     int prod = 1;
    //     for (int j = i; j < n; j++)
    //     {
    //         prod = prod * arr[j];
    //         max_prod = max(max_prod, prod);
    //     }
    // }
    // return max_prod;

    // Optimal Approach
    int n = arr.size();
    int maxi_prod = INT_MIN;
    int pref = 1, suff = 1;

    for (int i = 0; i < n; i++)
    {
        if (pref == 0)
            pref = 1;
        if (suff == 0)
            suff = 1;

        pref = pref * arr[i];
        suff = suff * arr[n - i - 1];
        maxi_prod = max(maxi_prod, max(pref, suff));
    }
    return maxi_prod;
}

int nCr(int n, int r)
{
    long long res = 1;
    for (int i = 0; i < r; i++)
    {
        res = res * (n - i);
        res = res / (i + 1);
    }
    return res;
}

int pascalTriangle(int r, int c)
{
    int ans = nCr(r - 1, c - 1);
    return ans;
}

void pascalTriangle(int n)
{
    // printing the entire row n:
    // Brute force
    // for (int c = 1; c <= n; c++)
    // {
    //     cout << nCr(n - 1, c - 1) << " ";
    // }

    // Optimal Approach
    long long ans = 1;
    cout << ans << " ";

    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i);
        cout << ans << " ";
    }
}

vector<int> generateRow(int n)
{
    vector<int> temp;
    long long ans = 1;
    temp.push_back(ans);
    for (int i = 1; i < n; i++)
    {
        ans = ans * (n - i);
        ans = ans / (i);
        temp.push_back(ans);
    }
    return temp;
}
vector<vector<int>> AllpascalTriangle(int n)
{
    // Brute force approach
    // vector<vector<int>> ans;

    // for (int row = 1; row <= n; row++)
    // {
    //     vector<int> temp;
    //     for (int col = 1; col <= n; col++)
    //     {
    //         temp.push_back(nCr(row - 1, col - 1));
    //     }
    //     ans.push_back(temp);
    // }
    // return ans;

    // Optimal Approach
    vector<vector<int>> ans;

    // store the entire pascal's triangle:
    for (int row = 1; row <= n; row++)
    {
        ans.push_back(generateRow(row));
    }
    return ans;
}

void Reverse(int arr[], int start, int end)
{
    while (start <= end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void Rotatetoright(int arr[], int n, int k)
{
    // // Brute force
    // if (n == 0)
    //     return;
    // k = k % n;
    // if (k > n)
    //     return;
    // int temp[k];
    // for (int i = n - k; i < n; i++)
    // {
    //     temp[i - n + k] = arr[i];
    // }
    // for (int i = n - k - 1; i >= 0; i--)
    // {
    //     arr[i + k] = arr[i];
    // }
    // for (int i = 0; i < k; i++)
    // {
    //     arr[i] = temp[i];
    // }

    // Optimal Approach
    //  Reverse first n-k elements
    Reverse(arr, 0, n - k - 1);
    // Reverse last k elements
    Reverse(arr, n - k, n - 1);
    // Reverse whole array
    Reverse(arr, 0, n - 1);
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

    // vector<vector<int>> arr1 = {{1, 3}, {8, 10}, {2, 6}, {15, 18}};
    // vector<vector<int>> ans = mergeOverlappingIntervals(arr1);
    // cout << "The merged intervals are: " << "\n";
    // for (auto it : ans)
    // {
    //     cout << "[" << it[0] << ", " << it[1] << "] ";
    // }
    // cout << endl;

    // long long arr1[] = {1, 4, 8, 10};
    // long long arr2[] = {2, 3, 9};
    // int n = 4, m = 3;
    // merge(arr1, arr2, n, m);
    // cout << "The merged arrays are: " << "\n";
    // cout << "arr1[] = ";
    // for (int i = 0; i < n; i++)
    // {
    //     cout << arr1[i] << " ";
    // }
    // cout << "\narr2[] = ";
    // for (int i = 0; i < m; i++)
    // {
    //     cout << arr2[i] << " ";
    // }
    // cout << endl;

    // vector<int> nums = {1, 2, -3, 0, -4, -5};
    // cout << "The maximum product subarray: " << maxProductSubArray(nums);

    // int r = 5; // row number
    // int c = 3; // col number
    // int element = pascalTriangle(r, c);
    // cout << "The element at position (r,c) is: "
    //      << element;
    // int n = 5;
    // pascalTriangle(n);

    // int n = 5;
    // vector<vector<int>> ans = AllpascalTriangle(n);
    // for (auto it : ans)
    // {
    //     for (auto ele : it)
    //     {
    //         cout << ele << " ";
    //     }
    //     cout << "\n";
    // }

    int n = 7;
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int k = 2;
    Rotatetoright(arr, n, k);
    cout << "After Rotating the elements to right " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}