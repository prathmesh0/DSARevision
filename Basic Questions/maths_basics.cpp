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

void isArmstrong(int num)
{
    int temp = num;
    int count = 0;
    while (temp != 0)
    {
        temp = temp / 10;
        count++;
    }
    temp = num;
    int ans = 0;
    while (temp != 0)
    {
        int digit = temp % 10;
        ans += pow(digit, count);
        temp /= 10;
    }
    if (ans == num)
    {
        cout << "armstrong number" << endl;
    }
    else
        cout << " not armstrong number" << endl;
}

void pritAllDivisor(int num)
{
    // for (int i = 1; i <= num; i++)
    // {
    //     if (num % i == 0)
    //     {
    //         cout << i << " ";
    //     }
    // }
    // cout << endl;
    for (int i = 1; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            cout << i << " ";
        }
        if (num / i != i)
        {
            cout << (num / i) << " ";
        }
    }
    cout << endl;
}

void isPrime(int num)
{
    bool flag = true;
    // for (int i = 2; i < num; i++)
    // {
    //     if (num % i == 0)
    //     {
    //         flag = false;

    //         break;
    //     }
    // }
    // if (flag)
    // {
    //     cout << "Prime Nummber" << endl;
    // }
    // else
    // cout << " Not a Prime Number" << endl;

    for (int i = 2; i < sqrt(num); i++)
    {
        if (num % i == 0)
        {
            flag = false;
            break;
        }
    }
    if (flag)
    {
        cout << "Prime Number" << endl;
    }
    else
        cout << " Not a Prime Number" << endl;
}
int main()
{
    int num = 56;
    // cout << coutNumber(num);
    // reverseNumber(num);
    // isPalindrome(num);
    // int num1 = 18, num2 = 12;
    // int ans = gcdOfNumber(num1, num2);
    // cout << ans << endl;

    // isArmstrong(num);
    // pritAllDivisor(num);
    isPrime(num);
    return 0;
}