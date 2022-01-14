#include <bits/stdc++.h>
using namespace std;

int fibonacci(int n)
{
    //base case
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;

    //recurrence relation
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
    int n;
    cin >> n;
    int ans = fibonacci(n);
    cout << ans << endl;
    return 0;
}
