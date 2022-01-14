#include <bits/stdc++.h>
using namespace std;

int power(int n)
{
    if (n == 0) //Base condition
        return 1;

    return 2 * power(n - 1); //Recurrence relation
}

int main()
{
    int n;
    cin >> n;
    int ans = power(n);
    cout << ans << endl;
    return 0;
}