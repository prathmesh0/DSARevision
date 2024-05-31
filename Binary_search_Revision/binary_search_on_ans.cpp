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
int sumByD(vector<int> &arr, int div)
{
    int sum = 0;
    for (int i = 0; i < arr.size(); i++)
    {
        sum += ceil(double(arr[i]) / (double)div);
    }
    return sum;
}
int smallestDivisor(vector<int> &arr, int limit)
{

    // Brute force approach
    int n = arr.size();
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
    }

    // for (int i = 1; i <= maxi; i++)
    // {
    //     if (sumByD(arr, i) <= limit)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // Binary search approach
    int s = 1, e = maxi;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (sumByD(arr, mid) <= limit)
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

int countPainters(vector<int> &boards, int time)
{
    int n = boards.size(); // size of array.
    int painters = 1;
    long long boardsPainter = 0;
    for (int i = 0; i < n; i++)
    {
        if (boardsPainter + boards[i] <= time)
        {
            // allocate board to current painter
            boardsPainter += boards[i];
        }
        else
        {
            // allocate board to next painter
            painters++;
            boardsPainter = boards[i];
        }
    }
    return painters;
}

int findLargestMinDistance(vector<int> &boards, int k)
{

    //LS
    // int low = *max_element(boards.begin(), boards.end());
    // int high = accumulate(boards.begin(), boards.end(), 0);

    // for (int time = low; time <= high; time++)
    // {
    //     if (countPainters(boards, time) <= k)
    //     {
    //         return time;
    //     }
    // }
    // return low;


    //Bs
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if (painters > k)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return low;
}
int main()
{
    // vector<int> v = {7, 15, 6, 3};
    // int h = 8;
    // int ans = minimumRateToEatBananas(v, h);
    // cout << "Koko should eat atleast " << ans << " bananas/hr.\n";

    // vector<int> arr = {7, 7, 7, 7, 13, 11, 12, 7};
    // int k = 3;
    // int m = 2;
    // int ans = roseGarden(arr, k, m);
    // if (ans == -1)
    //     cout << "We cannot make m bouquets.\n";
    // else
    //     cout << "We can make bouquets on day " << ans << "\n";

    // vector<int> arr = {1, 2, 3, 4, 5};
    // int limit = 8;
    // int ans = smallestDivisor(arr, limit);
    // cout << "The minimum divisor is: " << ans << "\n";

    vector<int> boards = {10, 20, 30, 40};
    int k = 2;
    int ans = findLargestMinDistance(boards, k);
    cout << "The answer is: " << ans << "\n";

    return 0;
}