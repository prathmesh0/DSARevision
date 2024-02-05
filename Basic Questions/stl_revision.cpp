#include <bits/stdc++.h>
using namespace std;

int main()
{
    // pair<int, int> roll(12, 45);
    // cout << roll.first << ":" << roll.second << endl;
    // pair<int, int> clg(roll);
    // cout << clg.first << ":" << clg.second << endl;

    vector<int> v = {1, 24, 555, 5};
    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    v.push_back(23);
    v.push_back(93);
    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    v.pop_back();

    for (auto it : v)
    {
        cout << it << " ";
    }
    cout << endl;
    if (v.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << " not empty" << endl;
    }
    v.erase(v.begin() + 2);
    for (auto it : v)
    {
        cout << it << " ";
    }
    v.clear();
    for (auto it : v)
    {
        cout << it << " ";
    }
    return 0;
}