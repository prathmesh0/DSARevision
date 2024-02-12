#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int arr[5] = {12, 23, 4, 10, 10};
    // int mpp[25] = {0};
    // // prefetch
    // for (int i = 0; i < 5; i++)
    // {
    //     mpp[arr[i]]++;
    // }
    // // fetch
    // int q;
    // cin >> q;
    // while (q--)
    // {
    //     int num;
    //     cin>>num;
    //     cout << mpp[num] << endl;
    // }

    // character hasing

    // string s;
    // cin >> s;

    // int hashmap[26] = {0};

    // for (int i = 0; i < s.length(); i++)
    // {
    //     hashmap[s[i] - 'a']++;
    // }

    // int qu;
    // cin >> qu;
    // while (qu--)
    // {
    //     char ch;
    //     cin >> ch;
    //     cout << hashmap[ch - 'a'] << endl;
    // }

    // using map or unordered_map
    int num[10] = {12, 22, 44, 5, 55, 1, 22, 77, 8};

    unordered_map<int, int> mpp1;
    for (int i = 0; i < 10; i++)
    {
        mpp1[num[i]]++;
    }

    for (auto it : mpp1)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}