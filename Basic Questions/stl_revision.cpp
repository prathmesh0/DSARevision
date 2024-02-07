#include <bits/stdc++.h>
#include <unordered_set>
using namespace std;

int main()
{
    pair<int, int> roll(12, 45);
    cout << roll.first << ":" << roll.second << endl;
    pair<int, int> clg(roll);
    cout << clg.first << ":" << clg.second << endl;

    // vector
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

    // deque
    deque<int> dq;
    dq.push_front(12);
    dq.push_front(43);
    dq.push_front(2);
    dq.push_back(22);
    dq.push_back(30);
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }
    cout << endl;
    if (dq.empty())
    {
        cout << "empty" << endl;
    }
    else
    {
        cout << "not empty" << endl;
    }

    dq.pop_back();
    for (auto it = dq.begin(); it != dq.end(); it++)
    {
        cout << *it << " ";
    }

    // queue
    queue<int> q;
    q.push(23);
    q.push(2);
    q.push(24);
    q.push(3);
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;
    q.push(24);
    q.push(3);
    q.pop();
    while (!q.empty())
    {
        cout << q.front() << " ";
        q.pop();
    }
    cout << endl;

    // stack
    stack<int> st;
    st.push(13);
    st.push(93);
    st.push(1);
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl; // 100 9 43
    st.push(43);
    st.push(9);
    st.push(100);
    st.pop();
    st.pop();
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    cout << endl;

    // max heap
    priority_queue<int> q1;
    q1.push(24);
    q1.push(4);
    q1.push(26);
    q1.push(34);
    priority_queue<int> q2(q1);
    while (!q1.empty())
    {
        cout << q1.top() << " ";
        q1.pop();
    }
    cout << endl;
    q2.pop();
    q2.pop();
    while (!q2.empty())
    {
        cout << q2.top() << " ";
        q2.pop();
    }
    cout << endl;

    // min heap
    priority_queue<int, vector<int>, greater<int>> w;
    w.push(24);
    w.push(4);
    w.push(26);
    w.push(34);

    while (!w.empty())
    {
        cout << w.top() << " ";
        w.pop();
    }
    cout << endl;

    // set
    set<int> st1;
    st1.insert(13);
    st1.insert(43);
    st1.insert(89);
    st1.insert(89);
    st1.insert(9);

    for (auto it : st1)
    {
        cout << it << " ";
    }
    cout << endl;
    st1.erase(43);
    for (auto it : st1)
    {
        cout << it << " ";
    }
    cout << endl;

    if (st1.find(89) != st1.end())
    {
        cout << "value is present" << endl;
    }

    // unordered set
    unordered_set<int> st2;
    st2.insert(56);
    st2.insert(5);
    st2.insert(59);
    st2.insert(1);
    for (auto it : st2)
    {
        cout << it << " ";
    }
    cout << endl;
    if (st2.find(56) != st2.end())
    {
        cout << "element is present" << endl;
    }
    cout << st2.size() << endl;

    // multiset
    multiset<int> st3;
    st3.insert(45);
    st3.insert(35);
    st3.insert(4);
    st3.insert(4);
    st3.insert(5);

    for (auto it : st3)
    {
        cout << it << " ";
    }

    // unoredered_multiset
    unordered_multiset<int> st4;
    st4.insert(56);
    st4.insert(56);
    st4.insert(5);
    st4.insert(90);
    for (auto it : st4)
    {
        cout << it << " ";
    }

    // map
    map<int, int> mpp;
    mpp.insert({1, 3});
    mpp.insert({8, 39});
    mpp.insert({10, 30});
    mpp.insert({10, 30});
    mpp.insert({6, 2});

    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    if (mpp.find(10) != mpp.end())
    {
        cout << "Value  is present" << endl;
    }

    mpp[50] = 90;
    for (auto it : mpp)
    {
        cout << it.first << " " << it.second << endl;
    }

    // unordered_map
    unordered_map<int, int> mp1;
    mp1.insert({45, 78});
    mp1.insert({5, 7});
    mp1.insert({4, 8});
    mp1.insert({4, 8});
    for (auto it : mp1)
    {
        cout << it.first << " " << it.second << endl;
    }

    if (mp1.find(5) != mp1.end())
    {
        cout << mp1[5] << endl;
    }

    // multimap
    multimap<int, int> mp2;
    mp2.insert({45, 78});
    mp2.insert({5, 7});
    mp2.insert({4, 8});
    mp2.insert({4, 8});
    for (auto it : mp2)
    {
        cout << it.first << " " << it.second << endl;
    }

    // unordered_multimap
    unordered_multimap<int, int> mp3;
    mp3.insert({45, 78});
    mp3.insert({5, 7});
    mp3.insert({4, 8});
    mp3.insert({4, 8});
    for (auto it : mp3)
    {
        cout << it.first << " " << it.second << endl;
    }

    return 0;
}