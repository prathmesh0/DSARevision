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

    vector<int> num1 = {1, 3, 4, 5, 6};
    leftRotateByOne(num1);
    for (auto it : num1)
    {
        cout << it << " ";
    }

    return 0;
}