#include <bits/stdc++.h>
using namespace std;

int first = -1;
int last = -1;

int firstPosition(int arr[], int s, int e, int k)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
    {
        first = mid;
        firstPosition(arr, mid + 1, e, k);
    }
    else if (arr[mid] < k)
    {
        firstPosition(arr, mid + 1, e, k);
    }
    else
    {
        firstPosition(arr, s, mid - 1, k);
    }
    return first;
}

int lastPosition(int arr[], int s, int e, int k)
{
    if (s > e)
        return -1;

    int mid = s + (e - s) / 2;

    if (arr[mid] == k)
    {
        last = mid;
        lastPosition(arr, s, mid - 1, k);
    }
    else if (arr[mid] < k)
    {
        lastPosition(arr, mid + 1, e, k);
    }
    else
    {
        lastPosition(arr, s, mid - 1, k);
    }
    return last;
}

int main()
{

    int arr[11] = {2, 2, 4, 6, 6, 6, 6, 7, 8, 8, 8};
    int k = 6;
    pair<int, int> ans;
    ans.first = firstPosition(arr, 0, 6, k);
    ans.second = lastPosition(arr, 0, 6, k);
    int totaloccurence = ans.first - ans.second;
    cout << totaloccurence + 1 << endl;
    return 0;
}