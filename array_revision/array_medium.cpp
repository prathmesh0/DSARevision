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
int maxProfit(vector<int> &arr)
{
    // Brute force
    int n = arr.size();
    // int max_prof = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[j] > arr[i])
    //         {
    //             max_prof = max(max_prof, arr[j] - arr[i]);
    //         }
    //     }
    // }
    // return max_prof;

    int mini = INT_MAX;
    int max_prof = 0;
    for (int i = 0; i < n; i++)
    {
        mini = min(mini, arr[i]);
        max_prof = max(max_prof, arr[i] - mini);
    }
    return max_prof;
}

vector<int> printLeadersBruteForce(vector<int> arr)
{
    int n = arr.size();
    vector<int> ans;

    // Brute force approach
    //  for (int i = 0; i < n; i++)
    //  {
    //      int flag = true;
    //      for (int j = i + 1; j < n; j++)
    //      {
    //          if (arr[i] <= arr[j])
    //          {
    //              flag = false;
    //          }
    //      }
    //      if (flag == true)
    //      {
    //          ans.push_back(arr[i]);
    //      }
    //  }
    //  return ans;

    // Optimal Approach
    int maxi = INT_MIN;
    for (int i = n - 1; i >= 0; i--)
    {
        if (arr[i] > maxi)
        {
            ans.push_back(arr[i]);
            maxi = arr[i];
        }
    }
    return ans;
}

int findAllSubarraysWithGivenSum(vector<int> &arr, int k)
{
    // int n = arr.size();
    // int count = 0;
    // for (int i = 0; i < n; i++)
    // {

    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         if (sum == k)
    //         {
    //             count++;
    //         }
    //     }
    // }
    // return count;

    // Optimal Approach
    int n = arr.size();
    map<int, int> mpp;
    int preSum = 0, cnt = 0;

    mpp[0] = 1;
    for (int i = 0; i < n; i++)
    {

        preSum += arr[i];

        int remove = preSum - k;

        cnt += mpp[remove];

        mpp[preSum] += 1;
    }
    return cnt;
}

vector<int> spiralOrder(vector<vector<int>> &matrix)
{
    int n = matrix.size();
    int m = matrix[0].size();
    vector<int> ans;
    int left = 0, right = m - 1, bottom = n - 1, top = 0;

    while (top <= bottom && left <= right)
    {
        // left->right
        for (int i = left; i <= right; i++)
        {
            ans.push_back(matrix[top][i]);
        }
        top++;
        // top->bottom
        for (int i = top; i <= bottom; i++)
        {
            ans.push_back(matrix[i][right]);
        }
        right--;

        if (top <= bottom)
        {
            // right->left
            for (int i = right; i >= left; i--)
            {
                ans.push_back(matrix[bottom][i]);
            }
            bottom--;
        }

        if (left <= right)
        {
            // bottom->top
            for (int i = bottom; i >= top; i--)
            {
                ans.push_back(matrix[i][left]);
            }
            left++;
        }
    }

    return ans;
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
    // cout << maxSubarraySum(arr);

    // vector<int> arr3 = {7, 1, 5, 3, 6, 4};
    // int maxPro = maxProfit(arr3);
    // cout << "Max profit is: " << maxPro << endl;

    // vector<int> arr4 = {10, 22, 12, 3, 0, 6};

    // vector<int> ans = printLeadersBruteForce(arr4);

    // for (int i = 0; i < ans.size(); i++)
    // {

    //     cout << ans[i] << " ";
    // }

    // vector<int> arr5 = {3, 1, 2, 4};
    // int k = 6;
    // int cnt = findAllSubarraysWithGivenSum(arr5, k);
    // cout << "The number of subarrays is: " << cnt << "\n";
    vector<vector<int>> mat{{1, 2, 3, 4},
                            {5, 6, 7, 8},
                            {9, 10, 11, 12},
                            {13, 14, 15, 16}};

    vector<int> ans = spiralOrder(mat);

    for (int i = 0; i < ans.size(); i++)
    {

        cout << ans[i] << " ";
    }

    cout << endl;

    return 0;
}