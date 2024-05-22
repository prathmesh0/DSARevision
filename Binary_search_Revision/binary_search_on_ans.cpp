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
int main()
{
    vector<int> v = {7, 15, 6, 3};
    int h = 8;
    int ans = minimumRateToEatBananas(v, h);
    cout << "Koko should eat atleast " << ans << " bananas/hr.\n";
    return 0;
}