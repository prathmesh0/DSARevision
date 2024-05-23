#include <bits/stdc++.h>
using namespace std;

int calculateTotalHours(vector<int> &arr, int hourly)
{
    int totalHr = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        totalHr += ceil((double(arr[i])) / double(hourly));
    }
    return totalHr;
}
int minimumRateToEatBananas(vector<int> arr, int h)
{

    // Brute Force approach
    // int n = arr.size();
    // int maxi = INT_MIN;
    // for (int i = 0; i < n; i++)
    // {
    //     maxi = max(maxi, arr[i]);
    // }

    // for (int i = 1; i <= maxi; i++)
    // {
    //     int totalHr = calculateTotalHours(arr, i);
    //     if (totalHr <= h)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Optimal approach
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    int s = 1, e = maxi;

    while (s <= e)
    {
        int mid = s + (e - s) / 2;

        int totalHr = calculateTotalHours(arr, mid);
        if (totalHr <= h)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}

int isPossible(vector<int> &arr, int day, int k, int m)
{
    int n = arr.size();
    int count = 0, noOfB = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] <= day)
        {
            count++;
        }
        else
        {
            noOfB += (count / k);
            count = 0;
        }
    }
    noOfB += (count / k);

    return noOfB >= m;
}
int roseGarden(vector<int> &arr, int k, int m)
{
    int n = arr.size();
    if (k * m > n)
    {
        return -1;
    }
    int maxi = INT_MIN, mini = INT_MAX;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        mini = min(mini, arr[i]);
    }

    // Brute force - //O(n)+O(maxi-mini+1)*n

    // for (int i = mini; i <= maxi; i++)
    // {
    //     if (isPossible(arr, i, k, m))
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Binary Search appraoch - O(n)+Olog(maxi-mini+1)O(n)
    int s = mini, e = maxi;
    // int ans = -1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (isPossible(arr, mid, k, m))
        {
            // ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return s;
}
int main()
{
    // vector<int> v = {7, 15, 6, 3};
    // int h = 8;
    // int ans = minimumRateToEatBananas(v, h);
    // cout << "Koko should eat atleast " << ans << " bananas/hr.\n";

    vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    int k = 3;
    int m = 2;
    int ans = roseGarden(arr, k, m);
    if (ans == -1)
        cout << "We cannot make m bouquets.\n";
    else
        cout << "We can make bouquets on day " << ans << "\n";
    return 0;
}