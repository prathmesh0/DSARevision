#include <bits/stdc++.h>
using namespace std;

int coutNumber(int num)
{
    // int temp = num;
    // int count = 0;
    // while (temp != 0)
    // {
    //     temp = temp / 10;
    //     count++;
    // }
    // return count;
    string ans = to_string(num);

    return ans.length();
    // int ans = floor(log10(num)) + 1;
    // return ans;
}

void reverseNumber(int num)
{
    // string n = to_string(num);
    // reverse(n.begin(), n.end());
    // int ans = stoi(n);
    // cout<<ans;

    int temp = num;
    int ans = 0;
    while (temp != 0)
    {
        int digit = temp % 10;
        ans = ans * 10 + digit;
        temp = temp / 10;
    }
    cout << ans;
}

void isPalindrome(int num)
{
    // string str = to_string(num);
    // int s = 0;
    // int e = str.length() - 1;
    // int flag = true;
    // while (s <= e)
    // {
    //     if (str[s] != str[e])
    //     {
    //         flag = false;
    //         break;
    //     }
    //     s++;
    //     e--;
    // }
    // if (flag)
    // {
    //     cout << "Palindrome" << endl;
    // }
    // else
    // cout << " Not Palindrome" << endl;

    int temp = num;
    int ans = 0;
    while (temp != 0)
    {
        int digit = temp % 10;
        ans = ans * 10 + digit;
        temp = temp / 10;
    }

    if (num == ans)
    {
        cout << "Palindrome" << endl;
    }
    else
    {
        cout << " Not Palindrome" << endl;
    }
}

int gcdOfNumber(int num1, int num2)
{
    // int ans = 1;
    // for (int i = 1; i <= min(num1, num2); i++)
    // {
    //     if (num1 % i == 0 && num2 % i == 0)
    //     {
    //         ans = i;
    //     }
    // }
    // cout << "GCD = " << ans << endl;

    // recursive
    if (num2 == 0)
        return num1;
    return gcdOfNumber(num2, num1 % num2);
}
int main()
{
    int num = 1231;
    // cout << coutNumber(num);
    // reverseNumber(num);
    // isPalindrome(num);
    int num1 = 18, num2 = 12;
    int ans = gcdOfNumber(num1, num2);
    cout << ans << endl;
    return 0;
}