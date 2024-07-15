#include <iostream>
using namespace std;

/*
    Arithmetic, Logical, Relational, Bitwise, Assignment,

*/

void swapNo(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
    cout << "Inside Function " << endl;
    cout << a << b << endl;
}

int main()
{
    // cout << "Hello world" << endl;
    // int age;
    // cout << "Enter your age" << endl;
    // cin >> age;
    // if (age > 18)
    // {
    //     cout << "18+";
    // }
    // else if (age == 18)
    // {
    //     cout << "Exact 18";
    // }
    // else
    // {
    //     cout << "Below 18";
    // }
    // int day = 13;

    // switch (day)
    // {
    // case 1:
    //     cout << "day1" << endl;
    //     break;
    // case 2:
    //     cout << "day2" << endl;
    //     break;
    // case 3:
    //     cout << "day3" << endl;
    //     break;
    // case 4:
    //     cout << "day4" << endl;
    //     break;
    // case 5:
    //     cout << "day5" << endl;
    //     break;
    // default:
    //     cout << "Invalid" << endl;
    //     break;
    // }

    // for (int i = 0; i < 5; i++)
    // {
    //     cout << "prathmesh" << endl;
    // }
    // int n = 5;
    // while (n != 0)
    // {
    //     cout << "Pop" << endl;
    //     n--;
    // }

    // int a = 1;
    // do
    // {
    //     cout << "pratham" << " ";

    // } while (a != 0);

    // int a = 5, b = 10;

    // cout << "inside the main before swap " << a << b << endl;
    // swapNo(a, b);
    // cout << "inside the main after  swap" << a << b << endl;

    int n = 5;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        arr[i] = num;
    }

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}
