#include <bits/stdc++.h>
using namespace std;

string removeOuterParentheses(string s)
{
    // int count = 0;
    // string ans = "";

    // for (int i = 0; i < s.length(); i++)
    // {
    //     if (s[i] == '(')
    //     {
    //         if (count > 0)
    //         {
    //             ans += s[i];
    //         }
    //         count++;
    //     }
    //     else
    //     {
    //         count--;
    //         if (count > 0)
    //         {
    //             ans += s[i];
    //         }
    //     }
    // }
    // return ans;

    // using stack
    stack<char> st;
    string ans = "";

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            if (!st.empty())
            {
                ans += s[i];
            }
            st.push(s[i]);
        }
        else
        {
            st.pop();

            if (!st.empty())
            {
                ans += s[i];
            }
        }
    }
    return ans;
}
string reverseWords(string s)
{
    // using stack
    //  stack<string> st;
    //  int n = s.size();
    //  string temp = " ";

    // // traverse the string
    // for (int i = 0; i < n; i++)
    // {
    //     if (s[i] == ' ' && temp != " ")
    //     {
    //         st.push(temp);
    //         temp = " ";
    //     }
    //     else if (s[i] != ' ')
    //     {
    //         temp += s[i];
    //     }
    // }
    // // last word
    // if (temp != " ")
    // {
    //     st.push(temp);
    // }

    // string str = " ";

    // while (!st.empty())
    // {
    //     str += st.top();
    //     st.pop();
    // }

    // // removing spaces from starting if exist
    // int index = 0;
    // while (str[index] == ' ')
    // {
    //     index++;
    // }

    // string ans = "";
    // for (int i = index; i < str.size(); i++)
    // {
    //     ans += str[i];
    // }

    // return ans;

    // using loop
    int n = s.size();
    string ans = "";
    int i = 0;

    while (i < n)
    {
        string temp = "";

        while (s[i] == ' ' && i < n)
        {
            i++;
        }

        while (s[i] != ' ' && i < n)
        {
            temp += s[i];
            i++;
        }

        if (temp.size() > 0)
        {
            if (ans.size() == 0)
            {
                ans = temp;
            }
            else
            {
                ans = temp + " " + ans;
            }
        }
    }
    return ans;
}
int main()
{

    // string test1 = "(()())(())";

    // cout << "Test 1: " << removeOuterParentheses(test1) << endl;

    string s = "  Hello   World!!   ";
    cout << reverseWords(s);

    return 0;
}
