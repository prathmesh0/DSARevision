#include <bits/stdc++.h>
using namespace std;

void printonetoN(int count, int n)
{
    if (count > n)
    {
        return;
    }
    cout << count << " ";
    count++;
    printonetoN(count, n);
}

void printName(int count, int n)
{
    if (count == n)
        return;
    cout << "pop" << endl;

    printName(++count, n);
}
void printonetoNfunctional(int n)
{
    if (n == 0)
        return;
    printonetoNfunctional(n - 1);
    cout << n << " ";
}
void printnToone(int n)
{
    if (n < 1)
    {
        return;
    }
    cout << n << " ";
    printnToone(n - 1);
}
void printnTooneParameterized(int i, int n)
{
    if (i > n)
    {
        return;
    }
    printnTooneParameterized(i + 1, n);
    cout << i << " ";
}
void sumofNP(int sum, int n)
{
    if (n < 1)
    {
        cout << sum << endl;
        return;
    }
    sumofNP(sum + n, n - 1);
}

int sumofNf(int n)
{
    int sum = 0;
    if (n == 0)
    {
        return 0;
    }
    sum = n + sumofNf(n - 1);
    return sum;
}

int fFact(int n)
{
    if (n == 0)
    {
        return 1;
    }
    int fact = 1;
    fact = n * fFact(n - 1);
    return fact;
}

void pFact(int ans, int n)
{
    if (n < 1)
    {
        cout << ans;
        return;
    }
    pFact(ans * n, n - 1);
}

void reverseArray(vector<int> &v, int s, int e)
{
    if (s > e)
        return;
    swap(v[s], v[e]);
    reverseArray(v, s + 1, e - 1);
}

bool isPalinfrome(string name, int s, int e)
{
    if (s > e)
    {
        return true;
    }
    if (name[s] != name[e])
        return false;
    return isPalinfrome(name, s + 1, e - 1);
}

int fibbonacci(int n)
{
    if (n <= 1)
    {
        return n;
    }
    int last = fibbonacci(n - 1);
    int sLast = fibbonacci(n - 2);
    return last + sLast;
}

int main()
{
    int n = 5;
    int count = 0;
    // printonetoN(count, n);
    // printName(count, n);
    // printonetoNfunctional(n);
    // printnToone(n);
    // printnTooneParameterized(1, n);
    // sumofNP(0, n);
    // cout << sumofNf(n);
    // cout << fFact(n);
    // pFact(1, n);
    // vector<int> v = {10, 30, 48, 39, 9};
    // int s = 0;
    // int e = v.size() - 1;
    // reverseArray(v, s, e);
    // for (auto it : v)
    // {
    //     cout << it << " ";
    // }
    // string name = "madamm";
    // int start = 0;
    // int end = name.length() - 1;
    // if (isPalinfrome(name, start, end))
    // {
    //     cout << "Palindrome" << endl;
    // }
    // else
    // {
    //     cout << " Not a Palindrome" << endl;
    // }

    // int fib[n];
    // fib[0] = 0;
    // fib[1] = 1;
    // for (int i = 2; i < n; i++)
    // {
    //     fib[i] = fib[i - 1] + fib[i - 2];
    // }
    // for (int i = 0; i < n; i++)
    // {
    //     cout << fib[i] << " ";
    // }
    cout << fibbonacci(n);
    return 0;
}