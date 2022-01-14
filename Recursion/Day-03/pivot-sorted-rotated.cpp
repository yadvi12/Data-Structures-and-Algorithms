#include <bits/stdc++.h>
using namespace std;

//pivot in a sorted and rotated array using recursion

int findPivot(int arr[], int start, int end)
{
    if (start >= end)
        return start;

    int mid = start + (end - start) / 2;

    if (arr[mid] >= arr[0])
    {
        findPivot(arr, mid + 1, end);
    }
    else
    {
        findPivot(arr, start, mid);
    }
}

int main()
{
    int n = 5;
    int arr[1] = {2};
    int ans = findPivot(arr, 0, 0);
    cout << ans << endl;
    return 0;
}