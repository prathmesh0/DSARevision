#include <bits/stdc++.h>
using namespace std;

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