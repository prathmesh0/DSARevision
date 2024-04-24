#include <bits/stdc++.h>
using namespace std;

// void swapNo(int a, int b)
// {
//     int temp = a;
//     a = b;
//     b = temp;
//     cout << a << " " << b << endl;
// }

void swapNo(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << a << " " << b << endl;
}

int countDig(int num)
{
    // string s = to_string(num);
    // return s.size();

    // int temp = num;
    // int count = 0;
    // while (temp != 0)
    // {
    //     count++;
    //     temp = temp / 10;
    // }
    // return count;

    int ans = floor(log10(num)) + 1;
    return ans;
}

int reverNum(int num)
{
    // string str = to_string(num);
    // reverse(str.begin(), str.end());
    // int ans = stoi(str);
    // return ans;

    int temp = num;
    int rev = 0;

    while (temp != 0)
    {
        int dig = temp % 10;
        rev = rev * 10 + dig;
        temp /= 10;
    }
    return rev;
}

bool isPlaindrome(int num)
{
    int temp = num;
    int rev = 0;

    while (temp != 0)
    {
        int dig = temp % 10;
        rev = rev * 10 + dig;
        temp /= 10;
    }
    return (rev == num);
}
int gcdofNum(int num1, int num2)
{
    // int gcd = 1;
    // for (int i = 1; i <= min(num1, num2); i++)
    // {
    //     if (num1 % i == 0 && num2 % i == 0)
    //     {
    //         gcd = i;
    //     }
    // }
    // return gcd;

    if (num2 == 0)
    {
        return num1;
    }
    return gcdofNum(num2, num1 % num2);
}

bool armStrong(int num)
{
    int temp = num;
    int count = floor(log10(temp)) + 1;

    int sum = 0;
    temp = num;
    while (temp != 0)
    {
        int dig = temp % 10;
        sum += pow(dig, count);
        temp /= 10;
    }
    return sum == num;
}

bool isPrime(int num)
{
    for (int i = 2; i <= sqrt(num); i++)
    {
        if (num % i == 0)
        {
            return false;
        }
    }
    return true;
}

void print1ton(int num)
{
    if (num < 1)
    {
        return;
    }

    cout << num << " ";
    print1ton(num - 1);
}

void reverseA(vector<int> &arr, int start, int end)
{
    if (start > end)
    {
        return;
    }
    swap(arr[start], arr[end]);
    reverseA(arr, start + 1, end - 1);
}

int ocurrenceOfchar(string str, char ch)
{
    // int mpp[26] = {0};
    // for (int i = 0; i < str.length(); i++)
    // {
    //     mpp[str[i] - 'a']++;
    // }
    // ;

    map<int, int> mpp;
    for (int i = 0; i < str.length(); i++)
    {
        mpp[str[i] - 'a']++;
    }
    return mpp[ch -'a'];
}
int main()
{
    // int a = 10, b = 5;
    // cout << a << " " << b << endl;
    // swapNo(a, b);
    // cout << a << " " << b << endl;

    // int n = 4;
    // for (int i = 0; i <= n; i++)
    // {
    //     for (int j = 1; j <= (n - i); j++)
    //     {
    //         cout << "* ";
    //     }
    //     cout << endl;
    // }

    //     for (int i = 0; i < n; i++)
    //     {

    //         // space
    //         for (int j = 0; j < (n - i - 1); j++)
    //         {
    //             cout << " ";
    //         }
    //         // star
    //         for (int j = 0; j < (2 * i + 1); j++)
    //         {
    //             cout << "*";
    //         }
    //         cout << endl;
    //     }
    int num = 13;

    // cout << countDig(num);
    // cout << reverNum(num);

    // if (isPlaindrome(num))
    // {
    //     cout << "palindrome" << endl;
    // }
    // else
    // {
    //     cout << " not palindrome" << endl;
    // }

    // gcd = 3, 6 => 3
    // int num1 = 12, num2 = 18;
    // cout << gcdofNum(num1, num2) << endl;
    // cout << armStrong(num) << endl;
    // cout << isPrime(num) << endl;
    // print1ton(5);

    // vector<int> arr = {12, 3, 44, 1};
    // reverseA(arr, 0, arr.size() - 1);
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }

    // vector<int> v = {19, 0, 1, 1, 13, 4, 4};
    // int n = v.size();

    // int arr[20] = {0};
    // for (int i = 0; i < n; i++) // 19-1, 1->2
    // {
    //     arr[v[i]]++;
    // }

    // cout << arr[1] << endl;
    string str = "abbbababa";
    cout << ocurrenceOfchar(str, 'b');
}