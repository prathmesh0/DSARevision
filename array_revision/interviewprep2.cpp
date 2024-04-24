#include <bits/stdc++.h>
using namespace std;

void bubbleSort(vector<int> &arr1)

{
    int n = arr1.size();
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr1[j] > arr1[j + 1])
            {
                swap(arr1[j], arr1[j + 1]);
            }
        }
    }
}
void selectionSort(vector<int> &arr)
{
    int n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
        }
        if (i != min)
            swap(arr[i], arr[min]);
    }
}

int main()
{
    vector<int> arr = {1, 44, 2, 11, 4, 45, 6};
    selectionSort(arr);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    vector<int> arr1 = {1, 44, 2, 11, 4, 45, 6};
    bubbleSort(arr1);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}