#include <bits/stdc++.h>
using namespace std;
int mod = 1e9 + 7;
vector<long long> nextLargerElementI(vector<long long> arr, int n)
{
    // vector<long long> nge(n, -1);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (arr[i] < arr[j])
    //         {
    //             nge[i] = arr[j];
    //             break;
    //         }
    //     }
    // }
    // return nge;

    // Optimal approach
    vector<long long> nge(n, -1);
    stack<long long> st;

    for (int i = n - 1; i >= 0; i--)
    {

        while (!st.empty() && st.top() <= arr[i])
        {
            st.pop();
        }
        if (st.empty())
        {
            nge[i] = -1;
        }
        else
        {
            nge[i] = st.top();
        }
        st.push(arr[i]);
    }

    return nge;
}
vector<int> nextGreaterElementII(int N, vector<int> &arr)
{
    // vector<int> nge(N, -1);

    // for (int i = 0; i < N; i++)
    // {

    //     for (int j = i + 1; j <= (i + N - 1); j++)
    //     {
    //         int ind = j % N;

    //         if (arr[i] < arr[ind])
    //         {
    //             nge[i] = arr[ind];
    //             break;
    //         }
    //     }
    // }
    // return nge;

    // Optimal approach
    vector<int> nge(N, -1);
    stack<int> st;

    for (int i = 2 * N - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[i % N] >= st.top())
        {
            st.pop();
        }
        if (i < N)
        {
            nge[i] = st.empty() ? -1 : st.top();
        }

        st.push(arr[i % N]);
    }
    return nge;
}

vector<int> leftSmaller(int n, int arr[])
{
    // vector<int> ans(n, -1);

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i - 1; j >= 0; j--)
    //     {
    //         if (arr[j] < arr[i])
    //         {
    //             ans[i] = arr[j];
    //             break;
    //         }
    //     }
    // }
    // return ans;

    // Optimal
    stack<int> st;
    vector<int> ans(n);

    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[i] <= st.top())
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(arr[i]);
    }
    return ans;
}
void helper(stack<int> &s, int n, int ind)
{

    if (ind == n / 2)
    {
        s.pop();
        return;
    }
    int x = s.top();
    s.pop();
    ind++;

    helper(s, n, ind);

    s.push(x);
}
void deleteMid(stack<int> &s, int sizeOfStack)
{

    // Brute force appraoch

    // stack<int>st;
    // int m = sizeOfStack/2;
    // int i = 0;

    // while(!s.empty()){
    //     st.push(s.top());
    //     s.pop();
    //     i++;

    //     if(i == m){
    //         s.pop();
    //     }

    // }

    // while(!st.empty()){
    //     s.push(st.top());
    //     st.pop();
    // }

    // Optimal approach

    helper(s, sizeOfStack, 0);
}

int trap(vector<int> &height)
{
    // Brute force approach
    //  int n = height.size();
    //  int trapeWater = 0;

    // for (int i = 0; i < n; i++)
    // {

    //     int j = i;
    //     int leftMax = 0, rightMax = 0;
    //     // left nearest maximum height
    //     while (j >= 0)
    //     {
    //         leftMax = max(leftMax, height[j]);
    //         j--;
    //     }
    //     j = i;
    //     // right nearest maximum height
    //     while (j < n)
    //     {
    //         rightMax = max(rightMax, height[j]);
    //         j++;
    //     }
    //     trapeWater += min(leftMax, rightMax) - height[i];
    // }
    // return trapeWater;

    // Better approach

    // int n = height.size();
    // vector<int> prefix(n, 0);
    // vector<int> suffix(n, 0);
    // int trapeWater = 0;

    // prefix[0] = height[0];
    // for (int i = 1; i < n; i++)
    // {
    //     prefix[i] = max(prefix[i - 1], height[i]);
    // }
    // suffix[n - 1] = height[n - 1];
    // for (int i = n - 2; i >= 0; i--)
    // {
    //     suffix[i] = max(suffix[i + 1], height[i]);
    // }

    // // calculate trape water
    // for (int i = 0; i < n; i++)
    // {
    //     trapeWater += min(prefix[i], suffix[i]) - height[i];
    // }
    // return trapeWater;

    // Optimal approach
    int n = height.size();
    int left = 0, right = n - 1;
    int maxLeft = 0, maxRight = 0;
    int res = 0;

    while (left <= right)
    {
        if (height[left] <= height[right])
        {
            if (height[left] >= maxLeft)
            {
                maxLeft = height[left];
            }
            else
            {
                res += maxLeft - height[left];
            }
            left++;
        }
        else
        {
            if (height[right] >= maxRight)
            {
                maxRight = height[right];
            }
            else
            {
                res += maxRight - height[right];
            }
            right--;
        }
    }
    return res;
}

vector<int> findNSE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && arr[st.top()] >= arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? n : st.top();
        st.push(i);
    }
    return ans;
}

vector<int> findPSEE(vector<int> &arr)
{
    int n = arr.size();
    vector<int> ans(n);
    stack<int> st;
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && arr[st.top()] > arr[i])
        {
            st.pop();
        }
        ans[i] = st.empty() ? -1 : st.top();
        st.push(i);
    }
    return ans;
}
int sumSubarrayMins(vector<int> &arr)
{
    // brute force approach
    //  long long sum = 0;
    //  int n = arr.size();
    //  for (int i = 0; i < n; i++)
    //  {
    //      int mini = arr[i];
    //      for (int j = i; j < n; j++)
    //      {
    //          mini = min(mini, arr[j]);
    //          sum = (sum + mini) % mod;
    //      }
    //  }
    //  return sum;

    // optimal approach
    int n = arr.size();
    vector<int> nse = findNSE(arr);
    vector<int> pse = findPSEE(arr);
    long long total = 0;

    for (int i = 0; i < n; i++)
    {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        total = (total + ((right * left % mod) * arr[i] % mod)) % mod;
    }
    return (int)total;
}

// long long subArrayRanges(vector<int> &nums)
// {
//     long long ans = 0;
//     int n = nums.size();
//     for (int i = 0; i < n; i++)
//     {
//         int mini = nums[i];
//         int maxi = nums[i];
//         for (int j = i + 1; j < n; j++)
//         {
//             mini = min(mini, nums[j]);
//             maxi = max(maxi, nums[j]);
//             ans += (long long)(maxi - mini);
//         }
//     }
//     return ans;
// }

vector<int> NSE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> nse(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] >= nums[i])
        {
            st.pop();
        }
        nse[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return nse;
}

vector<int> PSE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> pse(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] > nums[i])
        {
            st.pop();
        }
        pse[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return pse;
}

vector<int> NGE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> nge(n, 0);
    for (int i = n - 1; i >= 0; i--)
    {
        while (!st.empty() && nums[st.top()] <= nums[i])
        {
            st.pop();
        }
        nge[i] = st.empty() ? n : st.top();

        st.push(i);
    }
    return nge;
}

vector<int> PGE(vector<int> &nums)
{
    stack<int> st;
    int n = nums.size();
    vector<int> pge(n, 0);
    for (int i = 0; i < n; i++)
    {
        while (!st.empty() && nums[st.top()] < nums[i])
        {
            st.pop();
        }
        pge[i] = st.empty() ? -1 : st.top();

        st.push(i);
    }
    return pge;
}
long long subArrayRanges(vector<int> &nums)
{
    long long sum = 0;
    int n = nums.size();
    vector<int> nse = NSE(nums);
    vector<int> pse = PSE(nums);
    vector<int> nge = NGE(nums);
    vector<int> pge = PGE(nums);
    long long largest = 0, smallest = 0;
    for (int i = 0; i < n; i++)
    {
        long long left = i - pse[i];
        long long right = nse[i] - i;
        long long left1 = i - pge[i];
        long long right1 = nge[i] - i;
        largest += (left * right * nums[i]);
        smallest += (left1 * right1 * nums[i]);
    }

    return abs(largest - smallest);
}
int main()
{
    vector<int> arr1 = {1, 2, 3, 4, 3};
    vector<long long> arr2 = {1, 2, 3, 4, 3};

    vector<int> ans1 = nextGreaterElementII(arr1.size(), arr1);
    vector<long long> ans2 = nextLargerElementI(arr2, arr2.size());

    cout << "Next Greater Elements for Circular Array: ";
    for (int val : ans1)
    {
        cout << val << " ";
    }
    cout << endl;

    cout << "Next Greater Elements for Linear Array: ";
    for (long long val : ans2)
    {
        cout << val << " ";
    }
    cout << endl;

    int arr[] = {4, 5, 2, 10, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    vector<int> result = leftSmaller(n, arr);
    for (int val : result)
    {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}