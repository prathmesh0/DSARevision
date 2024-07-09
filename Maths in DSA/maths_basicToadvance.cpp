#include <bits/stdc++.h>
using namespace std;

void print_divisors(int n)
{

    // Brute force approach
    //  for (int i = 1; i <= n; i++)
    //  {
    //      if (n % i == 0)
    //      {
    //          cout << i << " ";
    //      }
    //  }

    // Optimal approach
    vector<int> ans;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            if ((n / i) != i)
            {
                ans.push_back(n / i);
            }
        }
    }
    sort(ans.begin(), ans.end());
    for (auto it : ans)
    {
        cout << it << " ";
    }
}

bool isPrime(int n)
{

    // Brute force approach
    // int cnt = 0;
    // for (int i = 1; i <= n; i++)
    // {

    //     if (n % i == 0)
    //     {
    //         cnt++;
    //     }
    // }
    // if (cnt == 2)
    //     cout << "Prime" << endl;
    // else
    //     cout << " Not Prime" << endl;

    // Optimal approach

    int cnt = 0;
    for (int i = 1; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            cnt++;
            if ((n / i) != i)
                cnt++;
        }
    }
    if (cnt == 2)
        return true;
    // cout << "Prime" << endl;

    else
        return false;
    // cout << " Not Prime" << endl;
}
double myPow(double x, int n)
{
    double ans = 1.0;
    int m = abs(n);
    while (m > 0)
    {
        if (m % 2 == 1)
        {
            ans = ans * x;
            m = m - 1;
        }
        else
        {
            m = m / 2;
            x = x * x;
        }
    }
    if (n < 0)
    {
        return (1.0 / ans);
    }
    return ans;
}
vector<int> primeFactor(int n)
{
    // vector<int> ans;
    // for (int i = 2; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         if (isPrime(i))
    //         {
    //             ans.push_back(i);
    //         }
    //     }
    // }
    // return ans;

    // better approch
    // vector<int> ans;
    // for (int i = 2; i * i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         if (isPrime(i))
    //         {
    //             ans.push_back(i);
    //         }
    //         if ((n / i) != i)
    //         {
    //             if (isPrime(n / i))
    //             {
    //                 ans.push_back(n / i);
    //             }
    //         }
    //     }
    // }
    // return ans;

    // Better approach 2
    // vector<int> ans;
    // for (int i = 2; i <= n; i++)
    // {
    //     if (n % i == 0)
    //     {
    //         ans.push_back(i);
    //         while (n % i == 0)
    //         {
    //             n = n / i;
    //         }
    //     }
    // }
    // return ans;

    // Optimal approach
    vector<int> ans;
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            ans.push_back(i);
            while (n % i == 0)
            {
                n = n / i;
            }
        }
    }
    if (n != 1)
        ans.push_back(n);
    return ans;
}
int countPrimes(int n)
{
    int cnt = 0;
    vector<int> isPrime(n + 1, 1);

    for (int i = 2; i * i <= n; i++)
    {
        if (isPrime[i] == 1)
        {

            for (int j = i * i; j <= n; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
    for (int i = 2; i < n; i++)
    {
        if (isPrime[i] == 1)
            cnt++;
    }
    return cnt;
}
int main()
{
    int n = 60;
    // print_divisors(n);
    // isPrime(13);
    // vector<int> ans;
    // ans = primeFactor(n);
    // for (auto it : ans)
    // {
    //     cout << it << " ";
    // }
    cout << countPrimes(10) << endl;
    return 0;
}