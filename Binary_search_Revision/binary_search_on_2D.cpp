#include <bits/stdc++.h>
using namespace std;

int count1inRow(vector<int> arr, int m)
{
    int s = 0, e = m - 1;
    int ans = m;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] >= 1)
        {
            ans = mid;
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    return ans;
}

int rowWithMax1s(vector<vector<int>> arr, int n, int m)
{

    // Linear Traversal
    //  int maxi = 0;
    //  int ans = -1;

    // for (int i = 0; i < n; i++)
    // {
    //     int count = 0;
    //     for (int j = 0; j < m; j++)
    //     {
    //         count += arr[i][j];
    //     }
    //     if (count > maxi)
    //     {
    //         maxi = count;
    //         ans = i;
    //     }
    // }
    // return ans;

    // Binary Search
    int maxi = 0;
    int ans = -1;

    for (int i = 0; i < n; i++)
    {
        int count = m - count1inRow(arr[i], m);

        if (count > maxi)
        {
            maxi = count;
            ans = i;
        }
    }
    return ans;
}

bool binarySearch(vector<int> &arr, int target, int m)
{
    int s = 0, e = m - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        if (arr[mid] == target)
            return true;
        else if (arr[mid] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}
bool searchMatrix(vector<vector<int>> &matrix, int target)
{
    int n = matrix.size(), m = matrix[0].size();

    // traverse the matrix:

    // Brute force approach
    //  for (int i = 0; i < n; i++)
    //  {
    //      for (int j = 0; j < m; j++)
    //      {
    //          if (matrix[i][j] == target)
    //              return true;
    //      }
    //  }
    //  return false;

    // Better Approach

    // for (int i = 0; i < n; i++)
    // {
    //     // if (binarySearch(matrix[i], target, m) == true)
    //     // {
    //     //     return true;
    //     // }

    //     if (matrix[i][0] <= target && matrix[i][m - 1] >= target)
    //     {
    //         return binarySearch(matrix[i], target, m);
    //     }
    // }
    // return false;

    // Optimal Approach

    int s = 0, e = (m * n) - 1;
    while (s <= e)
    {
        int mid = s + (e - s) / 2;
        int row = mid / m;
        int col = mid % m;

        if (matrix[row][col] == target)
        {
            return true;
        }
        else if (matrix[row][col] < target)
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }
    return false;
}
bool searchElement1(vector<vector<int>> &arr, int target)
{
    // brute force approach
    int n = arr.size();
    int m = arr[0].size();

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (arr[i][j] == target)
    //         {
    //             return true;
    //         }
    //     }
    // }
    // return false;

    // better appraoch = O(n*Log(m))

    // for (int i = 0; i < n; i++)
    // {
    //     if (binarySearch(arr[i], target, m) == true)
    //     {
    //         return true;
    //     }
    // }
    // return false;

    // Optimal Approach
    int row = 0, col = m - 1;

    while (row < n && col >= 0)
    {
        if (arr[row][col] == target)
        {
            return true;
        }
        else if (arr[row][col] < target)
        {
            row++;
        }
        else
        {
            col--;
        }
    }

    return false;
}

bool isPeak(vector<vector<int>> &mat, int i, int j)
{
    int n = mat.size();
    int m = mat[0].size();

    if (i > 0 && mat[i][j] < mat[i - 1][j])
        return false;
    if (i < n - 1 && mat[i][j] < mat[i + 1][j])
        return false;
    if (j > 0 && mat[i][j] < mat[i][j - 1])
        return false;
    if (j < m - 1 && mat[i][j] < mat[i][j + 1])
        return false;

    return true;
}

vector<int> findPeakGrid(vector<vector<int>> &mat)
{
    int n = mat.size();
    int m = mat[0].size();

    // Brute force appraoch
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         if (isPeak(mat, i, j))
    //         {
    //             return {i, j};
    //         }
    //     }
    // }
    // return {-1, -1};

    // Better
    int n = mat.size();
    int m = mat[0].size();
    int maxi = INT_MIN;
    int row = -1, col = -1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] > maxi)
            {
                maxi = mat[i][j];
                row = i;
                col = j;
            }
        }
    }

    return {row, col};
}
int main()
{
    // vector<vector<int>> matrix = {{1, 1, 1}, {0, 0, 1}, {0, 0, 0}};
    // int n = 3, m = 3;
    // cout << "The row with maximum no. of 1's is: " << rowWithMax1s(matrix, n, m) << '\n';

    // vector<vector<int>> matrix = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    // searchMatrix(matrix, 8) == true ? cout << "true\n" : cout << "false\n";

    // vector<vector<int>> matrix = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    // searchElement1(matrix, 8) == true ? cout << "true\n" : cout << "false\n";

    vector<vector<int>> mat = {
        {1, 4, 3},
        {6, 5, 2},
        {7, 8, 9}};

    vector<int> peak = findPeakGrid(mat);
    cout << "Peak element found at: (" << peak[0] << ", " << peak[1] << ")" << endl;

    return 0;
}