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
vector<int> RearrangebySign(vector<int> &arr)
{

    // variation 1- Brute force
    int n = arr.size();
    // vector<int> pos;
    // vector<int> neg;

    // for (auto it : arr)
    // {
    //     if (it < 0)
    //     {
    //         neg.push_back(it);
    //     }
    //     else
    //     {
    //         pos.push_back(it);
    //     }
    // }
    // for (int i = 0; i < n / 2; i++)
    // {
    //     arr[i * 2] = pos[i];
    //     arr[i * 2 + 1] = neg[i];
    // }
    // return arr;

    // optimal approch
    // vector<int> ans(n, 0);
    // int posInd = 0, negInd = 1;

    // for (int i = 0; i < n; i++)
    // {
    //     if (arr[i] < 0)
    //     {
    //         ans[negInd] = arr[i];
    //         negInd += 2;
    //     }

    //     else
    //     {
    //         ans[posInd] = arr[i];
    //         posInd += 2;
    //     }
    // }
    // return ans;

    // variety 2 -> Optimal
    vector<int> pos;
    vector<int> neg;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] < 0)
        {
            neg.push_back(arr[i]);
        }
        else
        {
            pos.push_back(arr[i]);
        }
    }

    // If positives are lesser than the negatives.
    if (pos.size() < neg.size())
    {
        for (int i = 0; i < pos.size(); i++)
        {
            arr[i * 2] = pos[i];
            arr[i * 2 + 1] = neg[i];
        }
        int index = pos.size() * 2;
        for (int i = pos.size(); i < neg.size(); i++)
        {
            arr[index] = neg[i];
            index++;
        }
    }

    else
    {
        for (int i = 0; i < neg.size(); i++)
        {
            arr[i * 2] = pos[i];
            arr[i * 2 + 1] = neg[i];
        }
        int index = neg.size() * 2;
        for (int i = neg.size(); i < pos.size(); i++)
        {
            arr[index] = pos[i];
            index++;
        }
    }
    return arr;
}

bool linearSearch(vector<int> &arr, int x)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == x)
        {
            return true;
        }
    }
    return false;
}
int longestSuccessiveElements(vector<int> &arr)
{
    // Brute force approach
    int n = arr.size();
    // int longest_count = 0;
    // for (int i = 0; i < n; i++)
    // {

    //     int x = arr[i];
    //     int count = 1;

    //     while (linearSearch(arr, x + 1) == true)
    //     {
    //         x = x + 1;
    //         count++;
    //     }
    //     longest_count = max(longest_count, count);
    // }
    // return longest_count;

    // Better Approach
    sort(arr.begin(), arr.end());
    int longest = 1;
    int count = 0;
    int last_smaller = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] - 1 == last_smaller)
        {
            count++;
            last_smaller = arr[i];
        }

        else if (arr[i] - 1 != last_smaller)
        {
            count = 1;
            last_smaller = arr[i];
        }
        longest = max(longest, count);
    }
    return longest;
}

int maxSubarraySum1(vector<int> &arr)
{
    // Brute force
    int n = arr.size();

    // int maxi_sum = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         int sum = 0;
    //         for (int k = i; k <= j; k++)
    //         {
    //             sum += arr[k];
    //         }
    //         maxi_sum = max(maxi_sum, sum);
    //     }
    // }
    // return maxi_sum;

    // better approach

    // for (int i = 0; i < n; i++)
    // {

    //     int sum = 0;
    //     for (int j = i; j < n; j++)
    //     {
    //         sum += arr[j];
    //         maxi_sum = max(maxi_sum, sum);
    //     }
    // }
    // return maxi_sum;

    // Optimal Approach
    // long long maxi_sum = LONG_MIN;
    // long long sum = 0;

    // for (int i = 0; i < n; i++)
    // {
    //     sum += arr[i];
    //     if (sum > maxi_sum)
    //     {
    //         maxi_sum = sum;
    //     }
    //     if (sum < 0)
    //     {
    //         sum = 0;
    //     }
    // }
    // return maxi_sum;

    // follow up question
    long long maxi_sum = LONG_MIN;
    long long sum = 0;
    int start = 0;
    int startInd = -1, endInd = -1;

    for (int i = 0; i < n; i++)
    {
        if (sum == 0)
        {
            start = i;
        }
        sum += arr[i];
        if (sum > maxi_sum)
        {
            maxi_sum = sum;
            startInd = start;
            endInd = i;
        }
        if (sum < 0)
        {
            sum = 0;
        }
    }

    for (int i = startInd; i <= endInd; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return maxi_sum;
}

vector<int> nextGreaterPermutation(vector<int> &A)
{
    int n = A.size(); // size of the array.

    // Step 1: Find the break point:
    int ind = -1; // break point
    for (int i = n - 2; i >= 0; i--)
    {
        if (A[i] < A[i + 1])
        {
            // index i is the break point
            ind = i;
            break;
        }
    }

    // If break point does not exist:
    if (ind == -1)
    {
        // reverse the whole array:
        reverse(A.begin(), A.end());
        return A;
    }

    // Step 2: Find the next greater element
    //         and swap it with arr[ind]:

    for (int i = n - 1; i > ind; i--)
    {
        if (A[i] > A[ind])
        {
            swap(A[i], A[ind]);
            break;
        }
    }

    // Step 3: reverse the right half:
    reverse(A.begin() + ind + 1, A.end());

    return A;
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

    // vector<int> A{1, 2, -4, -5, 99, 9};

    // vector<int> ans = RearrangebySign(A);

    // for (int i = 0; i < ans.size(); i++)
    // {
    //     cout << ans[i] << " ";
    // }

    // vector<int> a = {100, 200, 1, 2, 3, 4};
    // int ans = longestSuccessiveElements(a);
    // cout << "The longest consecutive sequence is " << ans << "\n";

    // vector<vector<int>> mat{{1, 2, 3, 4},
    //                         {5, 6, 7, 8},
    //                         {9, 10, 11, 12},
    //                         {13, 14, 15, 16}};

    // vector<int> ans = spiralOrder(mat);

    // for (int i = 0; i < ans.size(); i++)
    // {

    //     cout << ans[i] << " ";
    // }

    // cout << endl;

    // vector<int> arr6 = {-2, 1, -3, 4, -1, 2, 1, -5, 4};

    // int maxSum = maxSubarraySum1(arr6);
    // cout << "The maximum subarray sum is: " << maxSum << endl;

    vector<int> arr7 = {2, 1, 5, 4, 3, 0, 0};

    // next_permutation(arr7.begin(), arr7.end()); // using in-built function of C++
    // cout << arr7[0] << " " << arr7[1] << " " << arr7[2];

    vector<int> ans = nextGreaterPermutation(arr7);

    cout << "The next permutation is: [";
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << "]\n";

    return 0;
}