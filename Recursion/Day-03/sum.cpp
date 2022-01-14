#include <bits/stdc++.h>
using namespace std;

int sum = 0;

int getSum(int arr[], int n)
{
    if (n == 0)
        return sum;

    sum += arr[0];

    getSum(arr + 1, n - 1);
}

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = getSum(arr, n);
    cout << "Sum is " << ans;
    return 0;
}