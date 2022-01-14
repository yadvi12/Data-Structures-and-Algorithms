#include <iostream>
using namespace std;

long long sqrt(int n)
{
    long long start = 0;
    long long end = n;
    long long ans = -1;
    while (start <= end)
    {
        long long mid = start + (end - start) / 2;
        long long square = mid * mid;
        if (square == n)
        {
            return mid;
        }
        else if (square > n)
        {
            end = mid - 1;
        }
        else
        {
            ans = mid;
            start = mid + 1;
        }
    }
    return ans;
}

double morePrecision(int n, int precision, int tempsol)
{
    double factor = 1;
    double ans = tempsol;

    for (int i = 0; i < precision; i++)
    {
        factor = factor / 10;
        for (double j = ans; j * j < n; j = j + factor)
        {
            ans = j;
        }
    }
    return ans;
}

int main()
{
    int n;
    cin >> n;
    long long tempsol = sqrt(n);
    cout << morePrecision(n, 3, tempsol) << endl;
    return 0;
}