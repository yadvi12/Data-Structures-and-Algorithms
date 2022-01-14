#include <bits/stdc++.h>
using namespace std;

int fact(int n)
{
    if (n == 0) //Base condition
        return 1;

    return n * fact(n - 1); //Recurrence relation
}

int main()
{
    int n;
    cin >> n;
    int ans = fact(n);
    cout << ans << endl;
    return 0;
}
