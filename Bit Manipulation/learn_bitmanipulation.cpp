#include <bits/stdc++.h>
using namespace std;

string decimalToBinary(int n)
{
    string res = "";
    while (n != 0)
    {
        if (n % 2 == 1)
            res += '1';
        else
            res += '0';
        n = n / 2;
    }
    reverse(res.begin(), res.end());
    return res;
}
pair<int, int> swapNo(int a, int b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
    return {a, b};
}

bool checkKthBit(int n, int k)
{
    // using left shift
    //  if (n & (1 << k))
    //  {
    //      return true;
    //  }
    //  return false;

    // using right shift
    if ((n >> k) & 1 == 1)
    {
        return true;
    }
    return false;
}

int setithBit(int n, int i)
{
    return (n | (1 << i));
}

int clearithBit(int n, int i)
{
    return (n & ~(1 << i));
}

int binaryToDecimal(string s)
{
    int len = s.size();
    int pow = 1, num = 0;
    for (int i = len - 1; i >= 0; i--)
    {
        if (s[i] == '1')
        {
            num = num + pow;
        }
        pow = pow * 2;
    }
    return num;
}
int toggleIthBit(int n, int i)
{
    return (n ^ (1 << i));
}
int removelastSetBit(int n)
{
    return (n & (n - 1));
}

bool isPowerOfTwo(int n)
{
    if (n >= 1 && (n & (n - 1)) == 0)
        return true;
    return false;
}
string oddEven(int N)
{
    if (N & 1 == 1)
    {
        return "odd";
    }
    return "even";
}

int countSetBits(int n)
{
    // Brute force
    //  int cnt = 0;
    //  while (n > 1)
    //  {
    //      if (n % 2 == 1)
    //      {
    //          cnt++;
    //      }
    //      n = n / 2;
    //  }
    //  if (n == 1)
    //      cnt++;
    //  return cnt;

    // int cnt = 0;
    // while (n > 1)
    // {
    //     if ((n & 1) == 1)
    //     {
    //         cnt++;
    //     }
    //     n = n >> 1;
    // }
    // if (n == 1)
    //     cnt++;
    // return cnt;

    // optimal approach
    int cnt = 0;
    while (n != 0)
    {
        n = (n & (n - 1));
        cnt++;
    }
    return cnt;
}
int main()
{

    int n = 13;
    // cout << decimalToBinary(4);
    // string s = "1100";
    // cout << endl;
    // cout << binaryToDecimal(s);
    // int a = 5, b = 3;
    // pair<int, int> ans = swapNo(a, b);
    // cout << ans.first << " " << ans.second << endl;
    // cout << setithBit(9, 2) << endl;
    // cout << clearithBit(13, 2);

    // cout << toggleIthBit(n, 2);
    // cout << removelastSetBit(16);
    // cout << isPowerOfTwo(16) << endl;
    // cout << oddEven(8) << endl;
    cout << countSetBits(13) << endl;

    return 0;
}