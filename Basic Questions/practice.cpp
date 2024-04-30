#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int n1, n2;
    // cin >> n1 >> n2;
    // cout << n1 << " " << n2;
    // int n;
    // cin >> n;
    // vector<int> arr(n);
    // for (int i = 0; i < n; i++)
    // {
    //     int num;
    //     cin >> num;
    //     arr[i] = num;
    // }

    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    string name;
    // cin >> name;
    getline(cin, name);
    cout << name << endl;
    for (int i = 0; i < name.length(); i++)
    {
        cout << name[i];
    }
    return 0;
}