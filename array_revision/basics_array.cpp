#include <bits/stdc++.h>
using namespace std;

int largestElement(vector<int> &arr)
{
    int n = arr.size();
    // Brute force
    // sort(arr.begin(), arr.end());
    // return arr[n - 1];

    // Optimal Approach
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > maxi)
        {
            maxi = arr[i];
        }
    }
    return maxi;
}

int secondLargestElement(vector<int> &arr)
{
    // Brute force
    int n = arr.size();
    // sort(arr.begin(), arr.end());
    // return arr[n - 2];

    // Better Approach
    // int maxi = INT_MIN;
    // int s_maxi = INT_MIN;

    // for (int i = 0; i < n; i++)
    // {
    //     maxi = max(maxi, arr[i]);
    // }

    // for (int i = 0; i < n; i++)
    // {
    //     if (s_maxi < arr[i] && arr[i] != maxi)
    //     {
    //         s_maxi = arr[i];
    //     }
    // }
    // return s_maxi;

    // Optimal Aproach
    int largest = INT_MIN; // 12 44 5 55 22 1
    int s_largest = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            s_largest = largest;
            largest = arr[i];
        }
        else if (arr[i] > s_largest && arr[i] != largest)
        {
            s_largest = arr[i];
        }
    }
    return s_largest;
}

bool isSorted(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 1; i < n; i++)
    {
        if (arr[i] < arr[i - 1])
        {
            return false;
        }
    }
    return true;
}

int removeDuplicatesFromSorted(vector<int> &nums)
{
    // hashmap
    // vector<int> ans;
    // map<int, int> mpp;
    // for (auto it : nums)
    // {
    //     mpp[it]++;
    // }

    // for (auto it : mpp)
    // {
    //     ans.push_back(it.first);
    // }
    // for (int i = 0; i < ans.size(); i++)
    // {
    //     nums[i] = ans[i];
    // }
    // return ans.size();

    // set
    // set<int> st;
    // for (auto it : nums)
    // {
    //     st.insert(it);
    // }

    // int n = st.size();
    // int i = 0;
    // for (auto it : st)
    // {
    //     nums[i] = it;
    //     i++;
    // }
    // return n;

    int i = 0; // 1 2 2  2 3 3
    for (int j = 1; i < nums.size(); j++)
    {
        if (nums[i] != nums[j])
        {
            i++;
            nums[i] = nums[j];
        }
    }
    return (i + 1);
}

void leftRotateByOne(vector<int> &num1)
{
    // 1,2,3,4,5
    int n = num1.size();
    // brute force
    int temp = num1[0];
    for (int i = 1; i < n; i++)
    {
        num1[i - 1] = num1[i];
    }
    num1[n - 1] = temp;
}

void moveZeroToEnd(vector<int> &arr)
{
    int n = arr.size();
    // Brute force
    //  vector<int> ans(n, 0);
    //  int j = 0;
    //  for (int i = 0; i < n; i++)
    //  {
    //      if (arr[i] != 0)
    //      {
    //          ans[j] = arr[i];
    //          j++;
    //      }
    //  }
    //  j = 0;
    //  for (auto it : ans)
    //  {
    //      arr[j] = it;
    //      j++;
    //  }

    // Optimal
    int j = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == 0)
        {
            j = i;
            break;
        }
    }

    if (j == -1)
    {
        return;
    }

    for (int i = j + 1; i < n; i++)
    {
        if (arr[i] != 0)
        {
            swap(arr[i], arr[j]);
            j++;
        }
    }
}

int isPresent(vector<int> &num1, int key)
{
    int n = num1.size();
    for (int i = 0; i < n; i++)
    {
        if (num1[i] == key)
        {
            return i;
        }
    }
    return -1;
}

vector<int> findUnion(vector<int> &arr1, vector<int> &arr2)
{
    int n = arr1.size();
    int m = arr2.size();

    // set<int> st;
    // vector<int> ans;
    // for (int i = 0; i < n; i++)
    // {
    //     st.insert(arr1[i]);
    // }

    // for (int i = 0; i < m; i++)
    // {
    //     st.insert(arr2[i]);
    // }

    // for (auto it : st)
    // {
    //     ans.push_back(it);
    // }
    // return ans;

    // optimal approach
    int i = 0, j = 0;  // pointers
    vector<int> Union; // Uninon vector
    while (i < n && j < m)
    {
        if (arr1[i] <= arr2[j]) // Case 1 and 2
        {
            if (Union.size() == 0 || Union.back() != arr1[i])
                Union.push_back(arr1[i]);
            i++;
        }
        else // case 3
        {
            if (Union.size() == 0 || Union.back() != arr2[j])
                Union.push_back(arr2[j]);
            j++;
        }
    }
    while (i < n) // IF any element left in arr1
    {
        if (Union.back() != arr1[i])
            Union.push_back(arr1[i]);
        i++;
    }
    while (j < m) // If any elements left in arr2
    {
        if (Union.back() != arr2[j])
            Union.push_back(arr2[j]);
        j++;
    }
    return Union;
}

int missingNumber(vector<int> &arr)
{
    int n = arr.size();

    // Brute- force

    // for (int i = 0; i <= n; i++)
    // {
    //     int flag = 0;
    //     for (int j = 0; j < n; j++)
    //     {
    //         if (arr[j] == i)
    //         {
    //             flag = 1;
    //             break;
    //         }
    //     }
    //     if (flag == 0)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // better approach
    // vector<int> hash(n + 1, 0);
    // for (int i = 0; i < n; i++)
    // {
    //     hash[arr[i]]++;
    // }

    // for (int i = 0; i <= n; i++)
    // {
    //     if (hash[i] == 0)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Optimal Approach
    // int sum_n = n * (n + 1) / 2;
    // int sum_arr = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     sum_arr += arr[i];
    // }
    // return sum_n - sum_arr;

    // most optimal
    int xor1 = 0;
    int xor2 = 0;
    for (auto it : arr)
    {
        xor1 = xor1 ^ it;
    }

    for (int i = 0; i <= n; i++)
    {
        xor2 = xor2 ^ i;
    }
    return (xor1 ^ xor2);
}
int maximumConsecutiveOne(vector<int> &num)
{
    int n = num.size();
    int maxi_one = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {

        if (num[i] == 1)
        {
            count++;
        }
        else
        {
            maxi_one = max(maxi_one, count);
            count = 0;
        }
    }
    return maxi_one;
}
int main()
{
    vector<int> arr = {12, 44, 55, 222};
    // cout << largestElement(arr);
    // cout << secondLargestElement(arr);
    // if (isSorted(arr))
    // {
    //     cout << "Array is sorted" << endl;
    // }
    // else
    // {
    //     cout << "Array is not sorted" << endl;
    // }
    // vector<int> nums = {1, 2, 2, 3, 3, 3, 3, 4};
    // cout << removeDuplicatesFromSorted(nums) << endl;
    // for (auto it : nums)
    // {
    //     cout << it << " ";
    // }

    vector<int> num1 = {1, 0, 0, 3, 0, 4, 0, 5, 6};
    // leftRotateByOne(num1);
    // moveZeroToEnd(num1);
    // for (auto it : num1)
    // {
    //     cout << it << " ";
    // }
    int key = 16;
    // cout << isPresent(num1, key);
    // vector<int> arr1 = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    // vector<int> arr2 = {2, 3, 4, 4, 5, 11, 12};
    // vector<int> ans = findUnion(arr1, arr2);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    // vector<int> num2 = {0, 3, 1};
    // cout << missingNumber(num2);
    vector<int> num3 = {0, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 0, 1, 0};
    cout << maximumConsecutiveOne(num3);

    return 0;
}