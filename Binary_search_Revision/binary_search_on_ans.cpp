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

    // LS
    //  int low = *max_element(boards.begin(), boards.end());
    //  int high = accumulate(boards.begin(), boards.end(), 0);

    // for (int time = low; time <= high; time++)
    // {
    //     if (countPainters(boards, time) <= k)
    //     {
    //         return time;
    //     }
    // }
    // return low;

    // Bs
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

bool canWePlace(vector<int> &stalls, int dist, int k)
{
    int n = stalls.size();
    int countCows = 1;
    int last = stalls[0];
    for (int i = 1; i < n; i++)
    {
        if (stalls[i] - last >= dist)
        {
            countCows++;
            last = stalls[i];
        }
    }
    if (countCows >= k)
    {
        return true;
    }
    return false;
}
int aggressiveCows(vector<int> &stalls, int k)
{
    int n = stalls.size();
    sort(stalls.begin(), stalls.end());
    int limit = stalls[n - 1] - stalls[0];

    // LS
    //  for (int i = 1; i <= limit; i++)
    //  {
    //      if (canWePlace(stalls, i, k) == false)
    //      {
    //          return (i - 1);
    //      }
    //  }
    //  return limit;

    // BS
    int s = 1, e = limit;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (canWePlace(stalls, mid, k))
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return e;
}

double median(vector<int> &a, vector<int> &b)
{
    // Brute force approach
    // int n1 = a.size(), n2 = b.size();

    // vector<int> arr3;

    // int i = 0, j = 0;
    // while (i < n1 && j < n2)
    // {
    //     if (a[i] < b[j])
    //         arr3.push_back(a[i++]);
    //     else
    //         arr3.push_back(b[j++]);
    // }

    // while (i < n1)
    //     arr3.push_back(a[i++]);
    // while (j < n2)
    //     arr3.push_back(b[j++]);

    // int n = n1 + n2;
    // if (n % 2 == 1)
    // {
    //     return (double)arr3[n / 2];
    // }

    // double median = ((double)arr3[n / 2] + (double)arr3[(n / 2) - 1]) / 2.0;
    // return median;

    // Optimal Approach
    // int n1 = a.size(), n2 = b.size();
    // int n = n1 + n2; // total size

    // int ind2 = n / 2;
    // int ind1 = ind2 - 1;
    // int cnt = 0;
    // int ind1el = -1, ind2el = -1;

    // int i = 0, j = 0;
    // while (i < n1 && j < n2)
    // {
    //     if (a[i] < b[j])
    //     {
    //         if (cnt == ind1)
    //             ind1el = a[i];
    //         if (cnt == ind2)
    //             ind2el = a[i];
    //         cnt++;
    //         i++;
    //     }
    //     else
    //     {
    //         if (cnt == ind1)
    //             ind1el = b[j];
    //         if (cnt == ind2)
    //             ind2el = b[j];
    //         cnt++;
    //         j++;
    //     }
    // }

    // while (i < n1)
    // {
    //     if (cnt == ind1)
    //         ind1el = a[i];
    //     if (cnt == ind2)
    //         ind2el = a[i];
    //     cnt++;
    //     i++;
    // }
    // while (j < n2)
    // {
    //     if (cnt == ind1)
    //         ind1el = b[j];
    //     if (cnt == ind2)
    //         ind2el = b[j];
    //     cnt++;
    //     j++;
    // }

    // if (n % 2 == 1)
    // {
    //     return (double)ind2el;
    // }

    // return (double)((double)(ind1el + ind2el)) / 2.0;

    // Optimal Approach using BS
    int n1 = a.size(), n2 = b.size();

    if (n1 > n2)
        return median(b, a);

    int n = n1 + n2;              // total length
    int left = (n1 + n2 + 1) / 2; // length of left half

    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;

        // calculate l1, l2, r1 and r2;
        int l1 = INT_MIN, l2 = INT_MIN;
        int r1 = INT_MAX, r2 = INT_MAX;
        if (mid1 < n1)
            r1 = a[mid1];
        if (mid2 < n2)
            r2 = b[mid2];
        if (mid1 - 1 >= 0)
            l1 = a[mid1 - 1];
        if (mid2 - 1 >= 0)
            l2 = b[mid2 - 1];

        if (l1 <= r2 && l2 <= r1)
        {
            if (n % 2 == 1)
                return max(l1, l2);
            else
                return ((double)(max(l1, l2) + min(r1, r2))) / 2.0;
        }

        else if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int countStudents(vector<int> arr, int pages)
{
    int countStudent = 1;
    int n = arr.size();
    long long pagesStudent = 0;
    for (int i = 0; i < n; i++)
    {
        if (pagesStudent + arr[i] <= pages)
        {
            pagesStudent += arr[i];
        }
        else
        {
            countStudent++;
            pagesStudent = arr[i];
        }
    }
    return countStudent;
}
int findPages(vector<int> arr, int n, int m)
{
    if (m > n)
        return -1;
    int sum = 0;
    int maxi = INT_MIN;

    for (int i = 0; i < n; i++)
    {
        maxi = max(maxi, arr[i]);
        sum += arr[i];
    }
    // Brute force
    //  for (int i = maxi; i <= sum; i++)
    //  {
    //      int countStu = countStudents(arr, i);
    //      if (countStu == m)
    //      {
    //          return i;
    //      }
    //  }
    //  return maxi;

    // Binary Search

    int s = maxi, e = sum;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (countStudents(arr, mid) > m)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
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

    // vector<int> stalls = {0, 3, 4, 7, 10, 9};
    // int k = 4;
    // int ans = aggressiveCows(stalls, k);
    // cout << "The maximum possible minimum distance is: " << ans << "\n";

    // vector<int> boards = {10, 20, 30, 40};
    // int k = 2;
    // int ans = findLargestMinDistance(boards, k);
    // cout << "The answer is: " << ans << "\n";

    vector<int> arr = {25, 46, 28, 49, 24};
    int n = 5;
    int m = 4;
    int ans = findPages(arr, n, m);
    cout << "The answer is: " << ans << "\n";

    // vector<int> a = {1, 4, 7, 10, 12};
    // vector<int> b = {2, 3, 6, 15};
    // cout << "The median of two sorted array is " << fixed << setprecision(1)
    //      << median(a, b) << '\n';

    return 0;
}