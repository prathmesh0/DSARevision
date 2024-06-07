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

string largestOddNumber(string num)
{
    // brute force
    //  check the code again
    //   int n = num.size();
    //   string ans = "";

    // for (int i = 0; i < n; i++)
    // {
    //     string temp = "";
    //     for (int j = i; j < n; j++)
    //     {
    //         temp += num[j];
    //         if ((temp.back() - '0') % 2 == 1)
    //         {
    //             if (ans.empty() || temp > ans)
    //             {
    //                 ans = temp;
    //             }
    //         }
    //     }
    // }
    // return ans;

    // Optimal approach
    int n = num.length();

    for (int i = n - 1; i >= 0; i--)
    {
        if ((num[i] - '0') % 2 == 1)
        {
            string ans = num.substr(0, i + 1);
            return ans;
        }
    }
    return "";
}
string longestCommonPrefix(vector<string> &strs)
{
    // brute force
    //  string ans;
    //  for (int i = 0; i < strs[0].size(); i++)
    //  {
    //      for (int j = 1; j < strs.size(); j++)
    //      {
    //          if (strs[0][i] != strs[j][i])
    //          {
    //              return ans;
    //          }
    //      }
    //      ans += strs[0][i];
    //  }
    //  return ans;

    // optimal approach

    string ans = "";
    int x = strs.size();
    sort(strs.begin(), strs.end());

    string first = strs[0];
    string last = strs[x - 1];
    int n = first.length(), m = last.length();
    for (int i = 0; i < min(n, m); i++)
    {
        if (first[i] != last[i])
        {
            return ans;
        }
        ans += first[i];
    }
    return ans;
}

bool isIsomorphic(string s, string t)
{
    //Brute force
    // if (s.length() != t.length())
    //     return false;

    // for (int i = 0; i < s.length(); i++)
    // {
    //     for (int j = 0; j < s.length(); j++)
    //     {
    //         if (((s[i] == s[j]) && (t[i] != t[j])) || ((s[i] != s[j]) && (t[i] == t[j])))
    //         {
    //             return false;
    //         }
    //     }
    // }
    // return true;

    //optimal approach
    if (s.length() != t.length())
        return false;
    unordered_map<char, char> mp1, mp2;

    for (int i = 0; i < s.size(); i++)
    {
        if (mp1.find(s[i]) != mp1.end())
        {
            if (mp1[s[i]] != t[i])
            {
                return false;
            }
        }
        else if (mp2.find(t[i]) != mp2.end())
        {
            if (mp2[t[i]] != s[i])
            {
                return false;
            }
        }
        else
        {
            mp1[s[i]] = t[i];
            mp2[t[i]] = s[i];
        }
    }
    return true;

    
}
int main()
{

    // string test1 = "(()())(())";

    // cout << "Test 1: " << removeOuterParentheses(test1) << endl;

    // string s = "  Hello   World!!   ";
    // cout << reverseWords(s);

    // string test3 = "35427";
    // cout << "Test 3: " << largestOddNumber(test3) << endl;
    // vector<string> s = {"flower", "flow", "flight"};
    // cout << longestCommonPrefix(s);

    string s = "egg";
    string t = "add";
    if (isIsomorphic(s, t))
    {
        cout << "Isomorphic String" << endl;
    }
    else
    {
        cout << " Not Isomorphic String" << endl;
    }
    return 0;
}
