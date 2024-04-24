#include <bits/stdc++.h>
using namespace std;

bool twoSum(int n, vector<int> &arr, int target)
{
    // Brute force
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = i + 1; j < n; j++)
    //      {
    //          if (arr[i] + arr[j] == target)
    //          {
    //              return true;
    //          }
    //      }
    //  }
    //  return false;

    // Better  Approach
    // unordered_map<int, int> mpp;
    // for (int i = 0; i < n; i++)
    // {
    //     int num = arr[i];
    //     int moreNeeded = target - num;
    //     if (mpp.find(moreNeeded) != mpp.end())
    //     {
    //         return true;
    //     }
    //     mpp[num] = i;
    // }
    // return false;

    // Optimal Approach
    sort(arr.begin(), arr.end());
    int s = 0, e = n - 1;
    while (s < e)
    {
        if (arr[s] + arr[e] == target)
        {
            return true;
        }
        else if (arr[s] + arr[e] > target)
        {
            e--;
        }
        else
        {
            s++;
        }
    }
    return false;
}

void sortZeroOneTwo(vector<int> &nums)
{
    // brute force approach
    // sort(nums.begin(), nums.end());
    int n = nums.size();
    int countZero = 0;
    int countOne = 0;
    int countTwo = 0;
    for (int i = 0; i < n; i++)
    {
        if (nums[i] == 0)
        {
            countZero++;
        }
        else if (nums[i] == 1)
        {
            countOne++;
        }
        else
        {
            countTwo++;
        }
    }
    int i = 0;
    for (int j = 0; j < countZero; j++)
    {
        nums[i] = 0;
        i++;
    }
    for (int j = 0; j < countOne; j++)
    {
        nums[i] = 1;
        i++;
    }
    for (int j = 0; j < countTwo; j++)
    {
        nums[i] = 2;
        i++;
    }
}
int main()
{
    // int n = 5;
    // vector<int> arr = {2, 6, 5, 8, 11};
    // int target = 14;
    // // bool ans = twoSum(n, arr, target);
    // cout << "This is the answer for variant 1: " << ans << endl;
    vector<int> nums = {0, 0, 3, 1, 1, 3, 2, 2};

    sortZeroOneTwo(nums);
    for (auto it : nums)
    {
        cout << it << " ";
    }
    return 0;
}