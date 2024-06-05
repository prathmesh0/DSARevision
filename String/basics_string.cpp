#include <bits/stdc++.h>
using namespace std;

int finLength(string str)
{
    // using in built
    // return str.length();

    // withouut using inbuilt

    int i;
    for (i = 0; str[i] != '\0'; i++)
    {
    }

    return i;
}

string displayFromBack(string s)
{
    int n = s.length();
    string ans = "";
    for (int i = n - 1; i >= 0; i--)
    {
        ans += s[i];
    }
    return ans;
}

int countWord(string t)
{
    int n;
    for (n = 0; t[n] != '\0'; n++)
    {
    }
    int words = 0;
    for (int i = 0; i < n; i++)
    {
        if (t[i] == ' ')
        {
            words++;
        }
    }
    return words + 1;
}
string concatinateString(string m, string n)
{
    // using + operator
    string ans = m + n;
    return ans;
}
bool isEqual(string a1, string a2)
{
    // return a1 == a2;
    if (a1.length() != a2.length())
        return false;
    for (int i = 0; i < a2.length(); i++)
    {
        if (a1[i] != a2[i])
        {
            return false;
        }
    }
    return true;
}
bool isPalindrom(string w)
{
    // using extra space
    //  string rev = "";
    int n = w.length();

    // for (int i = n - 1; i >= 0; i--)
    // {
    //     rev += w[i];
    // }
    // return rev == w;

    // without using extra space
    int s = 0, e = n - 1;
    while (s <= e)
    {
        if (w[s] != w[e])
        {
            return false;
        }
        else
        {
            s++;
            e--;
        }
    }
    return true;
}
string reverseWord(string &g)
{
    // using extra string
    // string ans = "";
    int n = g.size();
    // for (int i = n - 1; i >= 0; i--)
    // {
    //     ans += g[i];
    // }
    // return ans;

    // with out using extra string
    int s = 0, e = n - 1;
    while (s <= e)
    {
        swap(g[s], g[e]);
        s++, e--;
    }
    return g;
}

string lowecase(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] = str[i] + ('a' - 'A'); // A + 32 --> 65 +32 = 97 = 'a'
        }
    }
    return str;
}

string uppercase(string str)
{
    int n = str.size();
    for (int i = 0; i < n; i++)
    {
        if (str[i] >= 'a' && str[i] <= 'z')
        {
            str[i] = str[i] - ('a' - 'A'); // a - 32 --> 97 - 32 = 65 = 'A'
        }
    }
    return str;
}
int main()
{
    // string str;
    // cout << "Enter string" << endl;
    // getline(cin, str);
    // int ans = finLength(str);
    // cout << ans << endl;

    // string s = "Hello I am Pop";
    // cout << displayFromBack(s);

    // string t = "Hello Jarvis up?";
    // cout << countWord(t);

    // string m = "Hello  i am Prathmesh.";
    // string n = "Computer Engineer student.";
    // cout << concatinateString(m, n);

    // string a1 = "Pop";
    // string a2 = "Pop";
    // if (isEqual(a1, a2))
    // {
    //     cout << "String are equal" << endl;
    // }
    // else
    // {
    //     cout << "String are not equal" << endl;
    // }

    // string w = "madam";
    // isPalindrom(w) ? cout << "palindrome" : cout << "Not a palindrome";
    // cout << endl;

    // string g = "Prathmesh";
    // cout << reverseWord(g);

    // string h = "PRATHMESH PARAB";
    // cout << lowecase(h);
    string o = "prathmesh parab";
    cout << uppercase(o);
    return 0;
}