#include <bits/stdc++.h>
using namespace std;

int findPivot(int arr[], int start, int end)
{
    if (start >= end)
    {
        return start;
    }

    int mid = start + (end - start) / 2;
    if (arr[0] <= arr[mid])
    {
        findPivot(arr, mid + 1, end);
    }
    else
    {
        findPivot(arr, start, mid);
    }
}

int binarySearch(int arr[], int start, int end, int key)
{
    if (start > end)
    {
        return -1;
    }

    int mid = start + (end - start) / 2;

    if (arr[mid] == key)
    {
        return mid;
    }
    else if (arr[mid] > key)
    {
        binarySearch(arr, start, mid - 1, key);
    }
    else
    {
        binarySearch(arr, mid + 1, end, key);
    }
}

int findPosition(int arr[], int n, int key)
{
    int start = 0;
    int end = n - 1;
    int pivot = findPivot(arr, start, end);
    if (key >= arr[pivot] && key < arr[n])
    {
        return binarySearch(arr, pivot, n - 1, key);
    }
    else
    {
        return binarySearch(arr, 0, pivot - 1, key);
    }
}

int main()
{
    int n;
    cin >> n;
    int key;
    cin >> key;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int ans = findPosition(arr, n, key); //2 1 2
    cout << ans << endl;
    return 0;
}