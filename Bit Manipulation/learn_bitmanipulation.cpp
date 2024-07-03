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
int main()
{

    int n = 13;
    cout << decimalToBinary(4);
    string s = "1100";
    cout << endl;
    cout << binaryToDecimal(s);
    // int a = 5, b = 3;
    // pair<int, int> ans = swapNo(a, b);
    // cout << ans.first << " " << ans.second << endl;
    // cout << setithBit(9, 2) << endl;
    // cout << clearithBit(13, 2);
    return 0;
}