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

void isPrime(int n)
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
        cout << "Prime" << endl;
    else
        cout << " Not Prime" << endl;
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

int main()
{
    int n = 36;
    // print_divisors(n);
    isPrime(13);
    return 0;
}