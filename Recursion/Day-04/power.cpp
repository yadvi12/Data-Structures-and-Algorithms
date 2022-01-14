//take two values a and b from the user and output 'a to the power b'

#include <bits/stdc++.h>
using namespace std;

int power(int a, int b)
{
    //base case
    if (b == 0)
    {
        return 1;
    }
    //Recursive call
    int ans = power(a, b / 2);
    if (b % 2 == 0)
    {
        return ans * ans;
    }
    else
    {
        return a * ans * ans;
    }
}

int main()
{
    int a, b;
    cin >> a >> b;
    int ans = power(a, b);
    cout << ans << endl;
    return 0;
}