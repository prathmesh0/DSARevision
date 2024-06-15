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
    // Brute force
    //  if (s.length() != t.length())
    //      return false;

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

    // optimal approach
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

bool isAnagram(string s, string t)
{
    // Brute force approach
    // if (s.length() != t.length())
    //     return false;
    // sort(s.begin(), s.end());
    // sort(t.begin(), t.end());
    // return s == t;

    // Optimise approach
    int freq[26] = {0};

    for (int i = 0; i < s.length(); i++)
    {
        freq[s[i] - 'a']++;
    }

    for (int i = 0; i < t.length(); i++)
    {
        freq[t[i] - 'a']--;
    }

    for (int i = 0; i < 26; i++)
    {
        if (freq[i] != 0)
        {
            return false;
        }
    }
    return true;
}

bool rotateString(string s, string goal)
{

    // brute force
    // if (s.length() != goal.length())
    // {
    //     return false;
    // }
    // queue<char> q1;
    // queue<char> q2;

    // for (int i = 0; i < s.size(); i++)
    // {
    //     q1.push(s[i]);
    // }
    // for (int i = 0; i < goal.size(); i++)
    // {
    //     q2.push(goal[i]);
    // }
    // int k = goal.size();

    // while (k--)
    // {
    //     char ch = q2.front();
    //     q2.pop();
    //     q2.push(ch);
    //     if (q1 == q2)
    //         return true;
    // }
    // return false;

    // optimal approach
    if (s.length() != goal.length())
    {
        return false;
    }

    string temp = s + s;
    return (temp.find(goal) != string::npos);
}

int maxDepth(string s)
{
    // brute-force
    //  stack<char> st;
    //  int ans = 0;
    //  for (int i = 0; i < s.size(); i++)
    //  {
    //      if (s[i] == '(')
    //      {
    //          st.push('(');
    //      }
    //      else if (s[i] == ')')
    //      {
    //          st.pop();
    //      }
    //      ans = max(ans, (int)st.size());
    //  }
    //  return ans;

    // optimal approach
    int max = 0;
    int curr_max = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
        {
            curr_max++;
            if (curr_max > max)
            {
                max = curr_max;
            }
        }
        else if (s[i] == ')')
        {
            if (curr_max > 0)
            {
                curr_max--;
            }
            else
            {
                return -1;
            }
        }
    }
    if (curr_max != 0)
    {
        return -1;
    }
    return max;
}

int romanToInt(string s)
{
    unordered_map<char, int> mpp = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };
    int num, sum = 0;
    int n = s.length();
    for (int i = 0; i < n;)
    {
        if (i == (n - 1) || (mpp[s[i]] >= mpp[s[i + 1]]))
        {
            num = mpp[s[i]];
            i++;
        }
        else
        {
            num = mpp[s[i + 1]] - mpp[s[i]];
            i = i + 2;
        }
        sum += num;
    }
    return sum;
}

int myAtoi(string s)
{
    if (s.length() == 0)
    {
        return 0;
    }
    int i = 0;
    // handle leading white spaces
    while (i < s.size() && s[i] == ' ')
    {
        i++;
    }
    s = s.substr(i);
    long ans = 0;
    int sign = +1;

    if (s[0] == '-')
        sign = -1;
    i = (s[0] == '+' || s[0] == '-') ? 1 : 0;

    while (i < s.length())
    {
        if (s[0] == ' ' || !isdigit(s[i]))
        {
            break;
        }
        ans = ans * 10 + (s[i] - '0');
        if (sign == -1 && -1 * ans < INT_MIN)
            return INT_MIN;
        if (sign == 1 && ans > INT_MAX)
            return INT_MAX;
        i++;
    }
    return (int)(sign * ans);
}

char nonrepeatingCharacter(string S)
{

    vector<int> mpp(26, 0);
    int n = S.length();

    for (int i = 0; i < n; i++)
    {
        mpp[S[i] - 'a']++;
    }

    for (int i = 0; i < n; i++)
    {
        if (mpp[S[i] - 'a'] == 1)
        {
            return S[i];
        }
    }

    return '$';
}
char *reverse(char *S, int len)
{
    stack<char> st;

    for (int i = 0; i < len; i++)
    {
        st.push(S[i]);
    }

    int i = 0;
    while (!st.empty())
    {
        char ch = st.top();
        S[i++] = ch;
        st.pop();
    }
    return S;
}

string removeDups(string S)
{

    // Brute force
    unordered_set<char> st;
    string ans = "";

    for (auto it : S)
    {
        if (st.find(it) == st.end())
        {
            ans += it;
            st.insert(it);
        }
    }
    return ans;
    // Optimal Approach

    // string ans = "";
    // for (int i = 0; i < S.length(); i++)
    // {
    //     if (ans.find(S[i]) == string::npos)
    //     {
    //         ans += S[i];
    //     }
    // }
    // return ans;
}

char getMaxOccuringChar(string str)
{
    map<char, int> mpp;
    char ans;
    int maxi = INT_MIN;

    // Count frequency of each character
    for (int i = 0; i < str.size(); i++)
    {
        mpp[str[i]]++;
    }

    // Find the character with the maximum frequency
    for (auto it : mpp)
    {
        if (it.second > maxi)
        {
            ans = it.first;
            maxi = it.second;
        }
    }

    return ans;
}

bool check(int k, string s, string x)
{

    for (int i = 0; i < x.length(); i++)
    {
        if (s[k + i] != x[i])
            return false;
    }
    return true;
}
int strstr(string s, string x)
{
    // int n = s.length();
    // int m = x.length();

    // if (m > n)
    //     return -1;
    // for (int i = 0; i <= n - m; i++)
    // {
    //     if (s.substr(i, m) == x)
    //     {
    //         return i;
    //     }
    // }
    // return -1;

    // without using inbuilt function
    if (s.length() < x.length())
    {
        return -1;
    }

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == x[0])
        {
            if (check(i, s, x))
                return i;
        }
    }
    return -1;
}

vector<string> winner(string arr[], int n)
{
    map<string, int> mpp;
    vector<string> ans;

    for (int i = 0; i < n; i++)
    {
        mpp[arr[i]]++;
    }

    string temp = "";
    int maxi = INT_MIN;
    for (auto it : mpp)
    {
        if (it.second > maxi)
        {
            maxi = it.second;
            temp = it.first;
        }
    }

    ans.push_back(temp);
    ans.push_back(to_string(maxi));
    return ans;
}

int minIndexChar(string str, string patt)
{
    // Brute force
    //  set<char> st;

    // for (auto it : patt)
    // {
    //     st.insert(it);
    // }

    // int mini = INT_MAX;
    // for (int i = 0; i < str.length(); i++)
    // {
    //     if (st.find(str[i]) != st.end())
    //     {
    //         mini = min(mini, i);
    //     }
    // }
    // return mini == INT_MAX ? -1 : mini;

    // Optimal approach
    for (int i = 0; i < str.length(); i++)
    {
        if (patt.find(str[i]) != string::npos)
        {
            return i;
        }
    }
    return -1;
}

string encode(string s)
{
    string ans;
    int cnt = 1;
    char prev = s[0];
    for (int i = 1; i < s.length(); i++)
    {
        if (s[i] == prev)
        {
            cnt++;
        }
        else
        {
            ans += prev;
            ans += to_string(cnt);
            prev = s[i];
            cnt = 1;
        }
    }
    ans += prev;
    ans += to_string(cnt);
    return ans;
}

bool isPalindrome(string str)
{
    int s = 0, e = str.length() - 1;
    while (s <= e)
    {
        if (str[s] != str[e])
        {
            return false;
        }
        s++;
        e--;
    }
    return true;
}

string longestPalindrome(string s)
{
    // int n = s.length();
    // if (n == 0)
    //     return "";
    // if (n == 1)
    //     return s;

    // string ans = "";
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = i; j < n; j++)
    //     {
    //         string curr_sub = s.substr(i, j - i + 1);
    //         if (isPalindrome(curr_sub))
    //         {
    //             if (ans.size() < curr_sub.size())
    //             {
    //                 ans = curr_sub;
    //             }
    //         }
    //     }
    // }
    // return ans;

    int n = s.length();
    int len = 1;
    int start = 0, end = 0;
    for (int i = 0; i < n; i++)
    {

        // odd length palindrome check
        int l = i - 1, r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if ((r - l + 1) > len)
            {
                len = r - l + 1;
                start = l;
                end = r;
            }
            l--;
            r++;
        }

        // even length palindrome check
        l = i;
        r = i + 1;
        while (l >= 0 && r < n && s[l] == s[r])
        {
            if ((r - l + 1) > len)
            {
                len = r - l + 1;
                start = l;
                end = r;
            }
            l--;
            r++;
        }
    }
    string ans = s.substr(start, end - start + 1);
    return ans;
}

int beautySum(string s)
{
    // int n = s.length();
    // int ans = 0;
    // for (int i = 0; i < n; i++)
    // {
    //     unordered_map<char, int> mpp;
    //     for (int j = i; j < n; j++)
    //     {
    //         mpp[s[j]]++;
    //         int mini = INT_MAX, maxi = INT_MIN;
    //         for (auto it : mpp)
    //         {
    //             mini = min(mini, it.second);
    //             maxi = max(maxi, it.second);
    //         }
    //         ans += maxi - mini;
    //     }
    // }
    // return ans;

    int ans = 0;
    int n = s.length();
    for (int i = 0; i < n; i++)
    {
        unordered_map<char, int> mpp;
        multiset<int> st;
        for (int j = i; j < n; j++)
        {
            if (mpp.find(s[j]) != mpp.end())
            {
                st.erase(st.find(mpp[s[j]]));
            }
            mpp[s[j]]++;
            st.insert(mpp[s[j]]);
            ans += (*st.rbegin() - *st.begin());
        }
    }
    return ans;
}
bool checkPangram(string s)
{
    int arr[26] = {0};

    for (auto it : s)
    {
        int k = tolower(it) - 'a';
        arr[k]++;
    }

    for (auto it : arr)
    {
        if (it == 0)
        {
            return 0;
        }
    }
    return 1;
}
bool isIsogram(string s)
{
    vector<int> freq(26, 0);
    for (int i = 0; i < s.size(); i++)
    {
        freq[s[i] - 'a']++;
    }

    for (auto it : freq)
    {
        if (it > 1)
        {
            return false;
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

    // string s = "egg";
    // string t = "add";
    // if (isIsomorphic(s, t))
    // {
    //     cout << "Isomorphic String" << endl;
    // }
    // else
    // {
    //     cout << " Not Isomorphic String" << endl;
    // }
    // string s = "act", t = "cdat";
    // if (isAnagram(s, t))
    // {
    //     cout << "Anagram " << endl;
    // }
    // else
    // {
    //     cout << " Not Anagram " << endl;
    // }

    // string s = "abcde", goal = "cdeab";
    // if (rotateString(s, goal))
    // {
    //     cout << "Rotated" << endl;
    // }
    // else
    // {
    //     cout << " Not Rotated" << endl;
    // }

    // string s = "(1+(2*3)+((8)/4))+1";
    // cout << maxDepth(s) << endl;

    // string s1 = "LVIII";
    // cout << romanToInt(s1) << endl;

    // string s2 = "    -1337c0d3";
    // cout << myAtoi(s2) << endl;

    // string s = "aabddggee";
    // cout << nonrepeatingCharacter(s);

    // char S1[] = "hello";
    // int len1 = strlen(S1);
    // cout << "Original: " << S1 << endl;
    // cout << "Reversed: " << reverse(S1, len1) << endl;

    // string s = "aabddjggfee";
    // cout << removeDups(s);

    // string s2 = "hhggghhhhhhrwjdn";
    // cout << getMaxOccuringChar(s2);

    // string s = "GeeksForGeeks", x = "For";
    // cout << strstr(s, x);

    // int n = 13;
    // string arr[] = {"john", "johnny", "jackie", "johnny", "john",
    //                 "jackie", "jamie", "jamie", "john", "johnny", "jamie",
    //                 "johnny", "john"};

    // vector<string> ans = winner(arr, n);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }

    // string str = "geeksforgeeks";
    // string patt = "set";
    // cout << minIndexChar(str, patt) << endl;

    // string s = "babad";
    // cout << longestPalindrome(s) << endl;
    string s = "aabcbaa";
    cout << beautySum(s) << endl;
    return 0;
}
